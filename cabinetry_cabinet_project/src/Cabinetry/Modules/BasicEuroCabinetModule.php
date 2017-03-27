<?php

namespace Drupal\cabinetry_cabinet_project\Cabinetry\Modules;

use Drupal\cabinetry_cabinet_project\CabinetProjectConstants;
use Drupal\cabinetry_cabinet_project\CabinetModuleInterface;
use Drupal\cabinetry_cabinet_project\Cabinetry\CabinetComponent;
use Drupal\cabinetry_cabinet_project\Cabinetry\CabinetDoor;
use Drupal\cabinetry_core\Cabinetry\WoodPart;
use Drupal\cabinetry_core\CoreConstants;
use Drupal\node\NodeInterface;

/**
 * A generic object to serve as a basic european styled cabinet module.
 */
class BasicEuroCabinetModule extends CabinetComponent {

  /**
   * The back panel sheet good.
   *
   * @var \Drupal\taxonomy\TermInterface
   */
  public $backSheetGood = NULL;

  /**
   * The inner width dim, in millimeters.
   *
   * @var float
   */
  public $carcassInnerWidth = 0.0;

  /**
   * The carcass sheet good.
   *
   * @var \Drupal\taxonomy\TermInterface
   */
  public $carcassSheetGood = NULL;

  /**
   * An array of float values equal to or less than 1.0.
   *
   * The sum of the array values should total 1.0.
   *
   * @var float[]
   */
  public $divisions = [];

  /**
   * The doors attached to this module.
   *
   * @var \Drupal\cabinetry_cabinet_project\Cabinetry\CabinetDoor[]
   */
  public $doors = [];

  /**
   * The number of doors spanning the carcass opening.
   *
   * @var int
   */
  public $doorsAcrossGap = 0;

  /**
   * The door reveal, in millimeters.
   *
   * @var float
   */
  public $doorReveal = 0.0;

  /**
   * The door panel undersize for expansion, each side, in millimeters.
   *
   * @var float
   */
  public $doorPanelUndersize = 0.0;

  /**
   * The door frame material.
   *
   * @var \Drupal\taxonomy\TermInterface
   */
  public $doorFrameMaterial = NULL;

  /**
   * The door frame material thickness.
   *
   * @var float
   */
  public $doorFrameThickness = NULL;

  /**
   * The door frame material height.
   *
   * @var float
   */
  public $doorFrameHeight = NULL;

  /**
   * The door frame rail/stile bit.
   *
   * @var \Drupal\taxonomy\TermInterface
   */
  public $doorFrameRouterBit = NULL;

  /**
   * The door panel material.
   *
   * @var \Drupal\taxonomy\TermInterface
   */
  public $doorPanelMaterial = NULL;

  /**
   * The door hinge.
   *
   * @var \Drupal\taxonomy\TermInterface
   */
  public $doorHinge = NULL;

  /**
   * The door hinge plate.
   *
   * @var \Drupal\taxonomy\TermInterface
   */
  public $doorHingePlate = NULL;

  /**
   * The drawerSlides.
   *
   * @var \Drupal\taxonomy\TermInterface
   */
  public $drawerSlides = NULL;

  /**
   * The drawer Rail height.
   *
   * @var float
   */
  public $drawerRailHeight = NULL;

  /**
   * The drawer Rail height.
   *
   * @var float
   */
  public $drawerBottomMaterial = NULL;

  /**
   * The number of shelves.
   *
   * @var int
   */
  public $numShelves = 0;

  /**
   * The number of shelves.
   *
   * @var bool
   */
  public $counterOnTop = FALSE;

  /**
   * The parent project for this module.
   *
   * @var \Drupal\node\NodeInterface
   */
  public $project = NULL;

  /**
   * The CabinetModule or child entity to build.
   *
   * @var \Drupal\cabinetry_cabinet_project\CabinetModuleInterface
   */
  public $module = NULL;

  /**
   * Constructor.
   *
   * @param \Drupal\node\NodeInterface $project
   *   The parent project for this module.
   * @param \Drupal\cabinetry_cabinet_project\CabinetModuleInterface $module
   *   The CabinetModule or child entity to build.
   */
  public function __construct(NodeInterface $project, CabinetModuleInterface $module) {
    $this->project = $project;
    $this->module = $module;
  }

  /**
   * Build the cabinet and determine the parts required.
   */
  public function build() {
    $this->height = (float) $this->module->getHeight();
    $this->width = (float) $this->module->getWidth();
    $this->depth = (float) $this->module->getDepth();

    $this->carcassSheetGood = $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_CARCASS_MATERIAL_FIELD)
      ->first()->get('entity')->getTarget()->getValue();

    $this->backSheetGood = $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_CARCASS_BACK_MATERIAL_FIELD)
      ->first()->get('entity')->getTarget()->getValue();

    $this->numShelves = (int) $this->module->getNumShelves();
    $this->counterOnTop = (bool) $this->module->getCounterOnTop();

    // Door properties.
    $this->doorFrameThickness = (float) $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_RAILSTILE_THICKNESS_FIELD)
      ->getString();

    $this->doorFrameHeight = (float) $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_RAILSTILE_HEIGHT_FIELD)
      ->getString();

    $this->doorFrameMaterial = $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_DOOR_FRAME_MATERIAL_FIELD)
      ->first()->get('entity')->getTarget()->getValue();

    $this->doorFrameRouterBit = $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_DOOR_RAILSTILE_BIT_FIELD)
      ->first()->get('entity')->getTarget()->getValue();

    $this->doorPanelMaterial = $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_DOOR_PANEL_MATERIAL_FIELD)
      ->first()->get('entity')->getTarget()->getValue();

    $this->doorReveal = (float) $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_DOOR_REVEAL_FIELD)
      ->getString();

    $this->doorPanelUndersize = (float) $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_DOOR_UNDERSIZE_FIELD)
      ->getString();

    $this->doorsAcrossGap = (int) $this->module->getDoorsAcrossGap();

    $this->doorHinge = $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_DOOR_HINGE_FIELD)
      ->first()->get('entity')->getTarget()->getValue();

    $this->doorHingePlate = $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_DOOR_HINGE_PLATE_FIELD)
      ->first()->get('entity')->getTarget()->getValue();

    // Determine vertical division ratio array.
    $divisions_array = [];
    foreach ($this->module->getDivisionRatios() as $ratio_value) {
      if (!empty($ratio_value)) {
        $divisions_array[] = (float) $ratio_value;
      }
    }
    $this->divisions = $divisions_array;

    // Generate parts for cabinet.
    $this->generateParts();
  }

  /**
   * Generate parts required to build this cabinet configuration.
   */
  protected function generateParts() {
    $this->parts = [];
    $this->setInnerWidth();
    $this->generateShelfParts();
    $this->generateSidePart(t('Left'));
    $this->generateSidePart(t('Right'));

    if ($this->counterOnTop == FALSE) {
      $this->generateTopBottomPart(t('Top'));
    }
    else {
      $this->generateTopSpreaders();
    }

    $this->generateTopBottomPart(t('Bottom'));
    $this->generateBackPanelPart();
    $this->generateDividerPanelParts();
    $this->generateNailerParts();
    $this->generateDoorParts();
  }

  /**
   * Set inner width of this cabinet.
   */
  protected function setInnerWidth() {
    $this->carcassInnerWidth = $this->width
     - (2 * $this->carcassSheetGood->get(CoreConstants::CABINETRY_MATERIAL_DEPTH_FIELD)->getString());
  }

  /**
   * Generate the WoodPart shelves for this cabinet.
   */
  protected function generateShelfParts() {
    for ($shelf_id = 0; $shelf_id < $this->numShelves; $shelf_id++) {
      $this->parts[] = new WoodPart(
        t('Shelf @shelf_id', ['@shelf_id' => $shelf_id]),
        $this->carcassSheetGood->get(CoreConstants::CABINETRY_MATERIAL_DEPTH_FIELD)->getString(),
        $this->carcassInnerWidth - CabinetProjectConstants::CABINET_PROJECT_CABINET_SHELF_UNDERSIZE,
        $this->depth - CabinetProjectConstants::CABINET_PROJECT_CABINET_SHELF_UNDERSIZE,
        $this->carcassSheetGood,
        ''
      );
      $this->addBanding($this->carcassSheetGood, $this->carcassInnerWidth - CabinetProjectConstants::CABINET_PROJECT_CABINET_SHELF_UNDERSIZE);
    }
  }

  /**
   * Generate a side panel for the caracass.
   *
   * @param string $label
   *   A label to identify the panel (Left, Right).
   */
  protected function generateSidePart($label) {
    $sheet_depth = $this->carcassSheetGood
      ->get(CoreConstants::CABINETRY_MATERIAL_DEPTH_FIELD)->getString();

    $dado_depth = round($sheet_depth / 2, 1);

    $this->parts[] = new WoodPart(
      t('@label Carcass', ['@label' => $label]),
      $sheet_depth,
      $this->height,
      $this->depth,
      $this->carcassSheetGood,
      "Cut {$dado_depth}mm Deep Dado {$sheet_depth}mm from long side on one side."
    );
    $this->addBanding($this->carcassSheetGood, $this->height);
  }

  /**
   * Generate a top or bottom panel for the caracass.
   *
   * @param string $label
   *   A label to identify the side (Top, Bottom).
   */
  protected function generateTopBottomPart($label) {
    $sheet_depth = $this->carcassSheetGood
      ->get(CoreConstants::CABINETRY_MATERIAL_DEPTH_FIELD)->getString();

    $dado_depth = round($sheet_depth / 2, 1);

    $this->parts[] = new WoodPart(
      t('@label Carcass', ['@label' => $label]),
      $sheet_depth,
      $this->carcassInnerWidth,
      $this->depth,
      $this->carcassSheetGood,
      "Cut {$dado_depth}mm Deep Dado {$sheet_depth}mm from long side on one side."
    );
    $this->addBanding($this->carcassSheetGood, $this->carcassInnerWidth);
  }

  /**
   * Set inner width of this cabinet.
   */
  protected function generateTopSpreaders() {
    for ($spreader_id = 0; $spreader_id < 2; $spreader_id++) {
      $this->parts[] = new WoodPart(
        t('Top Spreader @spreader_id', ['@spreader_id' => $spreader_id]),
        $this->carcassSheetGood->get(CoreConstants::CABINETRY_MATERIAL_DEPTH_FIELD)
          ->getString(),
        $this->carcassInnerWidth,
        CabinetProjectConstants::CABINET_PROJECT_CABINET_NAILER_HEIGHT,
        $this->carcassSheetGood,
        ''
      );
    }
  }

  /**
   * Generate the back panel parts for the cabinet caracass.
   */
  protected function generateBackPanelPart() {
    $sheet_depth = $this->carcassSheetGood
      ->get(CoreConstants::CABINETRY_MATERIAL_DEPTH_FIELD)->getString();

    $dado_depth = round($sheet_depth / 2, 1);

    $this->parts[] = new WoodPart(
      t('Back Panel'),
      $this->backSheetGood->get(CoreConstants::CABINETRY_MATERIAL_DEPTH_FIELD)->getString(),
      $this->height - (2 * $sheet_depth) + (2 * $dado_depth),
      $this->carcassInnerWidth + (2 * $dado_depth),
      $this->backSheetGood,
      ''
    );
  }

  /**
   * Generate the divider panel parts for the cabinet caracass.
   */
  protected function generateDividerPanelParts() {
    for ($divider_id = 0; $divider_id < count($this->divisions) - 1; $divider_id++) {
      $this->generateTopBottomPart("Section $divider_id Divider");
    }
  }

  /**
   * Generate the nailer strips panel parts for the cabinet carcass.
   */
  protected function generateNailerParts() {
    for ($nailer_id = 0; $nailer_id < 2; $nailer_id++) {
      $this->parts[] = new WoodPart(
        t('Nailer @nailer_id', ['@nailer_id' => $nailer_id]),
        $this->carcassSheetGood->get(CoreConstants::CABINETRY_MATERIAL_DEPTH_FIELD)->getString(),
        $this->carcassInnerWidth,
        CabinetProjectConstants::CABINET_PROJECT_CABINET_NAILER_HEIGHT,
        $this->carcassSheetGood,
        ''
      );
    }
  }

  /**
   * Generate the doors for the cabinet.
   */
  protected function generateDoorParts() {
    $this->doors = [];
    foreach ($this->divisions as $division_ratio) {
      for ($door_counter = 0; $door_counter < $this->doorsAcrossGap; $door_counter++) {
        $door = new CabinetDoor(
          ($this->width / $this->doorsAcrossGap) - 2 * $this->doorReveal,
          ($this->height * $division_ratio) - 2 * $this->doorReveal,
          $this->doorFrameMaterial,
          $this->doorFrameHeight,
          $this->doorFrameThickness,
          $this->doorFrameRouterBit,
          $this->doorPanelMaterial,
          $this->doorPanelUndersize
        );
        $this->doors[] = $door;
        $this->addParts($door->parts);
        $this->hardware[] = $this->doorHinge->getName();
        $this->hardware[] = $this->doorHinge->getName();
        $this->hardware[] = $this->doorHingePlate->getName();
        $this->hardware[] = $this->doorHingePlate->getName();
      }
    }
  }

}
