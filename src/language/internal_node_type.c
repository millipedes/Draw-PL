#include "include/internal_node_type.h"

const char * internal_node_type_to_string(internal_node_type int_node_type) {
  switch(int_node_type) {
    case IN_CANVAS_DECLARATION:    return "canvas decl";
    case IN_COLOR_DECLARATION:     return "color decl";
    case IN_STAR_NEWLINE_STMT:     return "star newline stmt";
    case IN_STATEMENT:             return "statement";
    case IN_SHAPE_DECLARATION:     return "shape decl";
    case IN_RECTANGLE_DECLARATION: return "rectangle decl";
    case IN_SHAPE:                 return "shape";
    case IN_POINT_DECLARATION:     return "point declaration";
    case IN_PICK_NEWLINE_STMT:     return "pick newline stmt";
    case IN_ELLIPSE_DECLARATION:   return "ellipse decl";
    case IN_TO_DECLARATION:        return "to decl";
    case IN_FROM_DECLARATION:      return "from decl";
    case IN_LINE_DECLARATION:      return "line decl";
    case IN_FOR_LOOP:              return "for loop";
  }
  return NULL;
}
