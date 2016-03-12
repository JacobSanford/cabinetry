<?php
/**
 * @file
 * Provides a generic object for a solid wood part in a cabinetry project.
 */

/**
 * A generic object to serve as a solid wood part in a cabinetry project.
 */
class CabinetryWoodPart {

  /**
   * A label describing the part and its role.
   *
   * @var string
   */
  public $label = NULL;

  /**
   * The thickness (z) of the part, in millimeters.
   *
   * @var float
   */
  public $thickness = 0.0;

  /**
   * The width (x) of the part, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The height (y) of the part, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The source type of the part.
   *
   * @var object
   */
  public $source = NULL;

  /**
   * Any special notes or comments related to this part.
   *
   * @var string
   */
  public $notes = NULL;


  /**
   * Constructor.
   *
   * @param string $label
   *   A label to later be printed for this part. Typically this describes the
   *   component the part makes up, as well as the role of the part in the
   *   component.
   * @param float $thickness
   *   The thickness of this part, in millimeters.
   * @param float $width
   *   The width of this part, in millimeters.
   * @param float $height
   *   The height of this part, in millimeters.
   * @param object $source
   *   The source material this part is made out of. Typically this is type
   *   CabinetrySheetGood or CabinetrySolidWood.
   * @param string $notes
   *   Any special notes or comments related to this part, including cut
   *   instructions or handling directives. This will also be printed on
   *   the label.
   */
  public function __construct($label, $thickness, $width, $height, $source, $notes) {
    $this->label = $label;
    $this->thickness = $thickness;
    $this->width = $width;
    $this->height = $height;
    $this->source = $source;
    $this->notes = $notes;
  }

}
