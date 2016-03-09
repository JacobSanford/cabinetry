<?php
/**
 * @file
 * Provides a generic object for a solid wood piece in a cabinetry project.
 */

/**
 * A generic object to serve as a solid wood piece in a cabinetry project.
 */
class CabinetryWoodPiece {
  /**
   * An ID given to this component.
   *
   * @var string
   */
  public $id = NULL;

  /**
   * A label describing the piece and its role.
   *
   * @var string
   */
  public $label = NULL;

  /**
   * The thickness (z) of the piece, in millimeters.
   *
   * @var float
   */
  public $thickness = 0.0;

  /**
   * The width (x) of the piece, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The height (y) of the piece, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The material type of the piece.
   *
   * @var object
   */
  public $material = NULL;

  /**
   * Any special notes or comments related to this piece.
   *
   * @var string
   */
  public $notes = NULL;

  /**
   * Constructor.
   *
   * @param string $id
   *   An id, typically an integer to assign to this component.
   * @param string $label
   *   A label to later be printed for this piece. Typically this describes the
   *   component the piece makes up, as well as the role of the piece in the
   *   component.
   * @param float $thickness
   *   The thickness of this piece, in millimeters.
   * @param float $width
   *   The width of this piece, in millimeters.
   * @param float $height
   *   The height of this piece, in millimeters.
   * @param object $material
   *   The material this piece is made out of. Typically this is type
   *   CabinetrySheetGood or CabinetrySolidWood.
   * @param string $notes
   *   Any special notes or comments related to this piece, including cut
   *   instructions or handling directives. This will also be printed on
   *   the label.
   */
  public function __construct($id, $label, $thickness, $width, $height, $material, $notes) {
    $this->id = $id;
    $this->label = $label;
    $this->thickness = $thickness;
    $this->width = $width;
    $this->height = $height;
    $this->material = $material;
    $this->notes = $notes;
  }

}
