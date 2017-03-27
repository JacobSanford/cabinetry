<?php

namespace Drupal\cabinetry_core;

use Drupal\cabinetry_core\PhysicalObjectInterface;
use Drupal\taxonomy\TermInterface;

/**
 * Provides an interface defining a Cabinet Project entity.
 *
 * @ingroup cabinetry_cabinet_project
 */
interface CabinetryPartInterface extends PhysicalObjectInterface {

  /**
   * Gets the material object of the part.
   *
   * @return \Drupal\taxonomy\TermInterface
   *   A term representing the material of the sheet.
   */
  public function getMaterial();

  /**
   * Sets the material of the part.
   *
   * @param \Drupal\taxonomy\TermInterface $material
   *   The material term.
   *
   * @return $this
   */
  public function setMaterial(TermInterface $material);

  /**
   * Gets the material tid of the part.
   *
   * @return int
   *   The term tid of the material.
   */
  public function getMaterialId();

  /**
   * Sets the material tid of the part.
   *
   * @param int $tid
   *   The tid of the material term.
   *
   * @return $this
   */
  public function setMaterialId($tid);

  /**
   * Gets the name of the cabinetry part.
   *
   * @return string
   *   The name of the cabinetry part.
   */
  public function getName();

  /**
   * Sets the name of the cabinetry part.
   *
   * @param string $name
   *   The name of the cabinetry part.
   *
   * @return $this
   */
  public function setName($name);

  /**
   * Gets the notes for the cabinetry part.
   *
   * @return string
   *   The notes for the cabinetry part.
   */
  public function getNotes();

  /**
   * Sets the notes for the cabinetry part.
   *
   * @param string $notes
   *   The notes for the cabinetry part.
   *
   * @return $this
   */
  public function setNotes($notes);

  /**
   * Gets the rotated status of the part.
   *
   * @return bool
   *   TRUE if the part is rotated, FALSE otherwise.
   */
  public function getRotatedValue();

  /**
   * Sets the rotated status of the part.
   *
   * @param bool $rotated
   *   TRUE if the part is rotated, FALSE otherwise.
   *
   * @return $this
   */
  public function setRotatedValue($rotated);

}
