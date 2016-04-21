<?php
/**
 * @file
 * cabinetry_wainscoting_project.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cabinetry_wainscoting_project_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_extend_left_stil'.
  $field_instances['field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_extend_left_stil'] = array(
    'bundle' => 'field_cabinetry_wainscoting_sect',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Should the left stile be widened to allow for lap joint overlap from another wall?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_extend_left_stil',
    'label' => 'Extend Left Stile Width',
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
  // 'field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_extend_right_sti'.
  $field_instances['field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_extend_right_sti'] = array(
    'bundle' => 'field_cabinetry_wainscoting_sect',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Should the right stile be widened to allow for lap joint overlap from another wall?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_extend_right_sti',
    'label' => 'Extend Right Stile Width',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_left_stud_distan'.
  $field_instances['field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_left_stud_distan'] = array(
    'bundle' => 'field_cabinetry_wainscoting_sect',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Measurement to the center of the first stud from the left side',
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
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_left_stud_distan',
    'label' => 'Cabinetry Left Stud Distance',
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
  // 'field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_right_stud_dista'.
  $field_instances['field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_right_stud_dista'] = array(
    'bundle' => 'field_cabinetry_wainscoting_sect',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Measurement to the center of the first stud from the right side',
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
    'field_name' => 'field_cabinetry_right_stud_dista',
    'label' => 'Cabinetry Right Stud Distance',
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
  // 'field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_skip_baseboard_c'.
  $field_instances['field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_skip_baseboard_c'] = array(
    'bundle' => 'field_cabinetry_wainscoting_sect',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_skip_baseboard_c',
    'label' => 'Skip Baseboard Components',
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
  // 'field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_wainscot_sect_na'.
  $field_instances['field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_wainscot_sect_na'] = array(
    'bundle' => 'field_cabinetry_wainscoting_sect',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_wainscot_sect_na',
    'label' => 'Section Name',
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
  // 'field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_wainscoting_stud'.
  $field_instances['field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_wainscoting_stud'] = array(
    'bundle' => 'field_cabinetry_wainscoting_sect',
    'default_value' => array(
      0 => array(
        'value' => 406.4,
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
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_cabinetry_wainscoting_stud',
    'label' => 'Stud Spacing',
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
  // 'field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_width'.
  $field_instances['field_collection_item-field_cabinetry_wainscoting_sect-field_cabinetry_width'] = array(
    'bundle' => 'field_cabinetry_wainscoting_sect',
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
    'field_name' => 'field_cabinetry_width',
    'label' => 'Section Width',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cabinetry_wainscoting_sect-field_number_of_sections'.
  $field_instances['field_collection_item-field_cabinetry_wainscoting_sect-field_number_of_sections'] = array(
    'bundle' => 'field_cabinetry_wainscoting_sect',
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
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_number_of_sections',
    'label' => 'Number of Panels',
    'required' => 0,
    'settings' => array(
      'max' => 10,
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
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_blade_cut_width'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_blade_cut_width'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => array(
      0 => array(
        'value' => '4.0',
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
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_carcass_sheet_mt'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_carcass_sheet_mt'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => array(
      0 => array(
        'tid' => 1,
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
    'field_name' => 'field_cabinetry_carcass_sheet_mt',
    'label' => 'Panel Sheet Material',
    'required' => 0,
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
  // 'node-cabinetry_wainscoting_project-field_cabinetry_door_frame_mater'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_door_frame_mater'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => array(
      0 => array(
        'tid' => 9,
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
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_door_frame_mater',
    'label' => 'Rail/Stile Material',
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
  // 'node-cabinetry_wainscoting_project-field_cabinetry_extra_trim_mater'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_extra_trim_mater'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => array(
      0 => array(
        'tid' => 24,
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
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_extra_trim_mater',
    'label' => 'Trim Material',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_frame_router_bit'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_frame_router_bit'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => array(
      0 => array(
        'tid' => 20,
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
    'field_name' => 'field_cabinetry_frame_router_bit',
    'label' => 'Panel Router Bit',
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
  // 'node-cabinetry_wainscoting_project-field_cabinetry_height'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_height'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
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
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_height',
    'label' => 'Wainscoting Height',
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
  // 'node-cabinetry_wainscoting_project-field_cabinetry_materials_hardwa'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_materials_hardwa'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_materials_sheet'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_materials_sheet'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_materials_solid'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_materials_solid'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_project_labels'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_project_labels'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'field_name' => 'field_cabinetry_project_labels',
    'label' => 'Project Labels',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_sheet_packing_al'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_sheet_packing_al'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_solid_stock_leng'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_solid_stock_leng'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => array(
      0 => array(
        'value' => 2438.4,
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
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_thickness'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_thickness'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => array(
      0 => array(
        'value' => 19.05,
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
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_thickness',
    'label' => 'Solid Thickness',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_wainsc_cove_moul'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_wainsc_cove_moul'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => array(
      0 => array(
        'tid' => 26,
      ),
    ),
    'deleted' => 0,
    'description' => 'Cove Moulding',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_wainsc_cove_moul',
    'label' => 'Cove Moulding',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_wainsc_round_ove'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_wainsc_round_ove'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => array(
      0 => array(
        'tid' => 25,
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
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cabinetry_wainsc_round_ove',
    'label' => 'Round Over',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'node-cabinetry_wainscoting_project-field_cabinetry_wainscoting_sect'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_wainscoting_sect'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
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
    'field_name' => 'field_cabinetry_wainscoting_sect',
    'label' => 'Wall Section(s)',
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
  // 'node-cabinetry_wainscoting_project-field_cabinetry_wainscoting_styl'.
  $field_instances['node-cabinetry_wainscoting_project-field_cabinetry_wainscoting_styl'] = array(
    'bundle' => 'cabinetry_wainscoting_project',
    'default_value' => array(
      0 => array(
        'tid' => 19,
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
    'field_name' => 'field_cabinetry_wainscoting_styl',
    'label' => 'Wainscoting Style',
    'required' => 1,
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
  // 'taxonomy_term-cabinetry_wainscoting_style-field_cabinetry_php_library_clas'.
  $field_instances['taxonomy_term-cabinetry_wainscoting_style-field_cabinetry_php_library_clas'] = array(
    'bundle' => 'cabinetry_wainscoting_style',
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
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cabinetry_php_library_clas',
    'label' => 'Library Class Name',
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
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cabinetry Left Stud Distance');
  t('Cabinetry Right Stud Distance');
  t('Cove Moulding');
  t('Extend Left Stile Width');
  t('Extend Right Stile Width');
  t('Library Class Name');
  t('Materials Hardware');
  t('Materials Sheet Goods');
  t('Materials Solid');
  t('Measurement to the center of the first stud from the left side');
  t('Measurement to the center of the first stud from the right side');
  t('Number of Panels');
  t('Panel Router Bit');
  t('Panel Sheet Material');
  t('Project Labels');
  t('Rail/Stile Material');
  t('Round Over');
  t('Saw Blade Cut Width');
  t('Section Name');
  t('Section Width');
  t('Sheet Packing Algorithim');
  t('Should the left stile be widened to allow for lap joint overlap from another wall?');
  t('Should the right stile be widened to allow for lap joint overlap from another wall?');
  t('Skip Baseboard Components');
  t('Solid Stock Length');
  t('Solid Thickness');
  t('Stud Spacing');
  t('Trim Material');
  t('Wainscoting Height');
  t('Wainscoting Style');
  t('Wall Section(s)');

  return $field_instances;
}
