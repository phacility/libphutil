#pragma once

#include <stack>
#include <string>

#include "astnode.hpp"

class yy_extra_type {
  public:
    yy_extra_type() {
      first_lineno = 0;
      lineno = 1;
      terminated = false;
      last_token = -1;
      insert_token = -1;
      heredoc_yyleng = -1;
      short_tags = true;
      asp_tags = false;
      idx_expr = false;
      list_size = 0;
      pushStack();
    }

    bool short_tags; // `short_open_tag` in php.ini
    bool asp_tags; // `asp_tags` in php.ini
    bool idx_expr; // allow code like `foo()['bar']`
    size_t first_lineno; // line number before scanning the current token
    size_t lineno; // current line number being scanned.
    std::string error; // description of error (if terminated true)
    bool terminated; // becomes true when the parser terminates with an error
    int last_token; // the last token to be returned by the scanner
    int insert_token; // insert this token without reading from buffer
    size_t heredoc_yyleng; // last length of yytext while scanning
    std::string heredoc_label; // heredoc sentinel label
    std::stack<int> curly_stack; // tokens appearing before a {
    unsigned int list_size;

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
