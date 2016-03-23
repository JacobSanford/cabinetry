<?php

/**
 * @file
 * Provides project/node interfacing functions for cabinetry_cabinet_project.
 */

/**
 * Remove hardware material elements from a node object.
 *
 * @param object $node
 *   The node entity wrapper to modify.
 */
function _cabinetry_cabinet_project_remove_hardware_materials($node) {
  foreach ($node->field_cabinetry_materials_hardwa[LANGUAGE_NONE] as $hardware_index => $hardware_type) {
    // Delete field collection entities.
    if (isset($hardware_type['entity']) && method_exists($hardware_type['entity'], 'delete')) {
      $hardware_type['entity']->delete();
    }

    // Remove values from node object.
    unset($node->field_cabinetry_materials_hardwa[LANGUAGE_NONE][$hardware_index]);
  }
}

/**
 * Add hardware material elements to a node object.
 *
 * @param object $node
 *   The node entity wrapper to modify.
 * @param object $project
 *   The CabinetryCabinetProject object read data from.
 */
function _cabinetry_cabinet_project_add_hardware_materials($node, $project) {
  foreach ($project->hardware as $hardware_type => $hardware_item) {

    $field_collection_object = entity_create(
      'field_collection_item',
      array('field_name' => 'field_cabinetry_materials_hardwa')
    );

    $field_collection_object->field_cabinetry_hardware_name[LANGUAGE_NONE][0]['value'] = $hardware_item['name'];
    $field_collection_object->field_cabinetry_number_of_shelve[LANGUAGE_NONE][0]['value'] = $hardware_item['count'];
    $field_collection_object->field_cabinetry_item_cost[LANGUAGE_NONE][0]['value'] = $hardware_item['price'];

    $sheet_type_array = array(
      'field_cabinetry_hardware_name' => _cabinetry_cabinet_project_stuff_field($hardware_item['name']),
      'field_cabinetry_number_of_shelve' => _cabinetry_cabinet_project_stuff_field($hardware_item['count']),
      'field_cabinetry_item_cost' => _cabinetry_cabinet_project_stuff_field($hardware_item['price']),
      'remove_button' => 'Remove',
      'entity' => $field_collection_object,
    );
    $node->field_cabinetry_materials_hardwa[LANGUAGE_NONE][] = $sheet_type_array;
  }
}

/**
 * Remove solid material elements from a node object.
 *
 * @param object $node
 *   The node entity wrapper to modify.
 */
function _cabinetry_cabinet_project_remove_solid_materials($node) {
  foreach ($node->field_cabinetry_materials_solid[LANGUAGE_NONE] as $solid_index => $solid_type) {
    foreach ($solid_type['field_cabinetry_solid_part_list'][LANGUAGE_NONE] as $part_list_index => $part_list) {
      if (isset($part_list['entity']) && method_exists($part_list['entity'], 'delete')) {
        $part_list['entity']->delete();
      }
      unset($node->field_cabinetry_materials_solid[LANGUAGE_NONE][$solid_index]['field_cabinetry_solid_part_list'][LANGUAGE_NONE][$part_list_index]);
    }

    if (isset($solid_type['entity']) && method_exists($solid_type['entity'], 'delete')) {
      $solid_type['entity']->delete();
    }

    unset($node->field_cabinetry_materials_solid[LANGUAGE_NONE][$solid_index]);
  }
}

/**
 * Add solid material elements to a node object.
 *
 * @param object $node
 *   The node entity wrapper to modify.
 * @param object $project
 *   The CabinetryCabinetProject object read data from.
 */
function _cabinetry_cabinet_project_add_solid_materials($node, $project) {
  $directory = 'public://cabinetry/solids';
  file_prepare_directory($directory, FILE_CREATE_DIRECTORY);

  if (isset($project->parts['CabinetrySolidWood'])) {
    foreach ($project->parts['CabinetrySolidWood'] as $solid_type => $solid) {

      foreach ($solid['parts'] as $part_thickness => $thickness_part) {
        foreach ($thickness_part as $part_height => $height_part) {
          $parts_list = array();
          foreach ($height_part as $part_width => $width_parts) {
            if (is_numeric($part_width)) {
              $part_names = array();

              foreach ($width_parts as $part_name) {
                $part_names[] = array(
                  'value' => $part_name['label'],
                  '_weight' => 0,
                );
              }

              $parts_list_field_collection_object = entity_create(
                'field_collection_item',
                array('field_name' => 'field_cabinetry_solid_part_list')
              );

              $parts_list_field_collection_object->field_cabinetry_solid_length[LANGUAGE_NONE][0]['value'] = $part_width;
              $parts_list_field_collection_object->field_cabinetry_part_names[LANGUAGE_NONE] = $part_names;

              $parts_list[] = array(
                'field_cabinetry_solid_length' => _cabinetry_cabinet_project_stuff_field($part_width),
                'field_cabinetry_part_names' => array(
                  LANGUAGE_NONE => $part_names,
                ),
                'remove_button' => 'Remove',
                'entity' => $parts_list_field_collection_object,
              );
            }
          }

          $solid_materials_field_collection_object = entity_create(
            'field_collection_item',
            array('field_name' => 'field_cabinetry_materials_solid')
          );

          // Files.
          $plot_files = array();
          foreach ($height_part['plots'] as $plot_index => $plot_file) {
            $sheet_plot = file_get_contents($plot_file);
            $file_name = basename($plot_file);
            $file = file_save_data($sheet_plot, "$directory/$file_name.png", FILE_EXISTS_REPLACE);
            $file->status = FILE_STATUS_PERMANENT;
            file_save($file);
            $plot_files[] = (array)$file;
          }

          $solid_materials_field_collection_object->field_cabinetry_solid_name[LANGUAGE_NONE][0]['value'] = $solid_type;
          $solid_materials_field_collection_object->field_cabinetry_thickness[LANGUAGE_NONE][0]['value'] = $part_thickness;
          $solid_materials_field_collection_object->field_cabinetry_height[LANGUAGE_NONE][0]['value'] = $part_height;
          $solid_materials_field_collection_object->field_cabinetry_item_cost[LANGUAGE_NONE][0]['value'] = $solid['price'];
          $solid_materials_field_collection_object->field_cabinetry_solid_part_list[LANGUAGE_NONE] = $parts_list;
          $solid_materials_field_collection_object->field_image[LANGUAGE_NONE] = $plot_files;

          $solid_type_array = array(
            'field_cabinetry_solid_name' => _cabinetry_cabinet_project_stuff_field($solid_type),
            'field_cabinetry_item_cost' => _cabinetry_cabinet_project_stuff_field($solid['price']),
            'field_cabinetry_thickness' => _cabinetry_cabinet_project_stuff_field($part_thickness),
            'field_cabinetry_height' => _cabinetry_cabinet_project_stuff_field($part_height),
            'field_image' => array(
              LANGUAGE_NONE => $plot_files,
            ),
            'field_cabinetry_solid_part_list' => array(
              LANGUAGE_NONE => $parts_list,
            ),
            'remove_button' => 'Remove',
            'entity' => $solid_materials_field_collection_object,
          );

          $node->field_cabinetry_materials_solid[LANGUAGE_NONE][] = $solid_type_array;

        }
      }
    }
  }
}

/**
 * Remove sheet material elements from a node object.
 *
 * @param object $node
 *   The node entity wrapper to modify.
 */
function _cabinetry_cabinet_project_remove_sheet_materials($node) {
  foreach ($node->field_cabinetry_materials_sheet[LANGUAGE_NONE] as $sheet_index => $sheet_type) {
    if (!empty($sheet_type['field_image'][LANGUAGE_NONE])) {
      foreach ($sheet_type['field_image'][LANGUAGE_NONE] as $old_file) {
        if (!empty($old_file['fid']) && $old_file['fid'] != 0 && $old_file['fid'] != '') {
          $file_object = file_load($old_file['fid']);
          file_delete($file_object, TRUE);
        }
      }
    }

    if (isset($sheet_type['entity']) && method_exists($sheet_type['entity'], 'delete')) {
      $sheet_type['entity']->delete();
    }

    unset($node->field_cabinetry_materials_sheet[LANGUAGE_NONE][$sheet_index]);
  }
}

/**
 * Add sheet material elements to a node object.
 *
 * @param object $node
 *   The node entity wrapper to modify.
 * @param object $project
 *   The CabinetryCabinetProject object read data from.
 */
function _cabinetry_cabinet_project_add_sheet_materials($node, $project) {
  $directory = 'public://cabinetry/sheets';
  file_prepare_directory($directory, FILE_CREATE_DIRECTORY);

  foreach ($project->parts['CabinetrySheetGood'] as $sheet_type => $sheet) {
    // Files.
    $plot_files = array();
    foreach ($sheet['plots'] as $plot_index => $plot_file) {
      $sheet_plot = file_get_contents($plot_file);
      $file_name = basename($plot_file);
      $file = file_save_data($sheet_plot, "$directory/$file_name.png", FILE_EXISTS_REPLACE);
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      $plot_files[] = (array) $file;
    }

    $field_collection_object = entity_create(
      'field_collection_item',
      array('field_name' => 'field_cabinetry_materials_sheet')
    );

    $field_collection_object->field_cabinetry_item_cost[LANGUAGE_NONE][0]['value'] = $sheet['price'];
    $field_collection_object->field_cabinetry_sheet_name[LANGUAGE_NONE][0]['value'] = $sheet_type;
    $field_collection_object->field_image[LANGUAGE_NONE] = $plot_files;

    $sheet_type_array = array(
      'field_cabinetry_item_cost' => _cabinetry_cabinet_project_stuff_field($sheet['price']),
      'field_cabinetry_sheet_name' => _cabinetry_cabinet_project_stuff_field($sheet_type),
      'remove_button' => 'Remove',
      'field_image' => array(
        LANGUAGE_NONE => $plot_files,
      ),
      'entity' => $field_collection_object,
    );
    $node->field_cabinetry_materials_sheet[LANGUAGE_NONE][] = $sheet_type_array;
  }
}

/**
 * Remove solid material elements from a node object.
 *
 * @param object $node
 *   The node entity wrapper to modify.
 */
function _cabinetry_cabinet_project_remove_banding_materials($node) {
  foreach ($node->field_cabinetry_materials_bandin[LANGUAGE_NONE] as $banding_index => $banding) {
    if (isset($banding['entity']) && method_exists($banding['entity'], 'delete')) {
      $banding['entity']->delete();
    }

    unset($node->field_cabinetry_materials_bandin[LANGUAGE_NONE][$banding_index]);
  }
}

/**
 * Add hardware material elements to a node object.
 *
 * @param object $node
 *   The node entity wrapper to modify.
 * @param object $project
 *   The CabinetryCabinetProject object read data from.
 */
function _cabinetry_cabinet_project_add_banding_materials($node, $project) {
  foreach ($project->banding as $banding_type => $banding) {
    $field_collection_object = entity_create(
      'field_collection_item',
      array('field_name' => 'field_cabinetry_materials_bandin')
    );

    $field_collection_object->field_cabinetry_banding_material[LANGUAGE_NONE][0]['value'] = $banding->material;
    $field_collection_object->field_cabinetry_banding_amount[LANGUAGE_NONE][0]['value'] = $banding->length;

    $sheet_type_array = array(
      'field_cabinetry_banding_material' => _cabinetry_cabinet_project_stuff_field($banding->material),
      'field_cabinetry_banding_amount' => _cabinetry_cabinet_project_stuff_field($banding->length),
      'remove_button' => 'Remove',
      'entity' => $field_collection_object,
    );
    $node->field_cabinetry_materials_bandin[LANGUAGE_NONE][] = $sheet_type_array;
  }
}
