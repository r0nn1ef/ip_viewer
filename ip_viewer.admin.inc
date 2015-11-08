<?php
/**
 * Created by PhpStorm.
 * User: ronald
 * Date: 11/7/15
 * Time: 19:46
 */

function ip_viewer_list_form() {

  $header = array(
    'username' => array('data' => t('Username'), 'field' => 'u.name'),
    'ip_address' => array('data' => t('IP Address'), 'field' => 'i.ip_address'),
    'login' => array('data' => t('Last access'), 'field' => 'i.created'),
    'operations' => array('data' => t('Operations')),
  );

  $query = db_select('users', 'u');
  $query->join('ip_viewer', 'i', 'u.uid=i.uid');
  $query->leftJoin('blocked_ips', 'b', 'i.ip_address=b.ip');

  $query = $query->extend('PagerDefault')->extend('TableSort');

  $query->fields('u', array('uid', 'name'))
    ->fields('i', array('ipid', 'ip_address', 'created'))
    ->fields('b', array('ip'))
    ->orderByHeader($header)
    ->limit(50);

  $results = $query->execute();

  $accounts = array();

  $destination = drupal_get_destination();

  foreach ($results as $account) {
    $qstring = $destination + array('ip' => $account->ipid);
    $accounts[$account->ipid] = array(
      'username' => l($account->name, 'user/' . $account->uid),
      'ip_address' => $account->ip_address . (!empty($account->ip) ? ' <span style="font-style:italic;color:#ff0000;">('.t('blocked').')</span>' : ''),
      'login' => format_date($account->created, 'custom', 'm/j/Y g:i:s a'),
      'operations' => l(t('block'), 'admin/config/people/ip-blocking', array('query' => $qstring)),
    );
  }

  $build['list'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $accounts,
    '#empty' => t('No people available.'),
  );

  $build['pager'] = array('#theme' => 'pager');

  return render($build);
}