<?php

final class XHPASTToken extends AASTToken {

  public function getTypeName() {
    if (empty($this->typeName)) {
      $type_id = $this->typeID;
      if ($type_id <= 255) {
        $this->typeName = chr($type_id);
      }
      $this->typeName = parent::getTypeName();
    }
    return $this->typeName;
  }

  public function isComment() {
    static $type_ids = null;
    if ($type_ids === null) {
      $type_ids = array(
        $this->tree->getTokenTypeIDFromTypeName('T_COMMENT')      => true,
        $this->tree->getTokenTypeIDFromTypeName('T_DOC_COMMENT')  => true,
      );
    }

    return isset($type_ids[$this->typeID]);
  }

  public function isAnyWhitespace() {
    static $type_ids = null;
    if ($type_ids === null) {
      $type_ids = array(
        $this->tree->getTokenTypeIDFromTypeName('T_WHITESPACE') => true,
      );
    }

    return isset($type_ids[$this->typeID]);
  }

}
