<?php
/**
 * @file
 * Provides a generic object to serve as top element of a cabinetry project.
 */

/**
 * A generic object to serve as top element of a cabinetry project.
 */
class CabinetryProject {

  /**
   * An array of CabinetryEdgeBanding objects.
   *
   * @var array
   */
  public $banding = array();

  /**
   * An array of CabinetryComponent objects.
   *
   * @var array
   */
  public $components = array();

  /**
   * An array of CabinetryHardwareItem objects.
   *
   * @var array
   */
  public $hardware = array();

  /**
   * An array of CabinetryWoodPart objects.
   *
   * @var array
   */
  public $parts = array();


  /**
   * Constructor.
   */
  public function __construct() {
    // pass.
  }

  /**
   * Add edge banding to the project materials list.
   *
   * @param array $banding_array
   *   An array of CabinetryEdgeBanding objects.
   */
  public function addBanding($banding_array) {
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

  /**
   * Add a component to this project.
   *
   * @param object $component
   *   A CabinetryComponent object.
   */
  public function addComponent($component) {
    $this->components[] = $component;
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

}
