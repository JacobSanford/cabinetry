<?php
/* Caveat: I'm not a PHP programmer, so this may or may
 * not be the most idiomatic code...
 *
 * FPDF is a free PHP library for creating PDFs:
 * http://www.fpdf.org/
 */
libraries_load('fpdf');

class PDF_Image extends FPDF {
  const DPI = 96;
  const MM_IN_INCH = 25.4;
  const A4_HEIGHT = 297;
  const A4_WIDTH = 210;
  const MAX_WIDTH = 1150;
  const MAX_HEIGHT = 850;

  function pixelsToMM($val) {
    return $val * self::MM_IN_INCH / self::DPI;
  }

  function resizeToFit($imgFilename) {
    list($width, $height) = getimagesize($imgFilename);
    $widthScale = self::MAX_WIDTH / $width;
    $heightScale = self::MAX_HEIGHT / $height;
    $scale = min($widthScale, $heightScale);
    return array(
      round($this->pixelsToMM($scale * $width)),
      round($this->pixelsToMM($scale * $height))
    );
  }

  function centreImage($img, $extension) {
    list($width, $height) = $this->resizeToFit($img);
    $this->Image(
      $img, (self::A4_HEIGHT - $width) / 2,
      (self::A4_WIDTH - $height) / 2,
      $width,
      $height,
      $extension
    );
  }

}
