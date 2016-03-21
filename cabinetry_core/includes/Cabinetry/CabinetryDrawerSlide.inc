<?php
/**
 * @file
 * Provides a object to serve as hardware items within a cabinet project.
 */

/**
 * A generic object to serve as hardware item in a cabinetry project.
 */
class CabinetryDrawerSlide extends CabinetryHardwareItem {

  /**
   * The clearance from .
   *
   * @var float
   */
  public $carcassClearance = 0.00;

  /**
   * The lenth of the slide, in millimeters.
   *
   * @var float
   */
  public $length = 0.00;


  /**
   * Constructor.
   *
   * @param string $name
   *   The name of this hardware item.
   * @param float $price
   *   The price of one of these items.
   * @param float $length
   *   The length of the slide.
   * @param float $carcass_clearance
   *   The horizontal carcass clearance for each slide.
   */
  public function __construct($name, $price, $length, $carcass_clearance) {
    parent::__construct($name, $price);
    $this->length = (float) $length;
    $this->carcassClearance = (float) $carcass_clearance;
  }

}
