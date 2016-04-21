<?php
/**
 * @file
 * Provides a generic object to serve as components within a wainscoting project.
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
    // Assign component values to object from form.
    $this->studSpacing = (float) $section_component['field_cabinetry_wainscoting_stud'][LANGUAGE_NONE][0]['value'];
    $this->leftStudDistance = (float) $section_component['field_cabinetry_left_stud_distan'][LANGUAGE_NONE][0]['value'];
    $this->rightStudDistance = (float) $section_component['field_cabinetry_right_stud_dista'][LANGUAGE_NONE][0]['value'];
    $this->padLeftSide = (bool) $section_component['field_cabinetry_extend_left_stil'][LANGUAGE_NONE][0]['value'];
    $this->padRightSide = (bool) $section_component['field_cabinetry_extend_right_sti'][LANGUAGE_NONE][0]['value'];
    $this->numPanels = (int) $section_component['field_number_of_sections'][LANGUAGE_NONE][0]['value'];

    // Reduce size slightly to allow fitting.
    $this->width = $this->width - 2.0;

    // If connecting to padded/lapped side(s), reduce width.
    if ($this->padLeftSide == FALSE) {
      $this->width = $this->width - $this->solidThickness;
    }
    if ($this->padRightSide == FALSE) {
      $this->width = $this->width - $this->solidThickness;
    }

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
    $this->generateCleatParts();
    $this->generateBaseboardParts();
    $this->generateRoundOverParts();
    if ($this->skipBaseboard == FALSE) {
      $this->generateBaseCapTrimParts();
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
      - $this->solidThickness
      + (2 * $this->frameRouterBit->cutDepth);

    $this->stileWidth = $stile_width;

    for ($i = 0; $i <= $num_stiles - 1; $i++) {
      $stile_height = $this->stileHeight;
      $notes = 0.0;

      // If stiles are padded, use topRailHeight height and make a note to rip.
      if ($i == 0 && $this->padLeftSide == TRUE) {
        $stile_height = $this->topRailHeight;
        $notes = "Rip to " . ($this->stileHeight + $this->solidThickness) . "mm";
      }
      elseif ($i == $num_stiles - 1 && $this->padRightSide == TRUE) {
        $stile_height = $this->topRailHeight;
        $notes = "Rip to " . ($this->stileHeight + $this->solidThickness) . "mm";
      }
      $this->addSolidWoodPart($stile_width, $stile_height, $this->railSolidMaterialTid, "Stile $i", $notes);
      $this->totalStileHeight += $stile_height;

      // If stiles were padded, make sure we have a correct totalStileHeight.
      if ($i == 0 && $this->padLeftSide == TRUE) {
        $this->totalStileHeight = $this->totalStileHeight - ($this->topRailHeight - ($this->stileHeight + $this->solidThickness));
      }
      elseif ($i == $num_stiles - 1 && $this->padRightSide == TRUE) {
        $this->totalStileHeight = $this->totalStileHeight - ($this->topRailHeight - ($this->stileHeight + $this->solidThickness));
      }
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

  public function generateCleatParts() {
    $number_of_cleats = ceil($this->width / $this->panelSheetGood->width) + 2;
    for ($i = 0; $i < $number_of_cleats - 1; $i++) {
      $this->addSolidWoodPart($this->supportStrappingHeight, $this->chairRailHeight, $this->railSolidMaterialTid, "Cleat $i", '');
    }
  }

  public function generatePanelParts() {
    $panel_width = $this->width - $this->totalStileHeight;
    $each_panel_width = $panel_width / $this->numPanels + (2 * $this->frameRouterBit->cutDepth) - (2 * $this->panelUnderSize);
    $each_panel_height = $this->stileWidth;
    for ($i = 0; $i < $this->numPanels; $i++) {
      $this->addSheetGoodPart($each_panel_width, $each_panel_height, $this->panelSheetGood, "Panel $i");
    }
  }

  public function generateSolidParts($height, $max_length, $solid_tid, $label, $notes, $reverse = FALSE, $offset = 0, $needs_stud = FALSE) {
    $parts = array();
    $remainder_length = $this->width;

    if ($offset > 0) {
      $parts[] = array('width' => $offset);
      $remainder_length = $remainder_length - $offset;
    }

    while ($remainder_length > 0) {
      if ($remainder_length <= $max_length) {
        $parts[] = array('width' => $remainder_length);
        $remainder_length = 0;
      }
      else {
        $part_length = $max_length;
        if ($needs_stud == TRUE) {
          $part_length = $this->getMeasurementToFurthestStud($this->width - $remainder_length, $offset);
        }

        $parts[] = array('width' => $part_length);
        $remainder_length = $remainder_length - $part_length;
      }
    }

    if ($reverse == TRUE) {
      $parts = array_reverse($parts);
    }

    foreach ($parts as $part_index => $part) {
      $this->addSolidWoodPart($part['width'], $height, $solid_tid, "$label $part_index", $notes);
    }
  }

  public function generateSheetGoodParts($height, $sheet_good, $label, $notes, $reverse = FALSE, $offset = 0) {
    $parts = array();
    $remainder_length = $this->width;

    if ($offset > 0) {
      $parts[] = array('width' => $offset);
      $remainder_length = $remainder_length - $offset;
    }

    while ($remainder_length > 0) {
      if ($remainder_length <= $sheet_good->width) {
        $parts[] = array('width' => $remainder_length);
        $remainder_length = 0;
      }
      else {
        $part_length = $sheet_good->width;
        if ($sheet_good->width == TRUE) {
          $part_length = $this->getMeasurementToFurthestStud($this->width - $remainder_length, $offset);
        }

        $parts[] = array('width' => $part_length);
        $remainder_length = $remainder_length - $part_length;
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
