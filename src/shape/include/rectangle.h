/**
 * @file   rectangle.h
 * @brief  This file contains the function definitions for rectangle.c.
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Make rectangle use draw_line instead of bresenham_line_draw when
 * styles are more concrete.
 */
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

canvas draw_rectangle(canvas the_canvas, rectangle the_rect);
void debug_rectangle(rectangle the_rect);

#endif
