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
#include <string.h>
#include "pixel.h"

#define PPM_HEADER "P3"

#define MAX_OUT_NAME_LEN 256

#define DEFAULT_CAVNAS_HEIGHT 1000
#define DEFAULT_CAVNAS_WIDTH  1000
#define DEFAULT_CANVAS_R      255
#define DEFAULT_CANVAS_G      255
#define DEFAULT_CANVAS_B      255

typedef struct CANVAS_PARAMS_T {
  char * out_file_name;
  pixel color;
  int height;
  int width;
} canvas_params;

canvas_params add_out_file_name(canvas_params the_canvas_params,
    char * out_file_name);
void debug_canvas_params(canvas_params the_canvas_params);
void free_canvas_params(canvas_params the_canvas_params);

typedef struct CANVAS_T {
  pixel ** values;
  int height;
  int width;
} canvas;

canvas init_canvas(int height, int width, int r, int g, int b);
void debug_canvas(canvas the_canvas);
void write_canvas_ppm(canvas the_canvas, char * file_name);
void write_canvas_png(canvas the_canvas, char * file_name);
void free_canvas(canvas the_canvas);

#endif
