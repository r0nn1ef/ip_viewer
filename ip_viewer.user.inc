<?php
/**
 * Created by PhpStorm.
 * User: ronald
 * Date: 11/7/15
 * Time: 19:29
 */

/**
 * Implements hook_user_login().
 */
function ip_viewer_user_login(&$edit, $account) {
  ip_viewer_user_log($account);
}

/**
 * Implements hook_user_insert().
 */
function ip_viewer_user_insert(&$edit, $account, $category) {
  ip_viewer_user_log($account);
}

function ip_viewer_user_log($account) {
  db_insert('ip_viewer')
    ->fields(array(
      'uid' => $account->uid,
      'ip_address' => ip_address(),
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
    ))
    ->execute();
}