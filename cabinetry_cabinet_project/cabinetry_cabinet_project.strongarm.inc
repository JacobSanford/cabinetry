<?php
/**
 * @file
 * cabinetry_cabinet_project.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cabinetry_cabinet_project_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_cabinetry_cabinet_project';
  $strongarm->value = 0;
  $export['comment_anonymous_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_cabinetry_cabinet_project';
  $strongarm->value = '2';
  $export['comment_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_cabinetry_cabinet_project';
  $strongarm->value = 1;
  $export['comment_default_mode_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_cabinetry_cabinet_project';
  $strongarm->value = '50';
  $export['comment_default_per_page_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_cabinetry_cabinet_project';
  $strongarm->value = 1;
  $export['comment_form_location_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_cabinetry_cabinet_project';
  $strongarm->value = '1';
  $export['comment_preview_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_cabinetry_cabinet_project';
  $strongarm->value = 1;
  $export['comment_subject_field_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__cabinetry_cabinet_project';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cabinetry_cabinet_project';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cabinetry_cabinet_project';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cabinetry_cabinet_project';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cabinetry_cabinet_project';
  $strongarm->value = '0';
  $export['node_preview_cabinetry_cabinet_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cabinetry_cabinet_project';
  $strongarm->value = 1;
  $export['node_submitted_cabinetry_cabinet_project'] = $strongarm;

  return $export;
}
