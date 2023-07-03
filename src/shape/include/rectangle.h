#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "line.h"

typedef struct RECTANGLE_t {
  point center;
  pixel color;
  int height;
  int width;
  int thickness;
} rectangle;

canvas bresenham_rectangle_draw(canvas the_canvas, rectangle the_rect);
void debug_rectangle(int height, int width, point center);

#endif
