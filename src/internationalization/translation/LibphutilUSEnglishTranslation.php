<?php

final class LibphutilUSEnglishTranslation extends PhutilTranslation {

  public function getLocaleCode() {
    return 'en_US';
  }

  protected function getTranslations() {
    return array(
      'Daemon was idle for more than %s second(s), scaling pool down.' => array(
        'Daemon was idle for more than one second, scaling pool down.',
        'Daemon was idle for more than %s seconds, scaling pool down.',
      ),

      'Analyzing %s file(s) with %s subprocess(es)...' => array(
        array(
          'Analyzing one file with a single subprocess...',
          'Analyzing %s file with %s subprocesses...',
        ),
        array(
          'Analyzing %s files with a single subprocess...',
          'Analyzing %s files with %s subprocesses...',
        ),
      ),

      '... (%s more byte(s)) ...' => array(
        '... (%s more byte) ...',
        '... (%s more bytes) ...',
      ),
    );
  }

}
