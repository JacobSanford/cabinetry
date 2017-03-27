<?php

namespace Drupal\cabinetry_core\Cabinetry\Packer\ShelfFF;

use Drupal\cabinetry_core\Cabinetry\Packer\SheetGoodPacker;
use Drupal\cabinetry_core\Cabinetry\Packer\ShelfFF\ShelfFFSheet;
use Drupal\cabinetry_core\Cabinetry\Packer\ShelfFF\ShelfFFShelfSet;
use Drupal\cabinetry_core\CabinetryPartInterface;
use Drupal\node\NodeInterface;
use Drupal\taxonomy\TermInterface;

/**
 * A rudimentary object for packing a 2D sheet good from a list of parts.
 *
 * The sheet layout is calculated with a modified 2D bin packing algorithm,
 * based upon https://github.com/juj/RectangleBinPack as an example. The base
 * algorithm used is the SHELF-FF, with a modification that considers cabinet
 * doors look best with a vertical grain orientation.
 *
 * The algorithm isn't 100% efficient with intent of producing layouts that
 * ease the burden of cutting the sheets with a track (circular) saw. A 'shelf'
 * layout provides straight lines that are easy to break down quickly, while
 * minimizing human error. This is implemented by pre-sorting the parts from
 * largest to smallest before packing the shelves.
 *
 * Those planning to adapt this to set up a cut list (and toolpath) for a CNC
 * machine: CNC changes the above layout consideration significantly. Guillotine
 * based algorithms are significantly more efficient and should be considered,
 * since there is limited human involvement. If you do adapt this, please let
 * me know / contribute!
 */
class ShelfFFPacker extends SheetGoodPacker {

  /**
   * An array of CabinetryShelfFFShelf objects.
   *
   * @var \Drupal\cabinetry_core\Cabinetry\Packer\ShelfFF\ShelfFFShelf[]
   */
  public $shelves = [];

  /**
   * Constructor.
   *
   * @param \Drupal\node\NodeInterface $project
   *   The project node to pack.
   * @param \Drupal\taxonomy\TermInterface $material
   *   The material type of this sheet.
   * @param array $parts
   *   Array of \Drupal\cabinetry_core\CabinetryPartInterface objects.
   */
  protected function __construct(NodeInterface $project, TermInterface $material, array $parts) {
    parent::__construct($project, $material, $parts);
    $this->sortPartsByHeightAndWidth();
    $this->pack();
  }

  /**
   * Pack the parts into shelves, then shelves into sheets.
   */
  public function pack() {
    $this->packShelves();
    $this->packSheets();
  }

  /**
   * Pack the shelves into sheets.
   */
  public function packSheets() {
    foreach ($this->shelves as $shelf) {
      /* @var $shelf \Drupal\cabinetry_core\Cabinetry\Packer\ShelfFF\ShelfFFShelf */
      $shelf->sortPartsByHeightAndWidth();
      $sheet_found = FALSE;
      foreach ($this->sheets as $sheet_index => $sheet) {
        /* @var $sheet \Drupal\cabinetry_core\Cabinetry\Packer\ShelfFF\ShelfFFSheet */
        if ($sheet->shelfFits($shelf)) {
          $sheet_found = TRUE;
          $sheet->addShelf($shelf);
          break;
        }
      }
      if ($sheet_found == FALSE) {
        $this->sheets[] = new ShelfFFSheet(
          $this->height,
          $this->width,
          $this->cutWidth
        );
        $this->sheets[count($this->sheets) - 1]->addShelf($shelf);
      }
    }
  }

  /**
   * Pack the parts into shelves.
   */
  public function packShelves() {
    $sheet_set = new ShelfFFShelfSet(
      $this->width,
      $this->cutWidth,
      !$this->hasGrain
    );
    foreach ($this->parts as $part_index => $part) {
      $sheet_set->addPart($part);
    }
    $this->shelves = $sheet_set->shelves;
  }

  /**
   * Sort parts array by height DESC, then width DESC.
   */
  protected function sortPartsByHeightAndWidth() {
    $sort = [];
    foreach ($this->parts as $k => $v) {
      /* @var $v \Drupal\cabinetry_core\CabinetryPartInterface */
      $sort['height'][$k] = $v->getHeight();
      $sort['width'][$k] = $v->getWidth();
    }
    array_multisort(
      $sort['height'],
      SORT_DESC,
      $sort['width'],
      SORT_DESC,
      $this->parts
    );
  }

}
