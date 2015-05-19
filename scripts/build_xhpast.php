#!/usr/bin/env php
<?php

require_once dirname(__FILE__).'/__init_script__.php';

PhutilXHPASTBinary::build();
echo pht('Build successful!')."\n";
