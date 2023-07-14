#include "shape/point_test.h"
#include "shape/line_test.h"
#include "shape/rectangle_test.h"
#include "shape/ellipse_test.h"
#include "language/execute_test.h"

int main(void) {
  // Shape Test Start
  if(point_test())
    printf("[POINT_TEST]: PASSED\n");
  else
    printf("[POINT_TEST]: FAILED\n");
  if(line_test())
    printf("[LINE_TEST]: PASSED\n");
  else
    printf("[LINE_TEST]: FAILED\n");
  if(rectangle_test())
    printf("[RECTANGLE_TEST]: PASSED\n");
  else
    printf("[RECTANGLE_TEST]: FAILED\n");
  if(ellipse_test())
    printf("[ELLIPSE_TEST]: PASSED\n");
  else
    printf("[ELLIPSE_TEST]: FAILED\n");
  // Shape Test End


  symbol_table st = init_symbol_table();
  yyin = fopen("../example_progs/execution_test_one.ncl", "r");
  if(!yyin) {
    printf("unable to open input file\n");
    exit(1);
  }
  yyparse();
  execute(head, st);
  // print_graph(head, "test.dot");
  free_symbol_table(st);
  free_ast(head);
  fclose(yyin);
  yylex_destroy();

  // Language Test Start
  // if(execute_expression_test())
  //   printf("[EXECUTE_TEST]: PASSED\n");
  // else
  //   printf("[EXECUTE_TEST]: FAILED\n");
  // Language Test End

  return 0;
}
