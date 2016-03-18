<?php
/**
 * @file
 * Provides form utility functions for the thirty_two_project content type.
 */

/**
 * Set up autoload for cabinetry_cabinet_project objects.
 */
function _cabinetry_cabinet_project_bootstrap() {
  spl_autoload_register(function ($class_name) {
    $filename = DRUPAL_ROOT . '/' . drupal_get_path('module', 'cabinetry_cabinet_project') . "/includes/Cabinetry/$class_name.inc";
    if (file_exists($filename)) {
      include "$filename";
    }
  });
}

/**
 * Determine if a float is evenly divisible by another.
 *
 * If width, height of depth are not units of 32, then reject them.
 *
 * @param float $number
 *   The number to validate.
 * @param float $value
 *   The divisor to test.
 *
 * @return bool
 *   TRUE if $number is divisible by $value, FALSE if unset.
 */
function _cabinetry_cabinet_project_float_evenly_divisible($number, $value) {
  if (fmod((float) $number, (float) $value) != 0) {
    return FALSE;
  }
  return TRUE;
}

/**
 * Stuff value into a non-localized single item node field array.
 *
 * @param string $value
 *   The value to insert into the object.
 *
 * @return array
 *   The single item node field array.
 */
function _cabinetry_cabinet_project_stuff_field($value) {
  return array(
    LANGUAGE_NONE => array(
      0 => array(
        'value' => $value,
      ),
    ),
  );
}
