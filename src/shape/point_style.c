/**
 * @file   point_style.c
 * @brief  This file contains the functions relating to the point_style
 * enumeration.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/point_style.h"

/**
 * This function returns a "string" representation of the enumeration.
 * @param  ps - The point_style.
 * @return .\ - The "string" representation of the ps.
 */
const char * point_style_to_string(point_style ps) {
  switch(ps) {
    case POINT_CIRCLE: return "circle";
    case POINT_STAR:   return "star";
  }
  return NULL;
}
