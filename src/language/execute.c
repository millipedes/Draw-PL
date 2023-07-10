/**
 * @file   execute.c
 * @brief  This file contains the execution functions for the language. Note
 * that this language is dynamically typed!
 * @author Matthew C. Lindeman
 * @date   July 10, 2023
 * @bug    None known
 * @todo   Nothing
 */
#include "include/execute.h"

// void execute(ast head) {
//   symbol_table st = init_symbol_table();
//   st = populate_symbol_table(head, st);
// }

symbol execute_expression(ast head, result the_result) {
  for(int i = 0; i < head->no_children; i++) {
    if(!head->children[i]->leaf) {
      switch(head->children[i]->category) {
        case IN_EXPRESSION:
          switch(head->children[1]->leaf->category) {
            case PLUS:
              break;
            case MINUS:
              break;
            case STAR:
              break;
            case SLASH:
              break;
            case PERCENT:
              break;
          }
          break;
        case IN_EXPRESSION_LIST:
          fprintf(stderr, "Not implemented yet\n");
          exit(1);
          break;
        default:
          fprintf(stderr, "[EXECUTE_EXPRESSION]: Something went terribly wrong"
              "\n");
          exit(1);
      }
    } else if(head->children[i]->leaf) {
      symbol value = {0};
      size_t literal_len = 0;
      switch(head->children[i]->leaf->category) {
        case INTEGER:
          the_result.current_type = NCL_INTEGER;
          value.the_int = atoi(head->children[i]->leaf->literal);
          return value;
        case DOUBLE:
          the_result.current_type = NCL_DOUBLE;
          value.the_double = atof(head->children[i]->leaf->literal);
          return value;
        case TRUE:
          the_result.current_type = NCL_BOOL;
          value.the_bool = 1;
          return value;
        case FALSE:
          the_result.current_type = NCL_BOOL;
          value.the_bool = 0;
          return value;
        case NAME:
          the_result.current_type = NCL_LOOKUP;
          literal_len = strnlen(head->children[i]->leaf->literal, MAX_NAME);
          value.the_string = calloc(literal_len + 1, sizeof(char));
          strncpy(value.the_string, head->children[i]->leaf->literal,
              literal_len);
          return value;
        case STRING:
          the_result.current_type = NCL_STRING;
          literal_len = strnlen(head->children[i]->leaf->literal, MAX_NAME);
          value.the_string = calloc(literal_len + 1, sizeof(char));
          strncpy(value.the_string, head->children[i]->leaf->literal,
              literal_len);
          return value;
        default:
          fprintf(stderr, "[EXECUTE_EXPRESSION]: Something went terribly wrong"
              "\n");
          exit(1);
      }
    } else {
      fprintf(stderr, "[EXECUTE_EXPRESSION]: Something went terribly wrong\n");
      exit(1);
    }
  }
}
