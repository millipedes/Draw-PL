// #include "include/symbol_table.h"
// 
// symbol_table init_symbol_table(void) {
//   symbol_table st = calloc(1, sizeof(struct SYMBOL_TABLE_T));
//   st->member_names = NULL;
//   st->members = NULL;
//   st->member_types = NULL;
//   st->qty_members = 0;
//   return st;
// }
// 
// symbol_table populate_symbol_table(ast head, symbol_table st) {
//   if(head) {
//     if(head->category == IN_CANVAS_DECLARATION) {
//       symbol canvas_symbol.the_canvas = init_canvas(DEFAULT_CAVNAS_HEIGHT,
//           DEFAULT_CAVNAS_WIDTH, DEFAULT_CANVAS_R, DEFAULT_CANVAS_G,
//           DEFAULT_CANVAS_B);
//       canvas_symbol.the_canvas = adjust_cavnas_parameters(head->chlidern[0],
//           canvas_symbol.the_canvas);
//     }
//     // for(int i = 0; i < head->no_children; i ++) {
//     //   if(head->category == IN_EXPRESSION_ASSIGNMENT
//     //       || head->category == IN_SHAPE_ASSIGNMENT) {
//     //     if(head->children[0] && head->children[1] && head->children[2]) {
//     //     } else {
//     //       fprintf(stderr, "[POPULATE_SYMBOL_TABLE]: something went"
//     //           " catestrophically wrong, please report to millipedes author"
//     //           " of this programming language.\nExiting\n");
//     //       exit(1);
//     //     }
//     //   }
//     // }
//     return st;
//   } else {
//     return st;
//   }
// }
// 
// symbol_table add_member(symbol_table st, symbol new_symbol, char * literal,
//     ncl_type the_type) {
//   st->qty_members++;
//   size_t member_name_len = strnlen(literal, MAX_NAME);
//   char * member_name = calloc(member_name_len + 1, sizeof(char));
//   strncpy(member_name, literal, member_name_len);
//   if(!st->members) {
//     st->members = calloc(1, sizeof(symbol));
//     st->member_names = calloc(1, sizeof(char *));
//     st->member_types = calloc(1, sizeof(ncl_type));
//   } else {
//     st->members = realloc(st->members, st->qty_members * sizeof(symbol));
//     st->member_names = realloc(st->member_names, st->qty_members
//         * sizeof(char *));
//     st->member_types = realloc(st->member_types, st->qty_members
//         * sizeof(ncl_type));
//   }
//   st->members[st->qty_members - 1] = new_symbol;
//   st->member_names[st->qty_members - 1] = member_name;
//   st->member_types[st->qty_members - 1] = the_type;
//   return st;
// }
// 
// symbol adjust_cavnas_parameters(ast head, symbol canvas_symbol) {
//   if(head->category == IN_CANVAS_PARAMETERS) {
//     switch(head->children[1]->category) {
//       case IN_WIDTH_DECLARATION:
//         adjust_unary_parameter(head->children[1]);
//         break;
//       case IN_HEIGHT_DECLARATION:
//         adjust_unary_parameter(head->children[1]);
//         break;
//       case COLOR_DECLARATION:
//         break;
//     }
//   } else {
//     switch(head->category) {
//     }
//   }
// }
// 
// int adjust_unary_parameter(ast head) {
//   if(head->children[0])
//     return atoi(head->children[0]->leaf->literal);
//   else {
//     fprintf(stderr, "[ADJUST_UNARY_PARAMETER]: A function requires a single "
//         " integer argument\nExiting");
//     exit(1);
//   }
// }
// 
// // ncl_type determine_type(ast head) {
// //   if(head) {
// //     switch(head->category) {
// //       case IN_ELLIPSE_DECLARATION:
// //         return ELLIPSE;
// //       case IN_RECTANGLE_DECLARATION:
// //         return RECTANGLE;
// //       case IN_POINT_DECLARATION:
// //         return POINT;
// //       case IN_COLOR_DECLARATION:
// //         return COLOR;
// //       case IN_LINE_DECLARATION:
// //         return LINE;
// //       default:
// //         int tmp = -1;
// //         for(int i = 0; i < head->no_children; i++) {
// //           if((tmp = determine_type(head->children[i])) != -1)
// //             return tmp;
// //         }
// //         break;
// //     }
// //     return -1;
// //   }
// //   return -1;
// // }
// 
// void debug_symbol_table(symbol_table st) {
//   printf("[SYMBOL_TABLE]\n");
//   for(int i = 0; i < st->qty_members; i++) {
//     printf("Member[%d]: ", i);
//     switch(st->member_types[i]) {
//        case STRING:
//          printf("`%s` :: `%s`\n", st->member_names[i],
//              st->members[i].the_string);
//          break;
//        case BOOL:
//          printf("`%s` :: %s\n", st->member_names[i],
//              st->members[i].the_bool ? "true" : "false");
//          break;
//        case DOUBLE:
//          printf("`%s` :: %f\n", st->member_names[i],
//              st->members[i].the_double);
//          break;
//        case INT:
//          printf("`%s` :: %d\n", st->member_names[i], st->members[i].the_int);
//          break;
//        case RECTANGLE:
//          printf("`%s`\n", st->member_names[i]);
//          debug_rectangle(st->members[i].the_rect);
//          break;
//        case COLOR:
//          printf("`%s`\n", st->member_names[i]);
//          debug_pixel(st->members[i].the_color);
//          break;
//        case POINT:
//          printf("`%s`\n", st->member_names[i]);
//          debug_point(st->members[i].the_point);
//          break;
//        case LINE:
//          printf("`%s`\n", st->member_names[i]);
//          debug_point(st->members[i].the_point);
//          break;
//        case ELLIPSE:
//          printf("`%s`\n", st->member_names[i]);
//          debug_ellipse(st->members[i].the_ellipse);
//          break;
//        case CANVAS:
//          printf("`%s`\n", st->member_names[i]);
//          debug_canvas(st->members[i].the_canvas);
//          break;
//     }
//   }
// }
// 
// void free_symbol_table(symbol_table st) {
//   if(st) {
//     if(st->members)
//       free(st->members);
//     if(st->member_types)
//       free(st->member_types);
//     free(st);
//   }
// }
