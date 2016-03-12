<?php
/**
 * @file
 * Provides a generic object for a solid wood species in a cabinetry project.
 */

/**
 * A generic object to serve as a solid wood species in a cabinetry project.
 */
class CabinetrySolidWood extends CabinetryWoodPiece {

  /**
   * The length required, in millimeters.
   *
   * @var float
   */
  public $length = 0.0;


  /**
   * Constructor.
   *
   * @param string $material
   *   A label for this species, typically a descriptive string containing
   *   the material, thickness and veneers.
   * @param float $thickness
   *   The thickness of this species, in millimeters.
   * @param float $height
   *   The height of this species, in millimeters.
   * @param float $length
   *   The length required, in millimeters.
   */
  public function __construct($material, $thickness, $height, $length) {
    $this->material = $material;
    $this->thickness = $thickness;
    $this->height = $height;
    $this->length = $length;
  }

}
