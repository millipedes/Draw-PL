#include "include/point.h"

void debug_point(point the_point) {
  printf("[POINT]: (Style %s) (%f, %f) (radius: %d)\n",
      point_style_to_string(the_point.style), the_point.x, the_point.y,
      the_point.radius);
  debug_pixel(the_point.color);
}

void write_point_to_canvas(canvas the_canvas, point the_point) {
  switch(the_point.style) {
    case CIRCLE:
      scaline_circle_algorithm(the_canvas, the_point);
      break;
    case STAR:
      fprintf(stderr, "Star point style needs to be implemented\n");
      break;
  }
}

void scaline_circle_algorithm(canvas the_canvas, point the_point) {
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
      change_color(the_canvas->values[i][j], the_point.color);
    }
  }
}

void free_point(point the_point) {
  if(the_point.color)
    free_pixel(the_point.color);
}
