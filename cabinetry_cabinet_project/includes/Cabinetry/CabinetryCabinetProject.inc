<?php
/**
 * @file
 * Provides a generic object to serve as a cabinet project.
 */

/**
 * A generic object to serve as cabinet project.
 */
class CabinetryCabinetProject extends CabinetryProject {

  /**
   * The router bit to use for rail/stile frames.
   *
   * @var object
   */
  public $frameRouterBit = NULL;


  /**
   * Collate a list of parts from all components of the project.
   */
  public function collateParts() {
    foreach ($this->components as $component_id => $component) {
      // Add carcass panel parts.
      foreach ($component->parts as $part_id => $part) {
        $this->parts[] = array(
          'label' => "Cabinet $component_id $part->label",
          'part' => $part,
        );
      }

      // Add door parts.
      foreach ($component->doors as $door_id => $door) {
        foreach ($door->parts as $door_part_id => $door_part) {
          $this->parts[] = array(
            'label' => "Cabinet $component_id Door $door_id $door_part->label",
            'part' => $door_part,
          );
        }
      }

      // Add banding.
      $this->addBanding($component->banding);
    }
    dpm($this->parts);
  }

}
