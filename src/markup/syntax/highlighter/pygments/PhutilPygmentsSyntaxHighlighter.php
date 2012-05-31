<?php

/*
 * Copyright 2012 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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

    if ($language) {
      $language = $this->getPygmentsLexerNameFromLanguageName($language);
      $future = new ExecFuture(
        'pygmentize -O encoding=utf-8 -O stripnl=False -f html -l %s',
        $language);
      $future->write($source);
      return new PhutilDefaultSyntaxHighlighterEnginePygmentsFuture(
        $future,
        $source);
    }

    return id(new PhutilDefaultSyntaxHighlighter())
      ->getHighlightFuture($source);
  }

  private function getPygmentsLexerNameFromLanguageName($language) {
    static $map = array(
      'feature' => 'Cucumber',
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
      'S' => 'splus',
      'kid' => 'genshi',
      'vert' => 'glsl',
      'frag' => 'glsl',
      'geo' => 'glsl',
      'plot' => 'gnuplot',
      'plt' => 'gnuplot',
      'gdc' => 'gooddata-cl',
      'man' => 'groff',
      'hs' => 'haskell',
      'html' => 'html+evoque',
      'phtml' => 'html+php',
      'htm' => 'html',
      'xhtml' => 'html',
      'xslt' => 'xml',
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
      'm' => 'objective-c',
      'mm' => 'objective-c',
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
      'j' => 'objective-j',
      'ml' => 'ocaml',
      'mli' => 'ocaml',
      'mll' => 'ocaml',
      'mly' => 'ocaml',
      'pl' => 'prolog',
      'pm' => 'perl',
      'ps' => 'postscript',
      'eps' => 'postscript',
      'po' => 'pot',
      'inc' => 'pov',
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
      'R' => 'splus',
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
      'xml' => 'xml+evoque',
      'xsl' => 'xslt',
      'rss' => 'xml',
      'xsd' => 'xml',
      'wsdl' => 'xml',
      'xqy' => 'xquery',
      'yml' => 'yaml',
    );

    return idx($map, $language, $language);
  }

}
