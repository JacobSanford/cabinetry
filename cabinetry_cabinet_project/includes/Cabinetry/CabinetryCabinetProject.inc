<?php
/**
 * @file
 * Provides a generic object to serve as a cabinet project.
 */

/**
 * A generic object to serve as cabinet project.
 */
class CabinetryCabinetProject extends CabinetryProject {

  /**
   * The router bit to use for rail/stile frames.
   *
   * @var object CabinetryToolItem
   */
  public $frameRouterBit = NULL;

  /**
   * The length of the solid stock to use.
   *
   * @var float
   */
  public $solidStockLength = 0.0;

  /**
   * The width of the cut blade.
   *
   * @var float
   */
  public $bladeCutWidth = 0.0;

  /**
   * Collate a list of parts from all components of the project.
   */
  public function collateParts() {
    foreach ($this->components as $component_id => $component) {

      // Add carcass panel parts.
      foreach ($component->parts as $part_id => $part) {
        $this->sortPart(
          $part,
          "$component->label[$component_id] $part->label"
        );
      }

      // Add door parts.
      foreach ($component->doors as $door_id => $door) {
        foreach ($door->parts as $door_part_id => $door_part) {
          $this->sortPart(
            $door_part,
            "$component->label[$component_id] Door $door_id $door_part->label"
          );
        }
      }

      // Add banding.
      $this->addBanding($component->banding);

      // Add hardware.
      foreach ($component->hardware as $hardware_id => $hardware_item) {
        $this->sortPart(
          $hardware_item,
          "$component->label[$component_id] $hardware_item->name"
        );
      }
    }
  }

  /**
   * Collate a list of parts from all components of the project.
   *
   * @param object $part
   *    A CabinetryWoodPart object to sort.
   * @param string $label
   *    A label to identify the part.
   */
  public function sortPart($part, $label) {

    // Sheet goods.
    if (isset($part->source) && $part->source instanceof CabinetrySheetGood) {
      if (!isset($this->parts['CabinetrySheetGood'])) {
        $this->parts['CabinetrySheetGood'] = array();
      }

      if (!isset($this->parts['CabinetrySheetGood'][$part->source->material])) {
        $this->parts['CabinetrySheetGood'][$part->source->material] = array(
          'width' => $part->source->width,
          'height' => $part->source->height,
          'price' => $part->source->price,
          'preserve_grain' => $part->source->preserveGrain,
          'sheets' => array(),
          'parts' => array(),
        );
      }

      $found_part = FALSE;
      foreach ($this->parts['CabinetrySheetGood'][$part->source->material]['parts'] as $part_index => $cur_part) {
        if ($cur_part['width'] == $part->width && $cur_part['height'] == $part->height) {
          $found_part = TRUE;
          $this->parts['CabinetrySheetGood'][$part->source->material]['parts'][$part_index]['items'][] = array(
            'label' => $label,
            'notes' => $part->notes,
          );
        }
      }
      if ($found_part == FALSE) {
        $this->parts['CabinetrySheetGood'][$part->source->material]['parts'][] = array(
          'items' => array(
            array(
              'label' => $label,
              'notes' => $part->notes,
            ),
          ),
          'width' => $part->width,
          'height' => $part->height,
        );
      }
    }

    // Solid Wood.
    if (isset($part->source) && $part->source instanceof CabinetrySolidWood) {

      if (!isset($this->parts['CabinetrySolidWood'])) {
        $this->parts['CabinetrySolidWood'] = array();
      }

      if (!isset($this->parts['CabinetrySolidWood'][$part->source->material])) {
        $this->parts['CabinetrySolidWood'][$part->source->material] = array(
          'thickness' => $part->source->thickness,
          'height' => $part->source->height,
          'price' => $part->source->price,
          'length' => 0.0,
          'board_feet' => 0.0,
          'parts' => array(),
        );
      }

      $found_part = FALSE;
      foreach ($this->parts['CabinetrySolidWood'][$part->source->material]['parts'] as $part_index => $cur_part) {
        if ($cur_part['length'] == $part->width) {
          $found_part = TRUE;
          $this->parts['CabinetrySolidWood'][$part->source->material]['parts'][$part_index]['items'][] = array(
            'label' => $label,
            'notes' => $part->notes,
          );
        }
      }
      if ($found_part == FALSE) {
        $this->parts['CabinetrySolidWood'][$part->source->material]['parts'][] = array(
          'items' => array(
            array(
              'label' => $label,
              'notes' => $part->notes,
            ),
          ),
          'length' => $part->width,
        );
      }

      $this->parts['CabinetrySolidWood'][$part->source->material]['length'] += $part->width;
      $part_boardfeet = $part->width * $this->parts['CabinetrySolidWood'][$part->source->material]['thickness'] * $this->parts['CabinetrySolidWood'][$part->source->material]['height'] * CABINETRY_CORE_MM3_TO_BOARDFEET;
      $this->parts['CabinetrySolidWood'][$part->source->material]['board_feet'] += $part_boardfeet;
    }

    // Hardware.
    if ($part instanceof CabinetryHardwareItem) {
      if (!isset($this->hardware[$part->name])) {
        $this->hardware[$part->name] = array(
          'name' => $part->name,
          'count' => 1,
          'price' => $part->price,
        );
      }
      else {
        $this->hardware[$part->name]['count']++;
      }
    }
  }

  /**
   * Pack sheet good parts into sheets.
   *
   * @param string $algorithm
   *    The algorithm to use to sort the parts.
   */
  public function packSheets($algorithm) {
    foreach ($this->parts['CabinetrySheetGood'] as $sheet_type_index => $sheet_type) {

      $piece_array = array();
      foreach ($sheet_type['parts'] as $piece_index => $piece) {
        foreach ($piece['items'] as $item) {
          $piece_array[] = array(
            'label' => $item['label'],
            'notes' => $item['notes'],
            'width' => $piece['width'],
            'height' => $piece['height'],
          );
        }
      }

      $packer = new $algorithm(
        $sheet_type['width'],
        $sheet_type['height'],
        $piece_array,
        $this->bladeCutWidth,
        $sheet_type['preserve_grain']
      );
      $packer->pack();
      $this->parts['CabinetrySheetGood'][$sheet_type_index]['sheets'] = $packer->sheets;
    }
  }

  /**
   * Pack sheet good parts into sheets.
   *
   * @param string $algorithm
   *    The algorithm to use to sort the parts.
   */
  public function packSolids($algorithm) {
    foreach ($this->parts['CabinetrySolidWood'] as $solid_index => $solid_type) {
      $this->parts['CabinetrySolidWood'][$solid_index]['plots'] = array();
      $piece_array = array();
      foreach ($solid_type['parts'] as $piece_index => $piece) {
        foreach ($piece['items'] as $item) {
          $piece_array[] = array(
            'label' => $item['label'],
            'notes' => $item['notes'],
            'width' => $piece['length'],
            'height' => $solid_type['height'],
          );
        }
      }

      $packer = new $algorithm(
        $this->solidStockLength,
        $solid_type['height'],
        $piece_array,
        $this->bladeCutWidth,
        TRUE
      );
      $packer->pack();

      foreach ($packer->sheets as $sheet_index => $sheet) {
        $sheet_plotter = new CabinetrySheetGoodPlotter($sheet);
        $this->parts['CabinetrySolidWood'][$solid_index]['plots'][] = $sheet_plotter->plotSheet();
      }

    }
  }

  /**
   * Generate the plots for the cut and shelves for the sheets goods.
   */
  public function plotSheets() {
    foreach ($this->parts['CabinetrySheetGood'] as $sheet_type_index => $sheet_type) {
      foreach ($sheet_type['sheets'] as $sheet_index => $sheet) {
        $sheet_plotter = new CabinetrySheetGoodPlotter($sheet);
        $file_path = $sheet_plotter->plotSheet();
        $this->parts['CabinetrySheetGood'][$sheet_type_index]['plots'][$sheet_index] = $file_path;
      }
    }
  }

}
