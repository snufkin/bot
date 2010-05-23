<?php

/**
 * @file
 * Parsing functions to grab different details from a project page on drupal.org.
 */

function _bot_project_parse_versions($project, $html) {
  
}

function _bot_project_parse_issues($project, $html) {

}

function _bot_project_parse_usage($project, $html) {
  $result = drupal_http_request('http://drupal.org/project/usage/' . $project);
  // Get the core versions from the table head.
  if (preg_match('s/<table\sid=\"project-usage-project-api\"[^>]*>[ \t\n\s]+<thead><tr>(.+?)<\/tr><\/thead>/i', $html, $matches)) {
    $versions_raw = $matches[1];
  }
  // First row is the latest usage statistics.
  if (preg_match('s/<table\sid=\"project-usage-project-api\"[^>]*>[ \t\n\s]+<thead><tr>.+?<\/tr><\/thead>[ \t\n\s]+<tbody>[ \t\n\s]+<tr[^>]*>(.+?)<\/tr>/i', $html, $matches)) {
    $usage_raw = $matches[1];
  }
}

/**
 * Extract the title of the project.
 */
function _bot_project_parse_title($project, $html) {
  if (preg_match("s/<title>(.+?)\s|\sdrupal\.org<\/title>", $html, $matches)) {
    return $matches[1];
  }
  else return $project;
}