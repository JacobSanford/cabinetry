<?php
/**
 * @file
 * cabinetry_wainscoting_project.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cabinetry_wainscoting_project_ctools_plugin_api($module = NULL, $api = NULL) {
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
function cabinetry_wainscoting_project_node_info() {
  $items = array(
    'cabinetry_wainscoting_project' => array(
      'name' => t('Wainscoting Project'),
      'base' => 'node_content',
      'description' => t('Cabinetry Wainscoting Project'),
      'has_title' => '1',
      'title_label' => t('Project Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
