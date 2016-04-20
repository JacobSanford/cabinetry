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
   * The height of the stiles, in millimeters.
   *
   * @var float
   */
  public $solidThickness = 19.05;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $topRailHeight = 114.3;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $bottomRailHeight = 88.9;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $chairRailHeight = 57.15;

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
   * @var object
   */
  public $roundOverMaterial = NULL;

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
   * @var float
   */
  public $stileWidth = 0.0;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $totalStileHeight = 0.0;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var int
   */
  public $numPanels = 1;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var float
   */
  public $panelUnderSize = 2.0;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var object
   */
  public $trimMaterial = NULL;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var object
   */
  public $coveMouldingMaterial = NULL;

  /**
   * The height of the top rail, in millimeters.
   *
   * @var object
   */
  public $skipBaseboard = FALSE;

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
    $this->generateChairRailParts();
    $this->generateCoveMouldingParts();
    $this->generatePanelParts();
    if ($this->skipBaseboard == FALSE) {
      $this->generateBaseboardParts();
      $this->generateBaseCapTrimParts();
      $this->generateRoundOverParts();
    }
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
      $this->addSolidWoodPart($part['width'], $height, $this->railSolidMaterialTid, "$label Rail $part_index");
    }
  }

  public function generateStileParts() {
    $this->totalStileHeight = 0.0;
    $num_stiles = $this->numPanels + 1;
    $stile_width = $this->height
      - $this->supportStrappingHeight
      - $this->bottomRailHeight
      - $this->topRailHeight
      - $this->panelSheetGood->thickness
      + (2 * $this->frameRouterBit->cutDepth);
    $this->stileWidth = $stile_width;

    for ($i = 0; $i <= $num_stiles - 1; $i++) {
      $stile_height = $this->stileHeight;
      $notes = 0.0;

      if ($i == 0 && $this->padLeftSide == TRUE) {
        $stile_height = $this->topRailHeight;
        $notes = "Rip to " . ($stile_height + $this->panelSheetGood->thickness) . "mm";
      }
      elseif ($i == $num_stiles - 1 && $this->padRightSide == TRUE) {
        $stile_height = $this->topRailHeight;
        $notes = "Rip to " . ($stile_height + $this->panelSheetGood->thickness) . "mm";
      }
      $this->addSolidWoodPart($stile_width, $stile_height, $this->railSolidMaterialTid, "Stile $i", $notes);
      $this->totalStileHeight += $stile_height;
    }
  }

  public function generateChairRailParts() {
    $this->generateSolidParts($this->chairRailHeight, $this->maxRailLength, $this->railSolidMaterialTid, 'Chair Rail', '', FALSE);
  }

  public function generateCoveMouldingParts() {
    $this->generateSheetGoodParts($this->coveMouldingMaterial->height, $this->coveMouldingMaterial, 'Cove', '', TRUE);
  }

  public function generateRoundOverParts() {
    $this->generateSheetGoodParts($this->roundOverMaterial->height, $this->roundOverMaterial, 'Round Over', '', TRUE);
  }

  public function generateBaseCapTrimParts() {
    $this->generateSheetGoodParts($this->trimMaterial->height, $this->trimMaterial, 'Base Cap', '', TRUE);
  }

  public function generateBaseboardParts() {
    $this->generateSheetGoodParts($this->baseBoardHeight, $this->panelSheetGood, "BaseBoard", '', FALSE);
  }

  public function generatePanelParts() {
    $panel_width = $this->width - $this->totalStileHeight;
    $each_panel_width = $panel_width / $this->numPanels + (2 * $this->frameRouterBit->cutDepth) - (2 * $this->panelUnderSize);
    $each_panel_height = $this->stileWidth;
    for ($i = 0; $i < $this->numPanels; $i++) {
      $this->addSheetGoodPart($each_panel_width, $each_panel_height, $this->panelSheetGood, "Panel $i");
    }
  }

  public function generateSolidParts($height, $max_length, $solid_tid, $label, $notes, $reverse = FALSE) {
    $parts = array();
    if ($this->width <= $max_length) {
      $parts[] = array('width' => $this->width);
    }
    else {
      $remainder_length = $this->width;
      while ($remainder_length > 0) {
        // Cut a custom length to get final piece.
        if ($remainder_length <= $max_length) {
          $parts[] = array('width' => $remainder_length);
          $remainder_length = 0;
        }
        else {
          $parts[] = array('width' => $max_length);
          $remainder_length = $remainder_length - $max_length;
        }
      }
    }
    if ($reverse == TRUE) {
      $parts = array_reverse($parts);
    }
    foreach ($parts as $part_index => $part) {
      $this->addSolidWoodPart($part['width'], $height, $solid_tid, "$label $part_index", $notes);
    }
  }

  public function generateSheetGoodParts($height, $sheet_good, $label, $notes, $reverse = FALSE) {
    $parts = array();
    if ($this->width <= $sheet_good->width) {
      $parts[] = array('width' => $this->width);
    }
    else {
      $remainder_length = $this->width;
      while ($remainder_length > 0) {
        // Cut a custom length to get final piece.
        if ($remainder_length <= $sheet_good->width) {
          $parts[] = array('width' => $remainder_length);
          $remainder_length = 0;
        }
        else {
          $parts[] = array('width' => $sheet_good->width);
          $remainder_length = $remainder_length - $sheet_good->width;
        }
      }
    }
    if ($reverse == TRUE) {
      $parts = array_reverse($parts);
    }
    foreach ($parts as $part_index => $part) {
      $this->addSheetGoodPart($part['width'], $height, $sheet_good, "$label $part_index", $notes);
    }
  }

  public function addSolidWoodPart($width, $height, $solid_tid, $label, $notes = '') {
    $this->parts[] = new CabinetryWoodPart(
      $label,
      $this->solidThickness,
      $width,
      $height,
      _cabinetry_core_load_solid_wood_object(
        $solid_tid,
        $this->solidThickness,
        $height
      ),
      $notes
    );
  }

  public function addSheetGoodPart($width, $height, $sheet_good, $label, $notes = '') {
    $this->parts[] = new CabinetryWoodPart(
      $label,
      $sheet_good->thickness,
      $width,
      $height,
      $sheet_good,
      $notes
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
