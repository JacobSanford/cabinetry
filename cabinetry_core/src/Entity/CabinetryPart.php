<?php

namespace Drupal\cabinetry_core\Entity;

use Drupal\cabinetry_core\CabinetryPartInterface;
use Drupal\cabinetry_core\Entity\PhysicalObject;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\taxonomy\TermInterface;

/**
 * Defines the CabinetModule entity.
 *
 * @ingroup cabinetry
 *
 * @ContentEntityType(
 *   id = "cabinetry_part",
 *   label = @Translation("Cabinet Part"),
 *   base_table = "cabinetry_cabinet_part",
 *   entity_keys = {
 *     "id" = "id",
 *     "uuid" = "uuid",
 *   },
 * )
 */
class CabinetryPart extends PhysicalObject implements CabinetryPartInterface {

  /**
   * Indicates whether this part has been rotated when packing.
   *
   * @var bool
   */
  public $rotated = FALSE;

  /**
   * {@inheritdoc}
   */
  public function getMaterial() {
    return $this->get('material')->entity;
  }

  /**
   * {@inheritdoc}
   */
  public function setMaterial(TermInterface $material) {
    $this->set('material', $material);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getMaterialId() {
    return $this->get('material')->target_id;
  }

  /**
   * {@inheritdoc}
   */
  public function setMaterialId($tid) {
    $this->set('material', $tid);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getName() {
    return $this->get('name')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setName($name) {
    $this->set('name', $name);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getNotes() {
    return $this->get('notes')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setNotes($notes) {
    $this->set('name', $notes);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getRotatedValue() {
    return $this->rotated;
  }

  /**
   * {@inheritdoc}
   */
  public function setRotatedValue($rotated) {
    $this->rotated = $rotated;
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {
    $fields = parent::baseFieldDefinitions($entity_type);

    // The name to be displayed on the cut sheet and labels for this part.
    $fields['name'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Name'))
      ->setDescription(t('The name of this part.'))
      ->setSettings(
        [
          'default_value' => '',
          'max_length' => 255,
        ]
      );

    // Any specific notes or instructions for this part, displayed on label.
    $fields['notes'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Notes'))
      ->setDescription(t('Any notes relating to this part.'))
      ->setSettings(
        [
          'default_value' => '',
          'max_length' => 255,
        ]
      );

    // The material of this part.
    $fields['material'] = BaseFieldDefinition::create('entity_reference')
      ->setLabel(t('Material'))
      ->setSettings(
        [
          'target_type' => 'taxonomy_term',
          'handler' => 'default:taxonomy_term',
          'multiple' => FALSE,
          'handler_settings' => [
            'target_bundles' => [
              'cabinetry_sheet_goods' => 'cabinetry_sheet_goods',
              'cabinetry_solid_stock' => 'cabinetry_solid_stock',
            ],
          ],
        ]
      );

    return $fields;
  }

}
