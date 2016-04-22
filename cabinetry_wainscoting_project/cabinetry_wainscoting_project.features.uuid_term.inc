<?php
/**
 * @file
 * cabinetry_wainscoting_project.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function cabinetry_wainscoting_project_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Standard With Chair Rail and MDF Backcutter',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6fd64477-8deb-4701-8459-3f36c9d6df8e',
    'vocabulary_machine_name' => 'cabinetry_wainscoting_style',
    'field_cabinetry_php_library_clas' => array(
      'und' => array(
        0 => array(
          'value' => 'CabinetryWainscotingStandardChairRailBackcutterMDF',
          'format' => NULL,
          'safe_value' => 'CabinetryWainscotingStandardChairRailBackcutterMDF',
        ),
      ),
    ),
  );
  return $terms;
}
