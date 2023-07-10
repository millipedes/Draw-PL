#include "execute_test.h"

int execute_expression_test(void) {
  const char * input = "1 + 2 * 3 - - 4";
  int buffer_value = yy_scan_string(input);
  yy_delete_buffer(buffer_value);
  yylex_destroy();
  return 1;
}
