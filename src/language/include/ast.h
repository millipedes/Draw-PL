#ifndef AST_H
#define AST_H

#include "token.h"
#include "internal_node_type.h"

#define PRINT_C_N(c, n) for(int zyx = 0;  zyx < n; zyx++) printf("%c", c);

extern int tree_id;
extern int yylineno;

typedef struct AST_T {
  struct AST_T ** children;
  token leaf;
  internal_node_type category;
  int no_children;
  int tree_id;
  int line_no;
} * ast;

ast init_ast(token the_token, int category);
void debug_ast(ast head, int level);
ast add_child(ast parent, ast child);
void free_ast(ast head);

#endif
