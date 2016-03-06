<?php
/**
 * @file
 * cabinetry_cabinet_project.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cabinetry_cabinet_project_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cabinetry_cabinet_project_node_info() {
  $items = array(
    'cabinetry_cabinet_project' => array(
      'name' => t('Cabinet Project'),
      'base' => 'node_content',
      'description' => t('Cabinet Project'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
