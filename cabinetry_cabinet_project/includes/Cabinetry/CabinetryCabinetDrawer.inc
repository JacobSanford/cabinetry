<?php

/**
 * @file
 * Provides a generic object to serve as a basic cabinet door.
 */

/**
 * A generic object to serve as a basic cabinet door.
 */
class CabinetryCabinetDrawerSection extends CabinetryComponent {
  /**
   * An array of CabinetryCabinetDoor objects comprising this component.
   *
   * @var array
   */
  public $doors = array();

  /**
   * The parent carcass sheet good type.
   *
   * @var object CabinetrySheetGood
   */
  public $cabinetCarcassSheetType = NULL;

  /**
   * The door frame material.
   *
   * @var object CabinetryWoodPiece
   */
  public $drawerFrontFrameMaterial = NULL;

  /**
   * The door frame rail/stile bit.
   *
   * @var object CabinetryToolItem
   */
  public $drawerFrontFrameRouterBit = NULL;

  /**
   * The door panel material.
   *
   * @var object CabinetrySheetGood
   */
  public $drawerFrontPanelMaterial = NULL;

  /**
   * The door panel material.
   *
   * @var object CabinetrySheetGood
   */
  public $drawerFrontReveal = NULL;

  /**
   * The door panel undersize for expansion, each side, in millimeters.
   *
   * @var float
   */
  public $drawerFrontPanelUndersize = 0.0;

  /**
   * Constructor.
   *
   * @param float $width
   *   Outer width of cabinet space allocated to the drawer, in millimeters.
   * @param float $height
   *   Outer height of cabinet space allocated to the drawer, in millimeters.
   * @param float $depth
   *   Outer depth of cabinet space allocated to the drawer, in millimeters.
   * @param object $parent_sheet_good
   *   The parent cabinet carcass sheet good type.
   * @param object $drawer_front_frame_material
   *   The drawer front frame material, type CabinetryWoodPiece.
   * @param object $drawer_front_frame_router_bit
   *   The drawer front frame router bit, type CabinetryToolItem.
   * @param object $drawer_front_panel_material
   *   The drawer front panel material, type CabinetryWoodPiece.
   * @param float $drawer_front_panel_undersize
   *   The amount to undersize the drawer front panel to allow for expansion,
   *   each side, in millimeters.
   * @param float $drawer_front_reveal
   *   The reveal of the door front frame, each side.
   */
  public function __construct($width, $height, $depth, $parent_sheet_good, $drawer_front_frame_material, $drawer_front_frame_router_bit, $drawer_front_panel_material, $drawer_front_panel_undersize, $drawer_front_reveal) {
    $this->width = $width;
    $this->height = $height;
    $this->depth = $depth;
    $this->cabinetCarcassSheetType = $parent_sheet_good;
    $this->drawerFrontFrameMaterial = $drawer_front_frame_material;
    $this->drawerFrontFrameRouterBit = $drawer_front_frame_router_bit;
    $this->drawerFrontPanelMaterial = $drawer_front_panel_material;
    $this->drawerFrontPanelUndersize = $drawer_front_panel_undersize;
    $this->drawerFrontReveal = $drawer_front_reveal;
    $this->generateParts();
  }

  /**
   * Generate parts required to build this door.
   */
  public function generateParts() {
    $this->parts = array();
    $this->generateDrawerFront();
    $this->generateDrawerBox();
    $this->addHardware();
  }

  /**
   * Generate the doors for the cabinet.
   */
  protected function generateDrawerFront() {
    $this->doors = array();
    $drawer_front = new CabinetryCabinetDrawerFront(
      $this->width - 2 * $this->drawerFrontReveal,
      $this->height - 2 * $this->drawerFrontReveal,
      $this->drawerFrontFrameMaterial,
      $this->drawerFrontFrameRouterBit,
      $this->drawerFrontPanelMaterial,
      $this->drawerFrontPanelUndersize
    );
    $this->doors[] = $drawer_front;
    $this->parts = array_merge($this->parts, $drawer_front);
  }

}
