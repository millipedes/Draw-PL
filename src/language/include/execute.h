#ifndef EXECUTE_H
#define EXECUTE_H

#include "symbol_table.h"

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

typedef struct RESULT_T {
  symbol result;
  ncl_type result_type;
} result;

// void execute(ast head);
result execute_expression(ast head, result the_result);

#endif
