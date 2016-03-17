<?php
/**
 * @file
 * Provides a generic object for a sheet good in a cabinetry project.
 */

/**
 * A generic object to serve as a sheet good in a cabinetry project.
 */
class CabinetrySheetGood extends CabinetryWoodPiece {

  /**
   * Should the grain orientation of this item be preserved.
   *
   * @var bool
   */
  public $preserveGrain = TRUE;

  /**
   * Constructor.
   *
   * @param string $material
   *   The material of this sheet good, typically a descriptive string
   *   containing the wood species, thickness and veneers.
   * @param float $thickness
   *   The thickness of this sheet good, in millimeters.
   * @param float $width
   *   The width of this sheet good, in millimeters.
   * @param float $height
   *   The height of this sheet good, in millimeters.
   * @param float $price
   *   This sheet good's cost.
   * @param bool $preserve_grain
   *   Should the grain orientation of this item be preserved?
   */
  public function __construct($material, $thickness, $width, $height, $price, $preserve_grain) {
    $this->material = $material;
    $this->thickness = $thickness;
    $this->width = $width;
    $this->height = $height;
    $this->price = $price;
    $this->preserveGrain = $preserve_grain;
  }

}
