<?php

namespace Drupal\cabinetry_core\Cabinetry\Packer\ShelfFF;

use Drupal\cabinetry_core\Cabinetry\Packer\ShelfFF\ShelfFFShelf;
use Drupal\cabinetry_core\CabinetryPartInterface;

/**
 * An object providing a set of CabinetryShelfFFShelf shelves.
 */
class ShelfFFShelfSet {

  /**
   * The shelves in this shelf set.
   *
   * @var \Drupal\cabinetry_core\Cabinetry\Packer\ShelfFF\ShelfFFShelf[]
   */
  public $shelves = [];

  /**
   * The width (x) of the shelf set, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * Can shelves rotate items to fit?
   *
   * @var bool
   */
  public $canRotate = FALSE;

  /**
   * The blade cut width to consider, in millimeters.
   *
   * @var float
   */
  public $cutWidth = 0.0;

  /**
   * Constructor.
   *
   * @param float $width
   *   The width of the shelf, in millimeters.
   * @param float $cut_width
   *   The blade cut width to allow for when packing the sheet.
   * @param bool $can_rotate
   *   Should the part orientations (grain parallel to width) be disregarded?
   */
  public function __construct($width, $cut_width, $can_rotate) {
    $this->width = $width;
    $this->canRotate = $can_rotate;
    $this->cutWidth = $cut_width;
  }

  /**
   * Add a part to the set of shelves.
   *
   * @param \Drupal\cabinetry_core\CabinetryPartInterface $part
   *   The part to add to the shelf.
   */
  public function addPart(CabinetryPartInterface $part) {
    $shelf_found = FALSE;
    foreach ($this->shelves as $shelf_index => $shelf) {
      $part_fits = $shelf->partFits($part);
      if ($part_fits != FALSE) {
        $shelf->addPart($part, $part_fits['rotated']);
        $shelf_found = TRUE;
        break;
      }
    }
    if ($shelf_found == FALSE) {
      $this->addShelf($part);
    }
  }

  /**
   * Add a part to a new shelf, and add the shelf to the set of shelves.
   *
   * @param \Drupal\cabinetry_core\CabinetryPartInterface $part
   *   The part to add to the shelf.
   */
  public function addShelf(CabinetryPartInterface $part) {
    $this->shelves[] = new ShelfFFShelf(
      $part->getHeight(),
      $this->width,
      $this->cutWidth,
      $this->canRotate
    );
    $this->shelves[count($this->shelves) - 1]->addPart($part);
  }

}
