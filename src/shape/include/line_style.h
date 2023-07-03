/**
 * @file   line_style.h
 * @brief  This file contains the function definitions for line_style.c.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#ifndef LINE_STYLE_H
#define LINE_STYLE_H

#include <stdlib.h>

typedef enum {
  SOLID,
  DOTTED
} line_style;

const char * line_style_to_string(line_style ls);

#endif
