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
      list_size = 0;
      pushStack();
    }

    size_t first_lineno; // line number before scanning the current token
    size_t lineno; // current line number being scanned.
    std::string error; // description of error (if terminated true)
    bool terminated; // becomes true when the parser terminates with an error
    int last_token; // the last token to be returned by the scanner
    int insert_token; // insert this token without reading from buffer
    size_t heredoc_yyleng; // last length of yytext while scanning
    std::string heredoc_label; // heredoc sentinel label
    unsigned int list_size;

    xhpast::token_list_t token_list;

    void pushStack() {
      tag_stack.push_front(std::deque<std::string>());
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
