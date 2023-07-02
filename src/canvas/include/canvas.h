/**
 * @file   canvas.h
 * @brief  This file contains the function definitions for canvas.c.
 * @author Matthew C. Lindeman
 * @date   April 07, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef CAN_H
#define CAN_H

#include <math.h>
#include <png.h>
#include "pixel.h"

#define PPM_HEADER "P3"

typedef struct CANVAS_T {
  pixel ** values;
  int height;
  int width;
} * canvas;

canvas init_canvas(int height, int width, int r, int g, int b);
void debug_canvas(canvas the_canvas);
void write_canvas_ppm(canvas the_canvas, char * file_name);
void write_canvas_png(canvas the_canvas, char * file_name);
void free_canvas(canvas the_canvas);

#endif
