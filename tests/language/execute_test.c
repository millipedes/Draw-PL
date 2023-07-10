#include "execute_test.h"

int execute_expression_test(void) {
  const char * input = "1 + 2 * 3 - - 4";
  yy_scan_string(input);
  yy_delete_buffer();
  yylex_destroy();
  return 1;
}
