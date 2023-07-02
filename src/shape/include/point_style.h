#ifndef POINT_STYLE_H
#define POINT_STYLE_H

#include <stdlib.h>

typedef enum {
  CIRCLE,
  STAR
} point_style;

const char * point_style_to_string(point_style ps);

#endif
