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
   * The list of pieces to sort into sheets.
   *
   * @var array
   */
  public $pieces = 0.0;

  /**
   * Does this sheet have grain that should be vertical?
   *
   * @var boolean
   */
  public $has_grain = TRUE;


  /**
   * Constructor.
   *
   * @param float $width
   *   The width of this sheet good, in millimeters.
   * @param float $height
   *   The height of this sheet good, in millimeters.
   * @param boolean $grain
   *   Should the piece orientations (grain parallel to width) be preserved?
   * @param array $pieces
   *   An associative array of pieces to fit into the sheet space. Each item
   *   must have 'width', 'height' and 'label' elements.
   */
  public function __construct($width, $height, $pieces, $grain) {
    $this->width = $width;
    $this->height = $height;
    $this->grain = $grain;
    $this->pieces = $pieces;
  }

}
