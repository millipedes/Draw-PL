#ifndef POINT_H
#define POINT_H

#include "canvas/include/canvas.h"
#include "point_style.h"

typedef struct POINT_T {
  double x;
  double y;
  point_style style;
} point;

void debug_point(point the_point);
void write_to_canvas(canvas the_canvas, point the_point);

#endif
