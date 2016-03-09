<?php
/**
 * @file
 * Provides a generic object to serve as components within a cabinet project.
 */

/**
 * A generic object to serve as components within a cabinetry project.
 */
class BasicEuroCabinet extends CabinetryComponent {

  /**
   * The back sheet good.
   *
   * @var object CabinetrySheetGood
   */
  public $backSheetGood = NULL;

  /**
   * An array of CabinetEdgeBanding objects comprising this component.
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
   * The division ratios.
   *
   * @var integer
   */
  public $divisions = array();

  /**
   * The number of shelves.
   *
   * @var integer
   */
  public $numShelves = 0;

  /**
   * Constructor.
   *
   * @param string $id
   *   An id, typically an integer to assign to this cabinet.
   */
  public function __construct($id) {
    parent::__construct($id);
  }

  /**
   * Build the cabinet and determine pieces required.
   *
   * @param array $cabinet_component
   *   An associative array obtained from iterating over the proprietary values
   *   in $form_state['values']['field_cabinetry_project_componen'] from the
   *   cabinetry_cabinet_project_node_form drupal module form submit.
   */
  public function build($cabinet_component) {
    $this->setHeight($cabinet_component['field_cabinetry_height'][LANGUAGE_NONE][0]['value']);
    $this->setWidth($cabinet_component['field_cabinetry_width'][LANGUAGE_NONE][0]['value']);
    $this->setDepth($cabinet_component['field_cabinetry_depth'][LANGUAGE_NONE][0]['value']);
    $this->setCarcassSheetGood(_cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_carcass_sheet_mt'][LANGUAGE_NONE][0]['tid']));
    $this->setBackSheetGood(_cabinetry_core_load_sheet_good_object($cabinet_component['field_cabinetry_carcass_back_mat'][LANGUAGE_NONE][0]['tid']));
    $this->setNumShelves($cabinet_component['field_cabinetry_number_of_shelve'][LANGUAGE_NONE][0]['value']);

    $divisions_array = array();
    foreach ($cabinet_component['field_cabinetry_carcass_division'][LANGUAGE_NONE][0]['field_cabinetry_division_ratio'][LANGUAGE_NONE] as $ratio_value) {
      if (!empty($ratio_value['value'])) {
        $divisions_array[] = (float) $ratio_value['value'];
      }
    }
    $this->setNumDivisions($divisions_array);
    $this->generatePieces();
  }

  /**
   * Generate pieces required to build this cabinet configuration.
   */
  protected function generatePieces() {
    $this->pieces = array();
    $this->setInnerWidth();
    $this->generateShelfPieces();
    $this->generateSidePiece('Left');
    $this->generateSidePiece('Right');
    $this->generateTopBottomPiece('Top');
    $this->generateTopBottomPiece('Bottom');
    $this->generateBackPiece();
    $this->generateDividerPieces();
    $this->generateNailers();
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
   * Set the back side sheet good of this cabinet.
   *
   * @param object $sheet_good
   *   A CabinetrySheetGood object.
   */
  protected function setBackSheetGood($sheet_good) {
    $this->backSheetGood = $sheet_good;
  }

  /**
   * Set the carcass sheet good of this cabinet.
   *
   * @param object $sheet_good
   *   A CabinetrySheetGood object.
   */
  protected function setCarcassSheetGood($sheet_good) {
    $this->carcassSheetGood = $sheet_good;
  }

  /**
   * Set inner width of this cabinet.
   */
  protected function setInnerWidth() {
    $this->carcassInnerWidth = $this->width - (2 * $this->carcassSheetGood->thickness);
  }

  /**
   * Set the vertical division ratios of this cabinet.
   *
   * @param array $divisions_array
   *   An array of float values equal to or less than 1.0. The sum of the array
   *   values should total 1.0.
   */
  protected function setDivisions(array $divisions_array) {
    $this->divisions = $divisions_array;
  }

  /**
   * Set the number of shelves of this cabinet.
   *
   * @param int $num_shelves
   *   The number of shelves this cabinet should have.
   */
  protected function setNumShelves($num_shelves) {
    $this->numShelves = $num_shelves;
  }

  /**
   * Generate the vertical dividers for the caracass.
   */
  protected function generateDividerPieces() {
    for ($divider_id = 0; $divider_id < count($this->divisions) - 1; $divider_id++) {
      $this->generateTopBottomPiece("Section $divider_id Divider");
    }
  }

  /**
   * Generate the back panel for the caracass.
   */
  protected function generateBackPiece() {
    $new_piece_id = count($this->pieces);
    $dado_depth = round($this->carcassSheetGood->thickness / 2, 1);

    $this->pieces[] = new CabinetryWoodPiece(
      $new_piece_id,
      "[#$new_piece_id] Cabinet {$this->id} Back Piece",
      $this->backSheetGood->thickness,
      $this->height,
      $this->carcassInnerWidth + 2 * $dado_depth,
      $this->backSheetGood,
      ''
    );
  }

  /**
   * Generate the nailer strips for this cabinet.
   */
  protected function generateNailers() {
    for ($nailerid = 0; $nailerid < 2; $nailerid++) {
      $new_piece_id = count($this->pieces);
      $this->pieces[] = new CabinetryWoodPiece(
        $new_piece_id,
        "[#$new_piece_id] Cabinet {$this->id} Nailer",
        $this->carcassSheetGood->thickness,
        $this->carcassInnerWidth,
        75,
        $this->carcassSheetGood,
        ''
      );
    }
  }

  /**
   * Generate the CabinetryWoodPiece shelves for this cabinet.
   */
  protected function generateShelfPieces() {
    for ($shelfid = 0; $shelfid < $this->numShelves; $shelfid++) {
      $new_piece_id = count($this->pieces);
      $this->pieces[] = new CabinetryWoodPiece(
        $new_piece_id,
        "[#$new_piece_id] Cabinet {$this->id} Shelf",
        $this->carcassSheetGood->thickness,
        $this->carcassInnerWidth - 6.0,
        $this->depth - 6.0,
        $this->carcassSheetGood,
        ''
      );
      $this->addBanding($this->carcassSheetGood->label, $this->carcassSheetGood->thickness, $this->carcassInnerWidth - 6.0);
    }
  }

  /**
   * Generate a side panel for the caracass.
   *
   * @param string $side_label
   *   The label string to identify the side (Left, Right).
   */
  protected function generateSidePiece($side_label) {
    $new_piece_id = count($this->pieces);
    $dado_depth = round($this->carcassSheetGood->thickness / 2, 1);

    $this->pieces[] = new CabinetryWoodPiece(
      $new_piece_id,
      "[#$new_piece_id] Cabinet {$this->id} $side_label Side Piece",
      $this->carcassSheetGood->thickness,
      $this->height,
      $this->depth,
      $this->carcassSheetGood,
      "Cut {$dado_depth}mm Deep Dado {$this->carcassSheetGood->thickness}mm from long side on one side."
    );
    $this->addBanding($this->carcassSheetGood->label, $this->carcassSheetGood->thickness, $this->height);
  }

  /**
   * Generate a top or bottom panel for the caracass.
   *
   * @param string $side_label
   *   The label string to identify the side (Top, Bottom).
   */
  protected function generateTopBottomPiece($side_label) {
    $new_piece_id = count($this->pieces);
    $this->pieces[] = new CabinetryWoodPiece(
      $new_piece_id,
      "[#$new_piece_id] Cabinet {$this->id} $side_label Piece",
      $this->carcassSheetGood->thickness,
      $this->carcassInnerWidth,
      $this->depth,
      $this->carcassSheetGood,
      ''
    );
    $this->addBanding($this->carcassSheetGood->label, $this->carcassSheetGood->thickness, $this->carcassInnerWidth);
  }

}
