<?php
/**
 * @file
 * Views plugin and data definitions for Onsep License Usage.
 */

/**
 * Implements hook_views_data().
 */
function custom_license_voucher_views_data() {
  $data = array();

  $data['commerce_coupon']['voucher_usage'] = array(
    'title' => t('Voucher usage_summary'),
    'help' => t('Displays a summary of voucher usage and usage limits.'),
    'field' => array(
      'handler' => 'custom_license_voucher_views_handler_area_usage_summary',
      'format' => 'full_html',
    ),
  );

  return $data;
}
