<?php
/**
 * @file
 * Provides a generic object to serve as top element of a cabinetry project.
 */

/**
 * A generic object to serve as top element of a cabinetry project.
 */
class CabinetryProject {
  /**
   * An array of CabinetryComponent objects comprising this project.
   *
   * @var array
   */
  public $components = array();

  /**
   * An array of CabinetryWoodPiece objects needed to build this project.
   *
   * @var array
   */
  public $pieces = array();

  /**
   * An array of CabinetryHardwareItem objects comprising this project.
   *
   * @var array
   */
  public $hardware = array();

  /**
   * Constructor.
   */
  public function __construct() {

  }

  public function addComponent($component) {
    $this->components[] = $component;
    $this->addPieces($component->pieces);
  }

  public function addPieces($pieces_array) {
    $this->pieces = array_merge($this->pieces, $pieces_array);
  }

}
