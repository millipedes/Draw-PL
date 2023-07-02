#include "line_test.h"

int line_test(void) {
  canvas the_canvas = init_canvas(1000, 1000, MAX_COL, MAX_COL, MAX_COL);
  point to = {100.0, 500.0, CIRCLE, (pixel){0, 23, 42}, 300};
  point from = {900.0, 500.0, CIRCLE, (pixel){0, 23, 42}, 300};
  line the_line = {to, from, SOLID, (pixel){0, 23, 42}, 15};
  the_canvas = write_line_to_canvas(the_canvas, the_line);
  to = (point){500.0, 100.0, CIRCLE, (pixel){0, 23, 42}, 300};
  from = (point){500.0, 900.0, CIRCLE, (pixel){0, 23, 42}, 300};
  the_line = (line){to, from, SOLID, (pixel){0, 23, 42}, 15};
  the_canvas = write_line_to_canvas(the_canvas, the_line);
  to = (point){100.0, 100.0, CIRCLE, (pixel){0, 23, 42}, 300};
  from = (point){900.0, 900.0, CIRCLE, (pixel){0, 23, 42}, 300};
  the_line = (line){to, from, SOLID, (pixel){0, 23, 42}, 15};
  the_canvas = write_line_to_canvas(the_canvas, the_line);
  to = (point){100.0, 900.0, CIRCLE, (pixel){0, 23, 42}, 300};
  from = (point){900.0, 100.0, CIRCLE, (pixel){0, 23, 42}, 300};
  the_line = (line){to, from, SOLID, (pixel){0, 23, 42}, 15};
  the_canvas = write_line_to_canvas(the_canvas, the_line);
  write_canvas_png(the_canvas, "line_test.png");
  free_canvas(the_canvas);
  return 1;
}
