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
   * The sheet good to plot.
   *
   * @var object CabinetrySheetGood
   */
  public $sheet = array();

  /**
   * The canvas used to plot the sheet details.
   *
   * @var resource
   */
  public $canvas = NULL;

  /**
   * A running total of the shelf offset used as the sheet is filled.
   *
   * @var float
   */
  public $shelfOffset = 0.0;

  /**
   * The amount of pixels to offset the plot for shelf labels in the sheet plot.
   *
   * @var int
   */
  public $labelOffset = 256;

  /**
   * The amount of pixels to pad the plot image on all sides.
   *
   * @var int
   */
  public $padding = 64;

  /**
   * The font size used to plot the labels.
   *
   * @var int
   */
  public $fontSize = 5;

  /**
   * The imagecolorallocate color identifier used to plot the labels.
   *
   * @var int
   */
  public $labelColor = 0;

  /**
   * The imagecolorallocate color identifier used to plot the shelf line.
   *
   * @var int
   */
  public $shelfColor = 0;

  /**
   * The imagecolorallocate color identifier used to plot the cut lines.
   *
   * @var int
   */
  public $cutColor = 0;

  /**
   * The imagecolorallocate color identifier used to shade the pieces.
   *
   * @var int
   */
  public $pieceColor = 0;

  /**
   * The imagecolorallocate color identifier used as canvas background.
   *
   * @var int
   */
  public $canvasColor = 0;

  /**
   * Constructor.
   *
   * @param object $sheet
   *   The CabinetrySheetGood object to plot.
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
   * Set up the canvas used to plot the sheet.
   */
  public function setupCanvas() {
    $this->canvas = imagecreatetruecolor(
      $this->width + $this->labelOffset + 2 * $this->padding,
      $this->height + 2 * $this->padding
    );
  }

  /**
   * Set up colors used in the plot.
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
   * Plot a shelf to the canvas.
   *
   * @param object $shelf
   *   The CabinetryShelfFFShelf object to plot.
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

  /**
   * Get the dimensions, in pixels of rendered text.
   *
   * @param string $string
   *   The string to return the rendered dimensions of.
   *
   * @return array
   *   An associative array containing width and height elements describing the
   *   dimensions of the string.
   */
  public function getStringSize($string) {
    return array(
      'width' => (int) imagefontwidth($this->fontSize) * strlen($string),
      'height' => (int) imagefontheight($this->fontSize),
    );
  }

  /**
   * Plot a string centered inside a bounding box.
   *
   * @param string $string
   *   The string to plot.
   * @param int $upper_left_x
   *   The upper left x coordinate of the bounding box.
   * @param int $upper_left_y
   *   The upper left y coordinate of the bounding box.
   * @param int $bottom_right_x
   *   The bottom right x coordinate of the bounding box.
   * @param int $bottom_right_y
   *   The bottom right y coordinate of the bounding box.
   * @param bool $rotated
   *   Should the text be vertical, not horizontal?.
   */
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
