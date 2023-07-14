#ifndef EXECUTE_H
#define EXECUTE_H

#include "language/include/token.h"
#include "parser.tab.h"
#include "language/include/dot_gen.h"
#include "language/include/symbol_table.h"

// typedef union {
//   char * the_string;
//   int the_bool;
//   double the_double;
//   int the_int;
//   void * array;
//   rectangle the_rect;
//   pixel the_color;
//   point the_point;
//   line the_line;
//   ellipse the_ellipse;
//   canvas the_canvas;
// } symbol;

extern FILE * yyin;
extern int yylex_destroy();
extern ast head;

typedef struct RESULT_T {
  symbol result;
  ncl_type result_type;
} result;

void execute(ast head, symbol_table st);
result execute_canvas_declaration(ast head, result value);
result execute_rectangle_declaration(ast head, result value);
result execute_ellipse_declaration(ast head, result value);
result execute_color_declaration(ast head, result value);
result execute_point_declaration(ast head, result value);
result execute_line_declaration(ast head, result value);
result execute_expression(ast head, result the_result);

#endif
