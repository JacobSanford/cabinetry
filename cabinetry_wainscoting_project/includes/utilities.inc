<?php

/**
 * @file
 * Provides form utility functions for the thirty_two_project content type.
 */

/**
 * Set up autoload for cabinetry_wainscoting_project objects.
 */
function _cabinetry_wainscoting_project_bootstrap() {
  spl_autoload_register(function ($class_name) {
    $filename = DRUPAL_ROOT . '/' . drupal_get_path('module', 'cabinetry_wainscoting_project') . "/includes/Cabinetry/$class_name.inc";
    if (file_exists($filename)) {
      include "$filename";
    }
  });
}
