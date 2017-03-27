<?php

namespace Drupal\cabinetry_cabinet_project;

use Drupal\taxonomy\Entity\Term;

/**
 * Defines an object to help with taxonomy operations.
 */
class TaxonomyHelper {

  /**
   * Creates the default taxonomy terms for cabinet module types.
   */
  public static function addDefaultCabinetModuleTypes() {
    $config = \Drupal::config('cabinetry_cabinet_project.taxonomy.cabinetry_project_module_types.default_terms');
    $bit_items = $config->get('items');

    foreach ($bit_items as $bit_data) {
      Term::create(
        [
          'parent' => [],
          'name' => $bit_data['name'],
          'vid' => 'cabinetry_project_module_types',
          'field_cabinetry_proj_mod_class_n' => $bit_data['class'],
        ]
      )->save();
    }
  }

}
