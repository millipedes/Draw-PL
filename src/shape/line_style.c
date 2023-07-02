#include "include/line_style.h"

const char * line_style_to_string(line_style ls) {
  switch(ls) {
    case SOLID:  return "solid";
    case DOTTED: return "dotted";
  }
  return NULL;
}
