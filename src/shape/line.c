#include "include/line.h"

void debug_line(line the_line) {
  printf("[LINE] %d\n", the_line.thickness);
  printf("[FROM]:\n");
  debug_point(the_line.from);
  printf("[TO]:\n");
  debug_point(the_line.to);
  debug_pixel(the_line.color);
}

canvas write_line_to_canvas(canvas the_canvas, line the_line) {
  switch(the_line.style) {
    case SOLID:
      return bresenham_line_draw(the_canvas, the_line);
    case DOTTED:
      fprintf(stderr, "Dotted line not implemented yet\n");
      return NULL;
  }
  return NULL;
}

canvas bresenham_line_draw(canvas the_canvas, line the_line) {
  int dx = the_line.to.x - the_line.from.x;
  int dy = the_line.to.y - the_line.from.y;
  int x = the_line.from.x;
  int y = the_line.from.y;

  int x_inc = (dx > 0) ? 1 : -1;
  int y_inc = (dy > 0) ? 1 : -1;

  dx = abs(dx);
  dy = abs(dy);

  int two_dx = 2 * dx;
  int two_dy = 2 * dy;

  int error = 0;

  if(dx >= dy) {
    while(x != the_line.to.x) {
      for(int i = 0; i < the_line.thickness; i++) {
        for(int j = -the_line.thickness / 2; j <= the_line.thickness / 2;
            j++) {
          the_canvas->values[y + j][(int)x + i] = the_line.from.color;
        }
      }
      x += x_inc;
      error += two_dy;
      if (error > dx) {
        y += y_inc;
        error -= two_dx;
      }
    }
  } else {
    while(y != the_line.to.y) {
      for(int i = 0; i < the_line.thickness; i++) {
        for(int j = -the_line.thickness / 2; j <= the_line.thickness / 2;
            j++) {
          the_canvas->values[y + j][(int)x + i] = the_line.from.color;
        }
      }
      y += y_inc;
      error += two_dx;
      if(error > dy) {
        x += x_inc;
        error -= two_dy;
      }
    }
  }

  return the_canvas;
}
