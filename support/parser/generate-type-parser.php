#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/../../scripts/__init_script__.php';

$terminals = array(
  '|',
  '<',
  '>',
  '(',
  ')',
  ',',
  'k',
  'map',
  'list',
  '?',
  'opt',
  'cm',
);

$rules = array(
  'start' => 'maybe_optional',
  'maybe_optional' => array(
    'yes' => 'opt maybe_comment',
    'no' => 'maybe_comment',
  ),
  'maybe_comment' => array(
    'yes' => 'type comment',
    'no' => 'type',
  ),
  'comment' => '( comment_text )',
  'comment_text' => array(
    'comment_text cm',
    'cm',
  ),
  'type' => array(
    'yes' => 'some_type ?',
    'no' => 'some_type',
  ),
  'some_type' => array(
    'or_type',
    'not_or_type',
  ),
  'or_type' => array(
    'or_type | not_or_type',
    'not_or_type | not_or_type',
  ),
  'not_or_type' => array(
    'basic_type',
    'map_type',
    'list_type',
  ),
  'basic_type' => array(
    'k',
  ),
  'map_type' => array(
    'map < type , type >',
  ),
  'list_type' => array(
    'list < type >',
  ),
);

$parser = id(new PhutilParserGenerator())
  ->setTerminals($terminals)
  ->setRules($rules)
  ->processGrammar();

echo $parser->generateParserFunction('phutil_type_spec_parser')."\n";
