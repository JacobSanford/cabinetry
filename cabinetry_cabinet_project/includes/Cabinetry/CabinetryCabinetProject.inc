<?php
/**
 * @file
 * Provides a generic object to serve as components within a cabinet project.
 */

/**
 * A generic object to serve as cabinet components within a cabinetry project.
 */
class CabinetryCabinetProject extends CabinetryProject {

  /**
   * An array of CabinetryEdgeBanding objects comprising this project.
   *
   * @var array
   */
  public $banding = array();

  public function addComponent($component) {
    $this->components[] = $component;
    $this->addPieces($component->pieces);
    $this->addBanding($component->banding);
  }

  public function addBanding($banding_array) {
    foreach ($banding_array as $banding_width => $banding_items) {
      if (!array_key_exists($banding_width, $this->banding)) {
        $this->banding[$banding_width] = $banding_items;
      }
      else {
        $this->banding[$banding_width] = array_merge(
          $this->banding[$banding_width],
          $banding_items
        );
      }
    }
  }

}
