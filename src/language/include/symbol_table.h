#ifndef SYM_TAB_H
#define SYM_TAB_H

#include "ast.h"
#include "type.h"
#include "shape/include/ellipse.h"
#include "shape/include/rectangle.h"
#include "canvas/include/canvas.h"

typedef union {
  char * the_string;
  int the_bool;
  double the_double;
  int the_int;
  rectangle the_rect;
  pixel the_color;
  point the_point;
  ellipse the_ellipse;
  canvas the_canvas;
} symbol;

typedef struct SYMBOL_TABLE_T {
  char ** member_names;
  symbol * members;
  ncl_type * member_types;
  int qty_members;
} * symbol_table;

symbol_table init_symbol_table(void);
symbol_table populate_symbol_table(ast head, symbol_table st);
symbol_table add_member(symbol_table st, symbol new_symbol);
void free_symbol_table(symbol_table st);

#endif
