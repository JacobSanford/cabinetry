<?php
/**
 * @file
 * cabinetry_wainscoting_project.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cabinetry_wainscoting_project_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cabinetry_wains_general|node|cabinetry_wainscoting_project|form';
  $field_group->group_name = 'group_cabinetry_wains_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cabinetry_wainscoting_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Settings',
    'weight' => '1',
    'children' => array(
      0 => 'field_cabinetry_height',
      1 => 'field_cabinetry_wainscoting_styl',
      2 => 'field_cabinetry_solid_stock_leng',
      3 => 'field_cabinetry_carcass_sheet_mt',
      4 => 'field_cabinetry_door_frame_mater',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cabinetry-wains-general field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cabinetry_wains_general|node|cabinetry_wainscoting_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cabinetry_wains_materials|node|cabinetry_wainscoting_project|form';
  $field_group->group_name = 'group_cabinetry_wains_materials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cabinetry_wainscoting_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Materials List',
    'weight' => '4',
    'children' => array(
      0 => 'field_cabinetry_materials_hardwa',
      1 => 'field_cabinetry_materials_sheet',
      2 => 'field_cabinetry_materials_solid',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Materials List',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-cabinetry-wains-materials field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_cabinetry_wains_materials|node|cabinetry_wainscoting_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cabinetry_wains_sections|node|cabinetry_wainscoting_project|form';
  $field_group->group_name = 'group_cabinetry_wains_sections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cabinetry_wainscoting_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Wall Sections',
    'weight' => '3',
    'children' => array(
      0 => 'field_cabinetry_wainscoting_sect',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Wall Sections',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-cabinetry-wains-sections field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_cabinetry_wains_sections|node|cabinetry_wainscoting_project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cabinetry_wainscot_tools|node|cabinetry_wainscoting_project|form';
  $field_group->group_name = 'group_cabinetry_wainscot_tools';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cabinetry_wainscoting_project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tool Settings',
    'weight' => '2',
    'children' => array(
      0 => 'field_cabinetry_frame_router_bit',
      1 => 'field_cabinetry_sheet_packing_al',
      2 => 'field_cabinetry_blade_cut_width',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cabinetry-wainscot-tools field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cabinetry_wainscot_tools|node|cabinetry_wainscoting_project|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('General Settings');
  t('Materials List');
  t('Tool Settings');
  t('Wall Sections');

  return $field_groups;
}
