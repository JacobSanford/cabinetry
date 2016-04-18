<?php
/**
 * @file
 * cabinetry_wainscoting_project.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cabinetry_wainscoting_project_taxonomy_default_vocabularies() {
  return array(
    'cabinetry_wainscoting_style' => array(
      'name' => 'Wainscoting Style',
      'machine_name' => 'cabinetry_wainscoting_style',
      'description' => 'Wainscoting Style',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
