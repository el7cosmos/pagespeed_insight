<?php

/**
 * @file
 * Page callback for PageSpeed Insights module.
 */

function pagespeed_insight_page($url = NULL) {
  if (is_null($url)) {
    $url = empty($_GET['url']) ? NULL : $_GET['url'];
  }

  $page['form'] = drupal_get_form('pagespeed_insight_analyze_form');

  $page['result'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'id' => 'result',
    ),
  );
  if (!is_null($url)) {
    $data = pagespeed_insight_analyze($url);
    if (empty($data['error'])) {
      $page['result'] += pagespeed_insight_analyze_result($data);
    }
    else {
      dpm($data);
    }
  }

  return $page;
}
