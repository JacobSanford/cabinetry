<?php
/**
 * @file
 * Provides a generic object to serve as top element of a cabinet project.
 */

/**
 * A generic object to serve as top element of a cabinet project.
 */
class CabinetProject {
  /**
   * An array of CabinetComponent objects comprising this project.
   *
   * @var array
   */
  public $components = array();

  /**
   * An array of CabinetWoodPiece objects needed to build this project.
   *
   * @var array
   */
  public $pieces = array();

  /**
   * An array of CabinetHardwareItem objects comprising this project.
   *
   * @var array
   */
  public $hardware = array();

  /**
   * An array of CabinetEdgeBanding objects comprising this project.
   *
   * @var array
   */
  public $banding = array();

  /**
   * Constructor.
   */
  public function __construct() {

  }

}
