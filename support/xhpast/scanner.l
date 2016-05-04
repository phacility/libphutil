%{
#include "ast.hpp"
#define push_state(s) xhp_new_push_state(s, yyg)
#define pop_state() xhp_new_pop_state(yyg)
#define set_state(s) xhp_set_state(s, yyg)

#define pttok(t, txt) \
  yyextra->token_list.push_back( \
    new xhpast::Token(t, txt, yyextra->list_size++)); \
  *yylval = new xhpast::Node(0, yyextra->list_size - 1);
#define ptok(t) \
  pttok(t, yytext);
#define tok(t) \
  ptok(t); \
  return yy_token(t, yyg)
#define YY_USER_INIT \
  if (yyextra->insert_token) { \
    yyg->yy_init = 0; \
    int ft = yyextra->insert_token; \
    yyextra->insert_token = 0; \
    return yy_token(ft, yyg); \
  }

using namespace std;

const char* yytokname(int tok);
static int yy_token(int tok, struct yyguts_t* yyg);
static void yy_scan_newlines(const char* text, struct yyguts_t* yyg);

%}

%option prefix="xhpast"
%option reentrant
 /* PHP allows IF or if */
%option case-insensitive
%option noyywrap nodefault
%option stack
%option bison-bridge
%option 8bit

 /* The different lexing states. Note that the transitions are done either
  * in the lex actions, or in a generic manner in yy_token(). */
%s PHP
%s PHP_COMMENT
%s PHP_EOL_COMMENT
%s PHP_DOC_COMMENT
%s PHP_HEREDOC_START
%s PHP_HEREDOC_NSTART
%s PHP_HEREDOC_NEWLINE
%s PHP_NO_RESERVED_WORDS
%s PHP_NO_RESERVED_WORDS_PERSIST
%s PHP_

LNUM [0-9]+
DNUM ([0-9]*"."[0-9]+)|([0-9]+"."[0-9]*)
EXPONENT_DNUM (({LNUM}|{DNUM})[eE][+-]?{LNUM})
HNUM "0x"[0-9a-fA-F]+
BNUM "0b"[01]+

LABEL [a-zA-Z_\x7f-\xff][a-zA-Z0-9_\x7f-\xff]*
BYTE (.|\n)

WHITESPACE [ \n\r\t]+
TABS_AND_SPACES [ \t]*
NEWLINE ("\r\n"|"\n"|"\r")

%%

 /* Open / close PHP + inline HTML */
<INITIAL>{
  "<?php"/([ \t]|{NEWLINE}) {
    yy_scan_newlines(yytext + 5, yyg);
    // the state transition will be done in yy_token()
    tok(T_OPEN_TAG);
  }
  "<?" {
    tok(T_OPEN_TAG);
  }
  "<?=" {
    tok(T_OPEN_TAG_WITH_ECHO);
  }
  "<"|[^<]* {
    yy_scan_newlines(yytext, yyg);
    tok(T_INLINE_HTML);
  }
}
<PHP,PHP_NO_RESERVED_WORDS,PHP_NO_RESERVED_WORDS_PERSIST>{
  ("?>"|"</script"{WHITESPACE}*">"){NEWLINE}? {
    yy_scan_newlines(yytext + 2, yyg);
    tok(T_CLOSE_TAG);
  }
}

 /* Comments and whitespace */
<PHP,PHP_NO_RESERVED_WORDS,PHP_NO_RESERVED_WORDS_PERSIST>{
  "#"|"//" {
    push_state(PHP_EOL_COMMENT);
    yymore();
  }
  "/**"{WHITESPACE} {
    yy_scan_newlines(yytext + 3, yyg);
    push_state(PHP_DOC_COMMENT);
    yymore();
  }
  "/*" {
    push_state(PHP_COMMENT);
    yymore();
  }
  {WHITESPACE}+ {
    yy_scan_newlines(yytext, yyg);
    ptok(T_WHITESPACE);
  }
}
<PHP_EOL_COMMENT><<EOF>> {
  ptok(T_COMMENT);
  pop_state();
}
<PHP_EOL_COMMENT>{
  {NEWLINE} {
    ++yyextra->lineno;
    ptok(T_COMMENT);
    pop_state();
  }
  [^\r\n?]+ yymore();
  "?>" {
    yyless(yyleng - 2);
    ptok(T_COMMENT);
    pop_state();
  }
  . yymore();
}
<PHP_DOC_COMMENT,PHP_COMMENT>{
  {NEWLINE} {
    ++yyextra->lineno;
    yymore();
  }
  [^*\r\n]+|"*" yymore();
}
<PHP_DOC_COMMENT>"*/" {
  ptok(T_DOC_COMMENT);
  pop_state();
}
<PHP_DOC_COMMENT><<EOF>> {
  ptok(T_DOC_COMMENT);
  pop_state();
}
<PHP_COMMENT>"*/" {
  ptok(T_COMMENT);
  pop_state();
}
<PHP_COMMENT><<EOF>> {
  ptok(T_COMMENT);
  pop_state();
}

 /* Reserved words */
<PHP>{
  include tok(T_INCLUDE);
  include_once tok(T_INCLUDE_ONCE);
  eval tok(T_EVAL);
  require tok(T_REQUIRE);
  require_once tok(T_REQUIRE_ONCE);
  or tok(T_LOGICAL_OR);
  xor tok(T_LOGICAL_XOR);
  and tok(T_LOGICAL_AND);
  print tok(T_PRINT);
  instanceof tok(T_INSTANCEOF);
  new tok(T_NEW);
  clone tok(T_CLONE);
  exit tok(T_EXIT);
  if tok(T_IF);
  elseif tok(T_ELSEIF);
  else tok(T_ELSE);
  endif tok(T_ENDIF);
  echo tok(T_ECHO);
  do tok(T_DO);
  while tok(T_WHILE);
  endwhile tok(T_ENDWHILE);
  for tok(T_FOR);
  endfor tok(T_ENDFOR);
  foreach tok(T_FOREACH);
  endforeach tok(T_ENDFOREACH);
  declare tok(T_DECLARE);
  enddeclare tok(T_ENDDECLARE);
  as tok(T_AS);
  switch tok(T_SWITCH);
  endswitch tok(T_ENDSWITCH);
  case tok(T_CASE);
  default tok(T_DEFAULT);
  break tok(T_BREAK);
  continue tok(T_CONTINUE);
  goto tok(T_GOTO);
  function tok(T_FUNCTION);
  const tok(T_CONST);
  return tok(T_RETURN);
  try tok(T_TRY);
  catch tok(T_CATCH);
  throw tok(T_THROW);
  use tok(T_USE);
  global tok(T_GLOBAL);
  static tok(T_STATIC);
  abstract tok(T_ABSTRACT);
  final tok(T_FINAL);
  private tok(T_PRIVATE);
  protected tok(T_PROTECTED);
  public tok(T_PUBLIC);
  var tok(T_VAR);
  unset tok(T_UNSET);
  isset tok(T_ISSET);
  empty tok(T_EMPTY);
  __halt_compiler tok(T_HALT_COMPILER);
  class tok(T_CLASS);
  interface tok(T_INTERFACE);
  extends tok(T_EXTENDS);
  implements tok(T_IMPLEMENTS);
  list tok(T_LIST);
  array tok(T_ARRAY);
  __class__ tok(T_CLASS_C);
  __method__ tok(T_METHOD_C);
  __function__ tok(T_FUNC_C);
  __line__ tok(T_LINE);
  __file__ tok(T_FILE);
  namespace tok(T_NAMESPACE);
  __namespace__ tok(T_NS_C);
  __dir__ tok(T_DIR);
  insteadof tok(T_INSTEADOF);
  callable tok(T_CALLABLE);
  trait tok(T_TRAIT);
  __trait__ tok(T_TRAIT_C);
  yield tok(T_YIELD);
  finally tok(T_FINALLY);
}

 /* Operators */
<PHP,PHP_NO_RESERVED_WORDS,PHP_NO_RESERVED_WORDS_PERSIST>{
  "+=" tok(T_PLUS_EQUAL);
  "-=" tok(T_MINUS_EQUAL);
  "*=" tok(T_MUL_EQUAL);
  "/=" tok(T_DIV_EQUAL);
  ".=" tok(T_CONCAT_EQUAL);
  "%=" tok(T_MOD_EQUAL);
  "&=" tok(T_AND_EQUAL);
  "|=" tok(T_OR_EQUAL);
  "^=" tok(T_XOR_EQUAL);
  "<<=" tok(T_SL_EQUAL);
  ">>=" tok(T_SR_EQUAL);
  "||" tok(T_BOOLEAN_OR);
  "&&" tok(T_BOOLEAN_AND);
  "==" tok(T_IS_EQUAL);
  "!="|"<>" tok(T_IS_NOT_EQUAL);
  "===" tok(T_IS_IDENTICAL);
  "!==" tok(T_IS_NOT_IDENTICAL);
  "<=" tok(T_IS_SMALLER_OR_EQUAL);
  ">=" tok(T_IS_GREATER_OR_EQUAL);
  "<<" tok(T_SL);
  ">>" tok(T_SR);
  "++" tok(T_INC);
  "--" tok(T_DEC);
  "->" tok(T_OBJECT_OPERATOR);
  "=>" tok(T_DOUBLE_ARROW);
  "::" tok(T_PAAMAYIM_NEKUDOTAYIM);
  "\\" tok(T_NS_SEPARATOR);
  "..." tok(T_ELLIPSIS);
  "??" tok(T_COALESCE);
  "<=>" tok(T_SPACESHIP);
}

 /* Casts */
<PHP,PHP_NO_RESERVED_WORDS,PHP_NO_RESERVED_WORDS_PERSIST>{
  "("{TABS_AND_SPACES}(int|integer){TABS_AND_SPACES}")" tok(T_INT_CAST);
  "("{TABS_AND_SPACES}(real|double|float){TABS_AND_SPACES}")" tok(T_DOUBLE_CAST);
  "("{TABS_AND_SPACES}(string|binary){TABS_AND_SPACES}")" tok(T_STRING_CAST);
  "("{TABS_AND_SPACES}array{TABS_AND_SPACES}")" tok(T_ARRAY_CAST);
  "("{TABS_AND_SPACES}object{TABS_AND_SPACES}")" tok(T_OBJECT_CAST);
  "("{TABS_AND_SPACES}(bool|boolean){TABS_AND_SPACES}")" tok(T_BOOL_CAST);
  "("{TABS_AND_SPACES}unset{TABS_AND_SPACES}")" tok(T_UNSET_CAST);
}

 /* Scalars (parsing these doesn't really matter since we just pass them
    through literally) */
<PHP,PHP_NO_RESERVED_WORDS,PHP_NO_RESERVED_WORDS_PERSIST>{
  {LNUM}|{HNUM}|{BNUM} tok(T_LNUMBER);
  {DNUM}|{EXPONENT_DNUM} tok(T_DNUMBER);
  {LABEL} tok(T_STRING);
  "$"{LABEL} tok(T_VARIABLE);
  b?'(\\.|\\\n|[^\\']+)*'|b?\"(\\.|\\\n|[^\\\"]+)*\" {
    yy_scan_newlines(yytext, yyg);
    tok(T_CONSTANT_ENCAPSED_STRING);
  }
  `[^`]*` {
    yy_scan_newlines(yytext, yyg);
    tok(T_BACKTICKS_EXPR);
  }
}

 /* (HERE|NOW)DOC's */
<PHP,PHP_NO_RESERVED_WORDS,PHP_NO_RESERVED_WORDS_PERSIST>b?"<<<"{TABS_AND_SPACES} {
  push_state(PHP_HEREDOC_START);
  yyextra->heredoc_yyleng = yyleng;
  yymore();
}
<PHP_HEREDOC_START>{
  "'"{LABEL}"'"|\"{LABEL}\" {
    // Create a new string for the heredoc label. Since we're using yymore above
    // yytext will actually start at the "<<<" and not the label. Use of
    // heredoc_yyleng jumps past that. Then we add 1 to get past the " or '. The
    // match is similar to calculate length.
    yyextra->heredoc_label = string(
      yytext + yyextra->heredoc_yyleng + 1,
      yyleng - yyextra->heredoc_yyleng - 2);
    set_state(PHP_HEREDOC_NSTART);
    yyextra->heredoc_yyleng = yyleng;
    yymore();
  }
  {LABEL} {
    yyextra->heredoc_label = string(yytext + yyextra->heredoc_yyleng);
    set_state(PHP_HEREDOC_NSTART);
    yyextra->heredoc_yyleng = yyleng;
    yymore();
  }
}
<PHP_HEREDOC_NSTART>{NEWLINE} {
  yyextra->heredoc_yyleng = yyleng;
  set_state(PHP_HEREDOC_NEWLINE);
  yymore();
}
<PHP_HEREDOC_NEWLINE>{
  {LABEL};?{NEWLINE} {
    if (strncmp(
      yyextra->heredoc_label.c_str(),
      yytext + yyextra->heredoc_yyleng, yyextra->heredoc_label.size()) == 0) {

      switch (yytext[yyextra->heredoc_yyleng + yyextra->heredoc_label.size()]) {
        case ';': case '\n': case '\r':
          yyless(
            yyleng - (
              yyleng -
              yyextra->heredoc_yyleng -
              yyextra->heredoc_label.size()));
          pop_state();
          tok(T_HEREDOC);
      }
    }
    ++yyextra->lineno;
    yyextra->heredoc_yyleng = yyleng;
    yymore();
  }
  [^\r\n]+ {
    yyextra->heredoc_yyleng = yyleng;
    yymore();
  }
  {NEWLINE} {
    ++yyextra->lineno;
    yyextra->heredoc_yyleng = yyleng;
    yymore();
  }
}

 /* Other */
<*>{BYTE} {
  tok(yytext[0]);
  // fix unused function warnings
  yy_top_state(NULL);
  yyunput(0, 0, NULL);
}

%%

#ifdef DEBUG
static const char* yy_state_name(int state) {
  switch (state) {
    case INITIAL:
      return "INITIAL";
    case PHP:
      return "PHP";
    case PHP_COMMENT:
      return "PHP_COMMENT";
    case PHP_EOL_COMMENT:
      return "PHP_EOL_COMMENT";
    case PHP_DOC_COMMENT:
      return "PHP_DOC_COMMENT";
    case PHP_HEREDOC_START:
      return "PHP_HEREDOC_START";
    case PHP_HEREDOC_NSTART:
      return "PHP_HEREDOC_NSTART";
    case PHP_HEREDOC_NEWLINE:
      return "PHP_HEREDOC_NEWLINE";
    case PHP_NO_RESERVED_WORDS:
      return "PHP_NO_RESERVED_WORDS";
    case PHP_NO_RESERVED_WORDS_PERSIST:
      return "PHP_NO_RESERVED_WORDS_PERSIST";
    default:
      return "???";
  }
}

static void yy_log_token(int tok) {
  const char* tokname = yytokname(tok);
  if (tokname) {
    fprintf(stderr, "--> %s\n", tokname);
  } else {
    fprintf(stderr, "--> '%c'\n", tok);
  }
}
#endif

static int yy_token(int tok, yyguts_t* yyg) {
  if (YY_START == PHP_NO_RESERVED_WORDS) {
    pop_state();
  }

  switch (tok) {
    case T_OPEN_TAG:
    case T_OPEN_TAG_WITH_ECHO:
    case T_OPEN_TAG_FAKE:
      push_state(PHP);
      break;

    case T_CLOSE_TAG:
      pop_state();
      // We need to return a ';', not a T_CLOSE_TAG, because a construct like
      // "<?php echo $x ?>" is valid and there are about a billion parser rules
      // which terminate with ';' so making a new rule like
      // "semicolon_or_close_tag" would be hard. The token in yylval has the
      // correct type and value, we just don't generate a node.
      return ';';

    // In PHP it's ok to use keywords such as 'if' as field names
    // or function names.
    case T_OBJECT_OPERATOR:
    case T_FUNCTION:
      push_state(PHP_NO_RESERVED_WORDS);
      break;

    case T_PAAMAYIM_NEKUDOTAYIM:
      push_state(PHP_NO_RESERVED_WORDS);
      break;
  }
#ifdef DEBUG
  yy_log_token(tok);
#endif
  return yyextra->last_token = tok;
}

static inline void yy_scan_newlines(const char* text, struct yyguts_t* yyg) {
  for (; *text; ++text) {
    if (*text == '\r') {
      if (text[1] == '\n') {
        ++text;
      }
      ++yyextra->lineno;
    } else if (*text == '\n') {
      ++yyextra->lineno;
    }
  }
}

void xhp_new_push_state(int s, struct yyguts_t* yyg) {
#ifdef DEBUG
  fprintf(
    stderr,
    "--> PUSH(%s -> %s)\n",
    yy_state_name(YY_START),
    yy_state_name(s));
#endif
  yy_push_state(s, yyg);
}

void xhp_new_pop_state(struct yyguts_t* yyg) {
#ifdef DEBUG
  int s = YY_START;
#endif
  yy_pop_state(yyg);
#ifdef DEBUG
  fprintf(
    stderr,
    "--> POP(%s -> %s)\n",
    yy_state_name(s),
    yy_state_name(YY_START));
#endif
}

void xhp_set_state(int s, struct yyguts_t* yyg) {
#ifdef DEBUG
  fprintf(stderr, "--> SET(%s)\n", yy_state_name(s));
#endif
  BEGIN(s);
}
