#ifndef AST_H
#define AST_H

#include "token.h"

typedef struct AST_T {
  struct AST_T ** children;
  token leaf;
  int category;
  int no_children;
} * ast;

ast init_ast(token the_token, int category);
void free_ast(ast head);

#endif
