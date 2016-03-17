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
  public $name = NULL;

  /**
   * The approximate price of the hardware item, in dollars.
   *
   * @var float
   */
  public $price = 0.00;

  /**
   * Constructor.
   *
   * @param string $name
   *   The name of this hardware item.
   * @param float $price
   *   The price of one of these items.
   */
  public function __construct($name, $price) {
    $this->name = $name;
    $this->price = $price;
  }

}
