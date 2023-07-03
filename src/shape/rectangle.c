#include "include/rectangle.h"

canvas bresenham_rectangle_draw(canvas the_canvas, rectangle the_rect) {
  int half_width = the_rect.width / 2;
  int half_height = the_rect.height / 2;
  int x1 = the_rect.center.x - half_width;
  int y1 = the_rect.center.y - half_height;
  int x2 = the_rect.center.x + half_width;
  int y2 = the_rect.center.y + half_height;

  // Draw the four sides of the rectangle
  bresenham_line_draw(the_canvas, (line){
      (point){x1, y1, CIRCLE, the_rect.color, 15},
      (point){x2, y1, CIRCLE, the_rect.color, 15},
      SOLID,
      the_rect.color,
      the_rect.thickness
      });
  bresenham_line_draw(the_canvas, (line){
      (point){x2, y1, CIRCLE, the_rect.color, 15},
      (point){x2, y2, CIRCLE, the_rect.color, 15},
      SOLID,
      the_rect.color,
      the_rect.thickness
      });
  bresenham_line_draw(the_canvas, (line){
      (point){x2, y2, CIRCLE, the_rect.color, 15},
      (point){x1, y2, CIRCLE, the_rect.color, 15},
      SOLID,
      the_rect.color,
      the_rect.thickness
      });
  bresenham_line_draw(the_canvas, (line){
      (point){x1, y2, CIRCLE, the_rect.color, 15},
      (point){x1, y1, CIRCLE, the_rect.color, 15},
      SOLID,
      the_rect.color,
      the_rect.thickness
      });

  return the_canvas;
}
