<?php
/**
 * @file
 * Provides a object to serve as hardware items within a cabinet project.
 */

/**
 * A generic object to serve as hardware item in a cabinetry project.
 */
class CabinetryHardwareItem {

  /**
   * The name of the item.
   *
   * @var string
   */
  public $name = 0.0;

  /**
   * The number of this item required.
   *
   * @var integer
   */
  public $amount = 0;


  /**
   * Constructor.
   */
  public function __construct() {
    // pass.
  }

}
