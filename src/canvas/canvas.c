/**
 * @file   canvas.c
 * @brief  This file contains the functions related to the canvas data
 * structure.
 * @author Matthew C. Lindeman
 * @date   April 07, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/canvas.h"

/**
 * This function initializes a function with dimensions heighxwidth.
 * @param      height - The height of the canvas.
 * @param       width - The width of the canvas.
 * @return the_canvas - The inited canvas.
 */
canvas init_canvas(int height, int width, int r, int g, int b) {
  canvas the_canvas = {0};
  the_canvas.height = height;
  the_canvas.width = width;
  the_canvas.values = calloc(height, sizeof(struct PIXEL_T *));
  for(int i = 0; i < height; i++) {
    the_canvas.values[i] = calloc(width, sizeof(struct PIXEL_T));
    for(int j = 0; j < width; j++)
      the_canvas.values[i][j] = (pixel){r, g, b};
  }
  return the_canvas;
}

/**
 * This function debugs a canvas.
 * @param the_canvas - The canvas to be debugged.
 * @return       N/a
 */
void debug_canvas(canvas the_canvas) {
  printf("[CANVAS]\n");
  printf("Height: %d Width: %d\n", the_canvas.height, the_canvas.width);
  for(int i = 0; i < the_canvas.height; i++)
    for(int j = 0; j < the_canvas.width; j++)
      debug_pixel(the_canvas.values[i][j]);
}

/**
 * This function writes the_canvas to the file specified by file_name.
 * @param the_canvas - The canvas that will be written.
 * @param  file_name - The name of the file to be written.
 * @return       N/a
 */
void write_canvas_ppm(canvas the_canvas, char * file_name) {
  FILE * fp = fopen(file_name, "w");
  fprintf(fp, "%s\n", PPM_HEADER);
  fprintf(fp, "%d %d\n", the_canvas.width, the_canvas.height);
  fprintf(fp, "%d\n", MAX_COL);
  for(int i = 0; i < the_canvas.height; i++)
    for(int j = 0; j < the_canvas.width; j++)
      ppm_print(the_canvas.values[i][j], fp);
  fclose(fp);
}

void write_canvas_png(canvas the_canvas, char * file_name) {
  FILE * fp = fopen(file_name, "w");
  png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL,
      NULL, NULL);
  png_infop info_ptr = png_create_info_struct(png_ptr);
  png_init_io(png_ptr, fp);
  png_set_IHDR(png_ptr, info_ptr, the_canvas.width, the_canvas.height, 8,
      PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
      PNG_FILTER_TYPE_DEFAULT);
  png_write_info(png_ptr, info_ptr);
  for (int i = 0; i < the_canvas.height; i++) {
    png_bytep row = calloc(the_canvas.width * 3, sizeof(png_byte));
    for(int j = 0; j < the_canvas.width; j++) {
      row[3*j + 0] = (png_byte) the_canvas.values[i][j].r;
      row[3*j + 1] = (png_byte) the_canvas.values[i][j].g;
      row[3*j + 2] = (png_byte) the_canvas.values[i][j].b;
    }
    png_write_row(png_ptr, row);
    free(row);
    row = NULL;
  }

  png_write_end(png_ptr, info_ptr);
  png_destroy_write_struct(&png_ptr, &info_ptr);
  fclose(fp);
}

/**
 * This function frees a canvas.
 * @param the_canvas - The canvas to be freed.
 * @return       N/a
 */
void free_canvas(canvas the_canvas) {
  if(the_canvas.values) {
    for(int i = 0; i < the_canvas.height; i++) {
      if(the_canvas.values[i])
        free(the_canvas.values[i]);
    }
    free(the_canvas.values);
  }
}
