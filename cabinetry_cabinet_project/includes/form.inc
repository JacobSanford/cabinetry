<?php
/**
 * @file
 * Provides validation handlers for the cabinetry_cabinet_project node_form.
 */

/**
 * Form submit handler for cabinetry_cabinet_project node form.
 *
 * @see cabinetry_cabinet_project_validate_cabinet_dimensions()
 * @see cabinetry_cabinet_project_validate_thirty_two_system()
 */
function cabinetry_cabinet_project_generate_materials(&$form, &$form_state) {
  _cabinetry_core_bootstrap();
  _cabinetry_cabinet_project_bootstrap();

  $project = new CabinetryCabinetProject();
  $project->frameRouterBit = _cabinetry_cabinet_project_load_router_bit_object($form_state['values']['field_cabinetry_frame_router_bit'][LANGUAGE_NONE][0]['tid']);
  $project->solidStockLength = $form_state['values']['field_cabinetry_solid_stock_leng'][LANGUAGE_NONE][0]['value'];
  $project->bladeCutWidth = $form_state['values']['field_cabinetry_blade_cut_width'][LANGUAGE_NONE][0]['value'];

  foreach ($form_state['values']['field_cabinetry_project_componen'][LANGUAGE_NONE] as $component_index => $cabinet_component) {
    if (is_numeric($component_index)) {
      foreach ($cabinet_component['field_cabinetry_name'][LANGUAGE_NONE] as $name_index => $name_value) {
        if (!empty($name_value['value'])) {
          $component = new CabinetryBasicEuroCabinet();
          $component->label = $name_value['value'];
          $component->doorFrameRouterBit = $project->frameRouterBit;
          $component->build($cabinet_component);
          $project->addComponent($component);
        }
      }
    }
  }
  $project->collateParts();
  $project->packSolids($form_state['values']['field_cabinetry_sheet_packing_al'][LANGUAGE_NONE][0]['value']);
  $project->packSheets($form_state['values']['field_cabinetry_sheet_packing_al'][LANGUAGE_NONE][0]['value']);
  $project->plotSheets();

  ctools_include('object-cache');
  ctools_object_cache_set('cabinetry_cabinet_project', 'presave_object', $project);
}

/**
 * Validation handler for the cabinetry_cabinet_project node_form.
 *
 * If width, height of depth are not units of 32, then reject those fields and
 * set a form error.
 */
function cabinetry_cabinet_project_validate_thirty_two_system(&$form, &$form_state) {
  if ($form_state['values']['field_cabinetry_enforce_32mm'][LANGUAGE_NONE][0]['value'] == '1') {
    foreach ($form_state['values']['field_cabinetry_project_componen'][LANGUAGE_NONE] as $component_index => $cabinet_component) {
      if (is_numeric($component_index)) {
        foreach (array('field_cabinetry_width', 'field_cabinetry_height', 'field_cabinetry_depth') as $audit_field) {
          if (
            !empty($cabinet_component[$audit_field][LANGUAGE_NONE][0]['value']) &&
            !_cabinetry_cabinet_project_float_evenly_divisible($cabinet_component[$audit_field][LANGUAGE_NONE][0]['value'], CABINETRY_CABINET_PROJECT_THIRTY_TWO_UNIT_SIZE)
          ) {
            form_set_error(
              'field_cabinetry_project_componen][' . LANGUAGE_NONE . '][' . $component_index . '][' . $audit_field . '][' . LANGUAGE_NONE . '][0',
              t(
                'The @field_label value of Component @component_index [@value] is not evenly divisible by 32.0',
                array(
                  '@component_index' => $component_index,
                  '@field_label' => $form['field_cabinetry_project_componen'][LANGUAGE_NONE][$component_index][$audit_field][LANGUAGE_NONE][0]['value']['#title'],
                  '@value' => $cabinet_component[$audit_field][LANGUAGE_NONE][0]['value'],
                )
              )
            );
          }
        }
      }
    }
  }
}

/**
 * Validation handler for the cabinetry_cabinet_project node_form.
 *
 * Ensure width, height of depth are set for each component.
 */
function cabinetry_cabinet_project_validate_cabinet_dimensions(&$form, &$form_state) {
  foreach ($form_state['values']['field_cabinetry_project_componen'][LANGUAGE_NONE] as $component_index => $cabinet_component) {
    if (is_numeric($component_index)) {
      foreach (array('field_cabinetry_width', 'field_cabinetry_height', 'field_cabinetry_depth') as $audit_field) {
        if (
          empty($cabinet_component[$audit_field][LANGUAGE_NONE][0]['value']) ||
          !is_numeric($cabinet_component[$audit_field][LANGUAGE_NONE][0]['value']) ||
          $cabinet_component[$audit_field][LANGUAGE_NONE][0]['value'] < 0
        ) {
          form_set_error(
            'field_cabinetry_project_componen][' . LANGUAGE_NONE . '][' . $component_index . '][' . $audit_field . '][' . LANGUAGE_NONE . '][0',
            t(
              'The @field_label value of Component @component_index is not a positive decimal number.',
              array(
                '@audit_field' => $audit_field,
                '@component_index' => $component_index,
                '@field_label' => $form['field_cabinetry_project_componen'][LANGUAGE_NONE][$component_index][$audit_field][LANGUAGE_NONE][0]['value']['#title'],
              )
            )
          );
        }
      }
    }
  }
}

/**
 * Validation handler for the cabinetry_cabinet_project node_form.
 *
 * Audit division ratios.
 */
function cabinetry_cabinet_project_validate_division_ratio(&$form, &$form_state) {
  $division_ratio_sum = 0.0;
  foreach ($form_state['values']['field_cabinetry_project_componen'][LANGUAGE_NONE] as $component_index => $cabinet_component) {
    if (is_numeric($component_index)) {
      foreach ($cabinet_component['field_cabinetry_carcass_division'][LANGUAGE_NONE][0]['field_cabinetry_division_ratio'][LANGUAGE_NONE] as $division_index => $division_ratio) {
        if (!empty($division_ratio['value'])) {
          $division_ratio_sum += (float) $division_ratio['value'];

          if ($form_state['values']['field_cabinetry_enforce_32mm'][LANGUAGE_NONE][0]['value'] == '1') {
            if (!empty($form_state['values']['field_cabinetry_project_componen'][LANGUAGE_NONE][$component_index]['field_cabinetry_height'][LANGUAGE_NONE][0]['value'])) {
              $section_height = (float) $cabinet_component['field_cabinetry_height'][LANGUAGE_NONE][0]['value'] * (float) $division_ratio['value'];
              $section_height = round($section_height, 1);
              if (!_cabinetry_cabinet_project_float_evenly_divisible($section_height, CABINETRY_CABINET_PROJECT_THIRTY_TWO_UNIT_SIZE)) {
                form_set_error(
                  'field_cabinetry_project_componen][' . LANGUAGE_NONE . '][' . $component_index . '][field_cabinetry_carcass_division][' . LANGUAGE_NONE . '][0][field_cabinetry_division_ratio][' . LANGUAGE_NONE . '][' . $division_index,
                  t(
                    '@field_label @division_id of Component @component_index of does not evenly divide by 32, and Enforce 32 is enabled.',
                    array(
                      '@component_index' => $component_index,
                      '@division_id' => $division_index,
                      '@field_label' => $form['field_cabinetry_project_componen'][LANGUAGE_NONE][$component_index]['field_cabinetry_carcass_division'][LANGUAGE_NONE][0]['#title'],
                    )
                  )
                );
              }
            }
          }

        }
      }
      if ($division_ratio_sum != 1.0) {
        form_set_error(
          'field_cabinetry_project_componen][' . LANGUAGE_NONE . '][' . $component_index . '][field_cabinetry_carcass_division',
          t(
            'The sum of the @field_label elements of Component @component_index is not 1.0.',
            array(
              '@component_index' => $component_index,
              '@field_label' => $form['field_cabinetry_project_componen'][LANGUAGE_NONE][$component_index]['field_cabinetry_carcass_division'][LANGUAGE_NONE][0]['#title'],
            )
          )
        );
      }
    }
  }
}
