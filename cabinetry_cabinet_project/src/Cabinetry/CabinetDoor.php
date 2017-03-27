<?php

namespace Drupal\cabinetry_cabinet_project\Cabinetry;

use Drupal\cabinetry_cabinet_project\Cabinetry\CabinetComponent;
use Drupal\cabinetry_core\Cabinetry\WoodPart;
use Drupal\cabinetry_core\CoreConstants;

/**
 * A generic object to serve as edge banding type in a cabinetry project.
 */
class CabinetDoor extends CabinetComponent {

  /**
   * The door frame material.
   *
   * @var \Drupal\taxonomy\TermInterface
   */
  public $doorFrameMaterial = NULL;

  /**
   * The door frame height.
   *
   * @var float
   */
  public $doorFrameHeight = NULL;

  /**
   * The door frame thickness.
   *
   * @var float
   */
  public $doorFrameThickness = NULL;

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
   * @param float $door_frame_height
   *   The height of the door frame in in millimeters.
   * @param float $door_frame_thickness
   *   The thickness of the door frame in in millimeters.
   * @param object $door_frame_router_bit
   *   The door frame router bit, type CabinetryToolItem.
   * @param object $door_panel_material
   *   The door panel material, type CabinetryWoodPiece.
   * @param float $door_panel_undersize
   *   The amount to undersize the door panel to allow for expansion, each
   *   side, in millimeters.
   */
  public function __construct($width, $height, $door_frame_material, $door_frame_height, $door_frame_thickness, $door_frame_router_bit, $door_panel_material, $door_panel_undersize) {
    $this->width = $width;
    $this->height = $height;
    $this->doorFrameMaterial = $door_frame_material;
    $this->doorFrameRouterBit = $door_frame_router_bit;
    $this->doorPanelMaterial = $door_panel_material;
    $this->doorFrameHeight = $door_frame_height;
    $this->doorFrameThickness = $door_frame_thickness;
    $this->doorPanelUndersize = $door_panel_undersize;
    $this->generateParts();
  }

  /**
   * Generate parts required to build this door.
   */
  public function generateParts() {
    $this->parts = [];
    $this->generateStilePart(t('Left'));
    $this->generateStilePart(t('Right'));
    $this->generateRailPart(t('Top'));
    $this->generateRailPart(t('Bottom'));
    $this->generatePanelPart();
  }

  /**
   * Generate the panel component for this door.
   */
  protected function generatePanelPart() {
    $this->parts[] = new WoodPart(
      t('Door Panel'),
      $this->doorPanelMaterial->get(CoreConstants::CABINETRY_MATERIAL_DEPTH_FIELD)->getString(),
        $this->height - 2
        * $this->doorFrameHeight + 2
        * $this->doorFrameRouterBit->get(CoreConstants::CABINETRY_RAILSTILE_BIT_CUT_DEPTH_FIELD)->getString() - 2
        * $this->doorPanelUndersize,
      $this->width - 2
        * $this->doorFrameHeight + 2
        * $this->doorFrameRouterBit->get(CoreConstants::CABINETRY_RAILSTILE_BIT_CUT_DEPTH_FIELD)->getString() - 2
        * $this->doorPanelUndersize,
      $this->doorPanelMaterial,
      ''
    );
  }

  /**
   * Generate the rail components for this door.
   *
   * @param string $label
   *   A label to identify the side (Top, Bottom).
   */
  protected function generateRailPart($label) {
    $this->parts[] = new WoodPart(
      t('@label Rail', ['@label' => $label]),
      $this->doorFrameThickness,
      $this->width - 2
        * $this->doorFrameHeight + 2
        * $this->doorFrameRouterBit->get(CoreConstants::CABINETRY_RAILSTILE_BIT_CUT_DEPTH_FIELD)->getString(),
      $this->doorFrameHeight,
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
    $this->parts[] = new WoodPart(
      t('@label Stile', ['@label' => $label]),
      $this->doorFrameThickness,
      $this->height,
      $this->doorFrameHeight,
      $this->doorFrameMaterial,
      ''
    );
  }

}
