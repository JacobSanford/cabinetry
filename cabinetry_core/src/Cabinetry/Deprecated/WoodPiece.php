<?php

namespace Drupal\cabinetry_core\Cabinetry;

/**
 * A generic object to serve as a sheet good in a cabinetry project.
 */
class WoodPiece {

  /**
   * The height (y) of the wood piece, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * A label for this piece, typically a descriptive string.
   *
   * @var string
   */
  public $material = NULL;

  /**
   * Should the grain orientation of this item be preserved?
   *
   * @var bool
   */
  public $preserveGrain = TRUE;

  /**
   * The approximate price of wood piece, in dollars.
   *
   * @var float
   */
  public $price = 0.00;

  /**
   * The thickness (z) of the wood piece, in millimeters.
   *
   * @var float
   */
  public $thickness = 0.0;

  /**
   * The width (x) of the wood piece, in millimeters.
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
