#ifndef SYM_TAB_H
#define SYM_TAB_H

#include <string.h>

#include "ast.h"
#include "type.h"
#include "shape/include/ellipse.h"
#include "shape/include/rectangle.h"
#include "canvas/include/canvas.h"
#include "parser.tab.h"

#define MAX_NAME 256

typedef union {
  char * the_string;
  int the_bool;
  double the_double;
  int the_integer;
  // void * array;
  rectangle the_rect;
  pixel the_color;
  point the_point;
  line the_line;
  ellipse the_ellipse;
  canvas_params the_canvas;
} symbol;

typedef struct SYMBOL_TABLE_T {
  char ** member_names;
  symbol * members;
  ncl_type * member_types;
  int qty_members;
} * symbol_table;

typedef struct RESULT_T {
  symbol result;
  ncl_type result_type;
} result;

symbol_table init_symbol_table(void);
symbol_table add_member(symbol_table st, symbol new_symbol, char * literal,
    ncl_type the_type);
result find_symbol(symbol_table st, char * name);
void debug_symbol_table(symbol_table st);
void free_symbol_table(symbol_table st);

#endif
