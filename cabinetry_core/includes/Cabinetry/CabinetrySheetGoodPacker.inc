<?php
/**
 * @file
 * Provides a generic object for packing a sheet good from a piece list.
 */

/**
 * A generic object for packing a sheet good from a piece list.
 */
class CabinetrySheetGoodPacker {

  /**
   * The width (x) of the sheet good, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The height (y) of the sheet good, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * A list of pieces to sort into sheets.
   *
   * @var array
   */
  public $pieces = array();

  /**
   * Does this sheet have grain that should be vertical?
   *
   * @var boolean
   */
  public $hasGrain = TRUE;

  /**
   * The blade cut width to allow for, in millimeters.
   *
   * @var float
   */
  public $cutWidth = 0.0;

  /**
   * A list of sheets generated by the packing.
   *
   * @var array
   */
  public $sheets = array();

  /**
   * Constructor.
   *
   * @param float $width
   *   The width of this sheet good, in millimeters.
   * @param float $height
   *   The height of this sheet good, in millimeters.
   * @param array $pieces
   *   An associative array of pieces to fit into the sheet space. Each item
   *   must have 'width', 'height' and 'label' elements.
   * @param float $cut_width
   *   The blade cut width to allow for when packing the sheet.
   * @param bool $has_grain
   *   Should the piece orientations (grain parallel to width) be preserved?
   */
  public function __construct($width, $height, $pieces, $cut_width, $has_grain) {
    $this->width = $width;
    $this->height = $height;
    $this->hasGrain = $has_grain;
    $this->cutWidth = $cut_width;
    $this->pieces = $pieces;
  }

}
