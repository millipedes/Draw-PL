#include "include/symbol_table.h"

symbol_table init_symbol_table(void) {
  symbol_table st = calloc(1, sizeof(struct SYMBOL_TABLE_T));
  st->member_names = NULL;
  st->members = NULL;
  st->member_types = NULL;
  st->qty_members = 0;
  return st;
}

symbol_table populate_symbol_table(ast head, symbol_table st) {
  return NULL;
}

symbol_table add_member(symbol_table st, symbol new_symbol) {
  st->qty_members++;
  if(!st->members) {
    st->members = calloc(1, sizeof(symbol));
  } else {
    st->members = realloc(st->members, st->qty_members * sizeof(symbol));
  }
  st->members[st->qty_members - 1] = new_symbol;
  return st;
}

void debug_symbol_table(symbol_table st) {
  printf("[SYMBOL_TABLE]\n");
  for(int i = 0; i < st->qty_members; i++) {
    printf("Member[%d]: ", i);
    switch(st->member_types[i]) {
       case STRING:
         printf("`%s` :: `%s`\n", st->member_names[i],
             st->members[i].the_string);
         break;
       case BOOL:
         printf("`%s` :: %s\n", st->member_names[i],
             st->members[i].the_bool ? "true" : "false");
         break;
       case DOUBLE:
         printf("`%s` :: %f\n", st->member_names[i],
             st->members[i].the_double);
         break;
       case INT:
         printf("`%s` :: %d\n", st->member_names[i], st->members[i].the_int);
         break;
       case RECTANGLE:
         printf("`%s`\n", st->member_names[i]);
         debug_rectangle(st->members[i].the_rect);
         break;
       case COLOR:
         printf("`%s`\n", st->member_names[i]);
         debug_pixel(st->members[i].the_color);
         break;
       case POINT:
         printf("`%s`\n", st->member_names[i]);
         debug_point(st->members[i].the_point);
         break;
       case ELLIPSE:
         printf("`%s`\n", st->member_names[i]);
         debug_ellipse(st->members[i].the_ellipse);
         break;
       case CANVAS:
         printf("`%s`\n", st->member_names[i]);
         debug_canvas(st->members[i].the_canvas);
         break;
    }
  }
}

void free_symbol_table(symbol_table st) {
  if(st) {
    if(st->members)
      free(st->members);
    if(st->member_types)
      free(st->member_types);
    free(st);
  }
}
