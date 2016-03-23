<?php

/**
 * @file
 * Provides a generic object to serve as a basic cabinet door.
 */

define('CABINETRY_CABINET_PROJECT_CABINET_DRAWER_SECTION_DRAWER_LENGTH_DELTA', 10.0);
define('CABINETRY_CABINET_PROJECT_CABINET_DRAWER_SECTION_DRAWER_HEIGHT_DELTA', 25.4);


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
   * The drawer slides.
   *
   * @var object CabinetryDrawerSlides
   */
  public $drawerSlides = NULL;

  /**
   * The drawer Rail height.
   *
   * @var float
   */
  public $drawerRailHeight = NULL;

  /**
   * The drawer slides.
   *
   * @var object CabinetryDrawerSlides
   */
  public $drawerBottom = NULL;

  /**
   * The drawer outer width.
   *
   * @var float
   */
  public $drawerOuterWidth = 0.0;

  /**
   * The drawer inner width.
   *
   * @var float
   */
  public $drawerInnerWidth = 0.0;

  /**
   * The drawer depth.
   *
   * @var float
   */
  public $drawerDepth = 0.0;

  /**
   * The drawer outer height.
   *
   * @var float
   */
  public $drawerOuterHeight = 0.0;

  /**
   * The drawer inner height.
   *
   * @var float
   */
  public $drawerInnerHeight = 0.0;

  /**
   * The drawer box height.
   *
   * @var float
   */
  public $drawerBoxHeight = 0.0;

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
   * @param float $drawer_front_rail_height
   *   The height of the rail of the drawer fronts.
   * @param object $drawer_slides
   *   The drawer slides, type CabinetryDrawerSlide.
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
  public function __construct($width, $height, $depth, $parent_sheet_good, $drawer_front_frame_material, $drawer_front_rail_height, $drawer_slides, $drawer_front_frame_router_bit, $drawer_front_panel_material, $drawer_front_panel_undersize, $drawer_front_reveal, $drawer_bottom) {
    $this->width = $width;
    $this->height = $height;
    $this->depth = $depth;
    $this->cabinetCarcassSheetType = $parent_sheet_good;
    $this->drawerFrontFrameMaterial = $drawer_front_frame_material;
    $this->drawerFrontFrameRouterBit = $drawer_front_frame_router_bit;
    $this->drawerFrontPanelMaterial = $drawer_front_panel_material;
    $this->drawerFrontPanelUndersize = $drawer_front_panel_undersize;
    $this->drawerFrontReveal = $drawer_front_reveal;
    $this->drawerSlides = $drawer_slides;
    $this->drawerRailHeight = $drawer_front_rail_height;
    $this->drawerBottom = $drawer_bottom;
    $this->setDrawerDims();
    $this->generateParts();
  }

  /**
   * Generate parts required to build this door.
   */
  public function generateParts() {
    $this->parts = array();
    $this->generateDrawerFront();
    $this->generateDrawerBox();
    $this->hardware[] = $this->drawerSlides;
  }

  /**
   * Generate the drawer front.
   */
  protected function generateDrawerFront() {
    $drawer_front = new CabinetryCabinetDrawerFront(
      $this->width - 2 * $this->drawerFrontReveal,
      $this->height - 2 * $this->drawerFrontReveal,
      $this->drawerFrontFrameMaterial,
      $this->drawerFrontFrameRouterBit,
      $this->drawerFrontPanelMaterial,
      $this->drawerFrontPanelUndersize,
      $this->drawerRailHeight
    );
    $this->addParts($drawer_front->parts);
  }

  /**
   * Generate the drawer box for the cabinet.
   */
  protected function generateDrawerBox() {
    $this->generateBackFrontPart('Front');
    $this->generateBackFrontPart('Back');
    $this->generateSidePart('Left');
    $this->generateSidePart('Right');
    $this->generateDrawerPanelPart();
  }

  /**
   * Generate the drawer box for the cabinet.
   */
  protected function setDrawerDims() {
    $this->drawerOuterWidth = $this->width - 2 * $this->drawerSlides->carcassClearance;
    $this->drawerInnerWidth = $this->drawerOuterWidth - 2 * $this->cabinetCarcassSheetType->thickness;
    $this->drawerDepth = $this->drawerSlides->length - CABINETRY_CABINET_PROJECT_CABINET_DRAWER_SECTION_DRAWER_LENGTH_DELTA;
    $this->drawerOuterHeight = $this->height - 0.5 * $this->cabinetCarcassSheetType->thickness;
    $this->drawerInnerHeight = $this->drawerOuterHeight - 1.5 * $this->cabinetCarcassSheetType->thickness;
    $this->drawerBoxHeight = $this->drawerInnerHeight - CABINETRY_CABINET_PROJECT_CABINET_DRAWER_SECTION_DRAWER_HEIGHT_DELTA;
  }


  /**
   * Generate a back or front part for the drawer box.
   *
   * @param string $label
   *   A label to identify the side (Back, Front).
   */
  protected function generateBackFrontPart($label) {
    $this->parts[] = new CabinetryWoodPart(
      "Drawer $label",
      $this->cabinetCarcassSheetType->thickness,
      $this->drawerInnerWidth,
      $this->drawerBoxHeight,
      $this->cabinetCarcassSheetType,
      ''
    );
    $this->addBanding($this->cabinetCarcassSheetType->material, $this->cabinetCarcassSheetType->thickness, $this->drawerInnerWidth);
  }

  /**
   * Generate a side part for the drawer box.
   *
   * @param string $label
   *   A label to identify the side (Left, Right).
   */
  protected function generateSidePart($label) {
    $this->parts[] = new CabinetryWoodPart(
      "Drawer $label",
      $this->cabinetCarcassSheetType->thickness,
      $this->drawerDepth,
      $this->drawerBoxHeight,
      $this->cabinetCarcassSheetType,
      ''
    );
    $this->addBanding($this->cabinetCarcassSheetType->material, $this->cabinetCarcassSheetType->thickness, $this->drawerDepth);
  }

  /**
   * Generate a bottom panel for the drawer box.
   */
  protected function generateDrawerPanelPart() {
    $this->parts[] = new CabinetryWoodPart(
      "Drawer Bottom",
      $this->drawerBottom->thickness,
      $this->drawerOuterWidth,
      $this->drawerDepth,
      $this->drawerBottom,
      ''
    );
  }

}
