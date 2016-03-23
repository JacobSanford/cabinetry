<?php
/**
 * @file
 * Provides a generic object to serve as components within a cabinet project.
 */

/**
 * A generic object to serve as components within a cabinetry project.
 */
class CabinetryComponent {

  /**
   * The outer width (x) of the component, in millimeters.
   *
   * @var float
   */
  public $width = 0.0;

  /**
   * The outer height (y) of the component, in millimeters.
   *
   * @var float
   */
  public $height = 0.0;

  /**
   * The depth (z) of the component, in millimeters.
   *
   * @var float
   */
  public $depth = 0.0;

  /**
   * An array of CabinetHardwareItem objects comprising this component.
   *
   * @var array
   */
  public $hardware = array();

  /**
   * An array of CabinetryEdgeBanding objects comprising this component.
   *
   * @var array
   */
  public $banding = array();

  /**
   * An array of CabinetryWoodPart objects comprising this component.
   *
   * @var array
   */
  public $parts = array();

  /**
   * A label for this part.
   *
   * @var string
   */
  public $label = NULL;

  /**
   * Constructor.
   */
  public function __construct() {
    // Pass.
  }

  /**
   * Add a length of edge banding to the cabinet materials list.
   *
   * @param object $material
   *   The CabinetrySheetGood object to edge band.
   * @param float $width
   *   The width of the banding, in millimeters.
   * @param float $length
   *   The length required, in millimeters.
   */
  protected function addBanding($material, $width, $length) {
    $object_found = FALSE;
    foreach ($this->banding as $banding_index => $banding_value) {
      if (
        $banding_value->material == $material &&
        $banding_value->width == $width
      ) {
        $this->banding[$banding_index]->add($length);
        $object_found = TRUE;
      }
    }
    if ($object_found == FALSE) {
      $this->banding[] = new CabinetryEdgeBanding($material, $width);
      $this->banding[count($this->banding) - 1]->add($length);
    }
  }

  /**
   * Add additional parts to this project.
   *
   * @param array $parts_array
   *   An array of CabinetryWoodPart objects.
   */
  protected function addParts(array $parts_array) {
    $this->parts = array_merge($this->parts, $parts_array);
  }

  /**
   * Add additional parts to this project.
   *
   * @param array $hardware_array
   *   An array of CabinetHardwareItem objects.
   */
  protected function addHardware(array $hardware_array) {
    $this->hardware = array_merge($this->hardware, $hardware_array);
  }

  /**
   * Add edge banding to the project materials list.
   *
   * @param array $banding_array
   *   An array of CabinetryEdgeBanding objects.
   */
  public function addBandingArray($banding_array) {
    foreach ($banding_array as $banding_object) {
      $object_found = FALSE;
      foreach ($this->banding as $banding_index => $banding_value) {
        if (
          $banding_value->material == $banding_object->material &&
          $banding_value->width == $banding_object->width
        ) {
          $this->banding[$banding_index]->add($banding_object->length);
          $object_found = TRUE;
        }
      }
      if ($object_found == FALSE) {
        $this->banding[] = new CabinetryEdgeBanding($banding_object->material, $banding_object->width);
        $this->banding[count($this->banding) - 1]->add($banding_object->length);
      }
    }
  }

}
