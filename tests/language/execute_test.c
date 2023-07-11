#include "execute_test.h"

int execute_expression_test(void) {
  // const char * input = "1.1 + 2.1 + 4.1\n";
  // int buffer_value = yy_scan_string(input);
  // yyparse();
  ast head = init_ast(NULL, IN_EXPRESSION);
  head = add_child(head, init_ast(init_token(DOUBLE, "1.1", 0), DOUBLE));
  head = add_child(head, init_ast(init_token(MINUS, "-", 0), MINUS));
  head = add_child(head, init_ast(NULL, IN_EXPRESSION));
  head->children[2] = add_child(head->children[2], init_ast(init_token(DOUBLE, "2.1", 0), DOUBLE));
  head->children[2] = add_child(head->children[2], init_ast(init_token(SLASH, "/", 0), SLASH));
  head->children[2] = add_child(head->children[2], init_ast(init_token(DOUBLE, "3.1", 0), DOUBLE));
  result the_result = execute_expression(head, (result){0});
  printf("[%s]: %f\n", ncl_type_to_string(the_result.result_type), the_result.result.the_double);
  free_ast(head);
  // yy_delete_buffer(buffer_value);
  // yylex_destroy();
  return 1;
}
