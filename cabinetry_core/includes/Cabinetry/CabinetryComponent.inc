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
   * The outer width (x) of the component, in mm.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The outer height (y) of the component, in mm.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The depth (z) of the component, in mm.
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
   * An array of CabinetryWoodPiece objects comprising this component.
   *
   * @var object CabinetryWoodPiece
   */
  public $pieces = array();

  /**
   * An array of CabinetEdgeBanding objects comprising this component.
   *
   * @var array
   */
  public $banding = array();

  /**
   * Constructor.
   */
  public function __construct($id) {
    $this->id = $id;
  }

  /**
   * Set the component width.
   */
  public function setWidth($width) {
    $this->width = (float) $width;
  }

  /**
   * Set the component height.
   */
  public function setHeight($height) {
    $this->height = (float) $height;
  }

  /**
   * Set the component depth.
   */
  public function setDepth($depth) {
    $this->depth = (float) $depth;
  }

}
