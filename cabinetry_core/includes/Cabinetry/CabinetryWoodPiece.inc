<?php
/**
 * @file
 * Provides a generic object for a sheet good in a cabinetry project.
 */

/**
 * A generic object to serve as a sheet good in a cabinetry project.
 */
class CabinetryWoodPiece {

  /**
   * A label for this piece, typically a descriptive string.
   *
   * @var string
   */
  public $material = NULL;

  /**
   * The thickness (z) of the sheet good, in millimeters.
   *
   * @var float
   */
  public $thickness = 0.0;

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
   * The approximate price of the sheet good, in dollars.
   *
   * @var float
   */
  public $price = 0.00;

  /**
   * Constructor.
   */
  public function __construct() {

  }

}
