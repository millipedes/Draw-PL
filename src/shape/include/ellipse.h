#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "point.h"

typedef struct ELLIPSE_T {
  point center;
  pixel color;
  int major_axis;
  int minor_axis;
  int thickness;
} ellipse;

canvas draw_ellipse(canvas the_canvas, ellipse the_ellipse);
void draw_ellipse_points(canvas the_canvas, ellipse the_ellipse, int center_x,
    int center_y, int x, int y);

#endif
