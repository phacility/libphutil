<?php

/**
 * @group markup
 */
final class PhutilPygmentsSyntaxHighlighter {

  private $config = array();

  public function setConfig($key, $value) {
    $this->config[$key] = $value;
    return $this;
  }

  public function getHighlightFuture($source) {
    $language = idx($this->config, 'language');

    if (preg_match('/\r(?!\n)/', $source)) {
      // TODO: Pygments converts "\r" newlines into "\n" newlines, so we can't
      // use it on files with "\r" newlines. If we have "\r" not followed by
      // "\n" in the file, skip highlighting.
      $language = null;
    }

    if ($language) {
      $language = $this->getPygmentsLexerNameFromLanguageName($language);
      $future = new ExecFuture(
        'pygmentize -O encoding=utf-8 -O stripnl=False -f html -l %s',
        $language);
      $scrub = false;
      if ($language == 'php' && strpos($source, '<?') === false) {
        $source = "<?php\n".$source;
        $scrub = true;
      }
      $future->write($source);
      return new PhutilDefaultSyntaxHighlighterEnginePygmentsFuture(
        $future,
        $source,
        $scrub);
    }

    return id(new PhutilDefaultSyntaxHighlighter())
      ->getHighlightFuture($source);
  }

  private function getPygmentsLexerNameFromLanguageName($language) {
    static $map = array(
      'adb' => 'ada',
      'ads' => 'ada',
      'ahkl' => 'ahk',
      'G' => 'antlr-ruby',
      'g' => 'antlr-ruby',
      'htaccess' => 'apacheconf',
      'as' => 'as3',
      'aspx' => 'aspx-vb',
      'asax' => 'aspx-vb',
      'ascx' => 'aspx-vb',
      'ashx' => 'aspx-vb',
      'asmx' => 'aspx-vb',
      'axd' => 'aspx-vb',
      'sh' => 'bash',
      'ksh' => 'bash',
      'ebuild' => 'bash',
      'eclass' => 'bash',
      'cmd' => 'bat',
      'bmx' => 'blitzmax',
      'bf' => 'brainfuck',
      'b' => 'brainfuck',
      'h' => 'c',
      'cfml' => 'cfm',
      'cfc' => 'cfm',
      'tmpl' => 'cheetah',
      'spt' => 'cheetah',
      'clj' => 'clojure',
      'coffee' => 'coffee-script',
      'cl' => 'common-lisp',
      'lisp' => 'common-lisp',
      'el' => 'common-lisp',
      'sh-session' => 'console',
      'hpp' => 'cpp',
      'c++' => 'cpp',
      'h++' => 'cpp',
      'cc' => 'cpp',
      'hh' => 'cpp',
      'cxx' => 'cpp',
      'hxx' => 'cpp',
      'c++-objdump' => 'cpp-objdump',
      'cxx-objdump' => 'cpp-objdump',
      'cs' => 'csharp',
      'less' => 'css',
      'scss' => 'css',
      'feature' => 'Cucumber',
      'pyx' => 'cython',
      'pxd' => 'cython',
      'pxi' => 'cython',
      'di' => 'd',
      'pas' => 'delphi',
      'patch' => 'diff',
      'darcspatch' => 'dpatch',
      'jbst' => 'duel',
      'dyl' => 'dylan',
      'erl-sh' => 'erl',
      'erl' => 'erlang',
      'hrl' => 'erlang',
      'flx' => 'felix',
      'flxh' => 'felix',
      'f' => 'fortran',
      'f90' => 'fortran',
      's' => 'gas',
      'kid' => 'genshi',
      'vert' => 'glsl',
      'frag' => 'glsl',
      'geo' => 'glsl',
      'plot' => 'gnuplot',
      'plt' => 'gnuplot',
      'gdc' => 'gooddata-cl',
      'man' => 'groff',
      'hs' => 'haskell',
      'htm' => 'html',
      'xhtml' => 'html',
      'html' => 'html+evoque',
      'phtml' => 'html+php',
      'hy' => 'hybris',
      'hyb' => 'hybris',
      'cfg' => 'ini',
      'ik' => 'ioke',
      'weechatlog' => 'irc',
      'll' => 'llvm',
      'lgt' => 'logtalk',
      'wlua' => 'lua',
      'mak' => 'make',
      'Makefile' => 'make',
      'makefile' => 'make',
      'GNUmakefile' => 'make',
      'mao' => 'mako',
      'mhtml' => 'mason',
      'mc' => 'mason',
      'mi' => 'mason',
      'autohandler' => 'mason',
      'dhandler' => 'mason',
      'md' => 'minid',
      'mo' => 'modelica',
      'def' => 'modula2',
      'mod' => 'modula2',
      'moo' => 'moocode',
      'mu' => 'mupad',
      'myt' => 'myghty',
      'autodelegate' => 'myghty',
      'asm' => 'nasm',
      'ASM' => 'nasm',
      'ns2' => 'newspeak',
      'm' => 'objective-c',
      'mm' => 'objective-c',
      'j' => 'objective-j',
      'ml' => 'ocaml',
      'mli' => 'ocaml',
      'mll' => 'ocaml',
      'mly' => 'ocaml',
      'pm' => 'perl',
      'ps' => 'postscript',
      'eps' => 'postscript',
      'po' => 'pot',
      'inc' => 'pov',
      'pl' => 'prolog',
      'pro' => 'prolog',
      'proto' => 'protobuf',
      'py' => 'python',
      'pyw' => 'python',
      'sc' => 'python',
      'SConstruct' => 'python',
      'SConscript' => 'python',
      'tac' => 'python',
      'rl' => 'ragel-em',
      'rbw' => 'rb',
      'Rakefile' => 'rb',
      'rake' => 'rb',
      'gemspec' => 'rb',
      'rbx' => 'rb',
      'duby' => 'rb',
      'Rout' => 'rconsole',
      'r' => 'rebol',
      'r3' => 'rebol',
      'cw' => 'redcode',
      'rest' => 'rst',
      'scm' => 'scheme',
      'st' => 'smalltalk',
      'tpl' => 'smarty',
      'S' => 'splus',
      'R' => 'splus',
      'hql' => 'sql',
      'sqlite3-console' => 'sqlite3',
      'csh' => 'tcsh',
      'aux' => 'tex',
      'toc' => 'tex',
      'txt' => 'text',
      'sv' => 'v',
      'vapi' => 'vala',
      'vb' => 'vb.net',
      'bas' => 'vb.net',
      'vm' => 'velocity',
      'fhtml' => 'velocity',
      'vimrc' => 'vim',
      'xslt' => 'xml',
      'rss' => 'xml',
      'xsd' => 'xml',
      'wsdl' => 'xml',
      'xml' => 'xml+evoque',
      'xqy' => 'xquery',
      'xsl' => 'xslt',
      'yml' => 'yaml',
    );

    return idx($map, $language, $language);
  }

}
