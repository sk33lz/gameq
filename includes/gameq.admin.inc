<?php
/**
 * @file
 * The file for admin forms and functionality for the gameq entity
 */

/**
 * Implements hook_form().
 */
function gameq_form($form, &$form_state, $gameq = NULL) {
  $form = array();

  /*$form['id'] = array(
    '#title' => t('Server ID'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->id) ? $gameq->id : '',
    '#description' => t('Primary Key of the GameQ server entity.'),
    '#required' => TRUE,
    '#maxlength' => 255,
  );*/

  $form['name'] = array(
    '#title' => t('Gameserver name.'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->name) ? $gameq->name : '',
    '#required' => TRUE,
    '#maxlength' => 128,
  );

  $form['description'] = array(
    '#title' => t('Gameserver description.'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->description) ? $gameq->description : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  $form['ip'] = array(
    '#title' => t('IP Address of the GameQ server.'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->ip) ? $gameq->ip : '',
    '#required' => TRUE,
    '#maxlength' => 128,
  );

  $form['port'] = array(
    '#title' => t('Gameserver query port.'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->port) ? $gameq->port : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  $form['gametype'] = array(
    '#title' => t('Gameserver type.'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->gametype) ? $gameq->gametype : '',
    '#required' => TRUE,
    '#maxlength' => 128,
  );

  /*$form['players'] = array(
    '#title' => t('Number of players on gameserver at last update.'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->players) ? $gameq->players : '',
    '#required' => FALSE,
    '#maxlength' => 255,
  );

  $form['uid'] = array(
    '#title' => t('The {users}.uid that owns this gameserver; initially, this is the user that created it.'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->uid) ? $gameq->uid : '',
    '#required' => FALSE,
    '#maxlength' => 255,
  );

  $form['status'] = array(
    '#title' => t('Boolean indicating whether the gameserver is published (visible to non-administrators)'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->status) ? $gameq->status : '',
    '#required' => FALSE,
    '#maxlength' => 255,
  );

  $form['created'] = array(
    '#title' => t('The Unix timestamp when the gameserver was created.'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->created) ? $gameq->created : '',
    '#required' => FALSE,
    '#maxlength' => 255,
  );

  $form['changed'] = array(
    '#title' => t('The Unix timestamp when the server was most recently saved.'),
    '#type' => 'textfield',
    '#default_value' => isset($gameq->changed) ? $gameq->changed : '',
    '#required' => FALSE,
    '#maxlength' => 255,
  );*/

  field_attach_form('gameq', $gameq, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($gameq->gameq_id) ? t('Update GameQ Server') : t('Save GameQ Server'),
    ),
    'delete_link' => array(
      '#markup' => isset($gameq->gameq_id) ? l(t('Delete GameQ Server'), 'admin/content/gameq/manage/' . $gameq->gameq_id . '/delete', array('attributes' => array('id' => array('gameq-delete-' . $gameq->gameq_id), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/gameq'))) : ''));
  return $form;
}

/**
 * Implements hook_form_validate().
 */
function gameq_form_validate($form, &$form_state) {
}

/**
 * Implements hook_form_submit().
 */
function gameq_form_submit($form, &$form_state) {
  $gameq = entity_ui_form_submit_build_entity($form, $form_state);
  $gameq->save();
  drupal_set_message(t('@name GameQ Server has been saved.', array('@name' => $gameq->name)));
  // $form_state['redirect'] = 'admin/content/gameq';
  $form_state['redirect'] = 'gameq/' . $gameq->id;
}

/**
 * Confirmation before bulk deleting gameq.
 */
function gameq_bulk_delete($form, &$form_state, $gameq_ids) {
  $gameq_ids = explode('|', $gameq_ids);
  $gameqs = gameq_load_multiple($gameq_ids);

  $form = array();
  $form_state['gameq_ids'] = $gameq_ids;

  $variables = array(
    'type' => 'ul',
    'items' => array(),
    'title' => '',
    'attributes' => array(),
  );

  foreach ($gameqs as $gameq) {
    $variables['items'][] = $gameq->name;
  }

  $form['summary'] = array(
    '#markup' => theme_item_list($variables),
  );

  return confirm_form($form, t('Delete all gameq?'), 'admin/content/gameq', t('Placeholder description'), t('Delete all'), t('Cancel'));
}

/**
 * Implements hook_submit().
 */
function gameq_bulk_delete_submit($form, &$form_state) {
  $gameq_ids = $form_state['gameq_ids'];
  gameq_delete_multiple($gameq_ids);

  drupal_set_message(t('gameq deleted'));
  drupal_goto('admin/content/gameq');
}
