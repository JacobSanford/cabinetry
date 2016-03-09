<?php
/**
 * @file
 * Provides a generic object to serve as a cabinet based project.
 */

/**
 * A generic object to serve as cabinet based project.
 */
class CabinetryCabinetProject extends CabinetryProject {

  /**
   * Add a component to this project.
   *
   * @param object $component
   *   A CabinetryComponent object.
   */
  public function addComponent($component) {
    $this->components[] = $component;
    $this->addPieces($component->pieces);
    $this->addBanding($component->banding);
  }

}
