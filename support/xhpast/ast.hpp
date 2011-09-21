/*
 * Copyright 2011 Facebook, Inc.
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

#pragma once

#include <stdint.h>
#include <deque>
#include <stack>
#include <string>

#include "astnode.hpp"

class yy_extra_type {
  public:
    yy_extra_type() {
      lineno = 1;
      terminated = false;
      used = false;
      short_tags = true;
      asp_tags = false;
      idx_expr = false;
      include_debug = false;
      expecting_xhp_class_statements = false;
      list_size = 0;
      colon_hack = false;
      pushStack();
    }

    bool short_tags; // `short_open_tag` in php.ini
    bool asp_tags; // `asp_tags` in php.ini
    bool idx_expr; // allow code like `foo()['bar']`
    bool include_debug; // include line numbers and file names in XHP object creation
    size_t first_lineno; // line number before scanning the current token
    size_t lineno; // current line number being scanned.
    std::string error; // description of error (if terminated true)
    bool terminated; // becomes true when the parser terminates with an error
    bool used; // were any XHP-specific extensions found in this code?
    int last_token; // the last token to be returned by the scanner
    int insert_token; // insert this token without reading from buffer
    size_t heredoc_yyleng; // last length of yytext while scannling
    const char* heredoc_data; // where our heredoc data starts
    std::string heredoc_label; // heredoc sentinel label
    std::stack<int> curly_stack; // tokens appearing before a {
    bool expecting_xhp_class_statements; // when we're one level deep in a class
    bool old_expecting_xhp_class_statements; // store old value while inside class method
    bool used_attributes; // did this class use the `attribute` keyword
    unsigned int list_size;
    bool colon_hack;

    xhpast::token_list_t token_list;

    /* Utility functions for checking proper tag closing */
    bool haveTag() {
      return !tag_stack.front().empty();
    }
    const std::string &peekTag() {
      return tag_stack.front().front();
    }
    void pushTag(const std::string &tag) {
      tag_stack.front().push_front(tag);
    }
    void popTag() {
      tag_stack.front().pop_front();
    }
    void pushStack() {
      tag_stack.push_front(std::deque<std::string>());
    }
    void popStack() {
      tag_stack.pop_front();
    }

  protected:
    std::deque<std::deque<std::string> > tag_stack;
};

#define YYSTYPE xhpast::Node *
#define YY_HEADER_EXPORT_START_CONDITIONS
#define YY_EXTRA_TYPE yy_extra_type*

#include "parser.yacc.hpp"
#ifndef FLEX_SCANNER
  #include "scanner.lex.hpp"
#endif

int xhpparse(void*, YYSTYPE *);
void xhp_new_push_state(int s, struct yyguts_t* yyg);
void xhp_new_pop_state(struct yyguts_t* yyg);
void xhp_set_state(int s, struct yyguts_t* yyg);
