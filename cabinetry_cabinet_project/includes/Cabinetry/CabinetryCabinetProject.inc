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

  public $parts = array();

  /**
   * Collate a list of parts from all components of the project.
   */
  public function collateParts() {
    foreach ($this->components as $component_id => $component) {

      // Add carcass panel parts.
      foreach ($component->parts as $part_id => $part) {
        $this->sortPart(
          $part,
          "Cabinet $component_id $part->label"
        );
      }

      // Add door parts.
      foreach ($component->doors as $door_id => $door) {
        foreach ($door->parts as $door_part_id => $door_part) {
          $this->sortPart(
            $door_part,
            "Cabinet $component_id Door $door_id $door_part->label"
          );
        }
      }

      // Add banding.
      $this->addBanding($component->banding);
      $this->hardware = array_merge($this->hardware, $component->hardware);
    }
    dpm($this);
  }

  /**
   * Collate a list of parts from all components of the project.
   */
  public function sortPart($part, $label) {

    if ($part->source instanceof CabinetrySheetGood) {
      if (!isset($this->parts['CabinetrySheetGood'][$part->source->material])) {
        $this->parts['CabinetrySheetGood'][$part->source->material] = array(
          'width' => $part->source->width,
          'height' => $part->source->height,
          'sheets' => array(),
          'parts' => array(),
        );
      }

      $found_part = FALSE;
      foreach ($this->parts['CabinetrySheetGood'][$part->source->material]['parts'] as $part_index => $cur_part) {
        if ($cur_part->width == $part->width && $cur_part->height == $part->height) {
          $found_part = TRUE;
          $this->parts['CabinetrySheetGood'][$part->source->material]['parts'][$part_index]['items'][] = array(
            $label => $part->notes,
          );
        }
      }
      if ($found_part == FALSE) {
        $this->parts['CabinetrySheetGood'][$part->source->material]['parts'][] = array(
          'items' => array(
            $label => $part->notes,
          ),
          'width' => $part->width,
          'height' => $part->height,
        );
      }
    }

    if ($part->source instanceof CabinetrySolidWood) {
      if (!isset($this->parts['CabinetrySolidWood'][$part->source->material])) {
        $this->parts['CabinetrySolidWood'][$part->source->material] = array(
          'thickness' => $part->source->thickness,
          'height' => $part->source->height,
          'length' => 0.0,
          'parts' => array(),
        );
      }
      $this->parts['CabinetrySolidWood'][$part->source->material]['parts'][] = array(
        'label' => $label,
        'width' => $part->width,
        'height' => $part->height,
        'notes' => $part->notes,
      );
      $this->parts['CabinetrySolidWood'][$part->source->material]['length'] += $part->width;
    }

  }
}
