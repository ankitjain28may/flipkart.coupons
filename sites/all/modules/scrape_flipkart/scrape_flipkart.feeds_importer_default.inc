<?php
/**
 * @file
 * scrape_flipkart.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function scrape_flipkart_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'crawl_and_scrape';
  $feeds_importer->config = array(
    'name' => 'Crawl and scrape',
    'description' => 'Scrape and Paginate ',
    'fetcher' => array(
      'plugin_key' => 'FeedsCrawler',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => 'http',
        'accept_invalid_cert' => 0,
        'cache_http_result' => 1,
        'crawler' => array(
          'num_pages' => '5',
          'delay' => '1',
          'first_run' => '0',
          'auto' => '0',
          'xpath' => '//div[@class="_1JKxvj _31rYcN"]',
          'url' => array(
            'url_pattern' => 'https://www.flipkart.com/men/tshirts/pr?otracker=nmenu_sub_Men_0_T-Shirts&page=$index&sid=2oq%2Cs9b%2Cj9y&viewType=grid',
            'initial' => '1',
            'increment' => '1',
          ),
        ),
        'crawled' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserHTML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => './div[@class="_3liAhj"]/a[@class="_2cLu-l"]/text()',
          'xpathparser:1' => './div[@class="_3liAhj"]/a[@class="_2cLu-l"]/@href',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
        ),
        'context' => '//div[@class="MP_3W3 _31eJXZ"]',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
          ),
        ),
        'allow_override' => 1,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_product_url',
            'unique' => FALSE,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'products',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['crawl_and_scrape'] = $feeds_importer;

  return $export;
}
