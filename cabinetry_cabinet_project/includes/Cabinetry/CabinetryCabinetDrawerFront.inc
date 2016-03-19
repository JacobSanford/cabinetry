<?php

/**
 * @file
 * Provides a generic object to serve as a basic cabinet door.
 */

define('CABINETRY_CABINET_PROJECT_CABINET_DRAWER_FRONT_RAIL_HEIGHT', 38.1);

/**
 * A generic object to serve as a basic cabinet door.
 */
class CabinetryCabinetDrawerFront extends CabinetryCabinetDoor {

  /**
   * Generate the rail components for this door.
   *
   * @param string $label
   *    A label to identify the side (Top, Bottom).
   */
  protected function generateRailPart($label) {
    $this->parts[] = new CabinetryWoodPart(
      "$label Rail",
      $this->doorFrameMaterial->thickness,
      $this->width - 2 * $this->doorFrameMaterial->height + 2 * $this->doorFrameRouterBit->cutDepth,
      CABINETRY_CABINET_PROJECT_CABINET_DRAWER_FRONT_RAIL_HEIGHT,
      $this->doorFrameMaterial,
      ''
    );
  }

  /**
   * Generate the panel component for this door.
   */
  protected function generatePanelPart() {
    $this->parts[] = new CabinetryWoodPart(
      "Panel",
      $this->doorPanelMaterial->thickness,
      $this->height - 2 * CABINETRY_CABINET_PROJECT_CABINET_DRAWER_FRONT_RAIL_HEIGHT + 2 * $this->doorFrameRouterBit->cutDepth - 2 * $this->doorPanelUndersize,
      $this->width - 2 * $this->doorFrameMaterial->height + 2 * $this->doorFrameRouterBit->cutDepth - 2 * $this->doorPanelUndersize,
      $this->doorPanelMaterial,
      ''
    );
  }

}
