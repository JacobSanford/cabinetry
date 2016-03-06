<?php
/**
 * @file
 * Provides a object to serve as edge banding type within a cabinet project.
 */

/**
 * A generic object to serve as edge banding type in a cabinet project.
 */
class CabinetEdgeBanding {
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
