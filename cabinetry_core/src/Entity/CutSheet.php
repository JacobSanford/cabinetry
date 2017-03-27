<?php

namespace Drupal\cabinetry_core\Entity;

use Drupal\cabinetry_core\CutSheetInterface;
use Drupal\Core\Entity\ContentEntityBase;
use Drupal\Core\Entity\EntityStorageInterface;
use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Field\BaseFieldDefinition;
use Drupal\Core\Field\FieldStorageDefinitionInterface;
use Drupal\taxonomy\TermInterface;
use Drupal\user\UserInterface;

/**
 * Defines the CutSheet entity.
 *
 * @ingroup cabinetry
 *
 * @ContentEntityType(
 *   id = "cabinetry_cut_sheet",
 *   label = @Translation("Material Cut Sheet"),
 *   base_table = "cabinetry_cut_sheet",
 *   handlers = {
 *     "views_data" = "Drupal\cabinetry_core\Entity\CutSheetViewsData",
 *   },
 *   entity_keys = {
 *     "id" = "id",
 *     "uuid" = "uuid",
 *   },
 * )
 */
class CutSheet extends ContentEntityBase implements CutSheetInterface {

  /**
   * {@inheritdoc}
   *
   * When a new entity instance is added, set the user_id entity reference to
   * the current user as the creator of the instance.
   */
  public static function preCreate(EntityStorageInterface $storage_controller, array &$values) {
    parent::preCreate($storage_controller, $values);
    $values += [
      'user_id' => \Drupal::currentUser()->id(),
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function getCreatedTime() {
    return $this->get('created')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function getChangedTime() {
    return $this->get('changed')->value;
  }

  /**
   * {@inheritdoc}
   */
  public function setChangedTime($timestamp) {
    $this->set('changed', $timestamp);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getChangedTimeAcrossTranslations() {
    $changed = $this->getUntranslated()->getChangedTime();
    foreach ($this->getTranslationLanguages(FALSE) as $language) {
      $translation_changed = $this->getTranslation($language->getId())->getChangedTime();
      $changed = max($translation_changed, $changed);
    }
    return $changed;
  }

  /**
   * {@inheritdoc}
   */
  public function getOwner() {
    return $this->get('user_id')->entity;
  }

  /**
   * {@inheritdoc}
   */
  public function setOwner(UserInterface $account) {
    $this->set('user_id', $account->id());
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getOwnerId() {
    return $this->get('user_id')->target_id;
  }

  /**
   * {@inheritdoc}
   */
  public function setOwnerId($uid) {
    $this->set('user_id', $uid);
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
  public function getMaterial() {
    return $this->get('material')->entity;
  }

  /**
   * {@inheritdoc}
   */
  public function setMaterial(TermInterface $material) {
    $this->set('material', $material->id());
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
  public function getCutSheets() {
    $cut_sheets = [];
    foreach ($this->get('cut_sheets') as $cut_sheet) {
      $cut_sheets[] = $cut_sheet->entity;
    }
    return $cut_sheets;
  }

  /**
   * {@inheritdoc}
   */
  public function setCutSheets(array $sheets) {
    $sheet_ids = [];
    foreach ($sheets as $sheet) {
      $sheet_ids[] = $sheet->id();
    }
    $this->set('cut_sheets', $sheet_ids);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function getCutSheetIds() {
    $cut_sheets = [];
    foreach ($this->get('cut_sheets') as $cut_sheet) {
      $cut_sheets[] = $cut_sheet->target_id;
    }
    return $cut_sheets;
  }

  /**
   * {@inheritdoc}
   */
  public function setCutSheetIds(array $sheet_ids) {
    $this->set('cut_sheets', $sheet_ids);
    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public static function baseFieldDefinitions(EntityTypeInterface $entity_type) {
    $fields['id'] = BaseFieldDefinition::create('integer')
      ->setLabel(t('ID'))
      ->setDescription(t('The ID of the Contact entity.'))
      ->setReadOnly(TRUE);

    $fields['uuid'] = BaseFieldDefinition::create('uuid')
      ->setLabel(t('UUID'))
      ->setDescription(t('The UUID of the Contact entity.'))
      ->setReadOnly(TRUE);

    $fields['user_id'] = BaseFieldDefinition::create('integer')
      ->setLabel(t('ID'))
      ->setDescription(t('The UID of the creator.'))
      ->setReadOnly(TRUE);

    $fields['langcode'] = BaseFieldDefinition::create('language')
      ->setLabel(t('Language code'))
      ->setDescription(t('The language code of Contact entity.'));

    $fields['created'] = BaseFieldDefinition::create('created')
      ->setLabel(t('Created'))
      ->setDescription(t('The time that the entity was created.'));

    $fields['changed'] = BaseFieldDefinition::create('changed')
      ->setLabel(t('Changed'))
      ->setDescription(t('The time that the entity was last edited.'));

    // The name of this sheet, typically the material and dimensions.
    $fields['name'] = BaseFieldDefinition::create('string')
      ->setLabel(t('Material'))
      ->setDescription(t('The material type of this sheet set.'))
      ->setSettings(
        [
          'default_value' => '',
          'max_length' => 255,
        ]
      );

    // The material of this sheet.
    $fields['material'] = BaseFieldDefinition::create('entity_reference')
      ->setLabel(t('Material'))
      ->setRequired(TRUE)
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

    // The images generated displaying the cut layout of the cabinets.
    $fields['cut_sheets'] = BaseFieldDefinition::create('image')
      ->setLabel(t('Cut Sheets'))
      ->setDescription(t('Cut Sheets'))
      ->setRequired(TRUE)
      ->setCardinality(FieldStorageDefinitionInterface::CARDINALITY_UNLIMITED)
      ->setSettings([
        'file_directory' => 'cut_sheets',
        'alt_field_required' => FALSE,
        'file_extensions' => 'png jpg jpeg',
      ])
      ->setDisplayOptions(
        'view',
        [
          'label' => 'hidden',
          'type' => 'default',
          'weight' => 0,
        ]
      )
      ->setDisplayOptions(
        'form',
        [
          'label' => 'hidden',
          'type' => 'image_image',
          'weight' => 0,
        ]
      )
      ->setDisplayConfigurable('form', TRUE)
      ->setDisplayConfigurable('view', TRUE);

    return $fields;
  }

}
