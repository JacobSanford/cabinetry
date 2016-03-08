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
   * The carcass sheet good.
   *
   * @var object CabinetrySheetGood
   */
  public $carcassSheetGood = NULL;

  /**
   * The inner width dim, in mm.
   *
   * @var float
   */
  public $carcassInnerWidth = 0.0;

  /**
   * The number of shelves.
   *
   * @var integer
   */
  public $numShelves = 0;

  /**
   * The division ratios.
   *
   * @var integer
   */
  public $divisions = array();

  /**
   * Constructor.
   */
  public function __construct($id) {
    parent::__construct($id);
  }

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

  protected function setCarcassSheetGood($sheet_good) {
    $this->carcassSheetGood = $sheet_good;
  }

  protected function setBackSheetGood($sheet_good) {
    $this->backSheetGood = $sheet_good;
  }

  protected function setNumShelves($num_shelves) {
    $this->numShelves = $num_shelves;
  }

  protected function setNumDivisions($divisions_array) {
    $this->divisions = $divisions_array;
  }

  protected function setInnerWidth() {
    $this->carcassInnerWidth = $this->width - (2 * $this->carcassSheetGood->thickness);
  }

  protected function generatePieces() {
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
      $this->addBanding($this->carcassSheetGood->thickness, $this->carcassInnerWidth - 6.0);
    }
  }

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
    $this->addBanding($this->carcassSheetGood->thickness, $this->height);
  }

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
    $this->addBanding($this->carcassSheetGood->thickness, $this->carcassInnerWidth);
  }

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

  protected function generateDividerPieces() {
    for ($divider_id = 0; $divider_id < count($this->divisions) - 1; $divider_id++) {
      $this->generateTopBottomPiece("Section $divider_id Divider");
    }
  }


  protected function addBanding($width, $amount) {
    if (!array_key_exists($width, $this->banding)) {
      $this->banding[$this->carcassSheetGood->label] = $amount;
    }
    else {
      $this->banding[$this->carcassSheetGood->label] += $amount;
    }
  }

}
