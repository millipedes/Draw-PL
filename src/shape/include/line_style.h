#ifndef LINE_STYLE_H
#define LINE_STYLE_H

#include <stdlib.h>

typedef enum {
  SOLID,
  DOTTED
} line_style;

const char * line_style_to_string(line_style ls);

#endif
