<?php

/**
 * @file
 * Provides a generic object to serve as a basic european style cabinet.
 */

define('CABINETRY_CABINET_PROJECT_CABINET_DRAWER_SECTION_HEIGHT', 160.0);

/**
 * Provides basic european style cabinet with a standard drawer on top.
 */
class CabinetryBasicEuroDrawerCabinet extends CabinetryBasicEuroCabinet {

  /**
   * The height of the drawer section, in millimeters.
   *
   * @var float
   */
  public $drawerSectionHeight = 0.0;

  /**
   * The height of the cabinet section, in millimeters.
   *
   * @var float
   */
  public $cabinetSectionHeight = 0.0;

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
    $this->drawerRailHeight = (float) $cabinet_component['field_cabinetry_drawer_rail_heig'][LANGUAGE_NONE][0]['value'];
    $this->drawerBottomMaterial = _cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_drawer_bottom_ma'][LANGUAGE_NONE][0]['tid']);

    // Lay out sections.
    $this->drawerSectionHeight = CABINETRY_CABINET_PROJECT_CABINET_DRAWER_SECTION_HEIGHT;
    $this->cabinetSectionHeight = $this->height - $this->drawerSectionHeight;

    // Generate parts for cabinet.
    $this->generateParts();
  }

  /**
   * Generate parts required to build this cabinet configuration.
   */
  protected function generateParts() {
    parent::generateParts();

    // Add drawer spreader parts.
    $this->parts[] = new CabinetryWoodPart(
      "Drawer Spreader",
      $this->carcassSheetGood->thickness,
      $this->carcassInnerWidth,
      CABINETRY_CABINET_PROJECT_CABINET_NAILER_HEIGHT,
      $this->carcassSheetGood,
      ''
    );

    $this->addBanding($this->carcassSheetGood->material, $this->carcassSheetGood->thickness, $this->carcassInnerWidth);

    // Add drawer section.
    $drawer = new CabinetryCabinetDrawerSection(
      $this->width,
      $this->drawerSectionHeight,
      $this->depth,
      $this->carcassSheetGood,
      $this->doorFrameMaterial,
      $this->drawerRailHeight,
      $this->drawerSlides,
      $this->doorFrameRouterBit,
      $this->doorPanelMaterial,
      $this->doorPanelUndersize,
      $this->doorReveal,
      $this->drawerBottomMaterial
    );

    $this->addParts($drawer->parts);
    $this->addHardware($drawer->hardware);
    $this->addBandingArray($drawer->banding);
  }

  /**
   * Generate the doors for the cabinet.
   */
  protected function generateDoorParts() {
    $this->doors = array();

    for ($door_counter = 0; $door_counter < $this->doorsAcrossGap; $door_counter++) {
      $door = new CabinetryCabinetDoor(
        ($this->width / $this->doorsAcrossGap) - 2 * $this->doorReveal,
        $this->cabinetSectionHeight - 2 * $this->doorReveal,
        $this->doorFrameMaterial,
        $this->doorFrameRouterBit,
        $this->doorPanelMaterial,
        $this->doorPanelUndersize
      );
      $this->addParts($door->parts);
      $this->hardware[] = $this->doorHinge;
      $this->hardware[] = $this->doorHinge;
      $this->hardware[] = $this->doorHingePlate;
      $this->hardware[] = $this->doorHingePlate;
    }
  }

}
