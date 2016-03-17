
<?php
/**
 * @file
 * Functions related to theming the cabinet project display template.
 */

/**
 * Construct a metadata entity wrapper for the node being rendered.
 *
 * @param array $variables
 *   The variables array from hook_preprocess_hook().
 *
 * @return object
 *   The node entity wrapper.
 */
function _cabinetry_cabinet_project_get_metadata_wrapper(array $variables) {
  $language_to_render = _cabinetry_cabinet_project_get_language_to_render();
  $node_entity_wrapper = entity_metadata_wrapper('node', $variables['node']);
  $node_entity_wrapper->language($language_to_render);
  return $node_entity_wrapper;
}

/**
 * Determine the language to render.
 *
 * @return string
 *   The value of the language to render.
 */
function _cabinetry_cabinet_project_get_language_to_render() {
  global $language;
  if (isset($language->prefix)) {
    return $language->prefix;
  }
  return 'en';
}

/**
 * Determine a metadata wrapper field value, if it exists.
 *
 * @param object $node_entity_wrapper
 *   The node entity wrapper to query.
 * @param string $field_name
 *   The field name to query.
 *
 * @return string
 *   The value of the field, or NULL.
 */
function _cabinetry_cabinet_project_simple_field_return($node_entity_wrapper, $field_name) {
  if (!empty($node_entity_wrapper->$field_name)) {
    return $node_entity_wrapper->$field_name->value();
  }
  return NULL;
}

/**
 * Generate the cabinetry components table.
 *
 * @param object $node_entity_wrapper
 *   The node entity wrapper to query.
 *
 * @return string
 *   HTML of the table.
 */
function _cabinetry_cabinet_project_get_components_table($node_entity_wrapper) {
  $header = array(
    t('ID'),
    t('Component Name(s)'),
    t('Width'),
    t('Height'),
  );

  $rows = array();
  foreach ($node_entity_wrapper->field_cabinetry_project_componen->value() as $component_index => $component) {
    $component_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $component);

    $piece_names = array();
    foreach ($component_entity_metadata_wrapper->field_cabinetry_name->value() as $piece_name) {
      $piece_names[] = $piece_name;
    }

    $rows[] = array(
      $component_index,
      implode(', ', $piece_names),
      array('data' => _cabinetry_cabinet_project_render_measurement($component_entity_metadata_wrapper->field_cabinetry_width->value()), 'style' => 'text-align: right;'),
      array('data' => _cabinetry_cabinet_project_render_measurement($component_entity_metadata_wrapper->field_cabinetry_height->value()), 'style' => 'text-align: right;'),
    );
  }

  return theme_table(
    array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array(),
      'caption' => '',
      'sticky' => FALSE,
      'empty' => FALSE,
      'colgroups' => array(),
    )
  );
}

/**
 * Generate the cabinetry solids table.
 *
 * @param object $node_entity_wrapper
 *   The node entity wrapper to query.
 *
 * @return string
 *   HTML of the table.
 */
function _cabinetry_cabinet_project_get_solid_table($node_entity_wrapper, $node) {
  $header = array(
    t('ID'),
    t('Name'),
    t('Thickness'),
    t('Width'),
    t('Length'),
    t('#'),
  );
  $rows = array();

  foreach ($node_entity_wrapper->field_cabinetry_materials_solid->value() as $solid_index => $solid) {
    $solid_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $solid);
    foreach ($solid_entity_metadata_wrapper->field_cabinetry_solid_part_list->value() as $part_index => $part_list) {
      $solid_parts_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $part_list);
      if ($part_index == 0) {
        $rows[] = array(
          $solid_index,
          array('data' => $solid_entity_metadata_wrapper->field_cabinetry_solid_name->value(), 'style' => 'font-weight: 600;'),
          array('data' => _cabinetry_cabinet_project_render_measurement($solid_parts_entity_metadata_wrapper->field_cabinetry_solid_thickness->value()), 'style' => 'text-align: right;'),
          array('data' => _cabinetry_cabinet_project_render_measurement($solid_parts_entity_metadata_wrapper->field_cabinetry_solid_width->value()), 'style' => 'text-align: right;'),
          array('data' => _cabinetry_cabinet_project_render_measurement($solid_parts_entity_metadata_wrapper->field_cabinetry_solid_length->value()), 'style' => 'text-align: right;'),
          array('data' => count($solid_parts_entity_metadata_wrapper->field_cabinetry_part_names), 'style' => 'text-align: center;'),
        );
      }
      else {
        $rows[] = array(
          NULL,
          NULL,
          NULL,
          NULL,
          array('data' => _cabinetry_cabinet_project_render_measurement($solid_parts_entity_metadata_wrapper->field_cabinetry_solid_length->value()), 'style' => 'text-align: right;'),
          array('data' => count($solid_parts_entity_metadata_wrapper->field_cabinetry_part_names), 'style' => 'text-align: center;'),
        );
      }
    }

  }

  return theme_table(
    array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array(),
      'caption' => '',
      'sticky' => FALSE,
      'empty' => FALSE,
      'colgroups' => array(),
    )
  );
}

/**
 * Generate the cabinetry solids table.
 *
 * @param object $node_entity_wrapper
 *   The node entity wrapper to query.
 *
 * @return string
 *   HTML of the table.
 */
function _cabinetry_cabinet_project_get_sheet_table($node_entity_wrapper, $node) {
  $header = array(
    t('ID'),
    t('Type'),
    t('Sheet(s)'),
  );
  $rows = array();

  foreach ($node_entity_wrapper->field_cabinetry_materials_sheet->value() as $sheet_type_index => $sheet_type) {
    $sheet_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $sheet_type);
    foreach ($sheet_entity_metadata_wrapper->field_image->value() as $sheet_image_index => $sheet_image) {
      $image_html = l(
        theme('image_style', array('path' => $sheet_image['uri'], 'style_name' => 'large')),
        file_create_url($sheet_image['uri']),
        array(
          'html' => TRUE,
        )
      );

      if ($sheet_image_index == 0) {
        $rows[] = array(
          $sheet_type_index,
          $sheet_entity_metadata_wrapper->field_cabinetry_sheet_name->value(),
          array('data' => $image_html, 'style' => 'text-align: center;'),
        );
      }
      else {
        $rows[] = array(
          NULL,
          NULL,
          array('data' => $image_html, 'style' => 'text-align: center;'),
        );
      }
    }
  }

  return theme_table(
    array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array(),
      'caption' => '',
      'sticky' => FALSE,
      'empty' => FALSE,
      'colgroups' => array(),
    )
  );
}

/**
 * Render a measurement in a specific string.
 *
 * @param float $value
 *   The measurement, in millimeters.
 *
 * @return string
 *   The rendered measurement respresentation.
 */
function _cabinetry_cabinet_project_render_measurement($value) {
  return number_format((float) $value, 1, '.', '') . 'mm';
}
