<?php
/**
 * @file
 * Provides a generic object to serve as a basic european style cabinet.
 */

/**
 * A generic object to serve as a basic european style cabinet.
 */
class CabinetryBasicEuroCabinet extends CabinetryComponent {

  /**
   * The back sheet good.
   *
   * @var object CabinetrySheetGood
   */
  public $backSheetGood = NULL;

  /**
   * An array of CabinetryEdgeBanding objects comprising this component.
   *
   * @var array
   */
  public $banding = array();

  /**
   * The inner width dim, in millimeters.
   *
   * @var float
   */
  public $carcassInnerWidth = 0.0;

  /**
   * The carcass sheet good.
   *
   * @var object CabinetrySheetGood
   */
  public $carcassSheetGood = NULL;

  /**
   * An array of float values equal to or less than 1.0.
   *
   * The sum of the array values should total 1.0.
   *
   * @var integer
   */
  public $divisions = array();

  /**
   * An array of CabinetryCabinetDoor objects comprising this component.
   *
   * @var integer
   */
  public $doors = array();

  /**
   * The number of doors spanning the carcass opening.
   *
   * @var integer
   */
  public $doorsAcrossGap = 0;

  /**
   * The door reveal, in millimeters.
   *
   * @var float
   */
  public $doorReveal = 0.0;

  /**
   * The door panel undersize for expansion, each side, in millimeters.
   *
   * @var float
   */
  public $doorPanelUndersize = 0.0;

  /**
   * The door frame material.
   *
   * @var object
   */
  public $doorFrameMaterial = NULL;

  /**
   * The door frame rail/stile bit.
   *
   * @var object
   */
  public $doorFrameRouterBit = NULL;

  /**
   * The door panel material.
   *
   * @var object
   */
  public $doorPanelMaterial = NULL;

  /**
   * The door hinge.
   *
   * @var object
   */
  public $doorHinge = NULL;

  /**
   * The door hinge.
   *
   * @var object
   */
  public $doorHingePlate = NULL;

  /**
   * The number of shelves.
   *
   * @var integer
   */
  public $numShelves = 0;


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
    $this->doorFrameMaterial = _cabinetry_core_load_solid_wood_object($cabinet_component['field_cabinetry_door_frame_mater'][LANGUAGE_NONE][0]['tid']);
    $this->doorPanelMaterial = _cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_door_panel_mater'][LANGUAGE_NONE][0]['tid']);
    $this->doorReveal = (float) $cabinet_component['field_cabinetry_door_reveal'][LANGUAGE_NONE][0]['value'];
    $this->doorPanelUndersize = (float) $cabinet_component['field_cabinetry_door_panel_under'][LANGUAGE_NONE][0]['value'];
    $this->doorsAcrossGap = (int) $cabinet_component['field_cabinetry_doors_span_gap'][LANGUAGE_NONE][0]['value'];
    $this->doorHinge = _cabinetry_core_load_hardware_object($cabinet_component['field_cabinetry_door_hinge'][LANGUAGE_NONE][0]['tid']);
    $this->doorHingePlate = _cabinetry_core_load_hardware_object($cabinet_component['field_cabinetry_door_hinge_plate'][LANGUAGE_NONE][0]['tid']);

    // Determine vertical division ratio array.
    $divisions_array = array();
    foreach ($cabinet_component['field_cabinetry_carcass_division'][LANGUAGE_NONE][0]['field_cabinetry_division_ratio'][LANGUAGE_NONE] as $ratio_value) {
      if (!empty($ratio_value['value'])) {
        $divisions_array[] = (float) $ratio_value['value'];
      }
    }
    $this->divisions = $divisions_array;

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
  }

  /**
   * Add a length of edge banding to the cabinet materials list.
   *
   * @param float $width
   *   The width of the banding, in millimeters.
   * @param float $length
   *   The length required, in millimeters.
   */
  protected function addBanding($material, $width, $length) {
    $object_found = FALSE;
    foreach ($this->banding as $banding_index => $banding_value) {
      if (
        $banding_value->material == $material &&
        $banding_value->width == $width
      ) {
        $this->banding[$banding_index]->add($length);
        $object_found = TRUE;
      }
    }
    if ($object_found == FALSE) {
      $this->banding[] = new CabinetryEdgeBanding($material, $width);
      $this->banding[count($this->banding) - 1]->add($length);
    }
  }

  /**
   * Set inner width of this cabinet.
   */
  protected function setInnerWidth() {
    $this->carcassInnerWidth = $this->width - (2 * $this->carcassSheetGood->thickness);
  }

  /**
   * Generate the back panel parts for the cabinet caracass.
   */
  protected function generateBackPanelPart() {
    $dado_depth = round($this->carcassSheetGood->thickness / 2, 1);

    $this->parts[] = new CabinetryWoodPart(
      'Back Panel',
      $this->backSheetGood->thickness,
      $this->height,
      $this->carcassInnerWidth + 2 * $dado_depth,
      $this->backSheetGood,
      ''
    );
  }

  /**
   * Generate the divider panel parts for the cabinet caracass.
   */
  protected function generateDividerPanelParts() {
    for ($divider_id = 0; $divider_id < count($this->divisions) - 1; $divider_id++) {
      $this->generateTopBottomPart("Section $divider_id Divider");
    }
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
    foreach ($this->divisions as $division_ratio) {
      for ($door_counter = 0; $door_counter < $this->doorsAcrossGap; $door_counter++) {
        $this->doors[] = new CabinetryCabinetDoor(
          ($this->width / $this->doorsAcrossGap) - 2 * $this->doorReveal,
          ($this->height * $division_ratio) - 2 * $this->doorReveal,
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

  /**
   * Generate the nailer strips panel parts for the cabinet carcass.
   */
  protected function generateNailerParts() {
    for ($nailerid = 0; $nailerid < 2; $nailerid++) {
      $this->parts[] = new CabinetryWoodPart(
        "Nailer $nailerid",
        $this->carcassSheetGood->thickness,
        $this->carcassInnerWidth,
        75,
        $this->carcassSheetGood,
        ''
      );
    }
  }

  /**
   * Generate the CabinetryWoodPart shelves for this cabinet.
   */
  protected function generateShelfParts() {
    for ($shelfid = 0; $shelfid < $this->numShelves; $shelfid++) {
      $this->parts[] = new CabinetryWoodPart(
        "Shelf $shelfid",
        $this->carcassSheetGood->thickness,
        $this->carcassInnerWidth - 6.0,
        $this->depth - 6.0,
        $this->carcassSheetGood,
        ''
      );
      $this->addBanding($this->carcassSheetGood->material, $this->carcassSheetGood->thickness, $this->carcassInnerWidth - 6.0);
    }
  }

  /**
   * Generate a side panel for the caracass.
   *
   * @param string $label
   *   A label to identify the side (Left, Right).
   */
  protected function generateSidePart($label) {
    $dado_depth = round($this->carcassSheetGood->thickness / 2, 1);

    $this->parts[] = new CabinetryWoodPart(
      "$label Panel",
      $this->carcassSheetGood->thickness,
      $this->height,
      $this->depth,
      $this->carcassSheetGood,
      "Cut {$dado_depth}mm Deep Dado {$this->carcassSheetGood->thickness}mm from long side on one side."
    );
    $this->addBanding($this->carcassSheetGood->material, $this->carcassSheetGood->thickness, $this->height);
  }

  /**
   * Generate a top or bottom panel for the caracass.
   *
   * @param string $label
   *   A label to identify the side (Top, Bottom).
   */
  protected function generateTopBottomPart($label) {
    $this->parts[] = new CabinetryWoodPart(
      "$label Panel",
      $this->carcassSheetGood->thickness,
      $this->carcassInnerWidth,
      $this->depth,
      $this->carcassSheetGood,
      ''
    );
    $this->addBanding($this->carcassSheetGood->material, $this->carcassSheetGood->thickness, $this->carcassInnerWidth);
  }

}
