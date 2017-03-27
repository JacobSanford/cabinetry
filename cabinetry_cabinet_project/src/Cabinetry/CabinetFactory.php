<?php

namespace Drupal\cabinetry_cabinet_project\Cabinetry;

use Drupal\cabinetry_cabinet_project\CabinetProjectConstants;
use Drupal\node\Entity\Node;

/**
 * A generic object to serve as cabinetry cabinet project.
 */
class CabinetFactory {

  /**
   * Constructor.
   *
   * @param int $nid
   *   The node ID of the project to create.
   * @param int $eid
   *   The entity ID of the cabinet_module to generate parts for.
   */
  public function __construct($nid, $eid = NULL) {
    // pass.
  }

  /**
   * Clear current project parts, optionally in a batch operation.
   *
   * @param int $nid
   *   The node ID of the project to create.
   * @param array $context
   *   The batch context.
   */
  public static function clearProjectParts($nid, array &$context = []) {
    $node = Node::load($nid);

    // Sheet Entities.
    foreach ($node->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_CUT_SHEETS_FIELD) as $sheet_entity) {
      foreach ($sheet_entity->entity->get('cut_sheets') as $file_entity) {
        $file_entity->entity->delete();
      }
      $sheet_entity->entity->delete();
    }
    $node->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_CUT_SHEETS_FIELD)->setValue([]);

    // Remove attached cabinet parts.
    foreach ($node->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_PARTS_FIELD) as $part_entity) {
      $part_entity->entity->delete();
    }
    $node->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_PARTS_FIELD)->setValue([]);

    // Remove attached cut sheets.
    foreach ($node->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_CUT_SHEETS_FIELD) as $cut_sheet_entity) {
      if (!empty($cut_sheet_entity->entity)) {
        $cut_sheet_entity->entity->delete();
      }
    }
    $node->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_CUT_SHEETS_FIELD)->setValue([]);

    $node->save();

    $context['message'] = t(
      "Deleted existing child entities from @project_name",
      [
        '@project_name' => $node->getTitle(),
      ]
    );
  }

  /**
   * Generate the parts for a cabinet module.
   *
   * @param int $nid
   *   The node ID of the project to create.
   * @param int $eid
   *   The entity ID of the cabinet_module to generate parts for.
   * @param array $context
   *   The batch context.
   */
  public static function generateModuleParts($nid, $eid, array &$context) {
    $node = Node::load($nid);
    $entity = \Drupal::entityTypeManager()
      ->getStorage(CabinetProjectConstants::CABINET_MODULE_ENTITY_NAME)
      ->load($eid);
    /* @var $entity \Drupal\cabinetry_cabinet_project\CabinetModuleInterface */

    $class = $entity->getClass();
    $builder = new $class($node, $entity);
    /* @var $builder \Drupal\cabinetry_cabinet_project\Cabinetry\CabinetComponent */
    $builder->build();

    foreach ($builder->parts as $cur_part) {
      // Create part.
      $data = [
        'type' => 'cabinetry_part',
        'depth' => (float) $cur_part->thickness,
        'height' => (float) $cur_part->height,
        'width' => (float) $cur_part->width,
        'name' => (string) "[{$entity->getName()}] {$cur_part->label}",
        'notes' => (string) $cur_part->notes,
        'material' => $cur_part->material,
      ];
      $cabinet_module = \Drupal::entityTypeManager()
        ->getStorage('cabinetry_part')
        ->create($data);
      $cabinet_module->save();

      // Attach to node field_cabinetry_cabinet_parts.
      $node->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_PARTS_FIELD)->appendItem($cabinet_module->id());
    }
    $node->save();

    $context['message'] = t(
      "Generated parts for Module @module_name",
      [
        '@module_name' => $eid,
      ]
    );
  }

}
