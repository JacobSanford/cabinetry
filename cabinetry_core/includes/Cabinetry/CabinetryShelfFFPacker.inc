<?php
/**
 * @file
 * Provides an object for packing a sheet good from a piece list.
 */

/**
 * A rudimentary object for packing a 2D sheet good from a list of pieces.
 *
 * The sheet layout is calculated with a modified 2D bin packing algorithm,
 * based upon https://github.com/juj/RectangleBinPack as an example. The base
 * algorithm used is the SHELF-FF, with a modification that considers cabinet
 * doors look best with a vertical grain orientation.
 *
 * The algorithm isn't 100% efficient with intent of producing layouts that
 * ease the burden of cutting the sheets with a track (circular) saw. A 'shelf'
 * layout provides straight lines that are easy to break down quickly, while
 * minimizing human error. This is implemented by pre-sorting the pieces from
 * largest to smallest before packing the shelves.
 *
 * Those planning to adapt this to set up a cut list (and toolpath) for a CNC
 * machine: CNC changes the above layout consideration significantly. Guillotine
 * based algorithms are significantly more efficient and should be considered,
 * since there is limited human involvement. If you do adapt this, please let
 * me know / contribute!
 */
class CabinetryShelfFFPacker extends CabinetrySheetGoodPacker {

  /**
   * An array of CabinetryShelfFFShelf objects.
   *
   * @var array
   */
  public $shelves = array();

  /**
   * Constructor.
   *
   * @param float $width
   *   The width of this sheet good, in millimeters.
   * @param float $height
   *   The height of this sheet good, in millimeters.
   * @param array $pieces
   *   An associative array of pieces to fit into the sheet space. Each item
   *   must have 'width', 'height' and 'label' elements.
   * @param float $cut_width
   *   The blade cut width to allow for when packing the sheet.
   * @param bool $has_grain
   *   Should the piece orientations (grain parallel to width) be preserved?
   */
  public function __construct($width, $height, $pieces, $cut_width, $has_grain) {
    parent::__construct($width, $height, $pieces, $cut_width, $has_grain);
    $this->pieces = $this->sortPiecesByHeightAndWidth($this->pieces);
  }

  /**
   * Pack the pieces into shelves, then shelves into sheets.
   */
  public function pack() {
    $this->packShelves();
    $this->packSheets();
  }

  /**
   * Pack the pieces into shelves.
   */
  public function packShelves() {
    $sheet_set = new CabinetryShelfFFShelfSet(
      $this->width,
      $this->cutWidth,
      !$this->hasGrain
    );
    foreach ($this->pieces as $piece_index => $piece) {
      $sheet_set->addPiece(
        array(
          'label' => $piece['label'],
          'notes' => $piece['notes'],
          'width' => $piece['width'],
          'height' => $piece['height'],
        )
      );
    }
    $this->shelves = $sheet_set->shelves;
  }

  /**
   * Pack the shelves into sheets.
   */
  public function packSheets() {
    foreach ($this->shelves as $shelf) {
      $shelf->pieces = $this->sortPiecesByHeightAndWidth($shelf->pieces);
      $sheet_found = FALSE;
      foreach ($this->sheets as $sheet_index => $sheet) {
        if ($sheet->shelfFits($shelf)) {
          $sheet_found = TRUE;
          $sheet->addShelf($shelf);
          break;
        }
      }
      if ($sheet_found == FALSE) {
        $this->sheets[] = new CabinetryShelfFFSheet(
          $this->height,
          $this->width,
          $this->cutWidth
        );
        $this->sheets[count($this->sheets) - 1]->addShelf($shelf);
      }
    }
  }

  /**
   * Sort pieces array by height DESC, then width DESC.
   */
  protected function sortPiecesByHeightAndWidth($pieces) {
    $sort = array();
    foreach ($pieces as $k => $v) {
      $sort['height'][$k] = $v['height'];
      $sort['width'][$k] = $v['width'];
    }
    array_multisort(
      $sort['height'],
      SORT_DESC,
      $sort['width'],
      SORT_DESC,
      $pieces
    );
    return $pieces;
  }

}

/**
 * An object providing a set of CabinetryShelfFFShelf shelves.
 */
class CabinetryShelfFFShelfSet {

  /**
   * An array of CabinetryShelfFFShelf objects.
   *
   * @var array
   */
  public $shelves = array();

  /**
   * The width (x) of the shelf set, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * Can shelves rotate items to fit?
   *
   * @var boolean
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
   *   Should the piece orientations (grain parallel to width) be disregarded?
   */
  public function __construct($width, $cut_width, $can_rotate) {
    $this->width = $width;
    $this->canRotate = $can_rotate;
    $this->cutWidth = $cut_width;
  }

  /**
   * Add a piece to the set of shelves.
   */
  public function addPiece($piece) {
    $shelf_found = FALSE;
    foreach ($this->shelves as $shelf_index => $shelf) {
      $piece_fits = $shelf->pieceFits($piece);
      if ($piece_fits != FALSE) {
        $shelf->addPiece($piece, $piece_fits['rotated']);
        $shelf_found = TRUE;
        break;
      }
    }
    if ($shelf_found == FALSE) {
      $this->addShelf($piece);
    }
  }

  /**
   * Add a new shelf to the set of shelves.
   */
  public function addShelf($piece) {
    $this->shelves[] = new CabinetryShelfFFShelf(
      $piece['height'],
      $this->width,
      $this->cutWidth,
      $this->canRotate
    );
    $this->shelves[count($this->shelves) - 1]->addPiece($piece);
  }

}

/**
 * An object providing a sheet packing 'shelf'.
 */
class CabinetryShelfFFShelf {

  /**
   * The width (x) of the shelf, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The height (y) of the shelf, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The amount of the shelf width in use, in millimeters.
   *
   * @var float
   */
  public $used = 0.0;

  /**
   * The available width of the shelf, in millimeters.
   *
   * @var float
   */
  public $remain = 0.0;

  /**
   * Can the shelf rotate items to fit?
   *
   * @var boolean
   */
  public $canRotate = FALSE;

  /**
   * An array of pieces stored in the shelf.
   *
   * @var array
   */
  public $pieces = array();

  /**
   * The blade cut width to consider, in millimeters.
   *
   * @var float
   */
  public $cutWidth = 0.0;


  /**
   * Constructor.
   *
   * @param float $height
   *   The height of this shelf, in millimeters.
   * @param float $width
   *   The width of the shelf, in millimeters.
   * @param float $cut_width
   *   The blade cut width to allow for when packing the sheet.
   * @param bool $can_rotate
   *   Should the piece orientations (grain parallel to width) be disregarded?
   */
  public function __construct($height, $width, $cut_width, $can_rotate) {
    $this->height = $height;
    $this->width = $width;
    $this->remain = $width;
    $this->cutWidth = $cut_width;
    $this->canRotate = $can_rotate;
  }

  /**
   * Add a piece to the shelf.
   */
  public function addPiece($piece, $rotated = FALSE) {
    if ($rotated == TRUE) {
      $width_placeholder = $piece['width'];
      $piece['width'] = $piece['height'];
      $piece['height'] = $width_placeholder;
      $piece['rotated'] = TRUE;
    }
    else {
      $piece['rotated'] = FALSE;
    }

    if ($piece['width'] > $this->width) {
      die('Piece exceeds shelf length');
    }

    $this->pieces[] = $piece;
    $this->setRemainder();
  }

  /**
   * Set the remainder and used properties.
   */
  public function setRemainder() {
    $sum = 0.0;
    foreach ($this->pieces as $piece) {
      $sum += $piece['width'];
    }
    $this->used = $sum + (count($this->pieces) - 1) * $this->cutWidth;
    $this->remain = $this->width - $this->used;
  }

  /**
   * Check if the piece fits in this shelf.
   *
   * A scoring system based on consuming the most shelf height possible is used
   * to determine the best orientation of pieces in the shelf.
   */
  public function pieceFits($piece) {
    if ($piece['height'] > $this->height) {
      return FALSE;
    }

    if ($piece['width'] > $this->remain && $this->canRotate == FALSE) {
      return FALSE;
    }

    // If applicable, check if a rotation of the piece makes it fit.
    if ($this->canRotate == TRUE && $piece['height'] <= $this->remain && $piece['width'] <= $this->height) {
      $rotated_balance = $this->height - $piece['width'];
    }

    // Check if non-rotated fits better than rotated.
    if ($piece['width'] <= $this->remain) {
      if (!isset($rotated_balance) || $this->height - $piece['height'] <= $rotated_balance) {
        return array(
          'balance' => $this->remain - $piece['width'],
          'rotated' => FALSE,
        );
      }
    }

    // If the rotated piece fit, return it.
    if (isset($rotated_balance)) {
      return array(
        'balance' => $rotated_balance,
        'rotated' => TRUE,
      );
    }

    return FALSE;
  }

}

/**
 * An object providing a sheet packing sheet.
 */
class CabinetryShelfFFSheet {

  /**
   * The width (x) of the sheet, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The height (y) of the sheet, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The used height of sheet good by shelves, in millimeters.
   *
   * @var float
   */
  public $used = 0.0;

  /**
   * The unused height of sheet good, in millimeters.
   *
   * @var float
   */
  public $remain = 0.0;

  /**
   * An array of CabinetryShelfFFShelf objects assigned to this sheet.
   *
   * @var array
   */
  public $shelves = array();

  /**
   * The blade cut width to consider, in millimeters.
   *
   * @var float
   */
  public $cutWidth = 0.0;


  /**
   * Constructor.
   *
   * @param float $height
   *   The height of this sheet, in millimeters.
   * @param float $width
   *   The width of the shelf, in millimeters.
   * @param float $cut_width
   *   The blade cut width to allow for when packing the sheet.
   */
  public function __construct($height, $width, $cut_width) {
    $this->height = $height;
    $this->width = $width;
    $this->remain = $height;
    $this->cutWidth = $cut_width;
  }

  /**
   * Add a shelf to the sheet.
   */
  public function addShelf($shelf) {
    $this->shelves[] = $shelf;
    $this->setRemainder();
  }

  /**
   * Set the remainder and used properties.
   */
  public function setRemainder() {
    $sum = 0.0;
    foreach ($this->shelves as $shelf) {
      $sum += $shelf->height;
    }
    $this->used = $sum + (count($this->shelves) - 1) * $this->cutWidth;
    $this->remain = $this->height - $this->used;
  }

  /**
   * Check if the shelf fits in this sheet.
   */
  public function shelfFits($shelf) {
    if ($shelf->height > $this->height) {
      return FALSE;
    }

    if ($shelf->height > $this->remain) {
      return FALSE;
    }

    return TRUE;
  }

}
