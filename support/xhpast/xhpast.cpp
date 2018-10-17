#include "ast.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int xhpastparse(void*, xhpast::Node **);

int xhpast_process(std::string &in);
void print_node(xhpast::Node *node);

int main(int argc, char* argv[]) {
  if (argc != 1) {
    // Coupling: modify also src/parser/xhpast/bin/PhutilXHPASTBinary.php
    cout << "7.1.3\n";
    return 0;
  }

  ifstream inputFile;
  istream *inputStream;
  inputStream = &cin;

  std::stringbuf sb;
  *inputStream >> noskipws >> &sb;
  std::string buffer = sb.str();
  inputFile.close();

  return xhpast_process(buffer);
}

int xhpast_process(std::string &in) {

  char *buffer;
  in.reserve(in.size() + 1);
  buffer = const_cast<char*>(in.c_str());
  buffer[in.size() + 1] = 0; // need double NULL for scan_buffer

  void* scanner;
  yy_extra_type extra;
  extra.insert_token = 0;//flags.eval ? T_OPEN_TAG_FAKE : 0;

  xhpast::Node *root = NULL;

  xhpastlex_init(&scanner);
  xhpastset_extra(&extra, scanner);
  xhpast_scan_buffer(buffer, in.size() + 2, scanner);
  xhpastparse(scanner, &root);
  xhpastlex_destroy(scanner);

  if (extra.terminated) {
    fprintf(
      stderr,
      "XHPAST Parse Error: %s on line %d\n",
      extra.error.c_str(),
      (int)extra.lineno);
    return 1;
  }

  printf("{");
  printf("\"tree\":");
  if (root) {
    // Extend the right token for the root node to the end of the concrete
    // token stream. This ensure all tokens appear in the tree. If we don't
    // do this and the file ends in tokens which don't go to the parser (like
    // comments and whitespace) they won't be represented in the tree.
    root->r_tok = (extra.token_list.size() - 1);
    print_node(root);
  } else {
    printf("null");
  }
  printf(",");
  printf("\"stream\":");
  printf("[");

  if (!extra.token_list.empty()) {
    for (xhpast::token_list_t::iterator ii = extra.token_list.begin();;) {
      printf("[%d, %d]", (*ii)->type, (int)(*ii)->value.length());
      if (++ii != extra.token_list.end()) {
        printf(",");
      } else {
        break;
      }
    }
  }
  printf("]");
  printf("}\n");

  return 0;
}

void print_node(xhpast::Node *node) {
  int l = -1;
  if (node->l_tok != -1) {
    l = node->l_tok;
  }

  if (l == -1) {
    printf("[%u]", node->type);
  } else {
    int r = -1;

    if (node->r_tok != -1) {
      r = node->r_tok;
    }

    printf("[%u, %d, %d", node->type, l, r);
    if (!node->children.empty()) {
      printf(", [");
      for (xhpast::node_list_t::iterator ii = node->children.begin();;) {
        print_node(*ii);
        if (++ii != node->children.end()) {
          printf(",");
        } else {
          break;
        }
      }
      printf("]");
    }
    printf("]");
  }
}
