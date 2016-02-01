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
  $gameq_image_size = '200x250';
  $image_data = array(
    'path' => drupal_get_path('module', 'gameq') . '/images/' . $gameq_image_size . '/' . $gameq->bioguide_id . '.jpg',
  );

  $output .= '<div class="gameq_meta">';

  // Lazy...
  $output .= '<div class="image" style="float: left; margin-right: 20px">' . theme('image', $image_data) . '</div>';
  $output .= '<div class="gameq-name">' . trim($gameq->title) . '. ' . trim($gameq->firstname)  . ' ' . trim($gameq->lastname) . '</div>';
  $output .= '<div class="party">' . $gameq->party . ' ' . $gameq->state  . '  ' . $gameq->district . '</div>';
  $output .= '<div class="congress_office">' . $gameq->congress_office .  '</div>';
  $output .= '<div class="phone">tel: ' . $gameq->phone .  '</div>';
  $output .= '<div class="fax">fax: ' . $gameq->fax .  '</div>';

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

  if (user_access('administer gameq entities') && isset($gameq->gameq_id)) {
    $edit_link = '<ul class="tabs primary"><li>';
    $edit_link .= l(t('Edit'), 'admin/content/gameq/manage/' . $gameq->gameq_id, array('attributes' => array('class' => 'admin-edit-link')));
    $edit_link .= '</li></ul>';
    $output .= $edit_link;
  }

  $output .= '</div>';

  return $output;
}
