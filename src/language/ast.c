#include "include/ast.h"

ast init_ast(token the_token, int category) {
  ast the_ast = calloc(1, sizeof(struct AST_T));
  the_ast->children = NULL;
  the_ast->leaf = the_token;
  the_ast->category = category;
  the_ast->no_children = 0;
  return the_ast;
}

void free_ast(ast head) {
  if(head) {
    if(head->children) {
      for(int i = 0; i < head->no_children; i++) {
        free_ast(head->children[i]);
      }
    }
    if(head->leaf)
      free_token(head->leaf);
    free(head);
  }
}
