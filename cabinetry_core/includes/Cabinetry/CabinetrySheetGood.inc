<?php
/**
 * @file
 * Provides a generic object for a sheet good in a cabinetry project.
 */

/**
 * A generic object to serve as a sheet good in a cabinetry project.
 */
class CabinetrySheetGood {
  /**
   * A label describing the piece and its role.
   *
   * @var string
   */
  public $label = NULL;

  /**
   * The thickness (z) of the piece, in mm.
   *
   * @var float
   */
  public $thickness = 0.0;

  /**
   * The width (x) of the piece, in mm.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The height (y) of the piece, in mm.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * Constructor.
   */
  public function __construct($label, $thickness, $width, $height) {
    $this->label = $label;
    $this->thickness = $thickness;
    $this->width = $width;
    $this->height = $height;
  }

}
