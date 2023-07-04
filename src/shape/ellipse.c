/**
 * @file   ellipse.c
 * @brief  This file contains the functions related to drawing an ellipse.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/ellipse.h"

/**
 * This function draws an ellipse.
 * @param  the_canvas - The canvas which the ellipse will be drawn to.
 * @param the_ellipse - The ellipse which will be written to the canvas.
 * @return the_canvas - The canvas with the ellipse written to it.
 */
canvas draw_ellipse(canvas the_canvas, ellipse the_ellipse) {
  int center_x = the_ellipse.center.x;
  int center_y = the_ellipse.center.y;
  int radius_x = the_ellipse.major_axis / 2;
  int radius_y = the_ellipse.minor_axis / 2;
  
  int x = 0;
  int y = radius_y;
  int rx2 = radius_x * radius_x;
  int ry2 = radius_y * radius_y;
  int two_rx2 = 2 * rx2;
  int two_ry2 = 2 * ry2;
  int p = 0;

  // Region 1
  int dx = 0;
  int dy = two_rx2 * y;

  the_canvas = draw_ellipse_points(the_canvas, the_ellipse, center_x, center_y,
      x, y);

  // Region 1
  p = ry2 - (rx2 * radius_y) + (0.25 * rx2);

  while(dx < dy) {
    x++;
    dx += two_ry2;
    if (p < 0) {
      p += ry2 + dx;
    } else {
      y--;
      dy -= two_rx2;
      p += ry2 + dx - dy;
    }
    the_canvas = draw_ellipse_points(the_canvas, the_ellipse, center_x,
        center_y, x, y);
  }

  // Region 2
  p = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;

  while(y > 0) {
    y--;
    dy -= two_rx2;
    if (p > 0) {
      p += rx2 - dy;
    } else {
      x++;
      dx += two_ry2;
      p += rx2 - dy + dx;
    }
    the_canvas = draw_ellipse_points(the_canvas, the_ellipse, center_x,
        center_y, x, y);
  }

  return the_canvas;
}

/**
 * This function is a helper function to draw_ellipse.
 * @param  the_canvas - The canvas which the point will be written to.
 * @param the_ellipse - The ellipse whoe points are being written to the canvas.
 * @param    center_x - The center x point.
 * @param    center_y - The center y point.
 * @param           x - The x value of the point.
 * @param           y - The y value of the point.
 * @return the_canvas - The canvas which will have the points written to it.
 */
canvas draw_ellipse_points(canvas the_canvas, ellipse the_ellipse, int center_x,
    int center_y, int x, int y) {
  for(int i = -the_ellipse.thickness/2; i <= the_ellipse.thickness/2; i++) {
    for(int j = -the_ellipse.thickness/2; j <= the_ellipse.thickness/2; j++) {
      the_canvas->values[center_y + y + i][center_x + x + j]
        = the_ellipse.color;
      the_canvas->values[center_y + y + i][center_x - x + j]
        = the_ellipse.color;
      the_canvas->values[center_y - y + i][center_x + x + j]
        = the_ellipse.color;
      the_canvas->values[center_y - y + i][center_x - x + j]
        = the_ellipse.color;
    }
  }
  return the_canvas;
}

void debug_ellipse(ellipse the_ellipse) {
  printf("[ELLIPSE]: (%d, %d, %d)\n", the_ellipse.major_axis,
      the_ellipse.minor_axis, the_ellipse.thickness);
  debug_point(the_ellipse.center);
  debug_pixel(the_ellipse.color);
}
