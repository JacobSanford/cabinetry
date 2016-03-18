<?php
/**
 * @file
 * cabinetry_cabinet_project.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cabinetry_cabinet_project_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_bill_of_goods-field_cabinetry_bill_item_count'.
  $field_instances['field_collection_item-field_cabinetry_bill_of_goods-field_cabinetry_bill_item_count'] = array(
    'bundle' => 'field_cabinetry_bill_of_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_bill_item_count',
    'label' => 'Cabinetry Bill Item Count',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_bill_of_goods-field_cabinetry_bill_item_name'.
  $field_instances['field_collection_item-field_cabinetry_bill_of_goods-field_cabinetry_bill_item_name'] = array(
    'bundle' => 'field_cabinetry_bill_of_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_bill_item_name',
    'label' => 'Cabinetry Bill Item Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_bill_of_goods-field_cabinetry_bill_item_total'.
  $field_instances['field_collection_item-field_cabinetry_bill_of_goods-field_cabinetry_bill_item_total'] = array(
    'bundle' => 'field_cabinetry_bill_of_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_bill_item_total',
    'label' => 'Cabinetry Bill Item Total',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_bill_of_goods-field_cabinetry_bill_unit_price'.
  $field_instances['field_collection_item-field_cabinetry_bill_of_goods-field_cabinetry_bill_unit_price'] = array(
    'bundle' => 'field_cabinetry_bill_of_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_bill_unit_price',
    'label' => 'Cabinetry Bill Unit Price',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_carcass_division-field_cabinetry_division_ratio'.
  $field_instances['field_collection_item-field_cabinetry_carcass_division-field_cabinetry_division_ratio'] = array(
    'bundle' => 'field_cabinetry_carcass_division',
    'default_value' => array(
      0 => array(
        'value' => '1.0',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_division_ratio',
    'label' => 'Cabinetry Division Ratio',
    'required' => 0,
    'settings' => array(
      'max' => '1.0',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_bandin-field_cabinetry_banding_amount'.
  $field_instances['field_collection_item-field_cabinetry_materials_bandin-field_cabinetry_banding_amount'] = array(
    'bundle' => 'field_cabinetry_materials_bandin',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_banding_amount',
    'label' => 'Banding Amount',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_bandin-field_cabinetry_banding_material'.
  $field_instances['field_collection_item-field_cabinetry_materials_bandin-field_cabinetry_banding_material'] = array(
    'bundle' => 'field_cabinetry_materials_bandin',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_banding_material',
    'label' => 'Banding Material',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_hardwa-field_cabinetry_hardware_name'.
  $field_instances['field_collection_item-field_cabinetry_materials_hardwa-field_cabinetry_hardware_name'] = array(
    'bundle' => 'field_cabinetry_materials_hardwa',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Item Name',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_hardware_name',
    'label' => 'Item Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_hardwa-field_cabinetry_item_cost'.
  $field_instances['field_collection_item-field_cabinetry_materials_hardwa-field_cabinetry_item_cost'] = array(
    'bundle' => 'field_cabinetry_materials_hardwa',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_item_cost',
    'label' => 'Cost Each',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_hardwa-field_cabinetry_number_of_shelve'.
  $field_instances['field_collection_item-field_cabinetry_materials_hardwa-field_cabinetry_number_of_shelve'] = array(
    'bundle' => 'field_cabinetry_materials_hardwa',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_number_of_shelve',
    'label' => 'Number',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_sheet-field_cabinetry_item_cost'.
  $field_instances['field_collection_item-field_cabinetry_materials_sheet-field_cabinetry_item_cost'] = array(
    'bundle' => 'field_cabinetry_materials_sheet',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_item_cost',
    'label' => 'Cost Per Sheet',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_sheet-field_cabinetry_sheet_name'.
  $field_instances['field_collection_item-field_cabinetry_materials_sheet-field_cabinetry_sheet_name'] = array(
    'bundle' => 'field_cabinetry_materials_sheet',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_sheet_name',
    'label' => 'Sheet Type',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_sheet-field_image'.
  $field_instances['field_collection_item-field_cabinetry_materials_sheet-field_image'] = array(
    'bundle' => 'field_cabinetry_materials_sheet',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_image',
    'label' => 'Sheet Layouts',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'large',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_solid-field_cabinetry_board_feet'.
  $field_instances['field_collection_item-field_cabinetry_materials_solid-field_cabinetry_board_feet'] = array(
    'bundle' => 'field_cabinetry_materials_solid',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_board_feet',
    'label' => 'Cabinetry Board Feet',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_solid-field_cabinetry_item_cost'.
  $field_instances['field_collection_item-field_cabinetry_materials_solid-field_cabinetry_item_cost'] = array(
    'bundle' => 'field_cabinetry_materials_solid',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_item_cost',
    'label' => 'Cost Per BoardFoot',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_solid-field_cabinetry_solid_name'.
  $field_instances['field_collection_item-field_cabinetry_materials_solid-field_cabinetry_solid_name'] = array(
    'bundle' => 'field_cabinetry_materials_solid',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_solid_name',
    'label' => 'Solid Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_solid-field_cabinetry_solid_part_list'.
  $field_instances['field_collection_item-field_cabinetry_materials_solid-field_cabinetry_solid_part_list'] = array(
    'bundle' => 'field_cabinetry_materials_solid',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Part List',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_solid_part_list',
    'label' => 'Part List',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_materials_solid-field_image'.
  $field_instances['field_collection_item-field_cabinetry_materials_solid-field_image'] = array(
    'bundle' => 'field_cabinetry_materials_solid',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_image',
    'label' => 'Cut Plan',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_measurement_valu-field_cabinetry_measurement_axis'.
  $field_instances['field_collection_item-field_cabinetry_measurement_valu-field_cabinetry_measurement_axis'] = array(
    'bundle' => 'field_cabinetry_measurement_valu',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the direction of the measurement, i.e. \'Width\'.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_measurement_axis',
    'label' => 'Direction',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_measurement_valu-field_cabinetry_measurement_len'.
  $field_instances['field_collection_item-field_cabinetry_measurement_valu-field_cabinetry_measurement_len'] = array(
    'bundle' => 'field_cabinetry_measurement_valu',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the length, in mm.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_measurement_len',
    'label' => 'Length',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_carcass_back_mat'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_carcass_back_mat'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'tid' => 14,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select the material used for the back panel',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_carcass_back_mat',
    'label' => 'Carcass Back Material',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_carcass_division'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_carcass_division'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the number of divisions and ratio for the carcass box. Doors will also be divided to match.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_carcass_division',
    'label' => 'Carcass Divisions',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_carcass_sheet_mt'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_carcass_sheet_mt'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'tid' => 5,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select the material used for the box carcass.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_carcass_sheet_mt',
    'label' => 'Carcass Sheet Material',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_component_type'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_component_type'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'tid' => 2,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select the type of component.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_component_type',
    'label' => 'Component Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_depth'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_depth'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'value' => 576,
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the depth of the carcass (without doors), in mm.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_depth',
    'label' => 'Carcass Outer Depth',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_frame_mater'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_frame_mater'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'tid' => 7,
      ),
    ),
    'deleted' => 0,
    'description' => 'Door Frame Material',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_door_frame_mater',
    'label' => 'Door Frame Material',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_hinge'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_hinge'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'tid' => 6,
      ),
    ),
    'deleted' => 0,
    'description' => 'Door Hinges',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_door_hinge',
    'label' => 'Door Hinges',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_hinge_plate'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_hinge_plate'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'tid' => 12,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_door_hinge_plate',
    'label' => 'Door Hinge Plates',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_panel_mater'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_panel_mater'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'tid' => 9,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select the material used for the door panel.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_door_panel_mater',
    'label' => 'Door Panel Material',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_panel_under'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_panel_under'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'value' => '2.0',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the amount (on each side) to undersize the door panels to allow for fitting and expansion, in mm.
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_door_panel_under',
    'label' => 'Door Panel Underdersize',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_reveal'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_door_reveal'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'value' => 1.5,
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the door reveal for the box, in mm.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_door_reveal',
    'label' => 'Door Reveal',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_doors_span_gap'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_doors_span_gap'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'value' => 2,
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the number of doors that should span the carcass horizontally.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_doors_span_gap',
    'label' => 'Doors Across Gap',
    'required' => 0,
    'settings' => array(
      'max' => 2,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_height'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_height'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'value' => '768.0',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the outer height of the carcass, in mm.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_height',
    'label' => 'Carcass Outer Height',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_name'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_name'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>Enter an identifying name for this component.</p>
<p><b>If you want multiple copies of this exact cabinet, add additional name fields here.</p>
<p>The number of elements in this field controls the number of copies generated.</b></p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_name',
    'label' => 'Component Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_number_of_shelve'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_number_of_shelve'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select the number of shelves to create for this carcass.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_number_of_shelve',
    'label' => 'Number of Shelves',
    'required' => 0,
    'settings' => array(
      'max' => 8,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_componen-field_cabinetry_width'.
  $field_instances['field_collection_item-field_cabinetry_project_componen-field_cabinetry_width'] = array(
    'bundle' => 'field_cabinetry_project_componen',
    'default_value' => array(
      0 => array(
        'value' => '480.0',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the outer width of the carcass, in mm.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_width',
    'label' => 'Carcass Outer Width',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_measurem-field_cabinetry_measurement_item'.
  $field_instances['field_collection_item-field_cabinetry_project_measurem-field_cabinetry_measurement_item'] = array(
    'bundle' => 'field_cabinetry_project_measurem',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_measurement_item',
    'label' => 'Item',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_project_measurem-field_cabinetry_measurement_valu'.
  $field_instances['field_collection_item-field_cabinetry_project_measurem-field_cabinetry_measurement_valu'] = array(
    'bundle' => 'field_cabinetry_project_measurem',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_measurement_valu',
    'label' => 'Measurement Values',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_solid_part_list-field_cabinetry_part_names'.
  $field_instances['field_collection_item-field_cabinetry_solid_part_list-field_cabinetry_part_names'] = array(
    'bundle' => 'field_cabinetry_solid_part_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_part_names',
    'label' => 'Cabinetry Part Names',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_solid_part_list-field_cabinetry_solid_length'.
  $field_instances['field_collection_item-field_cabinetry_solid_part_list-field_cabinetry_solid_length'] = array(
    'bundle' => 'field_cabinetry_solid_part_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_solid_length',
    'label' => 'Cabinetry Solid Length',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_solid_part_list-field_cabinetry_solid_thickness'.
  $field_instances['field_collection_item-field_cabinetry_solid_part_list-field_cabinetry_solid_thickness'] = array(
    'bundle' => 'field_cabinetry_solid_part_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_solid_thickness',
    'label' => 'Cabinetry Solid Thickness',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_solid_part_list-field_cabinetry_solid_width'.
  $field_instances['field_collection_item-field_cabinetry_solid_part_list-field_cabinetry_solid_width'] = array(
    'bundle' => 'field_cabinetry_solid_part_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_solid_width',
    'label' => 'Cabinetry Solid Width',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_bill_of_goods'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_bill_of_goods'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_bill_of_goods',
    'label' => 'Bill of Goods',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_blade_cut_width'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_blade_cut_width'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => array(
      0 => array(
        'value' => '4.0',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the cut width of the saw blade, in mm.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_blade_cut_width',
    'label' => 'Saw Blade Cut Width',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_description'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_description'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a description of the project, including notes and errata.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_enforce_32mm'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_enforce_32mm'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Enforce 32mm system restrictions on carcass dimensions when auditing this project.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_enforce_32mm',
    'label' => 'Enforce 32mm System',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_frame_router_bit'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_frame_router_bit'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => array(
      0 => array(
        'tid' => 11,
      ),
    ),
    'deleted' => 0,
    'description' => 'Select the router bit that will be used to mill the rail/style grooves in the door frames.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_frame_router_bit',
    'label' => 'Rail/Stile Router Bit',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_materials_bandin'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_materials_bandin'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_materials_bandin',
    'label' => 'Banding Materials',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_materials_hardwa'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_materials_hardwa'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_materials_hardwa',
    'label' => 'Materials Hardware',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_materials_sheet'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_materials_sheet'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_materials_sheet',
    'label' => 'Materials Sheet Goods',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_materials_solid'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_materials_solid'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_materials_solid',
    'label' => 'Materials Solid',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_project_componen'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_project_componen'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_project_componen',
    'label' => 'Components',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_project_measurem'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_project_measurem'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_project_measurem',
    'label' => 'Measurements',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_sheet_packing_al'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_sheet_packing_al'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Sheet Packing Algorithim',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_sheet_packing_al',
    'label' => 'Sheet Packing Algorithim',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_cabinet_project-field_cabinetry_solid_stock_leng'.
  $field_instances['node-cabinetry_cabinet_project-field_cabinetry_solid_stock_leng'] = array(
    'bundle' => 'cabinetry_cabinet_project',
    'default_value' => array(
      0 => array(
        'value' => 2438.4,
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter the length of the hardwood lumber stock to use in computing how much to purchase.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_solid_stock_leng',
    'label' => 'Solid Stock Length',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_hinge_plates-field_cabinetry_item_cost'.
  $field_instances['taxonomy_term-cabinetry_hinge_plates-field_cabinetry_item_cost'] = array(
    'bundle' => 'cabinetry_hinge_plates',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_item_cost',
    'label' => 'Item Cost',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '$',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_hinges-field_cabinetry_item_cost'.
  $field_instances['taxonomy_term-cabinetry_hinges-field_cabinetry_item_cost'] = array(
    'bundle' => 'cabinetry_hinges',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the cost of the item, in dollars.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_item_cost',
    'label' => 'Item Cost',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '$',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_project_component_types-field_cabinetry_php_library_clas'.
  $field_instances['taxonomy_term-cabinetry_project_component_types-field_cabinetry_php_library_clas'] = array(
    'bundle' => 'cabinetry_project_component_types',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the class the PHP Library should use to build this component.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_php_library_clas',
    'label' => 'Cabinetry PHP Library Class',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_rail_stile_router_bits-field_cabinetry_rail_cut_depth'.
  $field_instances['taxonomy_term-cabinetry_rail_stile_router_bits-field_cabinetry_rail_cut_depth'] = array(
    'bundle' => 'cabinetry_rail_stile_router_bits',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the rail cut depth, in mm.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_rail_cut_depth',
    'label' => 'Rail Cut Depth',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_rail_stile_router_bits-field_cabinetry_rail_cut_thickne'.
  $field_instances['taxonomy_term-cabinetry_rail_stile_router_bits-field_cabinetry_rail_cut_thickne'] = array(
    'bundle' => 'cabinetry_rail_stile_router_bits',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the rail slot thickness, in mm.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_rail_cut_thickne',
    'label' => 'Rail Slot Thickness',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_sheet_goods-field_cabinetry_height'.
  $field_instances['taxonomy_term-cabinetry_sheet_goods-field_cabinetry_height'] = array(
    'bundle' => 'cabinetry_sheet_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the height of the sheet, in mm. Height is typically considered the dimension of the sheet that is perpendicular to the to the veneer grain, or the longest side if non-wood.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_height',
    'label' => 'Sheet Height',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_sheet_goods-field_cabinetry_item_cost'.
  $field_instances['taxonomy_term-cabinetry_sheet_goods-field_cabinetry_item_cost'] = array(
    'bundle' => 'cabinetry_sheet_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the approximate cost of a single item. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_item_cost',
    'label' => 'Item Cost',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.00',
      'prefix' => '',
      'suffix' => '$',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_sheet_goods-field_cabinetry_preserve_grain'.
  $field_instances['taxonomy_term-cabinetry_sheet_goods-field_cabinetry_preserve_grain'] = array(
    'bundle' => 'cabinetry_sheet_goods',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Does this sheet good have grain that should be preserved?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_preserve_grain',
    'label' => 'Preserve Grain',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_sheet_goods-field_cabinetry_sheet_core'.
  $field_instances['taxonomy_term-cabinetry_sheet_goods-field_cabinetry_sheet_core'] = array(
    'bundle' => 'cabinetry_sheet_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the core material of the sheet.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_sheet_core',
    'label' => 'Core Material',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_sheet_goods-field_cabinetry_sheet_veneer_one'.
  $field_instances['taxonomy_term-cabinetry_sheet_goods-field_cabinetry_sheet_veneer_one'] = array(
    'bundle' => 'cabinetry_sheet_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the veneer on the first side of the sheet. If the sides differ, side one is typically chosen to be the side of the sheet with the superior, or outward facing veneer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_sheet_veneer_one',
    'label' => 'Sheet Veneer Side 1',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_sheet_goods-field_cabinetry_sheet_veneer_two'.
  $field_instances['taxonomy_term-cabinetry_sheet_goods-field_cabinetry_sheet_veneer_two'] = array(
    'bundle' => 'cabinetry_sheet_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the veneer on the second side of the sheet. If the sides differ, side two is typically chosen to be the side of the sheet with the inferior, or hidden facing veneer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_sheet_veneer_two',
    'label' => 'Sheet Veneer Side 2',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_sheet_goods-field_cabinetry_thickness'.
  $field_instances['taxonomy_term-cabinetry_sheet_goods-field_cabinetry_thickness'] = array(
    'bundle' => 'cabinetry_sheet_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the thickness of the sheet, in mm.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_thickness',
    'label' => 'Sheet Thickness',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_sheet_goods-field_cabinetry_width'.
  $field_instances['taxonomy_term-cabinetry_sheet_goods-field_cabinetry_width'] = array(
    'bundle' => 'cabinetry_sheet_goods',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the width of the sheet, in mm. Width is typically considered the dimension of the sheet that is parallel to the veneer grain, or the longest side if non-wood.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_width',
    'label' => 'Sheet Width',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_solid_wood-field_cabinetry_height'.
  $field_instances['taxonomy_term-cabinetry_solid_wood-field_cabinetry_height'] = array(
    'bundle' => 'cabinetry_solid_wood',
    'default_value' => array(
      0 => array(
        'value' => 57.15,
      ),
    ),
    'deleted' => 0,
    'description' => 'Stock Width',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_height',
    'label' => 'Stock Width',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_solid_wood-field_cabinetry_item_cost'.
  $field_instances['taxonomy_term-cabinetry_solid_wood-field_cabinetry_item_cost'] = array(
    'bundle' => 'cabinetry_solid_wood',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Cost Per Board Foot',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_item_cost',
    'label' => 'Cost Per Board Foot',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.00',
      'prefix' => '',
      'suffix' => '$',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_solid_wood-field_cabinetry_thickness'.
  $field_instances['taxonomy_term-cabinetry_solid_wood-field_cabinetry_thickness'] = array(
    'bundle' => 'cabinetry_solid_wood',
    'default_value' => array(
      0 => array(
        'value' => 20.6,
      ),
    ),
    'deleted' => 0,
    'description' => 'Stock Thickness',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_thickness',
    'label' => 'Stock Thickness',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '0.0',
      'prefix' => '',
      'suffix' => 'mm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_veneers-field_cabinetry_color'.
  $field_instances['taxonomy_term-cabinetry_veneers-field_cabinetry_color'] = array(
    'bundle' => 'cabinetry_veneers',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the color of the veneer. If wood, \'natural\' is a usual choice.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_color',
    'label' => 'Color',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-cabinetry_veneers-field_cabinetry_item_cost'.
  $field_instances['taxonomy_term-cabinetry_veneers-field_cabinetry_item_cost'] = array(
    'bundle' => 'cabinetry_veneers',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the cost of the item, per meter, in dollars.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_item_cost',
    'label' => 'Cost Per Meter',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '$',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>Enter an identifying name for this component.</p>
<p><b>If you want multiple copies of this exact cabinet, add additional name fields here.</p>
<p>The number of elements in this field controls the number of copies generated.</b></p>');
  t('Banding Amount');
  t('Banding Material');
  t('Banding Materials');
  t('Bill of Goods');
  t('Cabinetry Bill Item Count');
  t('Cabinetry Bill Item Name');
  t('Cabinetry Bill Item Total');
  t('Cabinetry Bill Unit Price');
  t('Cabinetry Board Feet');
  t('Cabinetry Division Ratio');
  t('Cabinetry PHP Library Class');
  t('Cabinetry Part Names');
  t('Cabinetry Solid Length');
  t('Cabinetry Solid Thickness');
  t('Cabinetry Solid Width');
  t('Carcass Back Material');
  t('Carcass Divisions');
  t('Carcass Outer Depth');
  t('Carcass Outer Height');
  t('Carcass Outer Width');
  t('Carcass Sheet Material');
  t('Color');
  t('Component Name');
  t('Component Type');
  t('Components');
  t('Core Material');
  t('Cost Each');
  t('Cost Per Board Foot');
  t('Cost Per BoardFoot');
  t('Cost Per Meter');
  t('Cost Per Sheet');
  t('Cut Plan');
  t('Description');
  t('Direction');
  t('Does this sheet good have grain that should be preserved?');
  t('Door Frame Material');
  t('Door Hinge Plates');
  t('Door Hinges');
  t('Door Panel Material');
  t('Door Panel Underdersize');
  t('Door Reveal');
  t('Doors Across Gap');
  t('Enforce 32mm System');
  t('Enforce 32mm system restrictions on carcass dimensions when auditing this project.');
  t('Enter a description of the project, including notes and errata.');
  t('Enter the amount (on each side) to undersize the door panels to allow for fitting and expansion, in mm.
');
  t('Enter the approximate cost of a single item. ');
  t('Enter the class the PHP Library should use to build this component.');
  t('Enter the color of the veneer. If wood, \'natural\' is a usual choice.');
  t('Enter the cost of the item, in dollars.');
  t('Enter the cost of the item, per meter, in dollars.');
  t('Enter the cut width of the saw blade, in mm.');
  t('Enter the depth of the carcass (without doors), in mm.');
  t('Enter the direction of the measurement, i.e. \'Width\'.');
  t('Enter the door reveal for the box, in mm.');
  t('Enter the height of the sheet, in mm. Height is typically considered the dimension of the sheet that is perpendicular to the to the veneer grain, or the longest side if non-wood.');
  t('Enter the length of the hardwood lumber stock to use in computing how much to purchase.');
  t('Enter the length, in mm.');
  t('Enter the number of divisions and ratio for the carcass box. Doors will also be divided to match.');
  t('Enter the number of doors that should span the carcass horizontally.');
  t('Enter the outer height of the carcass, in mm.');
  t('Enter the outer width of the carcass, in mm.');
  t('Enter the rail cut depth, in mm.');
  t('Enter the rail slot thickness, in mm.');
  t('Enter the thickness of the sheet, in mm.');
  t('Enter the width of the sheet, in mm. Width is typically considered the dimension of the sheet that is parallel to the veneer grain, or the longest side if non-wood.');
  t('Item');
  t('Item Cost');
  t('Item Name');
  t('Length');
  t('Materials Hardware');
  t('Materials Sheet Goods');
  t('Materials Solid');
  t('Measurement Values');
  t('Measurements');
  t('Number');
  t('Number of Shelves');
  t('Part List');
  t('Preserve Grain');
  t('Rail Cut Depth');
  t('Rail Slot Thickness');
  t('Rail/Stile Router Bit');
  t('Saw Blade Cut Width');
  t('Select the core material of the sheet.');
  t('Select the material used for the back panel');
  t('Select the material used for the box carcass.');
  t('Select the material used for the door panel.');
  t('Select the number of shelves to create for this carcass.');
  t('Select the router bit that will be used to mill the rail/style grooves in the door frames.');
  t('Select the type of component.');
  t('Select the veneer on the first side of the sheet. If the sides differ, side one is typically chosen to be the side of the sheet with the superior, or outward facing veneer.');
  t('Select the veneer on the second side of the sheet. If the sides differ, side two is typically chosen to be the side of the sheet with the inferior, or hidden facing veneer.');
  t('Sheet Height');
  t('Sheet Layouts');
  t('Sheet Packing Algorithim');
  t('Sheet Thickness');
  t('Sheet Type');
  t('Sheet Veneer Side 1');
  t('Sheet Veneer Side 2');
  t('Sheet Width');
  t('Solid Name');
  t('Solid Stock Length');
  t('Stock Thickness');
  t('Stock Width');

  return $field_instances;
}
