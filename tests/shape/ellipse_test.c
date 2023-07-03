#include "ellipse_test.h"

int ellipse_test(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  ellipse the_ellipse = {
    (point){500.0, 500.0, CIRCLE, (pixel){0, 23, 42}, 15},
    (pixel){0, 23, 42},
    500,
    300,
    15
  };
  the_canvas = draw_ellipse(the_canvas, the_ellipse);
  write_canvas_png(the_canvas, "ellipse_test.png");
  free_canvas(the_canvas);
  return 1;
}
