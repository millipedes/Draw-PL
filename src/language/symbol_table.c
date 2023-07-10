#include "include/symbol_table.h"

symbol_table init_symbol_table(void) {
  symbol_table st = calloc(1, sizeof(struct SYMBOL_TABLE_T));
  st->member_names = NULL;
  st->members = NULL;
  st->member_types = NULL;
  st->qty_members = 0;
  return st;
}

// symbol_table add_member(symbol_table st, symbol new_symbol, char * literal,
//     ncl_type the_type) {
// }

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
         printf("`%s` :: %d\n", st->member_names[i], st->members[i].the_int);
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
         debug_point(st->members[i].the_point);
         break;
       case NCL_ELLIPSE:
         printf("`%s`\n", st->member_names[i]);
         debug_ellipse(st->members[i].the_ellipse);
         break;
       case NCL_CANVAS:
         printf("`%s`\n", st->member_names[i]);
         debug_canvas(st->members[i].the_canvas);
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
    if(st->members)
      free(st->members);
    if(st->member_types)
      free(st->member_types);
    free(st);
  }
}
