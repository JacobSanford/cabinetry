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
   * A numeric id to serve as a UUID within the project.
   *
   * @var int
   */
  public $id = NULL;

  /**
   * A label describing the piece and its role.
   *
   * @var string
   */
  public $label = NULL;

  /**
   * The thickness (z) of the piece, in mm.
   *
   * @var float
   */
  public $thickness = 0.0;

  /**
   * The width (x) of the piece, in mm.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The height (y) of the piece, in mm.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The material type of the piece.
   *
   * @var string
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
