#include "include/ast.h"

ast init_ast(token the_token, int category) {
  ast the_ast = calloc(1, sizeof(struct AST_T));
  the_ast->children = NULL;
  the_ast->leaf = the_token;
  the_ast->category = category;
  the_ast->no_children = 0;
  the_ast->tree_id = tree_id;
  the_ast->line_no = yylineno;
  tree_id++;
  return the_ast;
}

void debug_ast(ast head, int level) {
  PRINT_C_N(' ', level)
  if(head->leaf) {
    printf("[AST] %s ", category_to_string(head->category));
    printf("%s\n", head->leaf->literal);
  } else {
    printf("[AST] %s\n", internal_node_type_to_string(head->category));
  }
  if(head->children) {
    for(int i = 0; i < head->no_children; i++) {
      debug_ast(head->children[i], level + 1);
    }
  }
}

ast add_child(ast parent, ast child) {
  parent->no_children++;
  if(parent->children) {
    parent->children = realloc(parent->children, parent->no_children
        * sizeof(struct AST_T *));
  } else {
    parent->children = calloc(1, sizeof(struct AST_T *));
  }
  parent->children[parent->no_children - 1] = child;
  return parent;
}

void free_ast(ast head) {
  if(head) {
    if(head->children) {
      for(int i = 0; i < head->no_children; i++) {
        free_ast(head->children[i]);
      }
      free(head->children);
    }
    if(head->leaf) {
      free_token(head->leaf);
    }
    free(head);
  }
}
