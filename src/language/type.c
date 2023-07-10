#include "include/type.h"

const char * ncl_type_to_string(ncl_type the_ncl_type) {
  switch(the_ncl_type) {
    case NCL_STRING:    return "string";
    case NCL_BOOL:      return "bool";
    case NCL_DOUBLE:    return "double";
    case NCL_INTEGER:   return "int";
    case NCL_RECTANGLE: return "rectangle";
    case NCL_COLOR:     return "color";
    case NCL_POINT:     return "point";
    case NCL_LINE:      return "line";
    case NCL_ELLIPSE:   return "ellipse";
    case NCL_CANVAS:    return "canvas";
    case NCL_LOOKUP:    return "lookup";
  }
  return NULL;
}
