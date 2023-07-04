#include "include/type.h"

const char * ncl_type_to_string(ncl_type the_ncl_type) {
  switch(the_ncl_type) {
    case STRING:    return "string";
    case BOOL:      return "bool";
    case DOUBLE:    return "double";
    case INT:       return "int";
    case RECTANGLE: return "rectangle";
    case COLOR:     return "color";
    case POINT:     return "point";
    case ELLIPSE:   return "ellipse";
    case CANVAS:    return "canvas";
  }
  return NULL;
}
