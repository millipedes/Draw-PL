#ifndef EXECUTE_H
#define EXECUTE_H

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

#define IS_LEFT_UPCAST(l, r) (l.result_type == NCL_INTEGER \
                              && r.result_type == NCL_DOUBLE)
#define IS_RIGHT_UPCAST(l, r) (l.result_type == NCL_DOUBLE \
                               && r.result_type == NCL_INTEGER)

extern FILE * yyin;
extern int yylex_destroy();
extern ast head;

void execute(ast head, symbol_table st);
result execute_canvas_declaration(ast head, result value, symbol_table st);
result execute_rectangle_declaration(ast head, result value, symbol_table st);
result execute_ellipse_declaration(ast head, result value, symbol_table st);
result execute_color_declaration(ast head, result value, symbol_table st);
result execute_point_declaration(ast head, result value, symbol_table st);
result execute_line_declaration(ast head, result value, symbol_table st);
result execute_expression(ast head, result the_result, symbol_table st);

#endif
