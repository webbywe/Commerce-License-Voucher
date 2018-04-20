<?php

/**
 * @file
 * Default views configuration for Onsep License Vouchers.
 */


/**
 * Implements hook_views_default_views().
 */
function custom_license_voucher_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'voucher_usage';
  $view->description = 'Summary of coupon usage';
  $view->tag = 'default';
  $view->base_table = 'commerce_coupon_usage_transaction';
  $view->human_name = 'Voucher usage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Voucher usage';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Commerce Coupon: Coupon usage summary area */
  $handler->display->display_options['header']['usage_summary_area']['id'] = 'usage_summary_area';
  $handler->display->display_options['header']['usage_summary_area']['table'] = 'commerce_coupon';
  $handler->display->display_options['header']['usage_summary_area']['field'] = 'usage_summary_area';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No voucher usage details to show at this time.</a>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Commerce coupon usage transaction: Order_id */
  $handler->display->display_options['relationships']['order_id']['id'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['table'] = 'commerce_coupon_usage_transaction';
  $handler->display->display_options['relationships']['order_id']['field'] = 'order_id';
  $handler->display->display_options['relationships']['order_id']['required'] = TRUE;
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['id'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['table'] = 'field_data_commerce_customer_billing';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['field'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_billing_profile_id']['relationship'] = 'order_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['commerce_coupon_order_reference_target_id']['id'] = 'commerce_coupon_order_reference_target_id';
  $handler->display->display_options['relationships']['commerce_coupon_order_reference_target_id']['table'] = 'field_data_commerce_coupon_order_reference';
  $handler->display->display_options['relationships']['commerce_coupon_order_reference_target_id']['field'] = 'commerce_coupon_order_reference_target_id';
  $handler->display->display_options['relationships']['commerce_coupon_order_reference_target_id']['relationship'] = 'order_id';
  /* Field: Commerce coupon usage transaction: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'commerce_coupon_usage_transaction';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['date']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['date']['format_date_sql'] = 0;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['order_number']['alter']['text'] = 'Order [order_number]';
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'order_id';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['render_as_link'] = 1;
  /* Field: Commerce Customer profile: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['relationship'] = 'commerce_customer_billing_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = 'Purchased By';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['alter']['text'] = '[commerce_customer_address_name_line]<br/>[mail]';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['element_label_colon'] = FALSE;
  /* Sort criterion: Commerce coupon usage transaction: Date */
  $handler->display->display_options['sorts']['date']['id'] = 'date';
  $handler->display->display_options['sorts']['date']['table'] = 'commerce_coupon_usage_transaction';
  $handler->display->display_options['sorts']['date']['field'] = 'date';
  $handler->display->display_options['sorts']['date']['order'] = 'DESC';
  /* Contextual filter: Commerce coupon usage transaction: Coupon_id */
  $handler->display->display_options['arguments']['coupon_id']['id'] = 'coupon_id';
  $handler->display->display_options['arguments']['coupon_id']['table'] = 'commerce_coupon_usage_transaction';
  $handler->display->display_options['arguments']['coupon_id']['field'] = 'coupon_id';
  $handler->display->display_options['arguments']['coupon_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['coupon_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['coupon_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['coupon_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['coupon_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['coupon_id']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'voucher/%/usage';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Usage';
  $handler->display->display_options['menu']['weight'] = '100';
  $handler->display->display_options['menu']['context'] = 1;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Add view */
  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'user_vouchers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_coupon';
  $view->human_name = 'Vouchers List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Vouchers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No vouchers to show at this time..</a>
<p>Read more about <a href="subscriptions/institutional-subscriptions">Institutional Subscriptions</a>.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['commerce_coupon_recipient_target_id']['id'] = 'commerce_coupon_recipient_target_id';
  $handler->display->display_options['relationships']['commerce_coupon_recipient_target_id']['table'] = 'field_data_commerce_coupon_recipient';
  $handler->display->display_options['relationships']['commerce_coupon_recipient_target_id']['field'] = 'commerce_coupon_recipient_target_id';
  $handler->display->display_options['relationships']['commerce_coupon_recipient_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_coupon_product_target_id']['id'] = 'field_coupon_product_target_id';
  $handler->display->display_options['relationships']['field_coupon_product_target_id']['table'] = 'field_data_field_coupon_product';
  $handler->display->display_options['relationships']['field_coupon_product_target_id']['field'] = 'field_coupon_product_target_id';
  $handler->display->display_options['relationships']['field_coupon_product_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_commerce_bundled_products_target_id']['id'] = 'field_commerce_bundled_products_target_id';
  $handler->display->display_options['relationships']['field_commerce_bundled_products_target_id']['table'] = 'field_data_field_commerce_bundled_products';
  $handler->display->display_options['relationships']['field_commerce_bundled_products_target_id']['field'] = 'field_commerce_bundled_products_target_id';
  $handler->display->display_options['relationships']['field_commerce_bundled_products_target_id']['relationship'] = 'field_coupon_product_target_id';
  /* Field: Commerce Coupon: Commerce coupon ID */
  $handler->display->display_options['fields']['coupon_id']['id'] = 'coupon_id';
  $handler->display->display_options['fields']['coupon_id']['table'] = 'commerce_coupon';
  $handler->display->display_options['fields']['coupon_id']['field'] = 'coupon_id';
  $handler->display->display_options['fields']['coupon_id']['label'] = 'Coupon ID';
  $handler->display->display_options['fields']['coupon_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['coupon_id']['separator'] = '';
  /* Field: Commerce Coupon: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_coupon';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Purchased';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Field: Commerce Coupon: Label */
  $handler->display->display_options['fields']['code']['id'] = 'code';
  $handler->display->display_options['fields']['code']['table'] = 'commerce_coupon';
  $handler->display->display_options['fields']['code']['field'] = 'code';
  $handler->display->display_options['fields']['code']['label'] = 'Code';
  $handler->display->display_options['fields']['code']['element_label_colon'] = FALSE;
  /* Field: Commerce Product: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_coupon_product_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Subscription';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_product'] = 0;
  /* Field: Commerce Coupon: Voucher usage_summary */
  $handler->display->display_options['fields']['voucher_usage']['id'] = 'voucher_usage';
  $handler->display->display_options['fields']['voucher_usage']['table'] = 'commerce_coupon';
  $handler->display->display_options['fields']['voucher_usage']['field'] = 'voucher_usage';
  $handler->display->display_options['fields']['voucher_usage']['label'] = '';
  $handler->display->display_options['fields']['voucher_usage']['empty'] = 0;
  /* Sort criterion: Commerce Coupon: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'commerce_coupon';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Commerce Coupon: Recipient (commerce_coupon_recipient) */
  $handler->display->display_options['arguments']['commerce_coupon_recipient_target_id']['id'] = 'commerce_coupon_recipient_target_id';
  $handler->display->display_options['arguments']['commerce_coupon_recipient_target_id']['table'] = 'field_data_commerce_coupon_recipient';
  $handler->display->display_options['arguments']['commerce_coupon_recipient_target_id']['field'] = 'commerce_coupon_recipient_target_id';
  $handler->display->display_options['arguments']['commerce_coupon_recipient_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['commerce_coupon_recipient_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['commerce_coupon_recipient_target_id']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['commerce_coupon_recipient_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['commerce_coupon_recipient_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['commerce_coupon_recipient_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Field: Product (field_coupon_product) */
  $handler->display->display_options['filters']['field_coupon_product_target_id']['id'] = 'field_coupon_product_target_id';
  $handler->display->display_options['filters']['field_coupon_product_target_id']['table'] = 'field_data_field_coupon_product';
  $handler->display->display_options['filters']['field_coupon_product_target_id']['field'] = 'field_coupon_product_target_id';
  $handler->display->display_options['filters']['field_coupon_product_target_id']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/voucher';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Vouchers';
  $handler->display->display_options['menu']['description'] = 'List of Institutional Subscriptions purchased';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Vouchers';
  $handler->display->display_options['tab_options']['description'] = 'List institutional purchased by user';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'user-menu';

  /* Add view. */
  $views[$view->name] = $view;

  return $views;
}