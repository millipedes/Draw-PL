#ifndef INT_NODE_TYPE_H
#define INT_NODE_TYPE_H

#include <stdlib.h>

typedef enum {
  IN_CANVAS_DECLARATION,
  IN_COLOR_DECLARATION,
  IN_STAR_NEWLINE_STMT,
  IN_STATEMENT,
  IN_SHAPE_DECLARATION,
  IN_RECTANGLE_DECLARATION,
  IN_SHAPE,
  IN_POINT_DECLARATION,
  IN_PICK_NEWLINE_STMT,
  IN_ELLIPSE_DECLARATION,
  IN_TO_DECLARATION,
  IN_FROM_DECLARATION,
  IN_LINE_DECLARATION,
  IN_FOR_LOOP,
} internal_node_type;

const char * internal_node_type_to_string(internal_node_type int_node_type);

#endif
