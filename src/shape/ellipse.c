#include "include/ellipse.h"

canvas draw_ellipse(canvas the_canvas, ellipse the_ellipse) {
  int center_x = the_ellipse.center.x;
  int center_y = the_ellipse.center.y;
  int radius_x = the_ellipse.major_axis / 2;
  int radius_y = the_ellipse.minor_axis / 2;
  
  int x = 0;
  int y = radius_y;
  int rx2 = radius_x * radius_x;
  int ry2 = radius_y * radius_y;
  int two_rx2 = 2 * rx2;
  int two_ry2 = 2 * ry2;
  int p = 0;

  // Region 1
  int dx = 0;
  int dy = two_rx2 * y;

  draw_ellipse_points(the_canvas, the_ellipse, center_x, center_y, x, y);

  // Region 1
  p = ry2 - (rx2 * radius_y) + (0.25 * rx2);

  while(dx < dy) {
    x++;
    dx += two_ry2;
    if (p < 0) {
      p += ry2 + dx;
    } else {
      y--;
      dy -= two_rx2;
      p += ry2 + dx - dy;
    }
    draw_ellipse_points(the_canvas, the_ellipse, center_x, center_y, x, y);
  }

  // Region 2
  p = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;

  while(y > 0) {
    y--;
    dy -= two_rx2;
    if (p > 0) {
      p += rx2 - dy;
    } else {
      x++;
      dx += two_ry2;
      p += rx2 - dy + dx;
    }
    draw_ellipse_points(the_canvas, the_ellipse, center_x, center_y, x, y);
  }

  return the_canvas;
}

void draw_ellipse_points(canvas the_canvas, ellipse the_ellipse, int center_x,
    int center_y, int x, int y) {
  for(int i = -the_ellipse.thickness/2; i <= the_ellipse.thickness/2; i++) {
    for(int j = -the_ellipse.thickness/2; j <= the_ellipse.thickness/2; j++) {
      the_canvas->values[center_y + y + i][center_x + x + j]
        = the_ellipse.color;
      the_canvas->values[center_y + y + i][center_x - x + j]
        = the_ellipse.color;
      the_canvas->values[center_y - y + i][center_x + x + j]
        = the_ellipse.color;
      the_canvas->values[center_y - y + i][center_x - x + j]
        = the_ellipse.color;
    }
  }
}
