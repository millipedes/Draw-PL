#ifndef TYPE_H
#define TYPE_H

#include <stdlib.h>

typedef enum {
  NCL_STRING,
  NCL_BOOL,
  NCL_DOUBLE,
  NCL_INTEGER,
  NCL_RECTANGLE,
  NCL_COLOR,
  NCL_POINT,
  NCL_LINE,
  NCL_ELLIPSE,
  NCL_CANVAS,
  NCL_LOOKUP,
} ncl_type;

const char * ncl_type_to_string(ncl_type the_ncl_type);

#endif
