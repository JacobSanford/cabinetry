<?php
/**
 * @file
 * Provides a generic object for plotting a sheet good.
 */

/**
 * A generic object for plotting a sheet good.
 */
class CabinetrySheetGoodPlotter {

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
   * Does this sheet have grain that should be vertical?
   *
   * @var array
   */
  public $sheet = array();

  /**
   * Does this sheet have grain that should be vertical?
   *
   * @var resource
   */
  public $canvas = NULL;

  /**
   * Does this sheet have grain that should be vertical?
   *
   * @var float
   */
  public $shelfOffset = 0.0;

  /**
   * Does this sheet have grain that should be vertical?
   *
   * @var int
   */
  public $labelOffset = 256;

  /**
   * Does this sheet have grain that should be vertical?
   *
   * @var int
   */
  public $padding = 64;

  /**
   * The Font Size
   *
   * @var int
   */
  public $fontSize = 5;

  /**
   * Label Color
   *
   * @var int
   */
  public $labelColor = NULL;

  /**
   * Shelf Color
   *
   * @var int
   */
  public $shelfColor = NULL;

  /**
   * Cut Color
   *
   * @var int
   */
  public $cutColor = NULL;

  /**
   * Canvas Color
   *
   * @var int
   */
  public $pieceColor = NULL;

  /**
   * Canvas Color
   *
   * @var int
   */
  public $canvasColor = NULL;

  /**
   * Constructor.
   */
  public function __construct($sheet) {
    $this->sheet = $sheet;
    $this->width = $sheet->width;
    $this->height = $sheet->height;
    $this->setupCanvas();
    $this->setupColors();
    imagefill($this->canvas, 0, 0, $this->canvasColor);
  }

  /**
   * Set up canvas.
   */
  public function setupCanvas() {
    $this->canvas = imagecreatetruecolor(
      $this->width + $this->labelOffset + 2 * $this->padding,
      $this->height + 2 * $this->padding
    );
  }

  /**
   * Set up colors.
   */
  public function setupColors() {
    $this->labelColor = imagecolorallocate($this->canvas, 0, 0, 0);
    $this->shelfColor = imagecolorallocate($this->canvas, 255, 0, 0);
    $this->cutColor = imagecolorallocate($this->canvas, 0, 0, 0);
    $this->pieceColor = imagecolorallocate($this->canvas, 240, 240, 240);
    $this->canvasColor = imagecolorallocate($this->canvas, 255, 255, 255);
  }

  /**
   * Plot the sheet to the canvas.
   */
  public function plotSheet() {
    $sheet_color = imagecolorallocate($this->canvas, 0, 0, 0);
    imagerectangle(
      $this->canvas,
      $this->padding + $this->labelOffset,
      $this->padding,
      $this->padding + $this->labelOffset + $this->width - 1,
      $this->height + $this->padding - 1,
      $sheet_color
    );

    foreach ($this->sheet->shelves as $shelf_index => $shelf) {
      $this->plotShelf($shelf);
      $this->shelfOffset += $shelf->height;
    }

    $filepath = tempnam(sys_get_temp_dir(), 'cabinetry_sheet');

    imagepng($this->canvas, $filepath);
    imagedestroy($this->canvas);
    return $filepath;
  }

  /**
   * Plot the shelf to the canvas.
   */
  public function plotShelf($shelf) {
    $shelf_top_boundary = $this->padding + $this->height - $shelf->height - $this->shelfOffset;

    // Plot shelf pieces.
    $cur_x = $this->padding + $this->labelOffset;
    foreach ($shelf->pieces as $piece_index => $piece) {
      $upper_left_x = $cur_x;
      $bottom_right_x = $cur_x + $piece['width'];
      $bottom_right_y = $shelf_top_boundary + $shelf->height;
      $upper_left_y = $bottom_right_y - $piece['height'];

      // Plot piece.
      imagefilledrectangle(
        $this->canvas,
        $upper_left_x,
        $upper_left_y,
        $bottom_right_x,
        $bottom_right_y,
        $this->pieceColor
      );
      imagerectangle(
        $this->canvas,
        $upper_left_x,
        $upper_left_y,
        $bottom_right_x,
        $bottom_right_y,
        $this->cutColor
      );

      // Plot piece label.
      $this->centerStringInShape(
        "{$piece['label']} {$piece['width']}mm x {$piece['height']}mm",
        $upper_left_x,
        $upper_left_y,
        $bottom_right_x,
        $bottom_right_y,
        $piece['rotated']
      );
      $cur_x += $piece['width'];
    }

    // Shelf Boundary line.
    imageline(
      $this->canvas,
      $this->padding + $this->labelOffset - ($this->labelOffset / 4),
      $shelf_top_boundary,
      $this->padding + $this->labelOffset + $this->width,
      $shelf_top_boundary,
      $this->shelfColor
    );

    imagestring(
      $this->canvas,
      $this->fontSize,
      $this->padding + $this->labelOffset / 2,
      $shelf_top_boundary,
      "{$shelf->height}mm",
      $this->labelColor
    );
  }

  public function getStringSize($string) {
    return array(
      'width' => (int) imagefontwidth($this->fontSize) * strlen($string),
      'height' => (int) imagefontheight($this->fontSize),
    );
  }

  public function centerStringInShape($string, $upper_left_x, $upper_left_y, $bottom_right_x, $bottom_right_y, $rotated) {
    $string_dimensions = $this->getStringSize($string);

    if ($rotated) {
      $x_dim = $upper_left_x + (($bottom_right_x - $upper_left_x) / 2) - $string_dimensions['height'] / 2;
      $y_dim = $upper_left_y + (($bottom_right_y - $upper_left_y) / 2) + $string_dimensions['width'] / 2;
      $plot_function = 'imagestringup';
    }
    else {
      $x_dim = $upper_left_x + (($bottom_right_x - $upper_left_x) / 2) - $string_dimensions['width'] / 2;
      $y_dim = $upper_left_y + (($bottom_right_y - $upper_left_y) / 2) - $string_dimensions['height'] / 2;
      $plot_function = 'imagestring';
    }

    $plot_function(
      $this->canvas,
      $this->fontSize,
      $x_dim,
      $y_dim,
      $string,
      $this->labelColor
    );
  }

}
