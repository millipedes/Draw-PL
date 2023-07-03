/**
 * @file   point.h
 * @brief  This file contains the function definitions for point.c.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef POINT_H
#define POINT_H

#include <math.h>

#include "canvas/include/canvas.h"
#include "point_style.h"

typedef struct POINT_T {
  double x;
  double y;
  point_style style;
  pixel color;
  int radius;
} point;

void debug_point(point the_point);
canvas write_point_to_canvas(canvas the_canvas, point the_point);
canvas scaline_circle_algorithm(canvas the_canvas, point the_point);

#endif
