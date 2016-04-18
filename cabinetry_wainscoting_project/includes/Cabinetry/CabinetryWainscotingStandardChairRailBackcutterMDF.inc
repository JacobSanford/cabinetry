<?php
/**
 * @file
 * Provides a generic object to serve as components within a cabinet project.
 */

/**
 * A generic object to serve as components within a cabinetry project.
 */
class CabinetryWainscotingStandardChairRailBackcutterMDF extends CabinetryWainscotingStyle {

  /**
   * The panel rail/stile bit.
   *
   * @var object CabinetryToolItem
   */
  public $frameRouterBit = NULL;

  /**
   * The height of the baseboard, in millimeters.
   *
   * @var float
   */
  public $baseBoardHeight = 127.0;

  /**
   * The height of the support strapping, in millimeters.
   *
   * @var float
   */
  public $supportStrappingHeight = 115.0;

  /**
   * The height of the stiles, in millimeters.
   *
   * @var float
   */
  public $stileHeight = 88.9;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $topRailHeight = 101.6;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $bottomRailHeight = 88.9;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var object
   */
  public $panelSheetGood = NULL;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var int
   */
  public $railSolidMaterialTid = NULL;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $maxRailLength = 0.0;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $studSpacing = 0.0;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var bool
   */
  public $padLeftSide = FALSE;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var bool
   */
  public $padRightSide = FALSE;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $leftStudDistance = 0.0;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $rightStudDistance = 0.0;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var int
   */
  public $numPanels = 1;

  /**
   * Build the cabinet and determine parts required.
   *
   * @param array $section_component
   *   An associative array obtained from iterating over the proprietary values
   *   in $form_state['values']['field_cabinetry_project_componen'] from the
   *   cabinetry_cabinet_project_node_form drupal module form submit.
   */
  public function build($section_component) {
    $this->studSpacing = (float) $section_component['field_cabinetry_wainscoting_stud'][LANGUAGE_NONE][0]['value'];
    $this->leftStudDistance = (float) $section_component['field_cabinetry_left_stud_distan'][LANGUAGE_NONE][0]['value'];
    $this->rightStudDistance = (float) $section_component['field_cabinetry_right_stud_dista'][LANGUAGE_NONE][0]['value'];
    $this->padLeftSide = (bool) $section_component['field_cabinetry_extend_left_stil'][LANGUAGE_NONE][0]['value'];
    $this->padRightSide = (bool) $section_component['field_cabinetry_extend_right_sti'][LANGUAGE_NONE][0]['value'];
    $this->numPanels = (int) $section_component['field_number_of_sections'][LANGUAGE_NONE][0]['value'];
    $this->generateParts();
  }

  public function generateParts() {
    $this->parts = array();
    $this->generateRailParts('Top', $this->topRailHeight, $this->leftStudDistance);
    $this->generateRailParts('Bottom', $this->bottomRailHeight, $this->rightStudDistance, TRUE);
    $this->generateStileParts();
    dpm($this);
  }

  public function generateRailParts($label, $height, $offset, $reverse = FALSE) {
    $parts = array();
    if ($this->width <= $this->maxRailLength) {
      $parts[] = array('width' => $this->width);
    }
    else {
      // Offset first part to a stud.
      $remainder_length = $this->width;
      $parts[] = array('width' => $offset);
      $remainder_length = $remainder_length - $offset;

      while ($remainder_length > 0) {
        // Cut a custom length to get final piece.
        if ($remainder_length <= $this->maxRailLength) {
          $parts[] = array('width' => $remainder_length);
          $remainder_length = 0;
        }
        else {
          // Find the distance to the furthest stud center.
          $part_length = $this->getMeasurementToFurthestStud($this->width - $remainder_length, $offset);
          $parts[] = array('width' => $part_length);
          $remainder_length = $remainder_length - $part_length;
        }
      }
    }

    if ($reverse == TRUE) {
      $parts = array_reverse($parts);
    }

    foreach ($parts as $part_index => $part) {
      $this->addSolidWoodPart($part['width'], $height, "$label Rail $part_index");
    }
  }


  public function generateStileParts() {
    $stiles = array();
    $num_stiles = $this->numPanels + 1;
    $stile_width = $this->height
      - $this->supportStrappingHeight
      - $this->bottomRailHeight
      - $this->topRailHeight
      - $this->panelSheetGood->thickness
      + (2 * $this->frameRouterBit->cutDepth);

    for ($i = 0; $i <= $num_stiles - 1; $i++) {
      $stile_height = $this->stileHeight;
      if ($i == 0 && $this->padLeftSide == TRUE) {
        $stile_height = $stile_height + $this->panelSheetGood->thickness;
      }
      elseif ($i == $num_stiles - 1 && $this->padRightSide == TRUE) {
        $stile_height = $stile_height + $this->panelSheetGood->thickness;
      }
      $this->addSolidWoodPart($stile_width, $stile_height, "Stile $i");
    }

  }

  public function addSolidWoodPart($width, $height, $label) {
    $this->parts[] = new CabinetryWoodPart(
      $label,
      $this->panelSheetGood->thickness,
      $width,
      $height,
      _cabinetry_core_load_solid_wood_object(
        $this->railSolidMaterialTid,
        $this->panelSheetGood->thickness,
        $height
      ),
      ''
    );
  }

  public function getMeasurementToFurthestStud($position, $offset) {
    $cur_stud = $offset;
    $last_stud = $offset;
    while ($cur_stud - $position <= $this->maxRailLength) {
      $last_stud = $cur_stud;
      $cur_stud = $cur_stud + $this->studSpacing;
    }
    return $last_stud - $position;
  }

}
