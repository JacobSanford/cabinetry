<?php
/**
 * @file
 * Provides a generic object for a solid wood species in a cabinetry project.
 */

/**
 * A generic object to serve as a solid wood species in a cabinetry project.
 */
class CabinetrySolidWood {
  /**
   * A label for this species, typically a descriptive string.
   *
   * @var string
   */
  public $label = NULL;

  /**
   * The thickness (z) of the species, in millimeters.
   *
   * @var float
   */
  public $thickness = 0.0;

  /**
   * The width (x) of the species, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The height (y) of the species, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * Constructor.
   *
   * @param string $label
   *   A label for this species, typically a descriptive string containing
   *   the material, thickness and veneers.
   * @param float $thickness
   *   The thickness of this species, in millimeters.
   * @param float $width
   *   The width of this species, in millimeters.
   * @param float $height
   *   The height of this species, in millimeters.
   */
  public function __construct($label, $thickness, $width, $height) {
    $this->label = $label;
    $this->thickness = $thickness;
    $this->width = $width;
    $this->height = $height;
  }
}
