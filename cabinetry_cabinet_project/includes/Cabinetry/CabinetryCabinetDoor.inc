<?php

/**
 * @file
 * Provides a generic object to serve as a basic cabinet door.
 */

/**
 * A generic object to serve as a basic cabinet door.
 */
class CabinetryCabinetDoor extends CabinetryComponent {

  /**
   * The door frame material.
   *
   * @var object CabinetryWoodPiece
   */
  public $doorFrameMaterial = NULL;

  /**
   * The door frame rail/stile bit.
   *
   * @var object CabinetryToolItem
   */
  public $doorFrameRouterBit = NULL;

  /**
   * The door panel material.
   *
   * @var object CabinetrySheetGood
   */
  public $doorPanelMaterial = NULL;

  /**
   * The door panel undersize for expansion, each side, in millimeters.
   *
   * @var float
   */
  public $doorPanelUndersize = 0.0;


  /**
   * Constructor.
   *
   * @param float $width
   *   The width of this sheet good, in millimeters.
   * @param float $height
   *   The height of this sheet good, in millimeters.
   * @param object $door_frame_material
   *   The door frame material, type CabinetryWoodPiece.
   * @param object $door_frame_router_bit
   *   The door frame router bit, type CabinetryToolItem.
   * @param object $door_panel_material
   *   The door panel material, type CabinetryWoodPiece.
   * @param float $door_panel_undersize
   *   The amount to undersize the door panel to allow for expansion, each
   *   side, in millimeters.
   */
  public function __construct($width, $height, $door_frame_material, $door_frame_router_bit, $door_panel_material, $door_panel_undersize) {
    $this->width = $width;
    $this->height = $height;
    $this->doorFrameMaterial = $door_frame_material;
    $this->doorFrameRouterBit = $door_frame_router_bit;
    $this->doorPanelMaterial = $door_panel_material;
    $this->doorPanelUndersize = $door_panel_undersize;
    $this->generateParts();
  }

  /**
   * Generate parts required to build this door.
   */
  public function generateParts() {
    $this->parts = array();
    $this->generateStilePart('Left');
    $this->generateStilePart('Right');
    $this->generateRailPart('Top');
    $this->generateRailPart('Bottom');
    $this->generatePanelPart();
  }

  /**
   * Generate the stile components for this door.
   *
   * @param string $label
   *   A label to identify the side (Left, Right).
   */
  protected function generateStilePart($label) {
    $this->parts[] = new CabinetryWoodPart(
      "$label Stile",
      $this->doorFrameMaterial->thickness,
      $this->height,
      $this->doorFrameMaterial->height,
      $this->doorFrameMaterial,
      ''
    );
  }

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
      "Door Panel",
      $this->doorPanelMaterial->thickness,
      $this->height - 2 * $this->doorFrameMaterial->height + 2 * $this->doorFrameRouterBit->cutDepth - 2 * $this->doorPanelUndersize,
      $this->width - 2 * $this->doorFrameMaterial->height + 2 * $this->doorFrameRouterBit->cutDepth - 2 * $this->doorPanelUndersize,
      $this->doorPanelMaterial,
      ''
    );
  }

}
