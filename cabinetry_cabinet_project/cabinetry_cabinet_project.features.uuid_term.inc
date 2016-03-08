<?php
/**
 * @file
 * cabinetry_cabinet_project.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function cabinetry_cabinet_project_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => '3/4"(19.3mm) Ranger Board MDF',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0009dab1-c1a3-41f3-8346-be904463f815',
    'vocabulary_machine_name' => 'cabinetry_sheet_goods',
    'field_cabinetry_height' => array(
      'und' => array(
        0 => array(
          'value' => 1245,
        ),
      ),
    ),
    'field_cabinetry_item_cost' => array(),
    'field_cabinetry_sheet_core' => array(
      'und' => array(
        0 => array(
          'tid' => '9f87de29-3de6-4a39-acd3-74dd52f2d06b',
        ),
      ),
    ),
    'field_cabinetry_sheet_veneer_one' => array(),
    'field_cabinetry_sheet_veneer_two' => array(),
    'field_cabinetry_thickness' => array(
      'und' => array(
        0 => array(
          'value' => 19.3,
        ),
      ),
    ),
    'field_cabinetry_width' => array(
      'und' => array(
        0 => array(
          'value' => 2465,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Basic European Cabinet',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '075288c7-3a0c-40c5-b371-4101e55b586b',
    'vocabulary_machine_name' => 'cabinetry_project_component_types',
    'field_cabinetry_php_library_clas' => array(
      'und' => array(
        0 => array(
          'value' => 'BasicEuroCabinet',
          'format' => NULL,
          'safe_value' => 'BasicEuroCabinet',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Laminated Wood',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5a93ccb2-2e2c-4d49-90d7-01eee753de92',
    'vocabulary_machine_name' => 'cabinetry_sheet_good_cores',
  );
  $terms[] = array(
    'name' => 'White Mother of Pearl Melamine',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5faf5a8a-f759-40c1-bfe7-f2a405522373',
    'vocabulary_machine_name' => 'cabinetry_veneers',
    'field_cabinetry_color' => array(
      'und' => array(
        0 => array(
          'value' => 'White',
          'format' => NULL,
          'safe_value' => 'White',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '5/8" (16.8mm) Full Sheet White MOP Melamine',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '73a4786b-cb44-4eb9-a95e-7412c0a89b5f',
    'vocabulary_machine_name' => 'cabinetry_sheet_goods',
    'field_cabinetry_height' => array(
      'und' => array(
        0 => array(
          'value' => 1245,
        ),
      ),
    ),
    'field_cabinetry_item_cost' => array(),
    'field_cabinetry_sheet_core' => array(
      'und' => array(
        0 => array(
          'tid' => 'cf12db6f-ed1b-4609-aab3-5bbd479eaf71',
        ),
      ),
    ),
    'field_cabinetry_sheet_veneer_one' => array(
      'und' => array(
        0 => array(
          'tid' => '5faf5a8a-f759-40c1-bfe7-f2a405522373',
        ),
      ),
    ),
    'field_cabinetry_sheet_veneer_two' => array(
      'und' => array(
        0 => array(
          'tid' => '5faf5a8a-f759-40c1-bfe7-f2a405522373',
        ),
      ),
    ),
    'field_cabinetry_thickness' => array(
      'und' => array(
        0 => array(
          'value' => 16.8,
        ),
      ),
    ),
    'field_cabinetry_width' => array(
      'und' => array(
        0 => array(
          'value' => 2465,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'MDF',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9f87de29-3de6-4a39-acd3-74dd52f2d06b',
    'vocabulary_machine_name' => 'cabinetry_sheet_good_cores',
  );
  $terms[] = array(
    'name' => '1/4" (6mm) Birch OSB Core G2S',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'aef00698-5a82-485d-9519-941b8ed42ff7',
    'vocabulary_machine_name' => 'cabinetry_sheet_goods',
    'field_cabinetry_height' => array(
      'und' => array(
        0 => array(
          'value' => 1230,
        ),
      ),
    ),
    'field_cabinetry_item_cost' => array(),
    'field_cabinetry_sheet_core' => array(
      'und' => array(
        0 => array(
          'tid' => 'cf12db6f-ed1b-4609-aab3-5bbd479eaf71',
        ),
      ),
    ),
    'field_cabinetry_sheet_veneer_one' => array(
      'und' => array(
        0 => array(
          'tid' => 'b3332c91-ba60-470d-bd13-53c2ba1eb999',
        ),
      ),
    ),
    'field_cabinetry_sheet_veneer_two' => array(
      'und' => array(
        0 => array(
          'tid' => 'b3332c91-ba60-470d-bd13-53c2ba1eb999',
        ),
      ),
    ),
    'field_cabinetry_thickness' => array(
      'und' => array(
        0 => array(
          'value' => 6,
        ),
      ),
    ),
    'field_cabinetry_width' => array(
      'und' => array(
        0 => array(
          'value' => 2447,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'White Birch',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b3332c91-ba60-470d-bd13-53c2ba1eb999',
    'vocabulary_machine_name' => 'cabinetry_veneers',
    'field_cabinetry_color' => array(
      'und' => array(
        0 => array(
          'value' => 'Natural',
          'format' => NULL,
          'safe_value' => 'Natural',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'OSB',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cf12db6f-ed1b-4609-aab3-5bbd479eaf71',
    'vocabulary_machine_name' => 'cabinetry_sheet_good_cores',
  );
  $terms[] = array(
    'name' => 'Shaker Door Bit from Rockler',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e70085fd-01ae-4364-b3e3-59edb54911de',
    'vocabulary_machine_name' => 'cabinetry_rail_stile_router_bits',
    'field_cabinetry_rail_cut_depth' => array(
      'und' => array(
        0 => array(
          'value' => 9.5,
        ),
      ),
    ),
    'field_cabinetry_rail_cut_thickne' => array(
      'und' => array(
        0 => array(
          'value' => 6,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => '1/4" (6mm) FibreLex White One Side',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f1457487-ea01-4f59-9b73-b45a4e72d6b6',
    'vocabulary_machine_name' => 'cabinetry_sheet_goods',
    'field_cabinetry_height' => array(
      'und' => array(
        0 => array(
          'value' => 1220,
        ),
      ),
    ),
    'field_cabinetry_item_cost' => array(),
    'field_cabinetry_sheet_core' => array(
      'und' => array(
        0 => array(
          'tid' => '9f87de29-3de6-4a39-acd3-74dd52f2d06b',
        ),
      ),
    ),
    'field_cabinetry_sheet_veneer_one' => array(
      'und' => array(
        0 => array(
          'tid' => '5faf5a8a-f759-40c1-bfe7-f2a405522373',
        ),
      ),
    ),
    'field_cabinetry_sheet_veneer_two' => array(),
    'field_cabinetry_thickness' => array(
      'und' => array(
        0 => array(
          'value' => 6,
        ),
      ),
    ),
    'field_cabinetry_width' => array(
      'und' => array(
        0 => array(
          'value' => 2440,
        ),
      ),
    ),
  );
  return $terms;
}
