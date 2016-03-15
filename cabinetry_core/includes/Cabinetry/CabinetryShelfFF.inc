<?php
/**
 * @file
 * Provides a generic object for packing a sheet good from a piece list.
 */

/**
 * A generic object for packing a sheet good from a piece list.
 */
class CabinetryShelfFF extends CabinetrySheetGoodPacker {

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
   * @param boolean $grain
   *   Should the piece orientations (grain parallel to width) be preserved?
   * @param array $pieces
   *   An associative array of pieces to fit into the sheet space. Each item
   *   must have 'width', 'height' and 'label' elements.
   */
  public function __construct($width, $height, $pieces, $grain) {
    $this->width = $width;
    $this->height = $height;
    $this->grain = $grain;
    $this->pieces = $pieces;

    // TODO : This is key here. Tell why later.
    $this->sortPiecesByHeightAndWidth();
  }

  /**
   * Pack the Sheets.
   */
  public function pack() {
    $sheet_set = new CabinetryShelfFFShelfSet(
      $this->width,
      $this->grain,
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
    dpm($sheet_set);
  }

  /**
   * Returns the sheet array.
   */
  public function getSheets() {
    return array();
  }

  /**
   * Sort pieces array by height first, then width.
   */
  protected function sortPiecesByHeightAndWidth() {
    $sort = array();
    foreach($this->pieces as $k=>$v) {
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

  public function addPiece($piece) {
    $shelf_found = FALSE;
    foreach ($this->shelves as $shelf_index => $shelf) {
      if ($shelf->pieceFits($piece) != FALSE) {
        $shelf->addPiece($piece);
        $shelf_found = TRUE;
        break;
      }
    }

    if ($shelf_found == FALSE) {
      $this->addShelf($piece);
    }
  }

  public function addShelf($piece) {
    $this->shelves[] = new CabinetryShelfFFShelf(
      $piece['height'],
      $this->width,
      $this->canRotate,
      $this->cutWidth
    );
    $this->shelves[count($this->shelves)-1]->addPiece($piece);
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
  public function __construct($height, $width, $can_rotate, $cut_width) {
    $this->height = $height;
    $this->width = $width;
    $this->remain = $width;
    $this->cutWidth = $cut_width;
    $this->canRotate = $can_rotate;
  }

  public function addPiece($piece) {
    $this->pieces[] = $piece;
    $this->setRemainder();
  }

  public function setRemainder() {
    $sum = 0.0;
    foreach ($this->pieces as $piece) {
      $sum += $piece['width'];
    }
    $this->used = $sum + (count($this->pieces) - 1 * $this->cutWidth);
    $this->remain = $this->width - $this->used;
  }

  public function pieceFits($piece) {
    if ($piece['height'] > $this->height) {
      return FALSE;
    }

    if ($piece['width'] > $this->remain && $this->canRotate == FALSE) {
      return FALSE;
    }

    // If applicable, check if the piece was rotated fits.
    if ($piece['width'] > $this->remain && $this->canRotate == TRUE && $piece['height'] <= $this->remain) {
      $rotated_balance = $this->remain - $piece['height'];
    }

    // Check if non-rotated fits better than rotated.
    if ($piece['width'] <= $this->remain) {
      if (!isset($rotated_balance) || $this->remain - $piece['width'] <= $rotated_balance) {
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
