<?php

namespace Drupal\cabinetry_cabinet_project\Form;

use Drupal\cabinetry_cabinet_project\CabinetProjectConstants;
use Drupal\Core\Entity\ContentEntityForm;
use Drupal\Core\Form\FormStateInterface;
use Drupal\node\Entity\Node;

/**
 * Form controller for the cabinetry_cabinet_module entity edit forms.
 *
 * @ingroup cabinetry_cabinet_project
 */
class CabinetModuleForm extends ContentEntityForm {

  protected $node;

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state, $node = NULL) {
    /* @var $entity \Drupal\cabinetry_cabinet_project\Entity\CabinetModule */
    $this->node = $node;

    $form = parent::buildForm($form, $form_state);
    $entity = $this->entity;

    $form['class'] = [
      '#type' => 'select',
      '#title' => $this->t('Cabinet Type'),
      '#weight' => -10,
      '#options' => _cabinetry_cabinet_project_project_cabinet_types($node),
      '#default_value' => $entity->getClass(),
    ];

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {
    $nid = $this->node;

    // Set custom entity properties.
    $entity = $this->getEntity();
    /* @var $entity \Drupal\cabinetry_cabinet_project\Entity\CabinetModule */
    $entity->setClassLabel($form['class']['#options'][$form_state->getValue('class')]);
    $entity->setClass($form_state->getValue('class'));
    $entity->save();

    // Add module to entity reference.
    $cabinet_project_node = Node::load($nid);
    $new_item = TRUE;

    foreach ($cabinet_project_node->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_MODULES_FIELD) as $module_delta => $module_entity) {
      if ($module_entity->get('entity')->getTarget()->getValue()->id() == $entity->id()) {
        $new_item = FALSE;
        break;
      }
    }

    if ($new_item) {
      $cabinet_project_node->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_MODULES_FIELD)->appendItem($entity->id());
      $cabinet_project_node->save();
    }

    // Rebuild the cabinet parts.
    batch_set(
      _cabinetry_cabinet_project_project_parts_build_batch($nid)
    );

    // Redirect back to cabinet module list.
    $form_state->setRedirect(
      'cabinetry_cabinet_project.manage_project_modules',
      [
        'node' => $nid,
      ]
    );
  }

}
