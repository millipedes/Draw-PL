/**
 * @file   line.h.
 * @brief  This file contains the function definitions for line.c.
 * @author Matthew C. Lindeman
 * @date   July 23, 2023
 * @bug    None known
 * @todo   Write the dotten line style implementation.
 */
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
