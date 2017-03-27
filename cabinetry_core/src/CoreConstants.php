<?php

namespace Drupal\cabinetry_core;

/**
 * Defines an object to provide constants.
 */
abstract class CoreConstants {

  /**
   * Convert cubic millimeters to boardfeet.
   */
  const CONVERT_MM_TO_INCHES = 3.93701e-2;
  const CONVERT_MM3_TO_BOARD_FEET = 4.23776e-7;

  /**
   * Taxonomy Definitions.
   */
  const CABINETRY_MATERIAL_IS_SOLID = ['cabinetry_solid_stock'];

  /**
   * Field Names.
   */
  const CABINETRY_MATERIAL_DEPTH_FIELD = 'field_cabinetry_depth';
  const CABINETRY_MATERIAL_HEIGHT_FIELD = 'field_cabinetry_height';
  const CABINETRY_MATERIAL_WIDTH_FIELD = 'field_cabinetry_width';
  const CABINETRY_MATERIAL_PRESERVE_GRAIN_FIELD = 'field_cabinetry_preserve_grain';
  const CABINETRY_RAILSTILE_BIT_CUT_DEPTH_FIELD = 'field_cabinetry_rail_cut_depth';

}
