#include "include/point_style.h"

const char * point_style_to_string(point_style ps) {
  switch(ps) {
    case STAR: return "star";
  }
  return NULL;
}
