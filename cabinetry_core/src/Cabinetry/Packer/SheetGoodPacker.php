<?php

namespace Drupal\cabinetry_core\Cabinetry\Packer;

use Drupal\cabinetry_cabinet_project\CabinetProjectConstants;
use Drupal\cabinetry_core\Cabinetry\Plotter\SheetGoodPlotter;
use Drupal\cabinetry_core\CoreConstants;
use Drupal\file\Entity\File;
use Drupal\node\Entity\Node;
use Drupal\node\NodeInterface;
use Drupal\taxonomy\Entity\Term;
use Drupal\taxonomy\TermInterface;

/**
 * A generic object for packing a sheet good from a piece list.
 *
 * @TODO Remove shameful CabinetProjectConstants dependency
 */
class SheetGoodPacker {

  /**
   * The blade cut width to allow for, in millimeters.
   *
   * @var float
   */
  protected $cutWidth = 0.0;

  /**
   * Does this sheet have grain that should be vertical?
   *
   * @var bool
   */
  protected $hasGrain = TRUE;

  /**
   * The height (y) of the sheet good, in millimeters.
   *
   * @var float
   */
  protected $height = 0.0;

  /**
   * A list of pieces to sort into sheets.
   *
   * @var \Drupal\cabinetry_core\CabinetryPartInterface[]
   */
  protected $parts = [];

  /**
   * A list of sheets generated by the packing.
   *
   * @var \Drupal\cabinetry_core\Cabinetry\Packer\ShelfFF\ShelfFFSheet[]
   */
  protected $sheets = [];

  /**
   * The width (x) of the sheet good, in millimeters.
   *
   * @var float
   */
  protected $width = 0.0;

  /**
   * The parent project node.
   *
   * @var \Drupal\node\NodeInterface
   */
  protected $project = NULL;

  /**
   * The sheet material.
   *
   * @var \Drupal\taxonomy\TermInterface
   */
  protected $material = NULL;

  /**
   * Constructor.
   *
   * @param \Drupal\node\NodeInterface $project
   *   The width of the shelf, in millimeters.
   * @param \Drupal\taxonomy\TermInterface $material
   *   The blade cut width to allow for when packing the sheet.
   * @param \Drupal\cabinetry_core\CabinetryPartInterface[] $parts
   *   Parts to pack into sheets.
   */
  protected function __construct(NodeInterface $project, TermInterface $material, array $parts) {
    $this->project = $project;
    $this->material = $material;
    $this->parts = $parts;
    $material_vocabulary = $this->material->getVocabularyId();

    $this->width = $this->material->get(CoreConstants::CABINETRY_MATERIAL_WIDTH_FIELD)->getString();

    if (in_array($material_vocabulary, CoreConstants::CABINETRY_MATERIAL_IS_SOLID)) {
      // Solid material.
      $this->height = $this->project
        ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_RAILSTILE_HEIGHT_FIELD)
        ->getString();

      $this->depth = $this->project
        ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_RAILSTILE_THICKNESS_FIELD)
        ->getString();

      $this->hasGrain = TRUE;
    }
    else {
      // Sheet good.
      $this->height = $this->material->get(CoreConstants::CABINETRY_MATERIAL_HEIGHT_FIELD)->getString();
      $this->depth = $this->material->get(CoreConstants::CABINETRY_MATERIAL_DEPTH_FIELD)->getString();
      $this->hasGrain = $this->material->get(CoreConstants::CABINETRY_MATERIAL_PRESERVE_GRAIN_FIELD)->getString();
    }

    $this->cutWidth = $this->project
      ->get(CabinetProjectConstants::CABINET_PROJECT_SAW_BLADE_FIELD)
      ->first()->get('entity')->getTarget()->getValue()
      ->get(CoreConstants::CABINETRY_MATERIAL_WIDTH_FIELD)->getString();
  }

  /**
   * Constructor.
   *
   * @param int $project_nid
   *   The parent project node.
   * @param array $context
   *   The batch API context associative array for the batch.
   */
  public static function packParts($project_nid, array &$context) {
    $project = Node::load($project_nid);

    // Collate parts before packing sheets.
    $parts = [];
    foreach ($project->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_PARTS_FIELD) as $project_part) {
      $part = $project_part->get('entity')->getTarget()->getValue();
      /* @var $part \Drupal\cabinetry_core\CabinetryPartInterface */
      $tid = $part->getMaterialId();

      if (!isset($parts[$tid])) {
        $parts[$tid] = [];
      }
      $parts[$tid][] = $part;
    }

    // Pack each material type separately.
    foreach ($parts as $material_tid => $part_data) {
      $material = Term::load($material_tid);

      $obj = new static(
        $project,
        $material,
        $part_data
      );

      $sheet_files = [];
      foreach ($obj->sheets as $cur_sheet) {
        $plotter = new SheetGoodPlotter($cur_sheet);
        $image_path = $plotter->plotSheet();
        $sheet_files[] = $obj->addFileToSystem($image_path, '.png');
      }

      $cut_sheet_entity_data = [
        'type' => 'cabinetry_cut_sheet',
        'name' => $material->getName(),
        'material' => $material_tid,
        'cut_sheets' => $sheet_files,
      ];

      $cut_sheet_entity = \Drupal::entityTypeManager()
        ->getStorage('cabinetry_cut_sheet')
        ->create($cut_sheet_entity_data);
      $cut_sheet_entity->save();

      $project->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_CUT_SHEETS_FIELD)
        ->appendItem($cut_sheet_entity);
      $project->save();

      unset($obj);
    }

    $context['message'] = t(
      "Packed sheets for @project_name",
      [
        '@project_name' => $project->getTitle(),
      ]
    );
  }

  /**
   * Add a file from the disk to the filesystem.
   *
   * @param string $source
   *   The path to the file on the disk.
   * @param string $add_extension
   *   The extension to add to the file after copying to the filesystem.
   *
   * @return mixed
   *   The file object if the file was added, FALSE otherwise.
   */
  protected static function addFileToSystem($source, $add_extension = NULL) {
    $basename = basename($source);

    $dir = "public://cut_sheets";
    file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
    $destination = "$dir/$basename$add_extension";

    if (file_exists($source)) {
      $uri = file_unmanaged_copy($source, $destination, FILE_EXISTS_REPLACE);
      $file = File::Create([
        'uri' => $uri,
      ]);
      $file->setPermanent();
      $file->save();
      return $file;
    }
    else {
      return FALSE;
    }
  }

}
