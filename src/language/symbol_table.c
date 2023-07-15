#include "include/symbol_table.h"

symbol_table init_symbol_table(void) {
  symbol_table st = calloc(1, sizeof(struct SYMBOL_TABLE_T));
  st->member_names = NULL;
  st->members = NULL;
  st->member_types = NULL;
  st->qty_members = 0;
  return st;
}

// TODO add check for update symbol
symbol_table add_member(symbol_table st, symbol new_symbol, char * literal,
    ncl_type the_type) {
  size_t name_len = strnlen(literal, MAX_NAME);
  st->qty_members++;
  // Member Entry
  if(st->members) {
    st->members = realloc(st->members, st->qty_members * sizeof(symbol));
  } else {
    st->members = calloc(1, sizeof(symbol));
  }
  st->members[st->qty_members - 1] = new_symbol;
  // Name Entry
  if(st->member_names) {
    st->member_names = realloc(st->member_names, st->qty_members
        * sizeof(symbol));
  } else {
    st->member_names = calloc(1, sizeof(symbol));
  }
  st->member_names[st->qty_members - 1] = calloc(name_len + 1, sizeof(char));
  strncpy(st->member_names[st->qty_members - 1], literal, name_len);
  // Type Entry
  if(st->member_types) {
    st->member_types = realloc(st->member_types, st->qty_members
        * sizeof(symbol));
  } else {
    st->member_types = calloc(1, sizeof(symbol));
  }
  st->member_types[st->qty_members - 1] = the_type;
  return st;
}

result find_symbol(symbol_table st, char * name) {
  for(int i = 0; i < st->qty_members; i++) {
    if(!strncmp(st->member_names[i], name, MAX_NAME)) {
      return (result){st->members[i], st->member_types[i]};
    }
  }
  fprintf(stderr, "[FIND_SYMBOL]: symbol: `%s` no declared\nExiting\n", name);
  exit(1);
}

void debug_symbol_table(symbol_table st) {
  printf("[SYMBOL_TABLE]\n");
  for(int i = 0; i < st->qty_members; i++) {
    printf("Member[%d]: ", i);
    switch(st->member_types[i]) {
       case NCL_STRING:
         printf("`%s` :: `%s`\n", st->member_names[i],
             st->members[i].the_string);
         break;
       case NCL_BOOL:
         printf("`%s` :: %s\n", st->member_names[i],
             st->members[i].the_bool ? "true" : "false");
         break;
       case NCL_DOUBLE:
         printf("`%s` :: %f\n", st->member_names[i],
             st->members[i].the_double);
         break;
       case NCL_INTEGER:
         printf("`%s` :: %d\n", st->member_names[i],
             st->members[i].the_integer);
         break;
       case NCL_RECTANGLE:
         printf("`%s`\n", st->member_names[i]);
         debug_rectangle(st->members[i].the_rect);
         break;
       case NCL_COLOR:
         printf("`%s`\n", st->member_names[i]);
         debug_pixel(st->members[i].the_color);
         break;
       case NCL_POINT:
         printf("`%s`\n", st->member_names[i]);
         debug_point(st->members[i].the_point);
         break;
       case NCL_LINE:
         printf("`%s`\n", st->member_names[i]);
         debug_line(st->members[i].the_line);
         break;
       case NCL_ELLIPSE:
         printf("`%s`\n", st->member_names[i]);
         debug_ellipse(st->members[i].the_ellipse);
         break;
       case NCL_CANVAS:
         printf("`%s`\n", st->member_names[i]);
         debug_canvas_params(st->members[i].the_canvas);
         break;
       case NCL_LOOKUP:
         fprintf(stderr, "[DEBUG_SYMBOL_TABLE]: Something went wrong\nExiting"
             "\n");
         exit(1);
    }
  }
}

void free_symbol_table(symbol_table st) {
  if(st) {
    if(st->member_names) {
      for(int i = 0; i < st->qty_members; i++) {
        if(st->member_names[i]) {
          free(st->member_names[i]);
        }
      }
      free(st->member_names);
    }
    if(st->members) {
      for(int i = 0; i < st->qty_members; i++) {
        if(st->member_types[i] == NCL_CANVAS) {
          free_canvas_params(st->members[i].the_canvas);
        }
      }
      free(st->members);
    }
    if(st->member_types)
      free(st->member_types);
    free(st);
  }
}
