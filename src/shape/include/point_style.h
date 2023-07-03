/**
 * @file   point_style.h
 * @brief  This file contains the function definitions for point_style.c.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef POINT_STYLE_H
#define POINT_STYLE_H

#include <stdlib.h>

typedef enum {
  CIRCLE,
  STAR
} point_style;

const char * point_style_to_string(point_style ps);

#endif
