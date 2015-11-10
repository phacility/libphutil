#pragma once
#include <cstdio>
#include <cstdlib>
#include <list>
#include <string>

namespace xhpast {

  class Token;
  typedef std::list<Token *> token_list_t;

  class Token {

    public:
      unsigned int type;
      std::string value;
      unsigned int lineno;
      unsigned int n;

      Token(unsigned int type, char *value, unsigned int n) :
        type(type),
        value(value),
        lineno(0),
        n(n) {
      }
  };

  class Node;
  typedef std::list<Node *> node_list_t;

  class Node {
    public:
      unsigned int type;

      int l_tok;
      int r_tok;

      node_list_t children;


      Node() : type(0), l_tok(-1), r_tok(-1) {};

      Node(unsigned int type) : type(type), l_tok(-1), r_tok(-1) {};

      Node(unsigned int type, int end_tok) :
        type(type) {
          this->l_tok = end_tok;
          this->r_tok = end_tok;
      }

      Node(unsigned int type, int l_tok, int r_tok) :
        type(type),
        l_tok(l_tok),
        r_tok(r_tok) {

      }

      Node *appendChild(Node *node) {
        this->children.push_back(node);
        return this->expandRange(node);
      }

      Node *appendChildren(Node *node) {
        for (node_list_t::iterator ii = node->children.begin();
          ii != node->children.end();
          ++ii) {

          this->appendChild(*ii);
        }
        return this;
      }

      Node *firstChild() {
        if (this->children.empty()) {
          return NULL;
        }
        return *(this->children.begin());
      }

      Node *setType(unsigned int t) {
        this->type = t;
        return this;
      }

      Node *expandRange(Node *n) {
        if (!n) {
          fprintf(
            stderr,
            "Trying to expandRange() a null node to one of type %d\n",
            this->type);
          exit(1);
        };

        if (n->l_tok != -1 && (n->l_tok < this->l_tok || (this->l_tok == -1))) {
          this->l_tok = n->l_tok;
        }

        if (n->r_tok != -1 && (n->r_tok > this->r_tok || (this->r_tok == -1))) {
          this->r_tok = n->r_tok;
        }

        return this;
      }

  };
}
