<?php
/**
 * @file
 * Provides validation handlers for the cabinetry_wainscoting_project node_form.
 */

/**
 * Form submit handler for cabinetry_wainscoting_project node form.
 *
 * @see cabinetry_wainscoting_project_validate_cabinet_dimensions()
 * @see cabinetry_wainscoting_project_validate_thirty_two_system()
 */
function cabinetry_wainscoting_project_generate_materials(&$form, &$form_state) {
  _cabinetry_core_bootstrap();
  _cabinetry_wainscoting_project_bootstrap();

  $project = new CabinetryWainscotingProject();
  $project->frameRouterBit = _cabinetry_cabinet_project_load_router_bit_object($form_state['values']['field_cabinetry_frame_router_bit'][LANGUAGE_NONE][0]['tid']);
  $project->solidStockLength = $form_state['values']['field_cabinetry_solid_stock_leng'][LANGUAGE_NONE][0]['value'];
  $project->bladeCutWidth = $form_state['values']['field_cabinetry_blade_cut_width'][LANGUAGE_NONE][0]['value'];

  foreach ($form_state['values']['field_cabinetry_wainscoting_sect'][LANGUAGE_NONE] as $section_index => $section_component) {
    if (is_numeric($section_index)) {
      $component_class = _cabinetry_core_get_component_type_class($form_state['values']['field_cabinetry_wainscoting_styl'][LANGUAGE_NONE][0]['tid']);
      $component = new $component_class(
        $section_component['field_cabinetry_width'][LANGUAGE_NONE][0]['value'],
        $form_state['values']['field_cabinetry_height'][LANGUAGE_NONE][0]['value'],
        $form_state['values']['field_cabinetry_height'][LANGUAGE_NONE][0]['value'],
        $section_component['field_number_of_sections'][LANGUAGE_NONE][0]['value']
      );
      $component->frameRouterBit = $project->frameRouterBit;
      $component->panelSheetGood = _cabinetry_core_load_sheet_good_object($form_state['values']['field_cabinetry_carcass_sheet_mt'][LANGUAGE_NONE][0]['tid']);
      $component->railSolidMaterialTid = $form_state['values']['field_cabinetry_door_frame_mater'][LANGUAGE_NONE][0]['tid'];
      $component->maxRailLength = $form_state['values']['field_cabinetry_solid_stock_leng'][LANGUAGE_NONE][0]['value'];
      $component->build($section_component);
      $project->addComponent($component);
    }
  }

  // $project->collateParts();
  // $project->packSolids($form_state['values']['field_cabinetry_sheet_packing_al'][LANGUAGE_NONE][0]['value']);
  // $project->packSheets($form_state['values']['field_cabinetry_sheet_packing_al'][LANGUAGE_NONE][0]['value']);
  // $project->plotSheets();

  ctools_include('object-cache');
  ctools_object_cache_set('cabinetry_wainscoting_project', 'presave_object', $project);
}
