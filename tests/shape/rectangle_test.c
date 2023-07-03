/**
 * @file   rectangle_test.c
 * @brief  This file contains the test for drawing rectangles, could be improved, not
 * really a good test.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "rectangle_test.h"

/**
 * This function tests drawing a rectangle onto a canvas.
 * @param N/a
 * @return  1
 */
int rectangle_test(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  rectangle the_rectangle = {
    (point){500.0, 500.0, POINT_CIRCLE, (pixel){0, 23, 42}, 15},
    (pixel){0, 23, 42},
    300,
    500,
    15
  };
  the_canvas = draw_rectangle(the_canvas, the_rectangle);
  write_canvas_png(the_canvas, "rectangle_test.png");
  free_canvas(the_canvas);
  return 1;
}
