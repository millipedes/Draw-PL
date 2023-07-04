/**
 * @file   ellipse.h
 * @brief  This file contains the function definitions related to an ellipse.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
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
canvas draw_ellipse_points(canvas the_canvas, ellipse the_ellipse, int center_x,
    int center_y, int x, int y);
void debug_ellipse(ellipse the_ellipse);

#endif
