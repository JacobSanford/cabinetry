<?php
/**
 * @file
 * Provides form utility functions for the thirty_two_project content type.
 */

/**
 * Bootstrap cabinetry_core object classes.
 */
function _cabinetry_core_bootstrap() {
  spl_autoload_register(function ($class_name) {
    $filename = DRUPAL_ROOT . '/' . drupal_get_path('module', 'cabinetry_core') . "/includes/Cabinetry/$class_name.inc";
    if (file_exists($filename)) {
      include "$filename";
    }
  });
}
