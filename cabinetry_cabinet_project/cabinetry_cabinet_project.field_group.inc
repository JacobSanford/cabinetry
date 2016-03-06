<?php
/**
 * @file
 * cabinetry_cabinet_project.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cabinetry_cabinet_project_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cabinetry_carcass_details|field_collection_item|field_cabinetry_project_componen|form';
  $field_group->group_name = 'group_cabinetry_carcass_details';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cabinetry_project_componen';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Carcass Details',
    'weight' => '4',
    'children' => array(
      0 => 'field_cabinetry_carcass_sheet_mt',
      1 => 'field_cabinetry_width',
      2 => 'field_cabinetry_height',
      3 => 'field_cabinetry_depth',
      4 => 'field_cabinetry_carcass_back_mat',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cabinetry-carcass-details field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cabinetry_carcass_details|field_collection_item|field_cabinetry_project_componen|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cabinetry_carcass_style|field_collection_item|field_cabinetry_project_componen|form';
  $field_group->group_name = 'group_cabinetry_carcass_style';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cabinetry_project_componen';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Carcass Style',
    'weight' => '2',
    'children' => array(
      0 => 'field_cabinetry_carcass_division',
      1 => 'field_cabinetry_number_of_shelve',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cabinetry-carcass-style field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cabinetry_carcass_style|field_collection_item|field_cabinetry_project_componen|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cabinetry_door_details|field_collection_item|field_cabinetry_project_componen|form';
  $field_group->group_name = 'group_cabinetry_door_details';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cabinetry_project_componen';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Door Details',
    'weight' => '5',
    'children' => array(
      0 => 'field_cabinetry_doors_span_gap',
      1 => 'field_cabinetry_door_reveal',
      2 => 'field_cabinetry_door_frame_width',
      3 => 'field_cabinetry_door_frame_thick',
      4 => 'field_cabinetry_door_panel_mater',
      5 => 'field_cabinetry_door_panel_under',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cabinetry-door-details field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cabinetry_door_details|field_collection_item|field_cabinetry_project_componen|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cabinetry_project_comp|node|cabinetry_cabinet_project|form';
  $field_group->group_name = 'group_cabinetry_project_comp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cabinetry_cabinet_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cabinetry Project Components',
    'weight' => '7',
    'children' => array(
      0 => 'field_cabinetry_project_componen',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cabinetry-project-comp field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cabinetry_project_comp|node|cabinetry_cabinet_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cabinetry_project_info|node|cabinetry_cabinet_project|form';
  $field_group->group_name = 'group_cabinetry_project_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cabinetry_cabinet_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_cabinetry_description',
      1 => 'field_cabinetry_project_measurem',
      2 => 'field_cabinetry_enforce_32mm',
      3 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Project Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-cabinetry-project-info field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_cabinetry_project_info|node|cabinetry_cabinet_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cabinetry_tool_settings|node|cabinetry_cabinet_project|form';
  $field_group->group_name = 'group_cabinetry_tool_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cabinetry_cabinet_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tool Settings',
    'weight' => '4',
    'children' => array(
      0 => 'field_cabinetry_frame_router_bit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cabinetry-tool-settings field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cabinetry_tool_settings|node|cabinetry_cabinet_project|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Cabinetry Project Components');
  t('Carcass Details');
  t('Carcass Style');
  t('Door Details');
  t('Project Information');
  t('Tool Settings');

  return $field_groups;
}