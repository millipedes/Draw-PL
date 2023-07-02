#include "include/line.h"

// void brensenham_line_draw(canvas the_canvas, line the_line) {
//   double m = 0;
//   int b = 0;
//   // from parent, to child
//   if(line.from.x - line.to.x != 0)
//     m = ((double)(line.from.y - line.to.y)) 
//       / ((double)(line.from.x - line.to.x));
//   else
//     m = parent->fx;
//   b = parent->fy - m * parent->fx;
//   int x_start = 0;
//   int x_end = 0;
//   if(parent->fx < child->fx) {
//     x_start = parent->fx + (parent->radius * -cos(atan2((double)m, -1.0)));
//     x_end = child->fx + (child->radius
//         * cos(atan2((double)m, -1.0)));
//   } else if(parent->fx > child->fx) {
//     x_start = parent->fx + (parent->radius * cos(atan2((double)m, -1.0)));
//     x_end = child->fx + (child->radius
//         * -cos(atan2((double)m, -1.0)));
//   }
//   if(x_start > x_end) {
//     int tmp = x_start;
//     x_start = x_end;
//     x_end = tmp;
//   }
//   if(x_start == x_end && parent->fy < child->fy)
//     for(int j = parent->fy + parent->radius;
//         j < child->fy - child->radius; j++)
//       change_color(the_canvas->values[j][parent->fx], parent->color);
//   else if(x_start == x_end && parent->fy > child->fy)
//     for(int j = child->fy + child->radius;
//         j < parent->fy - parent->radius; j++)
//       change_color(the_canvas->values[j][parent->fx], parent->color);
//   else
//     for(int j = x_start; j <= x_end; j++)
//       change_color(the_canvas->values[(int)(m * j + b)][j], parent->color);
//   return the_canvas;
// }
