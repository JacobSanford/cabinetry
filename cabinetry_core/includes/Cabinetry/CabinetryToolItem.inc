<?php
/**
 * @file
 * Provides a generic object for a cutting tool.
 */

/**
 * A generic object to serve as a cutting tool.
 */
class CabinetryToolItem {

  /**
   * A label for this tool.
   *
   * @var string
   */
  public $name = NULL;

  /**
   * The cut depth of the tool, in millimeters.
   *
   * @var float
   */
  public $cutDepth = 0.0;

  /**
   * The cut width of the tool, in millimeters.
   *
   * @var float
   */
  public $cutWidth = 0.0;


  /**
   * Constructor.
   *
   * @param string $name
   *   The name of this tool item.
   * @param float $cut_depth
   *   The cut depth of this tool, in millimeters.
   * @param float $cut_width
   *   The cut width of this tool, in millimeters.
   */
  public function __construct($name, $cut_depth, $cut_width) {
    $this->name = $name;
    $this->cutDepth = $cut_depth;
    $this->cutWidth = $cut_width;
  }

}
