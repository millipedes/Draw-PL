#include "include/internal_node_type.h"

const char * internal_node_type_to_string(internal_node_type int_node_type) {
  switch(int_node_type) {
    case IN_CANVAS_DECLARATION:     return "canvas decl";
    case IN_COLOR_DECLARATION:      return "color decl";
    case IN_STAR_NEWLINE_STMT:      return "star newline stmt";
    case IN_STATEMENT:              return "statement";
    case IN_SHAPE_ASSIGNMENT:       return "shape decl";
    case IN_RECTANGLE_DECLARATION:  return "rectangle decl";
    case IN_SHAPE:                  return "shape";
    case IN_POINT_DECLARATION:      return "point declaration";
    case IN_PICK_NEWLINE_STMT:      return "pick newline stmt";
    case IN_ELLIPSE_DECLARATION:    return "ellipse decl";
    case IN_TO_DECLARATION:         return "to decl";
    case IN_FROM_DECLARATION:       return "from decl";
    case IN_LINE_DECLARATION:       return "line decl";
    case IN_FOR_LOOP:               return "for loop";
    case IN_EXPRESSION:             return "expression";
    case IN_EXPRESSION_ASSIGNMENT:  return "expression assignment";
    case IN_IF_STMT:                return "if stmt";
    case IN_EXPRESSION_LIST:        return "expression list";
    case IN_HEIGHT_DECLARATION:     return "height decl";
    case IN_WIDTH_DECLARATION:      return "width decl";
    case IN_RECTANGLE_PARAMETERS:   return "rectangle params";
    case IN_ELLIPSE_PARAMETERS:     return "ellipse params";
    case IN_MAJOR_AXIS_DECLARATION: return "major axis decl";
    case IN_MINOR_AXIS_DECLARATION: return "minor axis decl";
    case IN_THICKNESS_DECLARATION:  return "thickness decl";
    case IN_CANVAS_PARAMETERS:      return "canvas params";
  }
  return NULL;
}
