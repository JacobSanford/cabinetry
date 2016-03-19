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
    // TODO : parent::build($cabinet_component);

    $this->height = (float) $cabinet_component['field_cabinetry_height'][LANGUAGE_NONE][0]['value'];
    $this->width = (float) $cabinet_component['field_cabinetry_width'][LANGUAGE_NONE][0]['value'];
    $this->depth = (float) $cabinet_component['field_cabinetry_depth'][LANGUAGE_NONE][0]['value'];
    $this->carcassSheetGood = _cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_carcass_sheet_mt'][LANGUAGE_NONE][0]['tid']);
    $this->backSheetGood = _cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_carcass_back_mat'][LANGUAGE_NONE][0]['tid']);
    $this->numShelves = (int) $cabinet_component['field_cabinetry_number_of_shelve'][LANGUAGE_NONE][0]['value'];

    // Door properties.
    $this->doorFrameMaterial = _cabinetry_core_load_solid_wood_object($cabinet_component['field_cabinetry_door_frame_mater'][LANGUAGE_NONE][0]['tid']);
    $this->doorPanelMaterial = _cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_door_panel_mater'][LANGUAGE_NONE][0]['tid']);
    $this->doorReveal = (float) $cabinet_component['field_cabinetry_door_reveal'][LANGUAGE_NONE][0]['value'];
    $this->doorPanelUndersize = (float) $cabinet_component['field_cabinetry_door_panel_under'][LANGUAGE_NONE][0]['value'];
    $this->doorsAcrossGap = (int) $cabinet_component['field_cabinetry_doors_span_gap'][LANGUAGE_NONE][0]['value'];
    $this->doorHinge = _cabinetry_core_load_hardware_object($cabinet_component['field_cabinetry_door_hinge'][LANGUAGE_NONE][0]['tid']);
    $this->doorHingePlate = _cabinetry_core_load_hardware_object($cabinet_component['field_cabinetry_door_hinge_plate'][LANGUAGE_NONE][0]['tid']);

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
    $this->parts = array();
    $this->setInnerWidth();
    $this->generateShelfParts();
    $this->generateSidePart('Left');
    $this->generateSidePart('Right');
    $this->generateTopBottomPart('Top');
    $this->generateTopBottomPart('Bottom');
    $this->generateBackPanelPart();
    $this->generateDividerPanelParts();
    $this->generateNailerParts();
    $this->generateDoorParts();

    // Add drawer spreader parts.
    // Add drawer parts.
  }

  /**
   * Generate the doors parts for the cabinet.
   */
  protected function generateDoorParts() {
    $this->generateDoors();
    foreach ($this->doors as $door) {
      $door->generateParts();
    }
  }

  /**
   * Generate the doors for the cabinet.
   */
  protected function generateDoors() {
    $this->doors = array();

    // Add drawer front.
    // TODO : top and bottom rails smaller?
    $this->doors[] = new CabinetryCabinetDoor(
      $this->width - 2 * $this->doorReveal,
      $this->drawerSectionHeight - 2 * $this->doorReveal,
      $this->doorFrameMaterial,
      $this->doorFrameRouterBit,
      $this->doorPanelMaterial,
      $this->doorPanelUndersize
    );

    // Add cabinet section doors.
    for ($door_counter = 0; $door_counter < $this->doorsAcrossGap; $door_counter++) {
      $this->doors[] = new CabinetryCabinetDoor(
        ($this->width / $this->doorsAcrossGap) - 2 * $this->doorReveal,
        $this->cabinetSectionHeight - 2 * $this->doorReveal,
        $this->doorFrameMaterial,
        $this->doorFrameRouterBit,
        $this->doorPanelMaterial,
        $this->doorPanelUndersize
      );
      $this->hardware[] = $this->doorHinge;
      $this->hardware[] = $this->doorHinge;
      $this->hardware[] = $this->doorHingePlate;
      $this->hardware[] = $this->doorHingePlate;
    }
  }

}
