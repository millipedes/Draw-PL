/**
 * @file   pixel.c
 * @brief  This file contains the functions related to the pixel data structure.
 * @author Matthew C. Lindeman
 * @date   Arpil 07, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/pixel.h"

/**
 * This function changes the dest pixel to the color of the src pixel.
 * @param  dest - The pixel whose color is changed.
 * @param   src - The pixel whose color is being changed to.
 * @return dest - The pixel with the changed color.
 */
pixel change_color(pixel dest, pixel src) {
  dest.r = src.r;
  dest.g = src.g;
  dest.b = src.b;
  return dest;
}

/**
 * This function debugs a pixel.
 * @param the_pixel - The pixel to be debugged.
 * @return      N/a
 */
void debug_pixel(pixel the_pixel) {
  printf("[PIXEL]\n");
  printf("(%d, %d, %d)\n", the_pixel.r, the_pixel.g, the_pixel.b);
}

/**
 * This function is used to print the pixel to fp.
 * @param the_pixel - The pixel that is being printed.
 * @param        fp - The file the pixel is being printed to.
 * @return      N/a
 */
void ppm_print(pixel the_pixel, FILE * fp) {
  fprintf(fp, "%d %d %d\n", the_pixel.r, the_pixel.g, the_pixel.b);
}
