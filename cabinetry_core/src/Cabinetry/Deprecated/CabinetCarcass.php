<?php

namespace Drupal\cabinetry_core\Cabinetry;

/**
 * A generic object to serve as cabinet carcass in a cabinetry project.
 */
class CabinetCarcass {

  /**
   * The outer height (y) of the cabinet carcass in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The main carcass material, type SheetGood.
   *
   * @var object
   */
  public $carcassMaterial = NULL;

  /**
   * The carcass back material, type SheetGood.
   *
   * @var object
   */
  public $carcassBackMaterial = NULL;

  /**
   * The depth (z) of the cabinet carcass, in millimeters.
   *
   * @var float
   */
  public $depth = 0.0;

  /**
   * The outer width (x) of the cabinet carcass, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * Constructor.
   */
  public function __construct() {

  }

}
