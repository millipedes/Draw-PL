#ifndef TYPE_H
#define TYPE_H

#include <stdlib.h>

typedef enum {
  STRING,
  BOOL,
  DOUBLE,
  INT,
  RECTANGLE,
  COLOR,
  POINT,
  ELLIPSE,
  CANVAS,
} ncl_type;

const char * ncl_type_to_string(ncl_type the_ncl_type);

#endif
