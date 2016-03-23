<?php

/**
 * @file
 * Provides a generic object to serve as a basic cabinet door.
 */

/**
 * A generic object to serve as a basic cabinet door.
 */
class CabinetryCabinetDrawerFront extends CabinetryCabinetDoor {

  /**
   * The height of the rail components of the door frame.
   *
   * @var float
   */
  public $drawerRailHeight = 0.0;

  public function __construct($width, $height, $door_frame_material, $door_frame_router_bit, $door_panel_material, $door_panel_undersize, $rail_height) {
    $this->width = $width;
    $this->height = $height;
    $this->doorFrameMaterial = $door_frame_material;
    $this->doorFrameRouterBit = $door_frame_router_bit;
    $this->doorPanelMaterial = $door_panel_material;
    $this->doorPanelUndersize = $door_panel_undersize;
    $this->drawerRailHeight = $rail_height;
    $this->generateParts();
  }

  /**
   * Generate the rail components for this door.
   *
   * @param string $label
   *    A label to identify the side (Top, Bottom).
   */
  protected function generateRailPart($label) {
    $this->parts[] = new CabinetryWoodPart(
      "Drawer $label Rail",
      $this->doorFrameMaterial->thickness,
      $this->width - 2 * $this->doorFrameMaterial->height + 2 * $this->doorFrameRouterBit->cutDepth,
      $this->drawerRailHeight,
      $this->doorFrameMaterial,
      ''
    );
  }

  /**
   * Generate the stile components for this door.
   *
   * @param string $label
   *   A label to identify the side (Left, Right).
   */
  protected function generateStilePart($label) {
    $this->parts[] = new CabinetryWoodPart(
      "Drawer $label Stile",
      $this->doorFrameMaterial->thickness,
      $this->height,
      $this->doorFrameMaterial->height,
      $this->doorFrameMaterial,
      ''
    );
  }

  /**
   * Generate the panel component for this door.
   */
  protected function generatePanelPart() {
    $this->parts[] = new CabinetryWoodPart(
      "Drawer Panel",
      $this->doorPanelMaterial->thickness,
      $this->width - 2 * $this->doorFrameMaterial->height + 2 * $this->doorFrameRouterBit->cutDepth - 2 * $this->doorPanelUndersize,
      $this->height - 2 * $this->drawerRailHeight + 2 * $this->doorFrameRouterBit->cutDepth - 2 * $this->doorPanelUndersize,
      $this->doorPanelMaterial,
      ''
    );
  }

}
