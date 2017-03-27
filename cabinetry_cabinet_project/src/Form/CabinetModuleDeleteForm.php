<?php

namespace Drupal\cabinetry_cabinet_project\Form;

use Drupal\cabinetry_cabinet_project\CabinetProjectConstants;
use Drupal\Core\Entity\ContentEntityConfirmFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;
use Drupal\node\Entity\Node;

/**
 * Provides a form for deleting a cabinetry_cabinet_project entity.
 *
 * @ingroup cabinetry_cabinet_project
 */
class CabinetModuleDeleteForm extends ContentEntityConfirmFormBase {

  protected $delta;
  protected $node;

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state, $node = NULL, $delta = NULL) {
    /* @var $entity \Drupal\cabinetry_cabinet_project\Entity\CabinetModule */
    $this->node = $node;
    $this->delta = $delta;
    $form = parent::buildForm($form, $form_state);

    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function getQuestion() {
    return $this->t(
      'Are you sure you want to delete entity %name?',
      ['%name' => $this->entity->label()]
    );
  }

  /**
   * {@inheritdoc}
   *
   * If the delete command is canceled, return to the contact list.
   */
  public function getCancelURL() {
    return Url::fromUri("internal:/node/{$this->node}/cabinet_modules");
  }

  /**
   * {@inheritdoc}
   */
  public function getConfirmText() {
    return $this->t('Delete');
  }

  /**
   * {@inheritdoc}
   *
   * Delete the entity and log the event. log() replaces the watchdog.
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    $entity = $this->getEntity();
    $entity->delete();

    \Drupal::logger('cabinetry_cabinet_project')->notice(
      '@type: deleted %title.',
      [
        '@type' => $this->entity->bundle(),
        '%title' => $this->entity->label(),
      ]
    );

    // Add module to entity reference.
    $cabinet_project_node = Node::load($this->node);
    $cabinet_project_node
      ->get(CabinetProjectConstants::CABINET_PROJECT_CABINET_MODULES_FIELD)
      ->get($this->delta)->setValue([]);
    $cabinet_project_node->save();

    // Rebuild the cabinet parts.
    batch_set(
      _cabinetry_cabinet_project_project_parts_build_batch($this->node)
    );

    $form_state->setRedirect(
      'cabinetry_cabinet_project.manage_project_modules',
      [
        'node' => $this->node,
      ]
    );
  }

}
