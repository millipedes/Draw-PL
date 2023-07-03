/**
 * @file   point_test.c
 * @brief  This file contains the test for drawing points, could be improved, not
 * really a good test.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "point_test.h"

/**
 * This function tests drawing a point onto a canvas.
 * @param N/a
 * @return  1
 */
int point_test(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  point the_point = {500.0, 500.0, CIRCLE, (pixel){0, 23, 42}, 300};
  the_canvas = write_point_to_canvas(the_canvas, the_point);
  write_canvas_png(the_canvas, "point_test.png");
  free_canvas(the_canvas);
  return 1;
}
