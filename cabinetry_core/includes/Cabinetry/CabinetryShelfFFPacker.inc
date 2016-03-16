<?php
/**
 * @file
 * Provides a generic object for packing a sheet good from a piece list.
 */

/**
 * A generic object for packing a sheet good from a piece list.
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
   * @param bool $has_grain
   *   Should the piece orientations (grain parallel to width) be preserved?
   */
  public function __construct($width, $height, $pieces, $has_grain) {
    parent::__construct($width, $height, $pieces, $has_grain);

    // TODO : This is key here. Tell why later.
    $this->sortPiecesByHeightAndWidth();
  }

  /**
   * Pack the Sheets.
   */
  public function pack() {
    $sheet_set = new CabinetryShelfFFShelfSet(
      $this->width,
      $this->hasGrain,
      4.0
    );
    foreach ($this->pieces as $piece_index => $piece) {
      foreach ($piece['items'] as $item) {
        $sheet_set->addPiece(
          array(
            'label' => $item['label'],
            'notes' => $item['notes'],
            'width' => $piece['width'],
            'height' => $piece['height'],
          )
        );
      }
    }
    $this->shelves = $sheet_set->shelves;
    $this->packSheets();
  }

  /**
   * Pack the sheet array.
   */
  public function packSheets() {
    foreach ($this->shelves as $shelf) {
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
          4.0
        );
        $this->sheets[count($this->sheets) - 1]->addShelf($shelf);
      }
    }
  }

  /**
   * Sort pieces array by height first, then width.
   */
  protected function sortPiecesByHeightAndWidth() {
    $sort = array();
    foreach ($this->pieces as $k => $v) {
      $sort['height'][$k] = $v['height'];
      $sort['width'][$k] = $v['width'];
    }
    array_multisort($sort['height'], SORT_DESC, $sort['width'], SORT_DESC, $this->pieces);
  }

}


class CabinetryShelfFFShelfSet {

  /**
   * The shelves in the set.
   *
   * @var float
   */
  public $shelves = array();

  /**
   * The width (x) of the sheet set, in millimeters.
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
   * The cut width to allow for, in millimeters.
   *
   * @var boolean
   */
  public $cutWidth = FALSE;

  /**
   * Constructor.
   *
   * @param float $width
   *   The width of the shelf, in millimeters.
   */
  public function __construct($width, $can_rotate, $cut_width) {
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
   * Add a shelf to the set of shelves.
   */
  public function addShelf($piece) {
    $this->shelves[] = new CabinetryShelfFFShelf(
      $piece['height'],
      $this->width,
      $this->canRotate,
      $this->cutWidth
    );
    $this->shelves[count($this->shelves) - 1]->addPiece($piece);
  }

}


class CabinetryShelfFFShelf {

  /**
   * The width (x) of the sheet good, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The height (y) of the sheet good, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The height (y) of the sheet good, in millimeters.
   *
   * @var float
   */
  public $used = 0.0;

  /**
   * The height (y) of the sheet good, in millimeters.
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
   * Pieces this shelf contains.
   *
   * @var array
   */
  public $pieces = array();

  /**
   * The cut width to allow for, in millimeters.
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
   */
  public function __construct($height, $width, $preserve_grain, $cut_width) {
    $this->height = $height;
    $this->width = $width;
    $this->remain = $width;
    $this->cutWidth = $cut_width;
    $this->canRotate = !$preserve_grain;
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
   */
  public function pieceFits($piece) {
    if ($piece['height'] > $this->height) {
      return FALSE;
    }

    if ($piece['width'] > $this->remain && $this->canRotate == FALSE) {
      return FALSE;
    }

    // If applicable, check if the piece was rotated fits.
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


class CabinetryShelfFFSheet {

  /**
   * The width (x) of the sheet good, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The height (y) of the sheet good, in millimeters.
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
   * The remaining height of sheet good, in millimeters.
   *
   * @var float
   */
  public $remain = 0.0;

  /**
   * Shelves this sheet contains.
   *
   * @var array
   */
  public $shelves = array();

  /**
   * The cut width to allow for, in millimeters.
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
   */
  public function __construct($height, $width, $cut_width) {
    $this->height = $height;
    $this->width = $width;
    $this->remain = $height;
    $this->cutWidth = $cut_width;
  }

  /**
   * Add a piece to the shelf.
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
