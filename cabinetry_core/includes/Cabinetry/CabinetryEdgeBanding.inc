<?php
/**
 * @file
 * Provides a object to serve as edge banding type within a cabinetry project.
 */

/**
 * A generic object to serve as edge banding type in a cabinetry project.
 */
class CabinetryEdgeBanding {
  /**
   * The material of the item.
   *
   * @var string
   */
  public $material = '';

  /**
   * The width of the banding, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The length of banding, in millimeters.
   *
   * @var float
   */
  public $length = 0.0;

  /**
   * Constructor.
   *
   * @param string $material
   *   The edge banding material.
   * @param string $width
   *   The width of the sheet good the banding will be applied to, in
   *   millimeters.
   */
  public function __construct($material, $width) {
    $this->material = $material;
    $this->width = $width;
  }

  /**
   * Add additional length to this object.
   *
   * @param float $length
   *   The amount to add, in millimeters.
   */
  public function add($length) {
    $this->length += $length;
  }

}
