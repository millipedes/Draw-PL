#include "shape/point_test.h"
#include "shape/line_test.h"
#include "shape/rectangle_test.h"
#include "shape/ellipse_test.h"
#include "language/include/token.h"
#include "parser.tab.h"

extern FILE * yyin;
extern int yylex_destroy();
extern ast head;

int main(void) {
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
  yyin = fopen("../example_progs/example_one.dpl", "r");
  yyparse();
  debug_ast(head, 0);
  free_ast(head);

  fclose(yyin);
  yylex_destroy();
  return 0;
}
