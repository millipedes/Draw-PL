#ifndef LINE_H
#define LINE_H

#include "point.h"
#include "line_style.h"

typedef struct LINE_T {
  point to;
  point from;
  line_style style;
  pixel color;
  int thickness;
} line;

void debug_line(line the_line);
canvas write_line_to_canvas(canvas the_canvas, line the_line);
canvas bresenham_line_draw(canvas the_canvas, line the_line);

#endif
