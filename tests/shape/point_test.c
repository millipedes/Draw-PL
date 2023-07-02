#include "point_test.h"

int point_test(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  point the_point = {500.0, 500.0, CIRCLE, (pixel){0, 23, 42}, 300};
  write_point_to_canvas(the_canvas, the_point);
  write_canvas_png(the_canvas, "./test.png");
  free_canvas(the_canvas);
  return 1;
}
