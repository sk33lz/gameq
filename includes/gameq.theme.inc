<?php
/**
 * @file
 * gameq.theme.inc
 */

/**
 * Theme lawmaker full page.
 */
function theme_gameq_full($variables) {
  $output = '';
  $gameq = $variables['gameq'];

  $output .= '<div class="gameq_meta">';

  // Lazy...
  $output .= '<div class="gameq-id">' . trim($gameq->id) . '</div>';
  $output .= '<div class="gameq-name">' . trim($gameq->name) . '</div>';
  $output .= '<div class="description">' . $gameq->description . '</div>';
  $output .= '<div class="gameq-address-port">' . $gameq->ip . ' ': . $gameq->port .  </div>';
  $output .= '<div class="gametype">Game Type: ' . $gameq->gametype .  '</div>';
  $output .= '<div class="players">Players: ' . $gameq->players .  '</div>';

  if (!empty($gameq->website)) {
    $output .= '<div class="website"> ' . l(t('website'), $gameq->website, array('attributes' => array('target' => '_blank'))) . '</div>';
  }

  if (!empty($gameq->webform)) {
    $output .= '<div class="contact_form">' . l(t('contact form'), $gameq->webform) .  '</div>';
  }

  $output .= '<div class="social_media">Social Info</div>';

  if (!empty($gameq->twitter_id)) {
    $output .= '<div class="twitter">' . l(t('twitter'), 'http://twitter.com/' . $gameq->twitter_id, array('attributes' => array('target' => '_blank'))) . '</div>';
  }

  if (!empty($gameq->youtube_url)) {
    $output .= '<div class="youtube">' . l(t('youtube'), $gameq->youtube_url, array('attributes' => array('target' => '_blank'))) . '</div>';
  }

  if (user_access('administer gameq entities') && isset($gameq->id)) {
    $edit_link = '<ul class="tabs primary"><li>';
    $edit_link .= l(t('Edit'), 'admin/content/gameq/manage/' . $gameq->id, array('attributes' => array('class' => 'admin-edit-link')));
    $edit_link .= '</li></ul>';
    $output .= $edit_link;
  }

  $output .= '</div>';

  return $output;
}
