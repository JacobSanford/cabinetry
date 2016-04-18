<?php

/**
 * @file
 * Provides a generic object to serve as a wainscoting project.
 */

/**
 * A generic object to serve as wainscoting project.
 */
class CabinetryWainscotingProject extends CabinetryProject {

  /**
   * The router bit to use for rail/stile frames.
   *
   * @var object CabinetryToolItem
   */
  public $frameRouterBit = NULL;

  /**
   * The length of the solid stock to use.
   *
   * @var float
   */
  public $solidStockLength = 0.0;

  /**
   * The width of the cut blade.
   *
   * @var float
   */
  public $bladeCutWidth = 0.0;

}
