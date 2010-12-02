<?php

/**
 * Configures the project toolkit features.
 */
function bot_project_settings() {
  if (module_exists('api')) {
    $results = db_query('SELECT branch_name, title FROM {api_branch} ORDER BY title');
    $branches = array(); while ($result = db_fetch_object($results)) { $branches[$result->branch_name] = $result->title; }

    $form['bot_project_api'] = array(
      '#collapsible'   => TRUE,
      '#title'         => t('api.module integration'),
      '#type'          => 'fieldset',
    );
    $form['bot_project_api']['bot_project_api_default_branch'] = array(
      '#default_value' => variable_get('bot_project_api_default_branch', NULL),
      '#description'   => t('Choose the default branch that will be used for non-specific function lookups.'),
      '#options'       => $branches,
      '#title'         => t('Default API Branch'),
      '#type'          => 'select',
    );
    foreach ($branches as $branch => $title) {
      $form['bot_project_api']['bot_project_api_branch_' . $branch . '_url'] = array(
        '#default_value' => bot_project_branch_url($branch),
        '#description'   => t('Define the URL displayed in responses to this branch\'s function lookups.'),
        '#title'         => t('Function URLs for branch %name', array('%name' => $branch)),
        '#type'          => 'textfield',
      );
    }
  }

  $form['bot_project_project'] = array(
    '#collapsible'   => TRUE,
    '#title'         => t('project.module integration'),
    '#type'          => 'fieldset',
  );
  $form['bot_project_project']['bot_project_project_lookup_enabled'] = array(
    '#default_value' => variable_get('bot_project_project_lookup_enabled', FALSE),
    '#title'         => t('Enable project url lookups'),
    '#type'          => 'checkbox',
  );
  $form['bot_project_project']['bot_project_project_enable'] = array(
    '#default_value' => variable_get('bot_project_project_enable', FALSE),
    '#title'         => t('Enable project.module issue lookups'),
    '#type'          => 'checkbox',
  );
  $form['bot_project_project']['bot_project_project_url_regexp'] = array(
    '#default_value' => variable_get('bot_project_project_url_regexp', NULL),
    '#description'   => t('Lookup issues when matched in conversation (ex. %example).', array('%example' => 'http://[\w\d\-]*?\.?drupal\.org/node/\d+')),
    '#title'         => t('URL regexp for issue lookups'),
    '#type'          => 'textfield',
  );
  $form['bot_project_project']['bot_project_project_url'] = array(
    '#default_value' => variable_get('bot_project_project_url', NULL),
    '#description'   => t('Define the base URL used with node ID issue lookups (ex. %example).', array('%example' => 'http://drupal.org/')),
    '#title'         => t('Base URL (for node ID lookups)'),
    '#type'          => 'textfield',
  );
  $form['bot_project_project']['bot_project_project_nid_min'] = array(
    '#default_value' => variable_get('bot_project_project_nid_min', 0),
    '#description'   => t('Lookup issues ("#1234" or "1234" as the entire message) at the base URL larger than this node ID.'),
    '#title'         => t('Minimum node ID for lookups'),
    '#type'          => 'textfield',
  );
  $form['bot_project_project']['bot_project_project_nid_max'] = array(
    '#default_value' => variable_get('bot_project_project_nid_max', 99999),
    '#description'   => t('Lookup issues ("#1234" or "1234" as the entire message) at the base URL smaller than this node ID.'),
    '#title'         => t('Maximum node ID for lookups'),
    '#type'          => 'textfield',
  );

  $form['bot_project_trac'] = array(
    '#collapsible'   => TRUE,
    '#title'         => t('Trac integration'),
    '#type'          => 'fieldset',
  );
  $form['bot_project_trac']['bot_project_trac_enable'] = array(
    '#default_value' => variable_get('bot_project_trac_enable', FALSE),
    '#title'         => t('Enable Trac lookups'),
    '#type'          => 'checkbox',
  );
  $form['bot_project_trac']['bot_project_trac_url_regexp'] = array(
    '#default_value' => variable_get('bot_project_trac_url_regexp', NULL),
    '#description'   => t('Lookup data when matched in conversation (ex. %example).', array('%example' => 'http://www.example.com/trac/(changeset|ticket)/\d+')),
    '#title'         => t('URL regexp for data lookups'),
    '#type'          => 'textfield',
  );
  $form['bot_project_trac']['bot_project_trac_url'] = array(
    '#default_value' => variable_get('bot_project_trac_url', NULL),
    '#description'   => t('Define the base URL used with numerical lookups (ex. %example).', array('%example' => 'http://www.example.com/trac/')),
    '#title'         => t('Base URL (for numerical lookups)'),
    '#type'          => 'textfield',
  );
  $form['bot_project_trac']['bot_project_trac_num_min'] = array(
    '#default_value' => variable_get('bot_project_trac_num_min', 0),
    '#description'   => t('Lookup data ("#1234", "1234", or "r1234" as the entire message) at the base URL larger than this number.'),
    '#title'         => t('Minimum numerical value for lookups'),
    '#type'          => 'textfield',
  );
  $form['bot_project_trac']['bot_project_trac_num_max'] = array(
    '#default_value' => variable_get('bot_project_trac_num_max', 99999),
    '#description'   => t('Lookup data ("#1234", "1234", or "r1234" as the entire message) at the base URL smaller than this number.'),
    '#title'         => t('Maximum numerical for lookups'),
    '#type'          => 'textfield',
  );

  return system_settings_form($form);
}