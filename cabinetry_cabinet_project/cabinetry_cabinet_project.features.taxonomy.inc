<?php
/**
 * @file
 * cabinetry_cabinet_project.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cabinetry_cabinet_project_taxonomy_default_vocabularies() {
  return array(
    'cabinetry_project_component_types' => array(
      'name' => 'Component Types',
      'machine_name' => 'cabinetry_project_component_types',
      'description' => 'Project Component Types',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -6,
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
    'cabinetry_rail_stile_router_bits' => array(
      'name' => 'Rail/Stile Router Bits',
      'machine_name' => 'cabinetry_rail_stile_router_bits',
      'description' => 'Rail/Stile Router Bits',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -7,
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
    'cabinetry_sheet_good_cores' => array(
      'name' => 'Sheet Good Cores',
      'machine_name' => 'cabinetry_sheet_good_cores',
      'description' => 'Core Materials for Sheet Goods',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -10,
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
    'cabinetry_sheet_goods' => array(
      'name' => 'Sheet Goods',
      'machine_name' => 'cabinetry_sheet_goods',
      'description' => 'Sheet Goods',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
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
    'cabinetry_veneers' => array(
      'name' => 'Veneers',
      'machine_name' => 'cabinetry_veneers',
      'description' => 'Veneer Materials',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
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
