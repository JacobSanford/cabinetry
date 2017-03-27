<?php

namespace Drupal\cabinetry_core;

use Drupal\Core\Entity\ContentEntityInterface;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\taxonomy\TermInterface;
use Drupal\user\EntityOwnerInterface;

/**
 * Provides an interface defining a Cut Sheet entity.
 *
 * @ingroup cabinetry_core
 */
interface CutSheetInterface extends ContentEntityInterface, EntityOwnerInterface, EntityChangedInterface {

  /**
   * Gets the file objects of the cut sheet images.
   *
   * @return \Drupal\file\FileInterface[]
   *   An array of file objects for the cut sheet images.
   */
  public function getCutSheets();

  /**
   * Sets the cut sheet images for the cut sheet.
   *
   * @param \Drupal\file\FileInterface[] $sheets
   *   An array of Drupal\file\FileInterface values for the cut sheet images.
   *
   * @return $this
   */
  public function setCutSheets(array $sheets);

  /**
   * Gets the file id values of the cut sheet images.
   *
   * @return int[]
   *   An array of FID values for the cut sheet images.
   */
  public function getCutSheetIds();

  /**
   * Sets the file id values for the cut sheet images.
   *
   * @param int[] $sheet_ids
   *   An array of file id values for the cut sheet images.
   *
   * @return $this
   */
  public function setCutSheetIds(array $sheet_ids);

  /**
   * Gets the material object of the cut sheet.
   *
   * @return \Drupal\taxonomy\TermInterface
   *   A term representing the material of the sheet.
   */
  public function getMaterial();

  /**
   * Sets the material of the cut sheet.
   *
   * @param \Drupal\taxonomy\TermInterface $material
   *   The material term.
   *
   * @return $this
   */
  public function setMaterial(TermInterface $material);

  /**
   * Gets the material tid of the cut sheet.
   *
   * @return int
   *   The term tid of the material.
   */
  public function getMaterialId();

  /**
   * Sets the material tid of the cut sheet.
   *
   * @param int $tid
   *   The tid of the material term.
   *
   * @return $this
   */
  public function setMaterialId($tid);

  /**
   * Gets the name of the cut sheet.
   *
   * @return string
   *   The name of the object.
   */
  public function getName();

  /**
   * Sets the name of the cut sheet.
   *
   * @param string $name
   *   The name of the object.
   *
   * @return $this
   */
  public function setName($name);

}
