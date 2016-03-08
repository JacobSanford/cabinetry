<?php
/**
 * @file
 * Provides form utility functions for the thirty_two_project content type.
 */

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
