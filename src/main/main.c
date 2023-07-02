#include "shape/include/point.h"

int main(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  write_canvas_png(the_canvas, "./test.png");
  free_canvas(the_canvas);
  return 0;
}
