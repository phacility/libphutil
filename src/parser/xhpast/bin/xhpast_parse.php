<?php

function xhpast_build() {
  return PhutilXHPASTBinary::build();
}

function xhpast_get_binary_path() {
  return PhutilXHPASTBinary::getPath();
}

function xhpast_get_build_instructions() {
  return PhutilXHPASTBinary::getBuildInstructions();
}

function xhpast_get_parser_future($data) {
  return PhutilXHPASTBinary::getParserFuture($data);
}

function xhpast_is_available() {
  return PhutilXHPASTBinary::isAvailable();
}

function xhpast_version() {
  return PhutilXHPASTBinary::getVersion();
}
