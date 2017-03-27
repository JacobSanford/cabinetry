<?php

namespace Drupal\cabinetry_cabinet_project\Controller;

use Drupal\cabinetry_cabinet_project\CabinetProjectConstants;
use Drupal\Core\Access\AccessResult;
use Drupal\Core\Controller\ControllerBase;
use Drupal\node\Entity\Node;

/**
 * CabinetProjectCheckTypeController object.
 */
class CabinetProjectCheckTypeController extends ControllerBase {

  /**
   * Check to see if a node is a cabinet project node.
   *
   * @param int $node
   *   The node ID to check.
   *
   * @return bool
   *   TRUE if the node is type CABINET_PROJECT_ENTITY_NAME. FALSE otherwise.
   */
  public function checkType($node) {
    $actual_node = Node::load($node);
    return AccessResult::allowedIf($actual_node->bundle() === CabinetProjectConstants::CABINET_PROJECT_ENTITY_NAME);
  }

}
