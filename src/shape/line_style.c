/**
 * @file   line_style.c
 * @brief  This file contains the functions relating to the line_style
 * enumeration.
 * @author Matthew C. Lindeman
 * @date   July 02, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/line_style.h"

/**
 * This function returns a "string" representation of the enumeration.
 * @param  ls - The line_style.
 * @return .\ - The "string" representation of the ls.
 */
const char * line_style_to_string(line_style ls) {
  switch(ls) {
    case SOLID:  return "solid";
    case DOTTED: return "dotted";
  }
  return NULL;
}
