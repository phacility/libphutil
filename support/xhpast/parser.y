%{
/*
 * If you modify this grammar, please update the version number in
 * ./xhpast.cpp and libphutil/src/parser/xhpast/bin/xhpast_parse.php
 */

#include "ast.hpp"
#include "node_names.hpp"
// PHP's if/else rules use right reduction rather than left reduction which
// means while parsing nested if/else's the stack grows until it the last
// statement is read. This is annoying, particularly because of a quirk in
// bison.
// http://www.gnu.org/software/bison/manual/html_node/Memory-Management.html
// Apparently if you compile a bison parser with g++ it can no longer grow
// the stack. The work around is to just make your initial stack ridiculously
// large. Unfortunately that increases memory usage while parsing which is
// dumb. Anyway, putting a TODO here to fix PHP's if/else grammar.
#define YYINITDEPTH 500
%}

%{
#undef yyextra
#define yyextra static_cast<yy_extra_type*>(xhpastget_extra(yyscanner))
#undef yylineno
#define yylineno yyextra->first_lineno
#define push_state(s) xhp_new_push_state(s, (struct yyguts_t*) yyscanner)
#define pop_state() xhp_new_pop_state((struct yyguts_t*) yyscanner)
#define set_state(s) xhp_set_state(s, (struct yyguts_t*) yyscanner)

#define NNEW(t) \
  (new xhpast::Node(t))

#define NTYPE(n, type) \
  ((n)->setType(type))

#define NMORE(n, end) \
  ((n)->expandRange(end))

#define NSPAN(n, type, end) \
  (NMORE(NTYPE((n), type), end))

#define NEXPAND(l, n, r) \
  ((n)->expandRange(l)->expandRange(r))

using namespace std;

static void yyerror(void* yyscanner, void* _, const char* error) {
  if (yyextra->terminated) {
    return;
  }
  yyextra->terminated = true;
  yyextra->error = error;
}

%}

%expect 5
// 2: PHP's if/else grammar
// 7: expr '[' dim_offset ']' -- shift will default to first grammar
%name-prefix "xhpast"
%pure-parser
%parse-param { void* yyscanner }
%parse-param { xhpast::Node** root }
%lex-param { void* yyscanner }
%error-verbose

%precedence T_INCLUDE T_INCLUDE_ONCE
%token T_EVAL
%precedence T_REQUIRE T_REQUIRE_ONCE
%token ','
%left T_LOGICAL_OR
%left T_LOGICAL_XOR
%left T_LOGICAL_AND
%precedence T_PRINT
%precedence '=' T_PLUS_EQUAL
  T_MINUS_EQUAL
  T_MUL_EQUAL
  T_DIV_EQUAL
  T_CONCAT_EQUAL
  T_MOD_EQUAL
  T_AND_EQUAL
  T_OR_EQUAL
  T_XOR_EQUAL
  T_SL_EQUAL
  T_SR_EQUAL
%left '?' ':'
%right T_COALESCE
%left T_BOOLEAN_OR
%left T_BOOLEAN_AND
%left '|'
%left '^'
%left '&'
%nonassoc T_IS_EQUAL T_IS_NOT_EQUAL T_IS_IDENTICAL T_IS_NOT_IDENTICAL
  T_SPACESHIP
%nonassoc '<' T_IS_SMALLER_OR_EQUAL '>' T_IS_GREATER_OR_EQUAL
%left T_SL T_SR
%left '+' '-' '.'
%left '*' '/' '%'
%precedence '!'
%precedence T_INSTANCEOF
%precedence '~' T_INC
%token T_DEC
%precedence T_INT_CAST T_DOUBLE_CAST T_STRING_CAST
%token T_UNICODE_CAST
%token T_BINARY_CAST
%precedence T_ARRAY_CAST T_OBJECT_CAST T_BOOL_CAST T_UNSET_CAST '@'
%token '['
%token T_NEW
%precedence T_CLONE
%token T_EXIT
%token T_IF
%token T_ELSEIF
%token T_ELSE
%token T_ENDIF

%token T_LNUMBER
%token T_DNUMBER
%token T_STRING
%token T_STRING_VARNAME /* unused in XHP: `foo` in `"$foo"` */
%token T_VARIABLE
%token T_NUM_STRING /* unused in XHP: `0` in `"$foo[0]"` */
%token T_INLINE_HTML
%token T_CHARACTER /* unused in vanilla PHP */
%token T_BAD_CHARACTER /* unused in vanilla PHP */
%token T_ENCAPSED_AND_WHITESPACE /* unused in XHP: ` ` in `" "` */
%token T_CONSTANT_ENCAPSED_STRING /* overloaded in XHP;
  replaces '"' encaps_list '"' */
%token T_BACKTICKS_EXPR /* new in XHP; replaces '`' backticks_expr '`' */
%token T_ECHO
%token T_DO
%token T_WHILE
%token T_ENDWHILE
%token T_FOR
%token T_ENDFOR
%token T_FOREACH
%token T_ENDFOREACH
%token T_DECLARE
%token T_ENDDECLARE
%token T_AS
%token T_SWITCH
%token T_ENDSWITCH
%token T_CASE
%token T_DEFAULT
%token T_BREAK
%token T_CONTINUE
%token T_GOTO
%token T_FUNCTION
%token T_CONST
%token T_RETURN
%token T_TRY
%token T_CATCH
%token T_THROW
%token T_USE
%token T_GLOBAL
%token T_STATIC
%token T_ABSTRACT
%token T_FINAL
%token T_PRIVATE
%token T_PROTECTED
%token T_PUBLIC
%token T_VAR
%token T_UNSET
%token T_ISSET
%token T_EMPTY
%token T_HALT_COMPILER
%token T_CLASS
%token T_INTERFACE
%token T_EXTENDS
%token T_IMPLEMENTS
%token T_OBJECT_OPERATOR
%token T_DOUBLE_ARROW
%token T_LIST
%token T_ARRAY
%token T_CLASS_C
%token T_METHOD_C
%token T_FUNC_C
%token T_LINE
%token T_FILE
%token T_COMMENT
%token T_DOC_COMMENT
%token T_OPEN_TAG
%token T_OPEN_TAG_WITH_ECHO
%token T_OPEN_TAG_FAKE
%token T_CLOSE_TAG
%token T_WHITESPACE
%token T_START_HEREDOC /* unused in XHP; replaced with T_HEREDOC */
%token T_END_HEREDOC /* unused in XHP; replaced with T_HEREDOC */
%token T_HEREDOC /* new in XHP;
  replaces start_heredoc encaps_list T_END_HEREDOC */
%token T_DOLLAR_OPEN_CURLY_BRACES /* unused in XHP: `${` in `"${foo}"` */
%token T_CURLY_OPEN /* unused in XHP: `{$` in `"{$foo}"` */
%token T_PAAMAYIM_NEKUDOTAYIM
%token T_BINARY_DOUBLE /* unsused in XHP: `b"` in `b"foo"` */
%token T_BINARY_HEREDOC /* unsused in XHP: `b<<<` in `b<<<FOO` */
%token T_NAMESPACE
%token T_NS_C
%token T_DIR
%token T_NS_SEPARATOR
%token T_INSTEADOF
%token T_CALLABLE
%token T_TRAIT
%token T_TRAIT_C
%token T_YIELD
%token T_FINALLY
%token T_ELLIPSIS

%%

start:
  top_statement_list {
    *root = NNEW(n_PROGRAM)->appendChild($1);
  }
;

top_statement_list:
  top_statement_list top_statement {
    $$ = $1->appendChild($2);
  }
| %empty {
    $$ = NNEW(n_STATEMENT_LIST);
  }
;

namespace_name:
  T_STRING {
    $$ = NTYPE($1, n_SYMBOL_NAME);
  }
| namespace_name T_NS_SEPARATOR T_STRING {
    $$ = NMORE($1, $3);
  }
;

top_statement:
  statement
| function_declaration_statement
| class_declaration_statement
| T_HALT_COMPILER '(' ')' ';' {
    $1 = NSPAN($1, n_HALT_COMPILER, $3);
    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $4);
  }
| T_NAMESPACE namespace_name ';' {
    NSPAN($1, n_NAMESPACE, $2);
    $1->appendChild($2);
    $1->appendChild(NNEW(n_EMPTY));
    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $3);
  }
| T_NAMESPACE namespace_name '{' top_statement_list '}' {
  NSPAN($1, n_NAMESPACE, $5);
  $1->appendChild($2);
  $1->appendChild(NEXPAND($3, $4, $5));
  $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
| T_NAMESPACE '{' top_statement_list '}' {
  NSPAN($1, n_NAMESPACE, $4);
  $1->appendChild(NNEW(n_EMPTY));
  NMORE($3, $4);
  NMORE($3, $2);
  $1->appendChild($3);
  $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
| T_USE use_declarations ';' {
  NMORE($2, $1);
  $$ = NNEW(n_STATEMENT)->appendChild($2);
  NMORE($$, $3);
  }
| constant_declaration ';' {
  $$ = NNEW(n_STATEMENT)->appendChild($1);
  NMORE($$, $2);
  }
;

use_declarations:
  use_declarations ',' use_declaration {
    $$ = $1->appendChild($3);
  }
| use_declaration {
    $$ = NNEW(n_USE_LIST);
    $$->appendChild($1);
  }
;

use_declaration:
  namespace_name {
    $$ = NNEW(n_USE);
    $$->appendChild($1);
    $$->appendChild(NNEW(n_EMPTY));
  }
| namespace_name T_AS T_STRING {
    $$ = NNEW(n_USE);
    $$->appendChild($1);
    NTYPE($3, n_STRING);
    $$->appendChild($3);
  }
| T_NS_SEPARATOR namespace_name {
    $$ = NNEW(n_USE);
    NMORE($2, $1);
    $$->appendChild($2);
    $$->appendChild(NNEW(n_EMPTY));
  }
| T_NS_SEPARATOR namespace_name T_AS T_STRING {
    $$ = NNEW(n_USE);
    NMORE($2, $1);
    $$->appendChild($2);
    NTYPE($4, n_STRING);
    $$->appendChild($4);
  }
;

constant_declaration:
  constant_declaration ',' T_STRING '=' static_scalar {
    NMORE($$, $5);
    $$->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE($3, n_STRING))
        ->appendChild($5));
  }
| T_CONST T_STRING '=' static_scalar {
    NSPAN($$, n_CONSTANT_DECLARATION_LIST, $4);
    $$->appendChild(
      NNEW(n_CONSTANT_DECLARATION)
        ->appendChild(NTYPE($2, n_STRING))
        ->appendChild($4));
  }
;

inner_statement_list:
  inner_statement_list inner_statement {
    $$ = $1->appendChild($2);
  }
| %empty {
    $$ = NNEW(n_STATEMENT_LIST);
  }
;

inner_statement:
  statement
| function_declaration_statement
| class_declaration_statement
| T_HALT_COMPILER '(' ')' ';' {
  $1 = NSPAN($1, n_HALT_COMPILER, $3);
  $$ = NNEW(n_STATEMENT)->appendChild($1);
  NMORE($$, $4);
  }
;

statement:
  unticked_statement
| T_STRING ':' {
    NTYPE($1, n_STRING);
    $$ = NNEW(n_LABEL);
    $$->appendChild($1);
    NMORE($$, $2);
  }
| T_OPEN_TAG {
    $$ = NTYPE($1, n_OPEN_TAG);
  }
| T_OPEN_TAG_WITH_ECHO {
    $$ = NTYPE($1, n_OPEN_TAG);
  }
| T_CLOSE_TAG {
    $$ = NTYPE($1, n_CLOSE_TAG);
  }
;

unticked_statement:
  '{' inner_statement_list '}' {
    $$ = NEXPAND($1, $2, $3);
  }
| T_IF '(' expr ')' statement elseif_list else_single {
    $$ = NNEW(n_CONDITION_LIST);

    $1 = NTYPE($1, n_IF);
    $1->appendChild(NSPAN($2, n_CONTROL_CONDITION, $4)->appendChild($3));
    $1->appendChild($5);

    $$->appendChild($1);
    $$->appendChildren($6);

    // Hacks: merge a list of if (x) { } else if (y) { } into a single condition
    // list instead of a condition tree.

    if ($7->type == n_EMPTY) {
      // Ignore.
    } else if ($7->type == n_ELSE) {
      xhpast::Node *stype = $7->firstChild()->firstChild();
      if (stype && stype->type == n_CONDITION_LIST) {
        NTYPE(stype->firstChild(), n_ELSEIF);
        stype->firstChild()->l_tok = $7->l_tok;
        $$->appendChildren(stype);
      } else {
        $$->appendChild($7);
      }
    } else {
      $$->appendChild($7);
    }

    $$ = NNEW(n_STATEMENT)->appendChild($$);
  }
| T_IF '(' expr ')' ':'
  inner_statement_list
  new_elseif_list
  new_else_single
  T_ENDIF ';' {

    $$ = NNEW(n_CONDITION_LIST);
    NTYPE($1, n_IF);
    $1->appendChild(NSPAN($2, n_CONTROL_CONDITION, $4)->appendChild($3));
    $1->appendChild($6);

    $$->appendChild($1);
    $$->appendChildren($7);
    $$->appendChild($8);
    NMORE($$, $9);

    $$ = NNEW(n_STATEMENT)->appendChild($$);
    NMORE($$, $10);
  }
| T_WHILE '(' expr ')' while_statement {
    NTYPE($1, n_WHILE);
    $1->appendChild(NSPAN($2, n_CONTROL_CONDITION, $4)->appendChild($3));
    $1->appendChild($5);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
| T_DO statement T_WHILE '(' expr ')' ';' {
    NTYPE($1, n_DO_WHILE);
    $1->appendChild($2);
    $1->appendChild(NSPAN($4, n_CONTROL_CONDITION, $6)->appendChild($5));

    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $7);
  }
| T_FOR '(' for_expr ';' for_expr ';' for_expr ')' for_statement {
    NTYPE($1, n_FOR);

    NSPAN($2, n_FOR_EXPRESSION, $8)
      ->appendChild($3)
      ->appendChild($5)
      ->appendChild($7);

    $1->appendChild($2);
    $1->appendChild($9);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
| T_SWITCH '(' expr ')' switch_case_list {
    NTYPE($1, n_SWITCH);
    $1->appendChild(NSPAN($2, n_CONTROL_CONDITION, $4)->appendChild($3));
    $1->appendChild($5);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
| T_BREAK ';' {
    NTYPE($1, n_BREAK);
    $1->appendChild(NNEW(n_EMPTY));

    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $2);
  }
| T_BREAK expr ';' {
    NTYPE($1, n_BREAK);
    $1->appendChild($2);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $3);
  }
| T_CONTINUE ';' {
    NTYPE($1, n_CONTINUE);
    $1->appendChild(NNEW(n_EMPTY));

    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $2);
  }
| T_CONTINUE expr ';' {
    NTYPE($1, n_CONTINUE);
    $1->appendChild($2);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $3);
  }
| T_RETURN ';' {
    NTYPE($1, n_RETURN);
    $1->appendChild(NNEW(n_EMPTY));

    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $2);
  }
| T_RETURN expr_without_variable ';' {
    NTYPE($1, n_RETURN);
    $1->appendChild($2);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $3);
  }
| T_RETURN variable ';' {
    NTYPE($1, n_RETURN);
    $1->appendChild($2);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $3);
  }
| T_GLOBAL global_var_list ';' {
    NMORE($2, $1);
    $$ = NNEW(n_STATEMENT)->appendChild($2);
    NMORE($$, $3);
  }
| T_STATIC static_var_list ';' {
    NMORE($2, $1);
    $$ = NNEW(n_STATEMENT)->appendChild($2);
    NMORE($$, $3);
  }
| T_ECHO echo_expr_list ';' {
    NMORE($2, $1);
    $$ = NNEW(n_STATEMENT)->appendChild($2);
    NMORE($$, $3);
  }
| T_INLINE_HTML {
    NTYPE($1, n_INLINE_HTML);
    $$ = $1;
  }
| expr ';' {
    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $2);
  }
| yield_expr ';' {
    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $2);
  }
| T_UNSET '(' unset_variables ')' ';' {
    NMORE($3, $4);
    NMORE($3, $1);
    $$ = NNEW(n_STATEMENT)->appendChild($3);
    NMORE($$, $5);
  }
| T_FOREACH '(' variable T_AS foreach_variable foreach_optional_arg ')'
  foreach_statement {
    NTYPE($1, n_FOREACH);
    NSPAN($2, n_FOREACH_EXPRESSION, $7);
    $2->appendChild($3);
    if ($6->type == n_EMPTY) {
      $2->appendChild($6);
      $2->appendChild($5);
    } else {
      $2->appendChild($5);
      $2->appendChild($6);
    }
    $1->appendChild($2);

    $1->appendChild($8);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
| T_FOREACH '(' expr_without_variable T_AS variable foreach_optional_arg ')'
  foreach_statement {
    NTYPE($1, n_FOREACH);
    NSPAN($2, n_FOREACH_EXPRESSION, $7);
    $2->appendChild($3);
    if ($6->type == n_EMPTY) {
      $2->appendChild($6);
      $2->appendChild($5);
    } else {
      $2->appendChild($5);
      $2->appendChild($6);
    }
    $1->appendChild($2);
    $1->appendChild($8);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
| T_DECLARE '(' declare_list ')' declare_statement {
    NTYPE($1, n_DECLARE);
    $1->appendChild($3);
    $1->appendChild($5);
    $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
| ';' /* empty statement */ {
    $$ = NNEW(n_STATEMENT)->appendChild(NNEW(n_EMPTY));
    NMORE($$, $1);
  }
| T_TRY '{' inner_statement_list '}' catch_list finally_statement {
    NTYPE($1, n_TRY);
    $1->appendChild(NEXPAND($2, $3, $4));

    $1->appendChild($5);
    $1->appendChild($6);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
| T_TRY '{' inner_statement_list '}' non_empty_finally_statement {
    NTYPE($1, n_TRY);
    $1->appendChild(NEXPAND($2, $3, $4));

    $1->appendChild(NNEW(n_CATCH_LIST));
    $1->appendChild($5);

    $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
| T_THROW expr ';' {
  NTYPE($1, n_THROW);
  $1->appendChild($2);

  $$ = NNEW(n_STATEMENT)->appendChild($1);
  NMORE($$, $3);

  }
| T_GOTO T_STRING ';' {
  NTYPE($1, n_GOTO);
  NTYPE($2, n_STRING);
  $1->appendChild($2);

  $$ = NNEW(n_STATEMENT)->appendChild($1);
  NMORE($$, $3);
  }
;

catch_list:
  catch_list catch {
    $1->appendChild($2);
    $$ = $1;
  }
| catch {
  $$ = NNEW(n_CATCH_LIST);
  $$->appendChild($1);
}

catch:
  T_CATCH '(' fully_qualified_class_name T_VARIABLE ')'
  '{' inner_statement_list '}' {
    NTYPE($1, n_CATCH);
    $1->appendChild($3);
    $1->appendChild(NTYPE($4, n_VARIABLE));
    $1->appendChild(NEXPAND($6, $7, $8));
    NMORE($1, $8);
    $$ = $1;
  }
;

finally_statement:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| non_empty_finally_statement
;

non_empty_finally_statement:
  T_FINALLY '{' inner_statement_list '}' {
    NTYPE($1, n_FINALLY);
    $1->appendChild($3);
    NMORE($1, $4);
    $$ = $1;
  }
;

unset_variables:
  unset_variable {
    $$ = NNEW(n_UNSET_LIST);
    $$->appendChild($1);
  }
| unset_variables ',' unset_variable {
    $1->appendChild($3);
    $$ = $1;
  }
;

unset_variable:
  variable
;

function_declaration_statement:
  unticked_function_declaration_statement
;

class_declaration_statement:
  unticked_class_declaration_statement
;

is_reference:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| '&' {
    $$ = NTYPE($1, n_REFERENCE);
  }
;

unticked_function_declaration_statement:
  function is_reference T_STRING
  '(' parameter_list ')' return_type '{' inner_statement_list '}' {
    NSPAN($1, n_FUNCTION_DECLARATION, $9);
    $1->appendChild(NNEW(n_EMPTY));
    $1->appendChild($2);
    $1->appendChild(NTYPE($3, n_STRING));
    $1->appendChild(NEXPAND($4, $5, $6));
    $1->appendChild(NNEW(n_EMPTY));
    $1->appendChild($7);
    $1->appendChild(NEXPAND($8, $9, $10));

    $$ = NNEW(n_STATEMENT)->appendChild($1);
  }
;

unticked_class_declaration_statement:
  class_entry_type T_STRING extends_from implements_list
  '{' class_statement_list '}' {
    $$ = NNEW(n_CLASS_DECLARATION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_CLASS_NAME));
    $$->appendChild($3);
    $$->appendChild($4);
    $$->appendChild(NEXPAND($5, $6, $7));
    NMORE($$, $7);

    $$ = NNEW(n_STATEMENT)->appendChild($$);
  }
| interface_entry T_STRING interface_extends_list '{' class_statement_list '}' {
    $$ = NNEW(n_INTERFACE_DECLARATION);
    $$->appendChild(NNEW(n_CLASS_ATTRIBUTES));
    NMORE($$, $1);
    $$->appendChild(NTYPE($2, n_CLASS_NAME));
    $$->appendChild($3);
    $$->appendChild(NNEW(n_EMPTY));
    $$->appendChild(NEXPAND($4, $5, $6));
    NMORE($$, $6);

    $$ = NNEW(n_STATEMENT)->appendChild($$);
  }
;

class_entry_type:
  T_CLASS {
    NTYPE($1, n_CLASS_ATTRIBUTES);
    $$ = $1;
  }
| T_ABSTRACT T_CLASS {
    NTYPE($2, n_CLASS_ATTRIBUTES);
    NMORE($2, $1);
    $2->appendChild(NTYPE($1, n_STRING));

    $$ = $2;
  }
| T_FINAL T_CLASS {
    NTYPE($2, n_CLASS_ATTRIBUTES);
    NMORE($2, $1);
    $2->appendChild(NTYPE($1, n_STRING));

    $$ = $2;
  }
| T_TRAIT {
    $$ = NNEW(n_CLASS_ATTRIBUTES);
    $$->appendChild(NTYPE($1, n_STRING));
  }
;

extends_from:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| T_EXTENDS fully_qualified_class_name {
    $$ = NTYPE($1, n_EXTENDS_LIST)->appendChild($2);
  }
;

interface_entry:
  T_INTERFACE
;

interface_extends_list:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| T_EXTENDS interface_list {
    NTYPE($1, n_EXTENDS_LIST);
    $1->appendChildren($2);
    $$ = $1;
  }
;

implements_list:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| T_IMPLEMENTS interface_list {
    NTYPE($1, n_IMPLEMENTS_LIST);
    $1->appendChildren($2);
    $$ = $1;
  }
;

interface_list:
  fully_qualified_class_name {
    $$ = NNEW(n_IMPLEMENTS_LIST)->appendChild($1);
  }
| interface_list ',' fully_qualified_class_name {
    $$ = $1->appendChild($3);
  }
;

foreach_optional_arg:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| T_DOUBLE_ARROW foreach_variable {
    $$ = $2;
  }
;

foreach_variable:
  variable
| '&' variable {
    NTYPE($1, n_VARIABLE_REFERENCE);
    $1->appendChild($2);
    $$ = $1;
  }
;

for_statement:
  statement
| ':' inner_statement_list T_ENDFOR ';' {
  NMORE($2, $1);
  NMORE($2, $4);
  $$ = $2;
  }
;

foreach_statement:
  statement
| ':' inner_statement_list T_ENDFOREACH ';' {
  NMORE($2, $1);
  NMORE($2, $4);
  $$ = $2;
  }
;

declare_statement:
  statement
| ':' inner_statement_list T_ENDDECLARE ';' {
  NMORE($2, $1);
  NMORE($2, $4);
  $$ = $2;
  }
;

declare_list:
  T_STRING '=' static_scalar {
    $$ = NNEW(n_DECLARE_DECLARATION);
    $$->appendChild(NTYPE($1, n_STRING));
    $$->appendChild($3);
    $$ = NNEW(n_DECLARE_DECLARATION_LIST)->appendChild($$);
  }
| declare_list ',' T_STRING '=' static_scalar {
    $$ = NNEW(n_DECLARE_DECLARATION);
    $$->appendChild(NTYPE($3, n_STRING));
    $$->appendChild($5);

    $1->appendChild($$);
    $$ = $1;
  }
;

switch_case_list:
  '{' case_list '}' {
    $$ = NEXPAND($1, $2, $3);
  }
| '{' ';' case_list '}' {
    // ...why does this rule exist?

    NTYPE($2, n_STATEMENT);
    $1->appendChild(NNEW(n_EMPTY));

    $$ = NNEW(n_STATEMENT_LIST)->appendChild($2);
    $$->appendChildren($3);
    NEXPAND($1, $$, $4);
  }
| ':' case_list T_ENDSWITCH ';' {
    NMORE($2, $4);
    NMORE($2, $1);
    $$ = $2;
  }
| ':' ';' case_list T_ENDSWITCH ';' {
    NTYPE($2, n_STATEMENT);
    $1->appendChild(NNEW(n_EMPTY));

    $$ = NNEW(n_STATEMENT_LIST)->appendChild($2);
    $$->appendChildren($3);
    NMORE($$, $5);
    NMORE($$, $1);
  }
;

case_list:
  %empty {
    $$ = NNEW(n_STATEMENT_LIST);
  }
| case_list T_CASE expr case_separator inner_statement_list {
    NTYPE($2, n_CASE);
    $2->appendChild($3);
    $2->appendChild($5);

    $1->appendChild($2);
    $$ = $1;
  }
| case_list T_DEFAULT case_separator inner_statement_list {
    NTYPE($2, n_DEFAULT);
    $2->appendChild($4);

    $1->appendChild($2);
    $$ = $1;
  }
;

case_separator:
  ':'
| ';'
;

while_statement:
  statement
| ':' inner_statement_list T_ENDWHILE ';' {
  NMORE($2, $4);
  NMORE($2, $1);
  $$ = $2;
  }
;

elseif_list:
  %empty {
    $$ = NNEW(n_CONDITION_LIST);
  }
| elseif_list T_ELSEIF '(' expr ')' statement {
    NTYPE($2, n_ELSEIF);
    $2->appendChild(NSPAN($3, n_CONTROL_CONDITION, $5)->appendChild($4));
    $2->appendChild($6);

    $$ = $1->appendChild($2);
  }
;

new_elseif_list:
  %empty {
    $$ = NNEW(n_CONDITION_LIST);
  }
| new_elseif_list T_ELSEIF '(' expr ')' ':' inner_statement_list {
    NTYPE($2, n_ELSEIF);
    $2->appendChild($4);
    $2->appendChild($7);

    $$ = $1->appendChild($2);
  }
;

else_single:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| T_ELSE statement {
    NTYPE($1, n_ELSE);
    $1->appendChild($2);
    $$ = $1;
  }
;

new_else_single:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| T_ELSE ':' inner_statement_list {
    NTYPE($1, n_ELSE);
    $1->appendChild($3);
    $$ = $1;
  }
;

parameter_list:
  non_empty_parameter_list
| %empty {
    $$ = NNEW(n_DECLARATION_PARAMETER_LIST);
  }
;

non_empty_parameter_list:
  optional_type parameter {
    $$ = NNEW(n_DECLARATION_PARAMETER);
    $$->appendChild($1);
    $$->appendChild($2);
    $$->appendChild(NNEW(n_EMPTY));

    $$ = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild($$);
  }
| optional_type '&' parameter {
    $$ = NNEW(n_DECLARATION_PARAMETER);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_VARIABLE_REFERENCE));
      $2->appendChild($3);
    $$->appendChild(NNEW(n_EMPTY));

    $$ = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild($$);
  }
| optional_type '&' parameter '=' static_scalar {
    $$ = NNEW(n_DECLARATION_PARAMETER);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_VARIABLE_REFERENCE));
      $2->appendChild($3);
    $$->appendChild($5);

    $$ = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild($$);
  }
| optional_type parameter '=' static_scalar {
    $$ = NNEW(n_DECLARATION_PARAMETER);
    $$->appendChild($1);
    $$->appendChild($2);
    $$->appendChild($4);

    $$ = NNEW(n_DECLARATION_PARAMETER_LIST)->appendChild($$);
  }
| non_empty_parameter_list ',' optional_type parameter {
    $$ = NNEW(n_DECLARATION_PARAMETER);
    $$->appendChild($3);
    $$->appendChild($4);
    $$->appendChild(NNEW(n_EMPTY));

    $$ = $1->appendChild($$);
  }
| non_empty_parameter_list ',' optional_type '&' parameter {
    $$ = NNEW(n_DECLARATION_PARAMETER);
    $$->appendChild($3);
    $$->appendChild(NTYPE($4, n_VARIABLE_REFERENCE));
      $4->appendChild($5);
    $$->appendChild(NNEW(n_EMPTY));

    $$ = $1->appendChild($$);
  }
| non_empty_parameter_list ',' optional_type '&'
  parameter '=' static_scalar {
    $$ = NNEW(n_DECLARATION_PARAMETER);
    $$->appendChild($3);
    $$->appendChild(NTYPE($4, n_VARIABLE_REFERENCE));
      $4->appendChild($5);
    $$->appendChild($7);

    $$ = $1->appendChild($$);
  }
| non_empty_parameter_list ',' optional_type
  parameter '=' static_scalar {
    $$ = NNEW(n_DECLARATION_PARAMETER);
    $$->appendChild($3);
    $$->appendChild($4);
    $$->appendChild($6);

    $$ = $1->appendChild($$);
  }
;

parameter:
  T_ELLIPSIS T_VARIABLE {
    $$ = NTYPE($1, n_UNPACK);
    $$->appendChild(NTYPE($2, n_VARIABLE));
  }
| T_VARIABLE {
    $$ = NTYPE($1, n_VARIABLE);
  }
;

optional_type:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| type
| '?' type {
    $$ = NNEW(n_NULLABLE_TYPE);
    $$->appendChild($2);
  }
;

type:
  fully_qualified_class_name {
    $$ = $1;
  }
| T_ARRAY {
    $$ = NTYPE($1, n_TYPE_NAME);
  }
| T_CALLABLE {
    $$ = NTYPE($1, n_TYPE_NAME);
  }
;

return_type:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| ':' optional_type {
    $$ = NNEW(n_DECLARATION_RETURN);
    $$->appendChild($2);
  }
;

function_call_parameter_list:
  non_empty_function_call_parameter_list
| %empty {
    $$ = NNEW(n_CALL_PARAMETER_LIST);
  }
;

non_empty_function_call_parameter_list:
  argument {
    $$ = NNEW(n_CALL_PARAMETER_LIST)->appendChild($1);
  }
| non_empty_function_call_parameter_list ',' argument {
    $$ = $1->appendChild($3);
  }
;

argument:
  expr
| T_ELLIPSIS expr {
    $$ = NNEW(n_UNPACK)->appendChild($1);
  }
| '&' w_variable {
    NTYPE($1, n_VARIABLE_REFERENCE);
    $$ = $1->appendChild($2);
  }
;

global_var_list:
  global_var_list ',' global_var {
    $1->appendChild($3);
    $$ = $1;
  }
| global_var {
    $$ = NNEW(n_GLOBAL_DECLARATION_LIST);
    $$->appendChild($1);
  }
;

global_var:
  T_VARIABLE {
    $$ = NTYPE($1, n_VARIABLE);
  }
| '$' r_variable {
    $$ = NTYPE($1, n_VARIABLE_VARIABLE);
    $$->appendChild($2);
  }
| '$' '{' expr '}' {
    $$ = NTYPE($1, n_VARIABLE_VARIABLE);
    $$->appendChild($3);
  }
;

static_var_list:
  static_var_list ',' T_VARIABLE {
    NTYPE($3, n_VARIABLE);
    $$ = NNEW(n_STATIC_DECLARATION);
    $$->appendChild($3);
    $$->appendChild(NNEW(n_EMPTY));

    $$ = $1->appendChild($$);
  }
| static_var_list ',' T_VARIABLE '=' static_scalar {
    NTYPE($3, n_VARIABLE);
    $$ = NNEW(n_STATIC_DECLARATION);
    $$->appendChild($3);
    $$->appendChild($5);

    $$ = $1->appendChild($$);
  }
| T_VARIABLE {
    NTYPE($1, n_VARIABLE);
    $$ = NNEW(n_STATIC_DECLARATION);
    $$->appendChild($1);
    $$->appendChild(NNEW(n_EMPTY));

    $$ = NNEW(n_STATIC_DECLARATION_LIST)->appendChild($$);
  }
| T_VARIABLE '=' static_scalar {
    NTYPE($1, n_VARIABLE);
    $$ = NNEW(n_STATIC_DECLARATION);
    $$->appendChild($1);
    $$->appendChild($3);

    $$ = NNEW(n_STATIC_DECLARATION_LIST)->appendChild($$);
  }
;

class_statement_list:
  class_statement_list class_statement {
    $$ = $1->appendChild($2);
  }
| %empty {
    $$ = NNEW(n_STATEMENT_LIST);
  }
;

class_statement:
  variable_modifiers class_variable_declaration ';' {
    $$ = NNEW(n_CLASS_MEMBER_DECLARATION_LIST);
    $$->appendChild($1);
    $$->appendChildren($2);

    $$ = NNEW(n_STATEMENT)->appendChild($$);
    NMORE($$, $3);
  }
| class_constant_declaration ';' {
    $$ = NNEW(n_STATEMENT)->appendChild($1);
    NMORE($$, $2);
  }
| trait_use_statement {
    $$ = $1;
  }
| method_modifiers function {
    /* empty */
  } is_reference T_STRING '(' parameter_list ')' return_type method_body {
    $$ = NNEW(n_METHOD_DECLARATION);
    NMORE($$, $2);
    $$->appendChild($1);
    $$->appendChild($4);
    $$->appendChild(NTYPE($5, n_STRING));
    $$->appendChild(NEXPAND($6, $7, $8));
    $$->appendChild(NNEW(n_EMPTY));
    $$->appendChild($9);
    $$->appendChild($10);

    $$ = NNEW(n_STATEMENT)->appendChild($$);
  }
;

trait_use_statement:
  T_USE trait_list trait_adaptations {
    $$ = NTYPE($1, n_TRAIT_USE);
    $$->appendChildren($2);
    $$->appendChild($3);
  }
;

trait_list:
  fully_qualified_class_name {
    $$ = NNEW(n_TRAIT_USE_LIST)->appendChild($1);
  }
| trait_list ',' fully_qualified_class_name {
    $$ = $1->appendChild($3);
  }
;

trait_adaptations:
  ';' {
    $$ = NNEW(n_EMPTY);
  }
| '{' trait_adaptation_list '}' {
    $$ = NEXPAND($1, $2, $3);
  }
;

trait_adaptation_list:
  %empty {
    $$ = NNEW(n_TRAIT_ADAPTATION_LIST);
  }
| non_empty_trait_adaptation_list {
    $$ = $1;
  }
;

non_empty_trait_adaptation_list:
  trait_adaptation_statement {
    $$ = NNEW(n_TRAIT_ADAPTATION_LIST);
    $$->appendChild($1);
  }
|  non_empty_trait_adaptation_list trait_adaptation_statement {
    $1->appendChild($2);
    $$ = $1;
  }
;

trait_adaptation_statement:
  trait_precedence ';' {
    $$ = NMORE($1, $2);
  }
|  trait_alias ';' {
    $$ = NMORE($1, $2);
  }
;

trait_precedence:
  trait_method_reference_fully_qualified T_INSTEADOF trait_reference_list  {
    $$ = NNEW(n_TRAIT_INSTEADOF);
    $$->appendChild($1);
    $$->appendChild($3);
  }
;

trait_reference_list:
  fully_qualified_class_name {
    $$ = NNEW(n_TRAIT_REFERENCE_LIST);
    $$->appendChild($1);
  }
| trait_reference_list ',' fully_qualified_class_name  {
    $1->appendChild($3);
    $$ = $1;
  }
;

trait_method_reference:
  T_STRING {
    $$ = NNEW(n_TRAIT_METHOD_REFERENCE);
    $$->appendChild(NTYPE($1, n_STRING));
  }
|  trait_method_reference_fully_qualified {
    $$ = $1;
  }
;

trait_method_reference_fully_qualified:
  fully_qualified_class_name T_PAAMAYIM_NEKUDOTAYIM T_STRING {
    NTYPE($2, n_TRAIT_METHOD_REFERENCE);
    NEXPAND($1, $2, NTYPE($3, n_STRING));
    $$ = $2;
  }
;

trait_alias:
  trait_method_reference T_AS trait_modifiers T_STRING {
    $$ = NNEW(n_TRAIT_AS);
    $$->appendChild($1);
    $$->appendChild($3);
    $$->appendChild(NTYPE($4, n_STRING));
  }
|  trait_method_reference T_AS member_modifier {
    $$ = NNEW(n_TRAIT_AS);
    $$->appendChild($1);
    $$->appendChild($3);
    $$->appendChild(NNEW(n_EMPTY));
  }
;

trait_modifiers:
  %empty  {
    $$ = NNEW(n_EMPTY);
  }
|  member_modifier  {
    $$ = NNEW(n_METHOD_MODIFIER_LIST);
    $$->appendChild(NTYPE($1, n_STRING));
  }
;


method_body:
  ';' /* abstract method */ {
    $$ = NNEW(n_EMPTY);
  }
| '{' inner_statement_list '}' {
    $$ = NEXPAND($1, $2, $3);
  }
;

variable_modifiers:
  non_empty_member_modifiers
| T_VAR {
    $$ = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    $$->appendChild(NTYPE($1, n_STRING));
  }
;

method_modifiers:
  %empty {
    $$ = NNEW(n_METHOD_MODIFIER_LIST);
  }
| non_empty_member_modifiers {
    NTYPE($1, n_METHOD_MODIFIER_LIST);
    $$ = $1;
  }
;

non_empty_member_modifiers:
  member_modifier {
    $$ = NNEW(n_CLASS_MEMBER_MODIFIER_LIST);
    $$->appendChild(NTYPE($1, n_STRING));
  }
| non_empty_member_modifiers member_modifier {
    $$ = $1->appendChild(NTYPE($2, n_STRING));
  }
;

member_modifier:
  T_PUBLIC
| T_PROTECTED
| T_PRIVATE
| T_STATIC
| T_ABSTRACT
| T_FINAL
;

class_variable_declaration:
  class_variable_declaration ',' T_VARIABLE {
    $$ = NNEW(n_CLASS_MEMBER_DECLARATION);
    $$->appendChild(NTYPE($3, n_VARIABLE));
    $$->appendChild(NNEW(n_EMPTY));

    $$ = $1->appendChild($$);
  }
| class_variable_declaration ',' T_VARIABLE '=' static_scalar {
    $$ = NNEW(n_CLASS_MEMBER_DECLARATION);
    $$->appendChild(NTYPE($3, n_VARIABLE));
    $$->appendChild($5);

    $$ = $1->appendChild($$);
  }
| T_VARIABLE {
    $$ = NNEW(n_CLASS_MEMBER_DECLARATION);
    $$->appendChild(NTYPE($1, n_VARIABLE));
    $$->appendChild(NNEW(n_EMPTY));

    $$ = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild($$);
  }
| T_VARIABLE '=' static_scalar {
    $$ = NNEW(n_CLASS_MEMBER_DECLARATION);
    $$->appendChild(NTYPE($1, n_VARIABLE));
    $$->appendChild($3);

    $$ = NNEW(n_CLASS_MEMBER_DECLARATION_LIST)->appendChild($$);
  }
;

class_constant_declaration:
  class_constant_declaration ',' T_STRING '=' static_scalar {
    $$ = NNEW(n_CLASS_CONSTANT_DECLARATION);
    $$->appendChild(NTYPE($3, n_STRING));
    $$->appendChild($5);

    $1->appendChild($$);

    $$ = $1;
  }
| T_CONST T_STRING '=' static_scalar {
    NTYPE($1, n_CLASS_CONSTANT_DECLARATION_LIST);
    $$ = NNEW(n_CLASS_CONSTANT_DECLARATION);
    $$->appendChild(NTYPE($2, n_STRING));
    $$->appendChild($4);
    $1->appendChild($$);

    $$ = $1;
  }
;

echo_expr_list:
  echo_expr_list ',' expr {
    $1->appendChild($3);
  }
| expr {
    $$ = NNEW(n_ECHO_LIST);
    $$->appendChild($1);
  }
;

for_expr:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| non_empty_for_expr
;


non_empty_for_expr:
  non_empty_for_expr ',' expr {
    $1->appendChild($3);
  }
| expr {
    $$ = NNEW(n_EXPRESSION_LIST);
    $$->appendChild($1);
  }
;

expr_without_variable:
  T_LIST '(' assignment_list ')' '=' expr {
    NTYPE($1, n_LIST);
    $1->appendChild(NEXPAND($2, $3, $4));
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($5, n_OPERATOR));
    $$->appendChild($6);
  }
| variable '=' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable '=' '&' variable {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));

    NTYPE($3, n_VARIABLE_REFERENCE);
    $3->appendChild($4);

    $$->appendChild($3);
  }
| variable '=' '&' T_NEW class_name_reference ctor_arguments {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));

    NTYPE($4, n_NEW);
    $4->appendChild($5);
    $4->appendChild($6);

    NTYPE($3, n_VARIABLE_REFERENCE);
    $3->appendChild($4);

    $$->appendChild($3);
  }
| T_CLONE expr {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| variable T_PLUS_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable T_MINUS_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable T_MUL_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable T_DIV_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable T_CONCAT_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable T_MOD_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable T_AND_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable T_OR_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable T_XOR_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable T_SL_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| variable T_SR_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| rw_variable T_INC {
    $$ = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
  }
| T_INC rw_variable {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| rw_variable T_DEC {
    $$ = NNEW(n_UNARY_POSTFIX_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
  }
| T_DEC rw_variable {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| expr T_BOOLEAN_OR expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_BOOLEAN_AND expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_LOGICAL_OR expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_LOGICAL_AND expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_LOGICAL_XOR expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr '|' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr '&' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr '^' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr '.' expr {

    /* The concatenation operator generates n_CONCATENATION_LIST instead of
       n_BINARY_EXPRESSION because we tend to run into stack depth issues in a
       lot of real-world cases otherwise (e.g., in PHP and JSON decoders). */

    if ($1->type == n_CONCATENATION_LIST && $3->type == n_CONCATENATION_LIST) {
      $1->appendChild(NTYPE($2, n_OPERATOR));
      $1->appendChildren($3);
      $$ = $1;
    } else if ($1->type == n_CONCATENATION_LIST) {
      $1->appendChild(NTYPE($2, n_OPERATOR));
      $1->appendChild($3);
      $$ = $1;
    } else if ($3->type == n_CONCATENATION_LIST) {
      $$ = NNEW(n_CONCATENATION_LIST);
      $$->appendChild($1);
      $$->appendChild(NTYPE($2, n_OPERATOR));
      $$->appendChildren($3);
    } else {
      $$ = NNEW(n_CONCATENATION_LIST);
      $$->appendChild($1);
      $$->appendChild(NTYPE($2, n_OPERATOR));
      $$->appendChild($3);
    }
  }
| expr '+' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr '-' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr '*' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr '/' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr '%' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_SL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_SR expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| '+' expr %prec T_INC {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| '-' expr %prec T_INC {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| '!' expr {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| '~' expr {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| expr T_IS_IDENTICAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_IS_NOT_IDENTICAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_IS_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_IS_NOT_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr '<' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_IS_SMALLER_OR_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr '>' expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_IS_GREATER_OR_EQUAL expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_SPACESHIP expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| expr T_INSTANCEOF class_name_reference {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| parenthesis_expr
| new_expr
| expr '?' expr ':' expr {
    $$ = NNEW(n_TERNARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
    $$->appendChild(NTYPE($4, n_OPERATOR));
    $$->appendChild($5);
  }
| expr '?' ':' expr {
    $$ = NNEW(n_TERNARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild(NNEW(n_EMPTY));
    $$->appendChild(NTYPE($3, n_OPERATOR));
    $$->appendChild($4);
  }
| expr T_COALESCE expr {
    $$ = NNEW(n_BINARY_EXPRESSION);
    $$->appendChild($1);
    $$->appendChild(NTYPE($2, n_OPERATOR));
    $$->appendChild($3);
  }
| internal_functions_in_yacc
| T_INT_CAST expr {
    $$ = NNEW(n_CAST_EXPRESSION);
    $$->appendChild(NTYPE($1, n_CAST));
    $$->appendChild($2);
  }
| T_DOUBLE_CAST expr {
    $$ = NNEW(n_CAST_EXPRESSION);
    $$->appendChild(NTYPE($1, n_CAST));
    $$->appendChild($2);
  }
| T_STRING_CAST expr {
    $$ = NNEW(n_CAST_EXPRESSION);
    $$->appendChild(NTYPE($1, n_CAST));
    $$->appendChild($2);
  }
| T_ARRAY_CAST expr {
    $$ = NNEW(n_CAST_EXPRESSION);
    $$->appendChild(NTYPE($1, n_CAST));
    $$->appendChild($2);
  }
| T_OBJECT_CAST expr {
    $$ = NNEW(n_CAST_EXPRESSION);
    $$->appendChild(NTYPE($1, n_CAST));
    $$->appendChild($2);
  }
| T_BOOL_CAST expr {
    $$ = NNEW(n_CAST_EXPRESSION);
    $$->appendChild(NTYPE($1, n_CAST));
    $$->appendChild($2);
  }
| T_UNSET_CAST expr {
    $$ = NNEW(n_CAST_EXPRESSION);
    $$->appendChild(NTYPE($1, n_CAST));
    $$->appendChild($2);
  }
| T_EXIT exit_expr {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| '@' expr {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| T_BACKTICKS_EXPR {
    NTYPE($1, n_BACKTICKS_EXPRESSION);
    $$ = $1;
  }
| scalar
| combined_scalar_offset
| combined_scalar
| T_PRINT expr {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| T_YIELD {
    NTYPE($1, n_YIELD);
    $1->appendChild(NNEW(n_EMPTY));
    $1->appendChild(NNEW(n_EMPTY));
    $$ = $1;
  }
| function is_reference
  '(' parameter_list ')'
  lexical_vars return_type
  '{' inner_statement_list '}' {
    NSPAN($1, n_FUNCTION_DECLARATION, $9);
    $1->appendChild(NNEW(n_EMPTY));
    $1->appendChild($2);
    $1->appendChild(NNEW(n_EMPTY));
    $1->appendChild(NEXPAND($3, $4, $5));
    $1->appendChild($6);
    $1->appendChild($7);
    $1->appendChild(NEXPAND($8, $9, $10));

    $$ = $1;
  }
| T_STATIC function is_reference
  '(' parameter_list ')'
  lexical_vars return_type
  '{' inner_statement_list '}' {
    NSPAN($2, n_FUNCTION_DECLARATION, $10);
    NMORE($2, $1);

    $$ = NNEW(n_FUNCTION_MODIFIER_LIST);
    $$->appendChild(NTYPE($1, n_STRING));
    $2->appendChild($1);

    $2->appendChild(NNEW(n_EMPTY));
    $2->appendChild($3);
    $2->appendChild(NNEW(n_EMPTY));
    $2->appendChild(NEXPAND($4, $5, $6));
    $2->appendChild($7);
    $2->appendChild($8);
    $2->appendChild(NEXPAND($9, $10, $11));

    $$ = $2;
  }
;

yield_expr:
  T_YIELD expr_without_variable {
    NTYPE($1, n_YIELD);
    $2->appendChild(NNEW(n_EMPTY));
    $1->appendChild($2);
    $$ = $1;
  }
| T_YIELD variable {
    NTYPE($1, n_YIELD);
    $2->appendChild(NNEW(n_EMPTY));
    $1->appendChild($2);
    $$ = $1;
  }
|  T_YIELD expr T_DOUBLE_ARROW expr_without_variable {
    NTYPE($1, n_YIELD);
    $1->appendChild($2);
    $1->appendChild($4);
    $$ = $1;
  }
|  T_YIELD expr T_DOUBLE_ARROW variable {
    NTYPE($1, n_YIELD);
    $1->appendChild($2);
    $1->appendChild($4);
    $$ = $1;
  }
;

function:
  T_FUNCTION
;

lexical_vars:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| T_USE '(' lexical_var_list ')' {
    NTYPE($1, n_LEXICAL_VARIABLE_LIST);
    $1->appendChildren($3);
    $$ = $1;
  }
;

lexical_var_list:
  lexical_var_list ',' T_VARIABLE {
    $$ = $1->appendChild(NTYPE($3, n_VARIABLE));
  }
| lexical_var_list ',' '&' T_VARIABLE {
    NTYPE($3, n_VARIABLE_REFERENCE);
    $3->appendChild(NTYPE($4, n_VARIABLE));
    $$ = $1->appendChild($3);
  }
| T_VARIABLE {
    $$ = NNEW(n_LEXICAL_VARIABLE_LIST);
    $$->appendChild(NTYPE($1, n_VARIABLE));
  }
| '&' T_VARIABLE {
    NTYPE($1, n_VARIABLE_REFERENCE);
    $1->appendChild(NTYPE($2, n_VARIABLE));
    $$ = NNEW(n_LEXICAL_VARIABLE_LIST);
    $$->appendChild($1);
  }
;

function_call:
  namespace_name '(' function_call_parameter_list ')' {
    $$ = NNEW(n_FUNCTION_CALL);
    $$->appendChild($1);
    $$->appendChild(NEXPAND($2, $3, $4));
  }
| T_NAMESPACE T_NS_SEPARATOR namespace_name
  '(' function_call_parameter_list ')' {
    NMORE($3, $1);
    $$ = NNEW(n_FUNCTION_CALL);
    $$->appendChild($3);
    $$->appendChild(NEXPAND($4, $5, $6));
  }
| T_NS_SEPARATOR namespace_name '(' function_call_parameter_list ')' {
    NMORE($2, $1);
    $$ = NNEW(n_FUNCTION_CALL);
    $$->appendChild($2);
    $$->appendChild(NEXPAND($3, $4, $5));
  }
| class_name T_PAAMAYIM_NEKUDOTAYIM T_STRING
  '(' function_call_parameter_list ')' {
    $$ = NNEW(n_CLASS_STATIC_ACCESS);
    $$->appendChild($1);
    $$->appendChild(NTYPE($3, n_STRING));

    $$ = NNEW(n_FUNCTION_CALL)->appendChild($$);
    $$->appendChild(NEXPAND($4, $5, $6));
  }
| variable_class_name T_PAAMAYIM_NEKUDOTAYIM T_STRING
  '(' function_call_parameter_list ')' {
    $$ = NNEW(n_CLASS_STATIC_ACCESS);
    $$->appendChild($1);
    $$->appendChild(NTYPE($3, n_STRING));

    $$ = NNEW(n_FUNCTION_CALL)->appendChild($$);
    $$->appendChild(NEXPAND($4, $5, $6));
  }
| variable_class_name T_PAAMAYIM_NEKUDOTAYIM variable_without_objects
  '(' function_call_parameter_list ')' {
    $$ = NNEW(n_CLASS_STATIC_ACCESS);
    $$->appendChild($1);
    $$->appendChild(NTYPE($3, n_STRING));

    $$ = NNEW(n_FUNCTION_CALL)->appendChild($$);
    $$->appendChild(NEXPAND($4, $5, $6));
  }
| class_name T_PAAMAYIM_NEKUDOTAYIM variable_without_objects
  '(' function_call_parameter_list ')' {
    $$ = NNEW(n_CLASS_STATIC_ACCESS);
    $$->appendChild($1);
    $$->appendChild(NTYPE($3, n_STRING));

    $$ = NNEW(n_FUNCTION_CALL)->appendChild($$);
    $$->appendChild(NEXPAND($4, $5, $6));
  }
| variable_without_objects '(' function_call_parameter_list ')' {
    $$ = NNEW(n_FUNCTION_CALL);
    $$->appendChild($1);
    $$->appendChild(NEXPAND($2, $3, $4));
  }
;

class_name:
  T_STATIC {
    $$ = NTYPE($1, n_CLASS_NAME);
  }
| namespace_name {
    $$ = NTYPE($1, n_CLASS_NAME);
  }
| T_NAMESPACE T_NS_SEPARATOR namespace_name {
    NMORE($3, $1);
    $$ = NTYPE($3, n_CLASS_NAME);
  }
| T_NS_SEPARATOR namespace_name {
    NMORE($2, $1);
    $$ = NTYPE($2, n_CLASS_NAME);
  }
;

fully_qualified_class_name:
  namespace_name {
    $$ = NTYPE($1, n_CLASS_NAME);
  }
| T_NAMESPACE T_NS_SEPARATOR namespace_name {
    NMORE($3, $1);
    $$ = NTYPE($3, n_CLASS_NAME);
  }
| T_NS_SEPARATOR namespace_name {
    NMORE($2, $1);
    $$ = NTYPE($2, n_CLASS_NAME);
  }
;

class_name_reference:
  class_name
| dynamic_class_name_reference
;

dynamic_class_name_reference:
  base_variable
  T_OBJECT_OPERATOR
  object_property
  dynamic_class_name_variable_properties {
    $$ = NNEW(n_OBJECT_PROPERTY_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    for (xhpast::node_list_t::iterator ii = $4->children.begin();
      ii != $4->children.end();
      ++ii) {

      $$ = NNEW(n_OBJECT_PROPERTY_ACCESS)->appendChild($$);
      $$->appendChild(*ii);
    }
  }
| base_variable
;

dynamic_class_name_variable_properties:
  dynamic_class_name_variable_properties dynamic_class_name_variable_property {
    $$ = $1->appendChild($2);
  }
| %empty {
    $$ = NNEW(n_EMPTY);
  }
;

dynamic_class_name_variable_property:
  T_OBJECT_OPERATOR object_property {
    $$ = $2;
  }
;

exit_expr:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| '(' ')' {
    NSPAN($1, n_EMPTY, $2);
    $$ = $1;
  }
| '(' expr ')' {
    NSPAN($1, n_PARENTHETICAL_EXPRESSION, $3);
    $1->appendChild($2);
    $$ = $1;
  }
;

ctor_arguments:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| '(' function_call_parameter_list ')' {
    $$ = NEXPAND($1, $2, $3);
  }
;

common_scalar:
  T_LNUMBER {
    $$ = NTYPE($1, n_NUMERIC_SCALAR);
  }
| T_DNUMBER {
    $$ = NTYPE($1, n_NUMERIC_SCALAR);
  }
| T_CONSTANT_ENCAPSED_STRING {
    $$ = NTYPE($1, n_STRING_SCALAR);
  }
| T_LINE {
    $$ = NTYPE($1, n_MAGIC_SCALAR);
  }
| T_FILE {
    $$ = NTYPE($1, n_MAGIC_SCALAR);
  }
| T_DIR {
    $$ = NTYPE($1, n_MAGIC_SCALAR);
  }
| T_CLASS_C {
    $$ = NTYPE($1, n_MAGIC_SCALAR);
  }
| T_METHOD_C {
    $$ = NTYPE($1, n_MAGIC_SCALAR);
  }
| T_TRAIT_C {
    $$ = NTYPE($1, n_MAGIC_SCALAR);
  }
| T_FUNC_C {
    $$ = NTYPE($1, n_MAGIC_SCALAR);
  }
| T_NS_C {
    $$ = NTYPE($1, n_MAGIC_SCALAR);
  }
| T_HEREDOC {
    $$ = NTYPE($1, n_HEREDOC);
  }
;

static_scalar: /* compile-time evaluated scalars */
  common_scalar
| namespace_name
| T_NAMESPACE T_NS_SEPARATOR namespace_name {
    NMORE($3, $1);
    $$ = $3;
  }
| T_NS_SEPARATOR namespace_name {
    NMORE($2, $1);
    $$ = $2;
  }
| '+' static_scalar {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| '-' static_scalar {
    $$ = NNEW(n_UNARY_PREFIX_EXPRESSION);
    $$->appendChild(NTYPE($1, n_OPERATOR));
    $$->appendChild($2);
  }
| T_ARRAY '(' static_array_pair_list ')' {
    NTYPE($1, n_ARRAY_LITERAL);
    $1->appendChild(NEXPAND($2, $3, $4));
    $$ = $1;
  }
| '[' static_array_pair_list ']' {
    NTYPE($1, n_ARRAY_LITERAL);
    $1->appendChild(NEXPAND($1, $2, $3));
    $$ = $1;
  }
| static_class_constant
;

static_class_constant:
  class_name T_PAAMAYIM_NEKUDOTAYIM T_STRING {
    $$ = NNEW(n_CLASS_STATIC_ACCESS);
    $$->appendChild($1);
    $$->appendChild(NTYPE($3, n_STRING));
  }
;

scalar:
  T_STRING_VARNAME
| class_constant
| namespace_name
| T_NAMESPACE T_NS_SEPARATOR namespace_name {
    $$ = NMORE($3, $1);
  }
| T_NS_SEPARATOR namespace_name {
    $$ = NMORE($2, $1);
  }
| common_scalar
;

static_array_pair_list:
  %empty {
    $$ = NNEW(n_ARRAY_VALUE_LIST);
  }
| non_empty_static_array_pair_list possible_comma {
    $$ = NMORE($1, $2);
  }
;

possible_comma:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| ','
;

non_empty_static_array_pair_list:
  non_empty_static_array_pair_list
  ','
  static_scalar
  T_DOUBLE_ARROW
  static_scalar {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild($3);
    $$->appendChild($5);

    $$ = $1->appendChild($$);
  }
| non_empty_static_array_pair_list ',' static_scalar {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild(NNEW(n_EMPTY));
    $$->appendChild($3);

    $$ = $1->appendChild($$);
  }
| static_scalar T_DOUBLE_ARROW static_scalar {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild($1);
    $$->appendChild($3);

    $$ = NNEW(n_ARRAY_VALUE_LIST)->appendChild($$);
  }
| static_scalar {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild(NNEW(n_EMPTY));
    $$->appendChild($1);

    $$ = NNEW(n_ARRAY_VALUE_LIST)->appendChild($$);
  }
;

expr:
  r_variable
| expr_without_variable
;

r_variable:
  variable
;

w_variable:
  variable
;

rw_variable:
  variable
;

variable:
  base_variable_with_function_calls
  T_OBJECT_OPERATOR
  object_property method_or_not
  variable_properties {
    $$ = NNEW(n_OBJECT_PROPERTY_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);

    if ($4->type != n_EMPTY) {
      $$ = NNEW(n_METHOD_CALL)->appendChild($$);
      $$->appendChild($4);
    }

    for (xhpast::node_list_t::iterator ii = $5->children.begin();
      ii != $5->children.end();
      ++ii) {

      if ((*ii)->type == n_CALL_PARAMETER_LIST) {
        $$ = NNEW(n_METHOD_CALL)->appendChild($$);
        $$->appendChild((*ii));
      } else {
        $$ = NNEW(n_OBJECT_PROPERTY_ACCESS)->appendChild($$);
        $$->appendChild((*ii));
      }
    }
  }
| base_variable_with_function_calls
;

variable_properties:
  variable_properties variable_property {
    $$ = $1->appendChildren($2);
  }
| %empty {
    $$ = NNEW(n_EMPTY);
  }
;

variable_property:
  T_OBJECT_OPERATOR object_property method_or_not {
    $$ = NNEW(n_EMPTY);
    $$->appendChild($2);
    if ($3->type != n_EMPTY) {
      $$->appendChild($3);
    }
  }
;

array_method_dereference:
  array_method_dereference '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
| method '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
;

method:
  '(' function_call_parameter_list ')' {
    $$ = NEXPAND($1, $2, $3);
  }
;

method_or_not:
  method
| array_method_dereference
| %empty {
    $$ = NNEW(n_EMPTY);
  }
;

variable_without_objects:
  reference_variable
| simple_indirect_reference reference_variable {
    xhpast::Node *last = $1;
    NMORE($1, $2);
    while (last->firstChild() &&
           last->firstChild()->type == n_VARIABLE_VARIABLE) {
      NMORE(last, $2);
      last = last->firstChild();
    }
    last->appendChild($2);

    $$ = $1;
  }
;

static_member:
  class_name T_PAAMAYIM_NEKUDOTAYIM variable_without_objects {
    $$ = NNEW(n_CLASS_STATIC_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
  }
| variable_class_name T_PAAMAYIM_NEKUDOTAYIM variable_without_objects {
    $$ = NNEW(n_CLASS_STATIC_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
  }
;

variable_class_name:
  reference_variable
;

array_function_dereference:
  array_function_dereference '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
| function_call '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
;

base_variable_with_function_calls:
  base_variable
| array_function_dereference
| function_call
;

base_variable:
  reference_variable
| '(' new_expr ')' {
    $$ = NEXPAND($1, $2, $3);
  }
| simple_indirect_reference reference_variable {
    xhpast::Node *last = $1;
    NMORE($1, $2);
    while (last->firstChild() &&
           last->firstChild()->type == n_VARIABLE_VARIABLE) {
      NMORE(last, $2);
      last = last->firstChild();
    }
    last->appendChild($2);

    $$ = $1;
  }
| static_member
;

reference_variable:
  reference_variable '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
| reference_variable '{' expr '}' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
| compound_variable
;

compound_variable:
  T_VARIABLE {
    NTYPE($1, n_VARIABLE);
  }
| '$' '{' expr '}' {
    NSPAN($1, n_VARIABLE_EXPRESSION, $4);
    $1->appendChild($3);
    $$ = $1;
  }
;

dim_offset:
  %empty {
    $$ = NNEW(n_EMPTY);
  }
| expr {
    $$ = $1;
  }
;

object_property:
  object_dim_list
| variable_without_objects
;

object_dim_list:
  object_dim_list '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
| object_dim_list '{' expr '}' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
| variable_name
;

variable_name:
  T_STRING {
    NTYPE($1, n_STRING);
    $$ = $1;
  }
| '{' expr '}' {
  $$ = NEXPAND($1, $2, $3);
  }
;

simple_indirect_reference:
  '$' {
    $$ = NTYPE($1, n_VARIABLE_VARIABLE);
  }
| simple_indirect_reference '$' {
    $2 = NTYPE($2, n_VARIABLE_VARIABLE);

    xhpast::Node *last = $1;
    while (last->firstChild() &&
           last->firstChild()->type == n_VARIABLE_VARIABLE) {
      last = last->firstChild();
    }
    last->appendChild($2);

    $$ = $1;
  }
;

assignment_list:
  assignment_list ',' assignment_list_element {
    $$ = $1->appendChild($3);
  }
| assignment_list_element {
    $$ = NNEW(n_ASSIGNMENT_LIST);
    $$->appendChild($1);
  }
;

assignment_list_element:
  variable
| T_LIST '(' assignment_list ')' {
    $$ = NNEW(n_LIST);
    $$->appendChild(NEXPAND($2, $3, $4));
  }
| %empty {
    $$ = NNEW(n_EMPTY);
  }
;

array_pair_list:
  %empty {
    $$ = NNEW(n_ARRAY_VALUE_LIST);
  }
| non_empty_array_pair_list possible_comma {
    $$ = NMORE($1, $2);
  }
;

non_empty_array_pair_list:
  non_empty_array_pair_list ',' expr T_DOUBLE_ARROW expr {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild($3);
    $$->appendChild($5);

    $$ = $1->appendChild($$);
  }
| non_empty_array_pair_list ',' expr {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild(NNEW(n_EMPTY));
    $$->appendChild($3);

    $$ = $1->appendChild($$);
  }
| expr T_DOUBLE_ARROW expr {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild($1);
    $$->appendChild($3);

    $$ = NNEW(n_ARRAY_VALUE_LIST)->appendChild($$);
  }
| expr {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild(NNEW(n_EMPTY));
    $$->appendChild($1);

    $$ = NNEW(n_ARRAY_VALUE_LIST)->appendChild($$);
  }
| non_empty_array_pair_list ',' expr T_DOUBLE_ARROW '&' w_variable {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild($3);
    $$->appendChild(NTYPE($5, n_VARIABLE_REFERENCE)->appendChild($6));

    $$ = $1->appendChild($$);
  }
| non_empty_array_pair_list ',' '&' w_variable {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild(NNEW(n_EMPTY));
    $$->appendChild(NTYPE($3, n_VARIABLE_REFERENCE)->appendChild($4));

    $$ = $1->appendChild($$);
  }
| expr T_DOUBLE_ARROW '&' w_variable {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild($1);
    $$->appendChild(NTYPE($3, n_VARIABLE_REFERENCE)->appendChild($4));

    $$ = NNEW(n_ARRAY_VALUE_LIST)->appendChild($$);
  }
| '&' w_variable {
    $$ = NNEW(n_ARRAY_VALUE);
    $$->appendChild(NNEW(n_EMPTY));
    $$->appendChild(NTYPE($1, n_VARIABLE_REFERENCE)->appendChild($2));

    $$ = NNEW(n_ARRAY_VALUE_LIST)->appendChild($$);
  }
;

internal_functions_in_yacc:
  T_ISSET '(' isset_variables ')' {
    NTYPE($1, n_SYMBOL_NAME);

    NSPAN($2, n_CALL_PARAMETER_LIST, $4);
    $2->appendChildren($3);

    $$ = NNEW(n_FUNCTION_CALL);
    $$->appendChild($1);
    $$->appendChild($2);
  }
| T_EMPTY '(' variable ')' {
    NTYPE($1, n_SYMBOL_NAME);

    NSPAN($2, n_CALL_PARAMETER_LIST, $4);
    $2->appendChild($3);

    $$ = NNEW(n_FUNCTION_CALL);
    $$->appendChild($1);
    $$->appendChild($2);
  }
| T_INCLUDE expr {
    $$ = NTYPE($1, n_INCLUDE_FILE)->appendChild($2);
  }
| T_INCLUDE_ONCE expr {
    $$ = NTYPE($1, n_INCLUDE_FILE)->appendChild($2);
  }
| T_EVAL '(' expr ')' {
    NTYPE($1, n_SYMBOL_NAME);

    NSPAN($2, n_CALL_PARAMETER_LIST, $4);
    $2->appendChild($3);

    $$ = NNEW(n_FUNCTION_CALL);
    $$->appendChild($1);
    $$->appendChild($2);
  }
| T_REQUIRE expr {
    $$ = NTYPE($1, n_INCLUDE_FILE)->appendChild($2);
  }
| T_REQUIRE_ONCE expr {
    $$ = NTYPE($1, n_INCLUDE_FILE)->appendChild($2);
  }
;

isset_variables:
  variable {
    $$ = NNEW(n_EMPTY);
    $$->appendChild($1);
  }
| isset_variables ',' variable {
    $$ = $1->appendChild($3);
  }
;

parenthesis_expr:
  '(' expr ')' {
    NSPAN($1, n_PARENTHETICAL_EXPRESSION, $3);
    $1->appendChild($2);
    $$ = $1;
  }
| '(' yield_expr ')' {
    $$ = NEXPAND($1, $2, $3);
  }
;

combined_scalar_offset:
  combined_scalar '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
| combined_scalar_offset '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
| T_CONSTANT_ENCAPSED_STRING '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild(NTYPE($1, n_STRING_SCALAR));
    $$->appendChild($3);
    NMORE($$, $4);
  }
| class_constant '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild($1);
    $$->appendChild($3);
    NMORE($$, $4);
  }
| T_STRING '[' dim_offset ']' {
    $$ = NNEW(n_INDEX_ACCESS);
    $$->appendChild(NTYPE($1, n_STRING));
    $$->appendChild($3);
    NMORE($$, $4);
  }
;

combined_scalar:
  T_ARRAY '(' array_pair_list ')' {
    NTYPE($1, n_ARRAY_LITERAL);
    $1->appendChild(NEXPAND($2, $3, $4));
    $$ = $1;
  }
| '[' array_pair_list ']' {
    NTYPE($1, n_ARRAY_LITERAL);
    $1->appendChild(NEXPAND($1, $2, $3));
    $$ = $1;
  }
;

new_expr:
  T_NEW class_name_reference ctor_arguments {
    NTYPE($1, n_NEW);
    $1->appendChild($2);
    $1->appendChild($3);
    $$ = $1;
  }
| T_NEW T_CLASS ctor_arguments extends_from implements_list
  '{' class_statement_list '}' {
    $$ = NNEW(n_CLASS_DECLARATION);
    $$->appendChild($2);
    $$->appendChild(NNEW(n_EMPTY));
    $$->appendChild($4);
    $$->appendChild($5);
    $$->appendChild(NEXPAND($6, $7, $8));
    NMORE($$, $8);

    NTYPE($1, n_NEW);
    $1->appendChild($$);
    $1->appendChild($3);
    $$ = $1;
  }
;

class_constant:
  class_name T_PAAMAYIM_NEKUDOTAYIM T_STRING {
    $$ = NNEW(n_CLASS_STATIC_ACCESS);
    $$->appendChild($1);
    $$->appendChild(NTYPE($3, n_STRING));
  }
| variable_class_name T_PAAMAYIM_NEKUDOTAYIM T_STRING {
    $$ = NNEW(n_CLASS_STATIC_ACCESS);
    $$->appendChild($1);
    $$->appendChild(NTYPE($3, n_STRING));
  }
;

%%

const char* yytokname(int tok) {
  if (tok < 255) {
    return NULL;
  }
  return yytname[YYTRANSLATE(tok)];
}
