<?php

/**
 * @file
 * Provides a generic object to serve as components within a cabinet project.
 */

/**
 * A generic object to serve as components within a cabinetry project.
 */
class CabinetryWainscotingStyle {

  /**
   * The outer width (x) of the wall section, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The outer height (y) of the wall section, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The number of panels in this wall section.
   *
   * @var int
   */
  public $numPanels = 0;

  /**
   * The thickness of the rail/stiles, in millimeters.
   *
   * @var float
   */
  public $thickness = 0;

  /**
   * Constructor.
   */
  public function __construct($width, $height, $thickness, $num_panels) {
    $this->width = $width;
    $this->height = $height;
    $this->thickness = $thickness;
    $this->numPanels = $num_panels;
  }

}
