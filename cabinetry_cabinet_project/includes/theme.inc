
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
      array(
        'data' => $component_index,
        'style' => 'text-align: center;',
      ),
      implode(', ', $piece_names),
      array(
        'data' => _cabinetry_cabinet_project_render_measurement($component_entity_metadata_wrapper->field_cabinetry_width->value()),
        'style' => 'text-align: right;',
      ),
      array(
        'data' => _cabinetry_cabinet_project_render_measurement($component_entity_metadata_wrapper->field_cabinetry_height->value()),
        'style' => 'text-align: right;',
      ),
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
          array(
            'data' => $solid_index,
            'style' => 'text-align: center;',
          ),
          $solid_entity_metadata_wrapper->field_cabinetry_solid_name->value(),
          array(
            'data' => _cabinetry_cabinet_project_render_measurement($solid_parts_entity_metadata_wrapper->field_cabinetry_solid_thickness->value()),
            'style' => 'text-align: right;',
          ),
          array(
            'data' => _cabinetry_cabinet_project_render_measurement($solid_parts_entity_metadata_wrapper->field_cabinetry_solid_width->value()),
            'style' => 'text-align: right;',
          ),
          array(
            'data' => _cabinetry_cabinet_project_render_measurement($solid_parts_entity_metadata_wrapper->field_cabinetry_solid_length->value()),
            'style' => 'text-align: right;',
          ),
          array(
            'data' => count($solid_parts_entity_metadata_wrapper->field_cabinetry_part_names),
            'style' => 'text-align: center;',
          ),
        );
      }
      else {
        $rows[] = array(
          NULL,
          NULL,
          NULL,
          NULL,
          array(
            'data' => _cabinetry_cabinet_project_render_measurement($solid_parts_entity_metadata_wrapper->field_cabinetry_solid_length->value()),
            'style' => 'text-align: right;',
          ),
          array(
            'data' => count($solid_parts_entity_metadata_wrapper->field_cabinetry_part_names),
            'style' => 'text-align: center;',
          ),
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
 * Generate the cabinetry solid cut table.
 *
 * @param object $node_entity_wrapper
 *   The node entity wrapper to query.
 *
 * @return string
 *   HTML of the table.
 */
function _cabinetry_cabinet_project_get_solid_cut_list_table($node_entity_wrapper, $node) {
  $header = array(
    t('ID'),
    t('Name'),
    t('Num Lengths'),
    t('Cut Images'),
  );
  $rows = array();

  foreach ($node_entity_wrapper->field_cabinetry_materials_solid->value() as $solid_index => $solid) {
    $solid_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $solid);
    foreach ($solid_entity_metadata_wrapper->field_image->value() as $image_index => $image) {

      $image_html = l(
        theme(
          'image_style',
          array(
            'path' => $image['uri'],
            'style_name' => 'large',
          )
        ),
        file_create_url($image['uri']),
        array(
          'html' => TRUE,
        )
      );

      if ($image_index == 0) {
        $rows[] = array(
          array(
            'data' => $solid_index,
            'style' => 'text-align: center;',
          ),
          $solid_entity_metadata_wrapper->field_cabinetry_solid_name->value(),
          array(
            'data' => count($solid_entity_metadata_wrapper->field_image),
            'style' => 'text-align: center;',
          ),
          $image_html,
        );
      }
      else {
        $rows[] = array(
          NULL,
          NULL,
          NULL,
          $image_html,
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
        theme(
          'image_style', array(
            'path' => $sheet_image['uri'],
            'style_name' => 'large',
          )
        ),
        file_create_url($sheet_image['uri']),
        array(
          'html' => TRUE,
        )
      );

      if ($sheet_image_index == 0) {
        $rows[] = array(
          array(
            'data' => $sheet_type_index,
            'style' => 'text-align: center;',
          ),
          $sheet_entity_metadata_wrapper->field_cabinetry_sheet_name->value(),
          array(
            'data' => $image_html,
            'style' => 'text-align: center;',
          ),
        );
      }
      else {
        $rows[] = array(
          NULL,
          NULL,
          array(
            'data' => $image_html,
            'style' => 'text-align: center;',
          ),
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
 * Generate the cabinetry banding table.
 *
 * @param object $node_entity_wrapper
 *   The node entity wrapper to query.
 *
 * @return string
 *   HTML of the table.
 */
function _cabinetry_cabinet_project_get_banding_table($node_entity_wrapper, $node) {
  $header = array(
    t('ID'),
    t('Type'),
    t('Length'),
  );
  $rows = array();

  foreach ($node_entity_wrapper->field_cabinetry_materials_bandin->value() as $banding_index => $banding_item) {
    $banding_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $banding_item);
    $rows[] = array(
      array(
        'data' => $banding_index,
        'style' => 'text-align: center;',
      ),
      $banding_entity_metadata_wrapper->field_cabinetry_banding_material->value(),
      array(
        'data' => _cabinetry_cabinet_project_render_measurement($banding_entity_metadata_wrapper->field_cabinetry_banding_amount->value()),
        'style' => 'text-align: right;',
      ),
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
 * Generate the cabinetry bill of goods table.
 *
 * @param object $node_entity_wrapper
 *   The node entity wrapper to query.
 *
 * @return string
 *   HTML of the table.
 */
function _cabinetry_cabinet_project_get_bill_goods_table($node_entity_wrapper, $node) {
  $header = array(
    t('Item'),
    t('Price'),
    t('Count'),
    t('Total'),
  );
  $rows = array();
  $total_price = 0.00;

  list($solid_rows, $total_solid_price) = _cabinetry_cabinet_project_get_solid_bill_rows($node_entity_wrapper, $node);
  $total_price += (float) $total_solid_price;
  $rows = array_merge($rows, $solid_rows);

  list($sheet_rows, $total_sheet_price) = _cabinetry_cabinet_project_get_sheet_bill_rows($node_entity_wrapper, $node);
  $total_price += (float) $total_sheet_price;
  $rows = array_merge($rows, $sheet_rows);

  list($hardware_rows, $total_hardware_price) = _cabinetry_cabinet_project_get_hardware_bill_rows($node_entity_wrapper, $node);
  $total_price += (float) $total_hardware_price;
  $rows = array_merge($rows, $hardware_rows);

  /*
  foreach ($node_entity_wrapper->field_cabinetry_materials_hardwa->value() as $hardware_index => $hardware_type) {
    $hardware_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $hardware_type);
    $rows[] = array(
      $hardware_index,
      $hardware_entity_metadata_wrapper->field_cabinetry_hardware_name->value(),
      $hardware_entity_metadata_wrapper->field_cabinetry_number_of_shelve->value(),
    );
  }
*/

  $rows[] = array(
    NULL,
    NULL,
    array(
      'data' => t('Total'),
      'style' => 'text-align: right; font-weight: 600;',
    ),
    array(
      'data' => _cabinetry_cabinet_project_render_price($total_price),
      'style' => 'text-align: right; font-weight: 600;',
    ),
  );

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

function _cabinetry_cabinet_project_get_solid_bill_rows($node_entity_wrapper, $node) {
  $rows = array();
  $total_solid_cost = 0.00;

  foreach ($node_entity_wrapper->field_cabinetry_materials_solid->value() as $solid_index => $solid) {
    $solid_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $solid);
    $solid_stock_length = $node_entity_wrapper->field_cabinetry_solid_stock_leng->value();
    foreach ($solid_entity_metadata_wrapper->field_cabinetry_solid_part_list->value() as $part_index => $part_list) {
      $solid_parts_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $part_list);
      $lengths_count = count($solid_entity_metadata_wrapper->field_image->value());
      $total_cost = $lengths_count *
        $solid_stock_length *
        (float) $solid_parts_entity_metadata_wrapper->field_cabinetry_solid_width->value() *
        (float) $solid_parts_entity_metadata_wrapper->field_cabinetry_solid_thickness->value() *
        (float) CABINETRY_CORE_MM3_TO_BOARDFEET *
        (float) $solid_entity_metadata_wrapper->field_cabinetry_item_cost->value();
      $rows[] = array(
        $solid_entity_metadata_wrapper->field_cabinetry_solid_name->value(),
        array(
          'data' => _cabinetry_cabinet_project_render_price($solid_entity_metadata_wrapper->field_cabinetry_item_cost->value()) . "/bdft",
          'style' => 'text-align: center;',
        ),
        array(
          'data' => "$lengths_count x {$solid_stock_length}mm lengths",
          'style' => 'text-align: center;',
        ),
        array(
          'data' => _cabinetry_cabinet_project_render_price($total_cost),
          'style' => 'text-align: right;',
        ),
      );
      $total_solid_cost += $total_cost;
      break;
    }
  }

  return array($rows, $total_solid_cost);
}

function _cabinetry_cabinet_project_get_sheet_bill_rows($node_entity_wrapper, $node) {
  $rows = array();
  $total_sheet_price = 0.00;

  foreach ($node_entity_wrapper->field_cabinetry_materials_sheet->value() as $sheet_type_index => $sheet_type) {
    $sheet_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $sheet_type);
    $num_sheets = count($sheet_entity_metadata_wrapper->field_image->value());
    $sheet_price = $sheet_entity_metadata_wrapper->field_cabinetry_item_cost->value();
    $total_price = (float) $sheet_price * (float) $num_sheets;
    $total_sheet_price += $total_price;
    $sheet_name = $sheet_entity_metadata_wrapper->field_cabinetry_sheet_name->value();

    $rows[] = array(
      $sheet_name,
      array(
        'data' => _cabinetry_cabinet_project_render_price($sheet_price),
        'style' => 'text-align: center;',
      ),
      array(
        'data' => "$num_sheets sheets",
        'style' => 'text-align: center;',
      ),
      array(
        'data' => _cabinetry_cabinet_project_render_price($total_price),
        'style' => 'text-align: right;',
      ),
    );
  }

  return array($rows, $total_sheet_price);
}

function _cabinetry_cabinet_project_get_hardware_bill_rows($node_entity_wrapper, $node) {
  $rows = array();
  $total_hardware_cost = 0.00;

  foreach ($node_entity_wrapper->field_cabinetry_materials_hardwa->value() as $hardware_index => $hardware_type) {
    $hardware_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $hardware_type);
    $name = $hardware_entity_metadata_wrapper->field_cabinetry_hardware_name->value();
    $price = (float) $hardware_entity_metadata_wrapper->field_cabinetry_item_cost->value();
    $number = (float) $hardware_entity_metadata_wrapper->field_cabinetry_number_of_shelve->value();
    $total = $price * $number;
    $total_hardware_cost += $total_hardware_cost;
    $rows[] = array(
      array(
        'data' => $name,
        'style' => 'text-align: left;',
      ),
      array(
        'data' => _cabinetry_cabinet_project_render_price($price),
        'style' => 'text-align: center;',
      ),
      array(
        'data' => $number,
        'style' => 'text-align: center;',
      ),
      array(
        'data' => _cabinetry_cabinet_project_render_price($total),
        'style' => 'text-align: right;',
      ),
    );
  }

  return array($rows, $total_hardware_cost);
}

/**
 * Generate the cabinetry hardware table.
 *
 * @param object $node_entity_wrapper
 *   The node entity wrapper to query.
 *
 * @return string
 *   HTML of the table.
 */
function _cabinetry_cabinet_project_get_hardware_table($node_entity_wrapper, $node) {
  $header = array(
    t('ID'),
    t('Item'),
    t('Count'),
  );
  $rows = array();

  foreach ($node_entity_wrapper->field_cabinetry_materials_hardwa->value() as $hardware_index => $hardware_type) {
    $hardware_entity_metadata_wrapper = entity_metadata_wrapper('field_collection_item', $hardware_type);
    $rows[] = array(
      array(
        'data' => $hardware_index,
        'style' => 'text-align: center;',
      ),
      $hardware_entity_metadata_wrapper->field_cabinetry_hardware_name->value(),
      array(
        'data' => $hardware_entity_metadata_wrapper->field_cabinetry_number_of_shelve->value(),
        'style' => 'text-align: center;',
      ),
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
 * Render a measurement in a specific string.
 *
 * @param float $value
 *   The measurement, in millimeters.
 *
 * @return string
 *   The rendered measurement respresentation.
 */
function _cabinetry_cabinet_project_render_measurement($value) {
  return number_format(
    (float) $value,
    1,
    '.',
    ''
  ) . 'mm';
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
function _cabinetry_cabinet_project_render_price($value) {
  return '$' . number_format(
    (float) $value,
    2,
    '.',
    ''
  );
}