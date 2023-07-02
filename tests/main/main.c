#include "shape/point_test.h"

int main(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  point the_point = {500.0, 500.0, CIRCLE, init_pixel(0, 23, 42), 300};
  write_point_to_canvas(the_canvas, the_point);
  write_canvas_png(the_canvas, "./test.png");
  free_point(the_point);
  free_canvas(the_canvas);
  return 0;
}
