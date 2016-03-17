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
   * The material of edging to generate.
   *
   * @var object CabinetrySheetGood
   */
  public $material = NULL;

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
   * @param object $material
   *   The edge banding material.
   * @param float $width
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
