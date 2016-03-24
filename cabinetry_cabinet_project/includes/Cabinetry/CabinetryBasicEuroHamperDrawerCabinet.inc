<?php

/**
 * @file
 * Provides a generic object to serve as a basic european style cabinet.
 */

/**
 * Provides basic european style cabinet with a standard drawer on top.
 */
class CabinetryBasicEuroHamperDrawerCabinet extends CabinetryBasicEuroDrawerCabinet {

  /**
   * The height of the cabinet section, in millimeters.
   *
   * @var float
   */
  public $hamperSectionHeight = 0.0;

  /**
   * The height of the cabinet section, in millimeters.
   *
   * @var float
   */
  public $hamperSectionSlides = 0.0;

  /**
   * Build the cabinet and determine parts required.
   *
   * @param array $cabinet_component
   *   An associative array obtained from iterating over the proprietary values
   *   in $form_state['values']['field_cabinetry_project_componen'] from the
   *   cabinetry_cabinet_project_node_form drupal module form submit.
   */
  public function build($cabinet_component) {
    $this->height = (float) $cabinet_component['field_cabinetry_height'][LANGUAGE_NONE][0]['value'];
    $this->width = (float) $cabinet_component['field_cabinetry_width'][LANGUAGE_NONE][0]['value'];
    $this->depth = (float) $cabinet_component['field_cabinetry_depth'][LANGUAGE_NONE][0]['value'];
    $this->carcassSheetGood = _cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_carcass_sheet_mt'][LANGUAGE_NONE][0]['tid']);
    $this->backSheetGood = _cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_carcass_back_mat'][LANGUAGE_NONE][0]['tid']);
    $this->numShelves = (int) $cabinet_component['field_cabinetry_number_of_shelve'][LANGUAGE_NONE][0]['value'];
    $this->counterOnTop = $cabinet_component['field_cabinetry_counter_on_top'][LANGUAGE_NONE][0]['value'];

    // Door properties.
    $this->doorFrameThickness = (float) $cabinet_component['field_cabinetry_door_frame_thick'][LANGUAGE_NONE][0]['value'];
    $this->doorFrameHeight = (float) $cabinet_component['field_cabinetry_door_frame_heigh'][LANGUAGE_NONE][0]['value'];
    $this->doorFrameMaterial = _cabinetry_core_load_solid_wood_object(
      $cabinet_component['field_cabinetry_door_frame_mater'][LANGUAGE_NONE][0]['tid'],
      $this->doorFrameThickness,
      $this->doorFrameHeight
    );
    $this->doorPanelMaterial = _cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_door_panel_mater'][LANGUAGE_NONE][0]['tid']);
    $this->doorReveal = (float) $cabinet_component['field_cabinetry_door_reveal'][LANGUAGE_NONE][0]['value'];
    $this->doorPanelUndersize = (float) $cabinet_component['field_cabinetry_door_panel_under'][LANGUAGE_NONE][0]['value'];
    $this->doorsAcrossGap = (int) $cabinet_component['field_cabinetry_doors_span_gap'][LANGUAGE_NONE][0]['value'];
    $this->doorHinge = _cabinetry_core_load_hardware_object($cabinet_component['field_cabinetry_door_hinge'][LANGUAGE_NONE][0]['tid']);
    $this->doorHingePlate = _cabinetry_core_load_hardware_object($cabinet_component['field_cabinetry_door_hinge_plate'][LANGUAGE_NONE][0]['tid']);

    // Drawers.
    $this->drawerSlides = _cabinetry_core_load_drawer_slide_object($cabinet_component['field_cabinetry_drawer_slides'][LANGUAGE_NONE][0]['tid']);
    $this->hamperSectionSlides = _cabinetry_core_load_drawer_slide_object($cabinet_component['field_cabinetry_secondary_slides'][LANGUAGE_NONE][0]['tid']);
    $this->drawerRailHeight = (float) $cabinet_component['field_cabinetry_drawer_rail_heig'][LANGUAGE_NONE][0]['value'];
    $this->drawerBottomMaterial = _cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_drawer_bottom_ma'][LANGUAGE_NONE][0]['tid']);

    // Lay out sections.
    $this->drawerSectionHeight = CABINETRY_CABINET_PROJECT_CABINET_DRAWER_SECTION_HEIGHT;
    $this->hamperSectionHeight = $this->height - $this->drawerSectionHeight;

    // Generate parts for cabinet.
    $this->generateParts();
  }

  /**
   * Generate parts required to build this cabinet configuration.
   */
  protected function generateParts() {
    parent::generateParts();
    // Add hamper section.
    $hamper = new CabinetryCabinetDrawerSection(
      $this->width,
      $this->hamperSectionHeight,
      $this->depth,
      $this->carcassSheetGood,
      $this->doorFrameMaterial,
      $this->doorFrameHeight,
      $this->hamperSectionSlides,
      $this->doorFrameRouterBit,
      $this->doorPanelMaterial,
      $this->doorPanelUndersize,
      $this->doorReveal,
      $this->carcassSheetGood
    );
    $this->addParts($hamper->parts);
    $this->addHardware($hamper->hardware);
    $this->addBandingArray($hamper->banding);
  }

  protected function generateDoorParts() {
    // pass
  }

}
