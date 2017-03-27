<?php

namespace Drupal\cabinetry_cabinet_project;

/**
 * Defines an object to provide constants.
 */
abstract class CabinetProjectConstants {

  /**
   * Entity Names.
   */
  const CABINET_PROJECT_ENTITY_NAME = 'cabinetry_project_cabinets';
  const CABINET_MODULE_ENTITY_NAME = 'cabinetry_cabinet_module';

  /**
   * Field Names.
   */
  const CABINET_PROJECT_CABINET_CARCASS_BACK_MATERIAL_FIELD = 'field_cabinetry_proj_carcass_bac';
  const CABINET_PROJECT_CABINET_CARCASS_MATERIAL_FIELD = 'field_cabinetry_proj_carcass_mat';
  const CABINET_PROJECT_CABINET_CUT_SHEETS_FIELD = 'field_cabinetry_cut_sheets';
  const CABINET_PROJECT_CABINET_DOOR_FRAME_MATERIAL_FIELD = 'field_cabinetry_door_frame_mater';
  const CABINET_PROJECT_CABINET_DOOR_HINGE_FIELD = 'field_cabinetry_project_hinges';
  const CABINET_PROJECT_CABINET_DOOR_HINGE_PLATE_FIELD = 'field_cabinetry_project_hinge_pl';
  const CABINET_PROJECT_CABINET_DOOR_PANEL_MATERIAL_FIELD = 'field_cabinetry_door_panel_mater';
  const CABINET_PROJECT_CABINET_DOOR_RAILSTILE_BIT_FIELD = 'field_cabinetry_proj_door_bit';
  const CABINET_PROJECT_CABINET_DOOR_REVEAL_FIELD = 'field_cabinetry_cabinet_door_rev';
  const CABINET_PROJECT_CABINET_DOOR_UNDERSIZE_FIELD = 'field_cabinetry_door_panel_under';
  const CABINET_PROJECT_CABINET_MODULES_FIELD = 'field_cabinetry_cabinet_modules';
  const CABINET_PROJECT_CABINET_PARTS_FIELD = 'field_cabinetry_cabinet_parts';
  const CABINET_PROJECT_CABINET_RAILSTILE_HEIGHT_FIELD = 'field_cabinetry_railstile_height';
  const CABINET_PROJECT_CABINET_RAILSTILE_THICKNESS_FIELD = 'field_cabinetry_railstile_thickn';
  const CABINET_PROJECT_SAW_BLADE_FIELD = 'field_cabinetry_proj_saw_blade';


  /**
   * Constant Values.
   */
  const CABINET_PROJECT_CABINET_NAILER_HEIGHT = 75;
  const CABINET_PROJECT_CABINET_SHELF_UNDERSIZE = 6.0;

}
