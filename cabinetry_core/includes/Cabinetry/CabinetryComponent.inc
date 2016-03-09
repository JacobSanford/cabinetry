<?php
/**
 * @file
 * Provides a generic object to serve as components within a cabinet project.
 */

/**
 * A generic object to serve as components within a cabinetry project.
 */
class CabinetryComponent {
  /**
   * An optional ID given to this component.
   *
   * @var string
   */
  public $id = NULL;

  /**
   * The outer width (x) of the component, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The outer height (y) of the component, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The depth (z) of the component, in millimeters.
   *
   * @var float
   */
  public $depth = 0.0;

  /**
   * An array of CabinetHardwareItem objects comprising this component.
   *
   * @var array
   */
  public $hardware = array();

  /**
   * An array of CabinetryWoodPart objects comprising this component.
   *
   * @var object CabinetryWoodPart
   */
  public $parts = array();

  /**
   * Constructor.
   *
   * @param string $id
   *   An id, typically an integer to assign to this component.
   */
  public function __construct($id) {
    $this->id = $id;
  }

  /**
   * Set the component width.
   *
   * @param float $width
   *   The width of this cabinet component, in millimeters.
   */
  public function setWidth($width) {
    $this->width = (float) $width;
  }

  /**
   * Set the component height.
   *
   * @param float $height
   *   The height of this cabinet component, in millimeters.
   */
  public function setHeight($height) {
    $this->height = (float) $height;
  }

  /**
   * Set the component depth.
   *
   * @param float $depth
   *   The depth of this cabinet component, in millimeters.
   */
  public function setDepth($depth) {
    $this->depth = (float) $depth;
  }

}
