<?php

/**
 * @file
 * Provide view handlers for the vouchers.
 */

/**
 * Render a usage summary for a view with a coupon id as its argument.
 */
class custom_license_voucher_views_handler_area_usage_summary extends commerce_coupon_usage_views_handler_field_usage {
  /**
   * Call the parent constructor.
   */
  public function __construct() {
    parent::construct();
  }

  /**
   * Send back the rendered view.
   *
   * @return string
   *   The themed output of variables.
   */
  public function render($values) {
    $variables['coupon_id'] = (int) $this->view->field['coupon_id']->original_value;
    $variables['uid'] = (int) $this->view->argument['commerce_coupon_recipient_target_id']->value[0];
    $variables['details_link_text'] = ($variables['coupon_id']) ? 'Details' : FALSE;

    return theme('custom_license_voucher_usage_summary', $variables);
  }

}
