<?php

/**
 * @file
 * Riak admin form
 */

/**
 * Riak settings form
 * @param $form
 * @param $form_state
 * @return mixed
 */
function riak_settings_form($form, &$form_state) {

  $host = variable_get('riak_host', '127.0.0.1');
  $form['riak_host'] = array(
    '#title' => t('Host address'),
    '#type' => 'textfield',
    '#description' => t('Riak host, eg: 127.0.0.1 or example.com'),
    '#default_value' => $host,
    '#required' => TRUE
  );

  $port = variable_get('riak_port', '8098');
  $form['riak_port'] = array(
    '#title' => t('Port'),
    '#type' => 'textfield',
    '#description' => t('Riak port, eg: 8098'),
    '#default_value' => $port,
    '#required' => TRUE,
    '#size' => 5
  );

  $form['ssl'] = array(
    '#title' => t('SSL settings'),
    '#type' => 'fieldset',
  );

  $use_ssl = variable_get('riak_ssl_enabled', FALSE);
  $form['ssl']['riak_ssl_enabled'] = array(
    '#title' => t('Use SSL'),
    '#type' => 'checkbox',
    '#default_value' => $use_ssl
  );

  $ca_cert = variable_get('riak_ssl_ca_cert', NULL);
  $form['ssl']['riak_ssl_ca_cert'] = array(
    '#title' => t('CA certificate'),
    '#type' => 'textfield',
    '#description' => t('Path to CA certificate.'),
    '#default_value' => $ca_cert,
  );

  $client_cert = variable_get('riak_ssl_client_cert', NULL);
  $form['ssl']['riak_ssl_client_cert'] = array(
    '#title' => t('Client certificate file'),
    '#type' => 'textfield',
    '#description' => t('Path to client certificate.'),
    '#default_value' => $client_cert,
  );

  $client_key = variable_get('riak_ssl_client_key', NULL);
  $form['ssl']['riak_ssl_client_key'] = array(
    '#title' => t('Client key file'),
    '#type' => 'textfield',
    '#description' => t('Path to client key. Do not store your client key in public folder!'),
    '#default_value' => $client_key,
  );

  return system_settings_form($form);
}