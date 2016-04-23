<?php
/**
 * @file
 * Provides a generic object to serve as top element of a cabinetry project.
 */

/**
 * A generic object to serve as top element of a cabinetry project.
 */
class CabinetryProject {

  /**
   * An array of CabinetryEdgeBanding objects.
   *
   * @var array
   */
  public $banding = array();

  /**
   * An array of CabinetryComponent objects.
   *
   * @var array
   */
  public $components = array();

  /**
   * An array of CabinetryHardwareItem objects.
   *
   * @var array
   */
  public $hardware = array();

  /**
   * An array of CabinetryWoodPart objects.
   *
   * @var array
   */
  public $parts = array();

  /**
   * An array of text labels.
   *
   * @var array
   */
  public $labels = array();

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
   * Constructor.
   */
  public function __construct() {
    // pass.
  }

  /**
   * Add edge banding to the project materials list.
   *
   * @param array $banding_array
   *   An array of CabinetryEdgeBanding objects.
   */
  public function addBandingArray($banding_array) {
    foreach ($banding_array as $banding_object) {
      $object_found = FALSE;
      foreach ($this->banding as $banding_index => $banding_value) {
        if (
          $banding_value->material == $banding_object->material &&
          $banding_value->width == $banding_object->width
        ) {
          $this->banding[$banding_index]->add($banding_object->length);
          $object_found = TRUE;
        }
      }
      if ($object_found == FALSE) {
        $this->banding[] = new CabinetryEdgeBanding($banding_object->material, $banding_object->width);
        $this->banding[count($this->banding) - 1]->add($banding_object->length);
      }
    }
  }

  /**
   * Add a component to this project.
   *
   * @param object $component
   *   A CabinetryComponent object.
   */
  public function addComponent($component) {
    $this->components[] = $component;
  }

  /**
   * Add additional parts to this project.
   *
   * @param array $parts_array
   *   An array of CabinetryWoodPart objects.
   */
  protected function addParts(array $parts_array) {
    $this->parts = array_merge($this->parts, $parts_array);
  }

  /**
   * Collate a list of parts from all components of the project.
   */
  public function collateParts() {
    foreach ($this->components as $component_id => $component) {

      // Add parts.
      foreach ($component->parts as $part_id => $part) {
        $this->sortPart(
          $part,
          "[#$component_id] $component->label $part->label"
        );
        $this->labels[] = "[#$component_id]\n$component->label $part->label\n$part->notes";
      }

      // Add banding.
      if(!empty($component->banding)) {
        $this->addBandingArray($component->banding);
      }

      // Add hardware.
      foreach ($component->hardware as $hardware_id => $hardware_item) {
        $this->sortPart(
          $hardware_item,
          "[#$component_id] $component->label $hardware_item->name"
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
          'price' => $part->source->price,
          'parts' => array(),
        );
      }

      if (!empty($this->parts['CabinetrySolidWood'][$part->source->material]['parts']["$part->thickness"]["$part->height"]["$part->width"])) {
        $this->parts['CabinetrySolidWood'][$part->source->material]['parts']["$part->thickness"]["$part->height"]["$part->width"][] = array(
          'label' => $label,
          'notes' => $part->notes,
        );
      }
      else {
        $this->parts['CabinetrySolidWood'][$part->source->material]['parts']["$part->thickness"]["$part->height"]["$part->width"] = array(
          array(
            'label' => $label,
            'notes' => $part->notes,
          ),
        );
      }
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
    if (isset($this->parts['CabinetrySheetGood'])) {
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
  }

  /**
   * Pack sheet good parts into sheets.
   *
   * @param string $algorithm
   *    The algorithm to use to sort the parts.
   */
  public function packSolids($algorithm) {
    if (isset($this->parts['CabinetrySolidWood'])) {
      foreach ($this->parts['CabinetrySolidWood'] as $solid_index => $solid_type) {
        foreach ($solid_type['parts'] as $piece_thickness => $thickness_piece) {
          foreach ($thickness_piece as $piece_height => $height_piece) {

            $piece_array = array();
            $this->parts['CabinetrySolidWood'][$solid_index]['parts'][$piece_thickness][$piece_height]['plots'] = array();
            foreach ($height_piece as $piece_width => $width_pieces) {
              foreach ($width_pieces as $width_piece) {
                $piece_array[] = array(
                  'label' => $width_piece['label'],
                  'notes' => $width_piece['notes'],
                  'width' => $piece_width,
                  'height' => $piece_height,
                );
              }
            }
            $packer = new $algorithm(
              $this->solidStockLength,
              $piece_height,
              $piece_array,
              $this->bladeCutWidth,
              TRUE
            );
            $packer->pack();

            foreach ($packer->sheets as $sheet_index => $sheet) {
              $sheet_plotter = new CabinetrySheetGoodPlotter($sheet);
              $this->parts['CabinetrySolidWood'][$solid_index]['parts'][$piece_thickness][$piece_height]['plots'][] = $sheet_plotter->plotSheet();
            }
          }
        }
      }
    }
  }

  /**
   * Generate the plots for the cut and shelves for the sheets goods.
   */
  public function plotSheets() {
    if (isset($this->parts['CabinetrySheetGood'])) {
      foreach ($this->parts['CabinetrySheetGood'] as $sheet_type_index => $sheet_type) {
        foreach ($sheet_type['sheets'] as $sheet_index => $sheet) {
          $sheet_plotter = new CabinetrySheetGoodPlotter($sheet);
          $file_path = $sheet_plotter->plotSheet();
          $this->parts['CabinetrySheetGood'][$sheet_type_index]['plots'][$sheet_index] = $file_path;
        }
      }
    }
  }

}
