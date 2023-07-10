#ifndef EXE_TEST_H
#define EXE_TEST_H

#include "language/include/symbol_table.h"

extern int yy_scan_string(const char * yy_str);
extern void yy_delete_buffer(int b);
extern int yylex_destroy();

int execute_expression_test(void);

#endif
