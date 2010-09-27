<?php
// $Id

/**
 * Implementation of hook_views_data().
 */
function bot_log_views_data() {
  $data = array();
  $data['bot_log']['table']['group'] = 'bot_log';
  $data['bot_log']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Bot log'),
    'help' => t('Use items from the IRC bots log.'),
  );
  $data['bot_log']['id'] = array(
    'title' => t('Identifier'),
    'help' => t('ID of the log entry.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['bot_log']['type'] = array(
    'title' => t('Message type'),
    'help' => t('Message ID value as supplied by Net_SmartIRC.'),
  );
  $data['bot_log']['timestamp'] = array(
    'title' => t('Timestamp'),
    'help' => t('Unix timestamp when the message occured.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'views_handler_argument_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['bot_log']['channel'] = array(
    'title' => t('Channel'),
    'help' => t('Channel the message was sent to.'),
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => FILTER_FORMAT_DEFAULT,
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['bot_log']['nick'] = array(
    'title' => t('Nick'),
    'help' => t('Nickname of the user who sent the message.'),
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => FILTER_FORMAT_DEFAULT,
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['bot_log']['message'] = array(
    'title' => t('Message'),
    'help' => t('The log message'),
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => FILTER_FORMAT_DEFAULT,
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  return $data;
}
