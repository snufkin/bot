<?php
// $Id$

/**
 * Hooks provided by the bot module.
 *
 * For most IRC triggered hooks the name of the hook originaets from the possible
 * message types. See line 60 in bot_start.php for a list.
 *
 * This file is divided into three parts:
 * - Time handlers (hooks triggering in regular intervals)
 * - Action handlers (hooks triggering on IRC events)
 * - Hooks defined by the bot module
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Time handlers (cron triggered by Net_SmartIRC).
 */

/**
 * A cron hook that runs every 5 minutes (depends on bot_start.php setting).
 */
function hook_irc_bot_cron() {

}

/**
 * A cron hook that is triggered every minute.
 */
function hook_irc_bot_cron_faster() {

}

/**
 * A cron hook that is triggered every 4th seconds.
 */
function hook_irc_bot_cron_fastest() {

}

/**
 * Action handlers (aka something is happening on IRC and we react).
 */

/**
 * Regular IRC channel communication.
 */
function hook_irc_msg_channel($data) {
  // First lets get the regexp to match the bot name.
  $addressed = bot_name_regexp();

  // Process the IRC message to look for our reserved keyword and captcure arguments.
  if (preg_match("/^${addressed}log (bookmark|pointer)\s*[!\?\.]*\s*$/i", $data->message)) {
    // Look at what channel this message was sent in.
    $lc_channel = drupal_strtolower($data->channel); // lowercase the channel everywhere.
    $logged_channels = array_map('drupal_strtolower', variable_get('bot_log_channels', array()));
    if (in_array($lc_channel, $logged_channels)) { // clients can send case; we always LC.
      $path = 'bot/log/' . str_replace('#', '', $lc_channel) . '/' . gmdate('Y-m-d');
      // The bot sends the url of the channel log to the channel.
      bot_message($data->channel, url($path, array('fragment' => 'T' . $log_id, 'absolute' => TRUE)));
    }
    else {
      // If this channel is not logged, then this is reported.
      bot_message($data->channel, t('!channel is not logged; no URL exists.', array('!channel' => $lc_channel)));
    }
  }

}

/**
 * Hook triggered when a user joins a channel.
 */
function hook_irc_msg_join($data) {
  /// Send a greeting message to this user.
  bot_message($data->channel, t('Good morning !nick!', array('!nick' => $data->nick)));
}

/**
 * User is leaving the channel.
 */
function hook_irc_msg_part($data) {
  bot_message($data->channel, t('!nick just left the room.', array('!nick' => $data->nick));
}

/**
 * The bot is invited to a channel.
 */
function hook_irc_msg_invite($data) {

}

/**
 * User is performing an action of type $data->type.
 */
function hook_irc_msg_action($data) {

}

/**
 * The topic of the channel is changed.
 *
 * Channel name can be extracted from $data->rawmessageex[2].
 * Topic is in $data->message.
 */
function hook_irc_msg_topicchange($data) {

}

/**
 * User changed his or her nick.
 */
function hook_irc_msg_nickchange($data) {
  $old_nick = $data->nick;
  $new_nick = $data->message;
}

/**
 * User is being kicked from the channel.
 */
function hook_irc_msg_kick($data) {

}

/**
 * User logs in to the channel.
 */
function hook_irc_msg_login($data) {

}

/**
 * User is leaving the server. Note: $data->channel is no longer set in this hook.
 */
function hook_irc_msg_quit($data) {

}

function hook_irc_msg_info() {

}

function hook_irc_msg_list() {

}

function hook_irc_msg_name() {

}

function hook_irc_msg_motd() {

}

function hook_irc_msg_modechange() {

}

/**
 * Server sends an error message.
 */
function hook_irc_msg_error() {

}

function hook_irc_msg_banlist() {

}

function hook_irc_msg_topic() {

}

function hook_irc_msg_nonrelevant() {

}

/**
 * Unknown IRC event 
 */
function hook_irc_msg_unknown() {

}

function hook_irc_msg_query() {

}

function hook_irc_msg_ctcp() {

}

function hook_irc_msg_notice() {

}

/**
 * Net_SmartIRC is issuing a /WHO command.
 *
 * Interesting data is in the $data->rawmessageex array.
 */
function hook_irc_msg_who($data) {

}

function hook_irc_msg_whois() {

}

function hook_irc_msg_whowas() {

}

function hook_irc_msg_usermode() {

}

function hook_irc_msg_channelmode() {

}

function hook_irc_msg_ctcp_request() {

}

function hook_irc_msg_ctcp_reply() {

}

/**
 * Internal hooks.
 */

/**
 * Triggered in bot_action: an action is sent to the channel or user.
 *
 * @param $to
 *   The channel or user name the action is for.
 * @param $message
 *   The action message.
 */
function hook_irc_bot_reply_action($to, $message) {

}

/**
 * Triggered in bot_message: a message is sent to the channel or user.
 *
 * @param $to
 *   The channel or user name the message is for.
 * @param $message
 *   The message string.
 */
function hook_irc_bot_reply_message($to, $message) {

}

/**
 * @} End of "addtogroup hooks"
 */
