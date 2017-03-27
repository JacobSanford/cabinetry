<?php

namespace Drupal\cabinetry_core\Cabinetry;

use Drupal\cabinetry_core\WoodPiece;

/**
 * A generic object to serve as a solid wood species in a cabinetry project.
 */
class SolidWood extends WoodPiece {

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
   * @param float $width
   *   The length required, in millimeters.
   * @param float $price
   *   The price of a boardfoot of this species, in dollars.
   */
  public function __construct($material, $thickness, $height, $width, $price) {
    $this->material = $material;
    $this->thickness = $thickness;
    $this->height = $height;
    $this->width = $width;
    $this->price = $price;
  }

}
