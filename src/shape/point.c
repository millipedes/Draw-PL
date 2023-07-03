/**
 * @file   point.c
 * @brief  This file contains the functions which facilitate the point data
 * structure in this program.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/point.h"

/**
 * This function debugs a point data structure.
 * @param the_point - The point to be debugged.
 * @return      N/a
 */
void debug_point(point the_point) {
  printf("[POINT]: (Style %s) (%f, %f) (radius: %d)\n",
      point_style_to_string(the_point.style), the_point.x, the_point.y,
      the_point.radius);
  debug_pixel(the_point.color);
}

/**
 * This function takes a point and writes it to the canvas.
 * @param  the_canvas - The canvas for the point to be written to.
 * @param   the_point - The point to written onto the canvas.
 * @return the_canvas - The canvas with the point written to it.
 */
canvas write_point_to_canvas(canvas the_canvas, point the_point) {
  switch(the_point.style) {
    case CIRCLE:
      return scaline_circle_algorithm(the_canvas, the_point);
    case STAR:
      fprintf(stderr, "Star point style needs to be implemented\n");
      return NULL;
  }
  return NULL;
}

/**
 * This is the scaline circle drawing algorithm for the points that are supposed
 * to be filled in circles.
 * @param  the_canvas - The canvas for the point to be written to.
 * @param   the_point - The point to be written to the canvas using this
 * algorithm.
 * @return the_canvas - The canvas which has had the point written to it.
 */
canvas scaline_circle_algorithm(canvas the_canvas, point the_point) {
  int min_x = the_point.x - the_point.radius;
  int max_x = the_point.radius + the_point.x;
  int min_y = the_point.y - the_point.radius;
  int max_y = the_point.radius + the_point.y;
  for(int i = min_y; i <= max_y; i++) {
    int left_x = (int)the_point.x
      - (int)sqrt(the_point.radius * the_point.radius
        - (i - the_point.y) * (i - the_point.y));
    int right_x = (int)the_point.x
      + (int)sqrt(the_point.radius * the_point.radius
        - (i - the_point.y) * (i - the_point.y));

    left_x = (left_x < min_x) ? min_x : left_x;
    right_x = (right_x > max_x) ? max_x : right_x;

    for(int j = left_x; j <= right_x; j++) {
      the_canvas->values[i][j] = the_point.color;
    }
  }
  return the_canvas;
}
