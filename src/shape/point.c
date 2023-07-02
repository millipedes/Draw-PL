#include "include/point.h"

void debug_point(point the_point) {
  printf("[POINT]: (Style %s) (%f, %f)\n",
      point_style_to_string(the_point.style), the_point.x, the_point.y);
}
