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
   * The width of the banding, in mm.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The length of banding, in mm.
   *
   * @var float
   */
  public $length = 0.0;

  /**
   * Constructor.
   */
  public function __construct() {

  }

}
