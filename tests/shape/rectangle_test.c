#include "rectangle_test.h"

int rectangle_test(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  rectangle the_rectangle = {
    (point){500.0, 500.0, CIRCLE, (pixel){0, 23, 42}, 15},
    (pixel){0, 23, 42},
    300,
    500,
    15
  };
  the_canvas = bresenham_rectangle_draw(the_canvas, the_rectangle);
  write_canvas_png(the_canvas, "rectangle_test.png");
  free_canvas(the_canvas);
  return 1;
}
