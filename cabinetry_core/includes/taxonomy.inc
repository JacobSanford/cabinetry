<?php

/**
 * @file
 * Provides taxonomy interfacing functions for cabinetry_cabinet_project.
 */

/**
 * Instantiate a CabinetryToolItem from a cabinetry_rail_stile_router_bits tid.
 *
 * @param int $tid
 *   The tid to query.
 *
 * @return object
 *   Returns a CabinetryToolItem object populated from $tid.
 */
function _cabinetry_cabinet_project_load_router_bit_object($tid) {
  return new CabinetryToolItem(
    _cabinetry_core_get_term_field($tid, 'name'),
    (float) _cabinetry_core_get_term_field($tid, 'field_cabinetry_rail_cut_depth'),
    (float) _cabinetry_core_get_term_field($tid, 'field_cabinetry_rail_cut_thickne')
  );
}

/**
 * Instantiate a CabinetrySheetGood from a cabinetry_sheet_goods tid.
 *
 * @param int $tid
 *   The tid to query.
 *
 * @return object
 *   Returns a CabinetrySheetGood object populated from $tid.
 */
function _cabinetry_core_load_sheet_good_object($tid) {
  return new CabinetrySheetGood(
    _cabinetry_core_get_term_field($tid, 'name'),
    (float) _cabinetry_core_get_term_field($tid, 'field_cabinetry_thickness'),
    (float) _cabinetry_core_get_term_field($tid, 'field_cabinetry_width'),
    (float) _cabinetry_core_get_term_field($tid, 'field_cabinetry_height'),
    (float) _cabinetry_core_get_term_field($tid, 'field_cabinetry_item_cost'),
    (bool) _cabinetry_core_get_term_field($tid, 'field_cabinetry_preserve_grain')
  );
}

/**
 * Instantiate a CabinetrySolidWood from a cabinetry_solid_wood tid.
 *
 * @param int $tid
 *   The tid to query.
 *
 * @return object
 *   Returns a CabinetrySolidWood object populated from $tid.
 */
function _cabinetry_core_load_solid_wood_object($tid, $thickness, $height) {
  return new CabinetrySolidWood(
    _cabinetry_core_get_term_field($tid, 'name'),
    (float) $thickness,
    (float) $height,
    0.0,
    (float) _cabinetry_core_get_term_field($tid, 'field_cabinetry_item_cost')
  );
}

/**
 * Obtain a field value from a taxonomy term.
 *
 * @param int $tid
 *   The tid to query.
 * @param string $field_name
 *   The field name to return the value from.
 *
 * @return string
 *   Returns the value of $field_name, or NULL if empty/unset.
 */
function _cabinetry_core_get_term_field($tid, $field_name) {
  $term_wrapper = entity_metadata_wrapper('taxonomy_term', taxonomy_term_load($tid));
  if (!empty($term_wrapper->$field_name->value())) {
    return $term_wrapper->$field_name->value();
  }
  return NULL;
}

/**
 * Instantiate CabinetryHardwareItem object from a given tid.
 *
 * @param int $tid
 *   The tid to query.
 *
 * @return object
 *   Returns a CabinetryHardwareItem object populated from $tid.
 */
function _cabinetry_core_load_hardware_object($tid) {
  return new CabinetryHardwareItem(
    _cabinetry_core_get_term_field($tid, 'name'),
    (float) _cabinetry_core_get_term_field($tid, 'field_cabinetry_item_cost')
  );
}

/**
 * Instantiate a CabinetrySolidWood from a cabinetry_solid_wood tid.
 *
 * @param int $tid
 *   The tid to query.
 *
 * @return object
 *   Returns a CabinetrySolidWood object populated from $tid.
 */
function _cabinetry_core_load_drawer_slide_object($tid) {
  return new CabinetryDrawerSlide(
    _cabinetry_core_get_term_field($tid, 'name'),
    (float) _cabinetry_core_get_term_field($tid, 'field_cabinetry_item_cost'),
    (float) _cabinetry_core_get_term_field($tid, 'field_cabinetry_slide_clearance')
  );
}