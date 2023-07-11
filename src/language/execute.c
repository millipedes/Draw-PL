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

result execute_canvas(ast head, result value) {
  if(head->category == IN_CANVAS_PARAMETERS) {
    value.result_type = NCL_CANVAS;
    for(int i = 0; i < head->no_children; i++) {
      switch(head->children[i]->category) {
        case IN_WIDTH_DECLARATION:
          value.result.the_canvas.width =
            atoi(head->children[i]->children[0]->leaf->literal);
          return value;
        case IN_HEIGHT_DECLARATION:
          value.result.the_canvas.height =
            atoi(head->children[i]->children[0]->leaf->literal);
          return value;
        case IN_COLOR_DECLARATION:
          value.result.the_color = (pixel){
            atoi(head->children[i]->children[0]->leaf->literal),
            atoi(head->children[i]->children[1]->leaf->literal),
            atoi(head->children[i]->children[2]->leaf->literal),
          };
          return value;
        case IN_CANVAS_PARAMETERS:
          break;
        case STRING:
          break;
        default:
          break;
      }
    }
  }
}

result execute_expression(ast head, result value) {
  if(head) {
    if(!head->leaf) {
      result the_result = {0};
      for(int i = 0; i < head->no_children; i++) {
        switch(head->category) {
          case IN_EXPRESSION:
            result left = execute_expression(head->children[0], (result){0});
            result right = execute_expression(head->children[2], (result){0});
            switch(head->children[1]->leaf->category) {
              case PLUS:
                if(left.result_type == right.result_type) {
                  switch(left.result_type) {
                    case NCL_STRING:
                      fprintf(stderr, "[EXECUTE_EXPRESSION]: string not "
                          "implemented\n");
                      exit(1);
                    case NCL_DOUBLE:
                      the_result.result.the_double = left.result.the_double
                        + right.result.the_double;
                      the_result.result_type = NCL_DOUBLE;
                      return the_result;
                    case NCL_INTEGER:
                      the_result.result.the_integer = left.result.the_integer
                        + right.result.the_integer;
                      the_result.result_type = NCL_INTEGER;
                      return the_result;
                    default:
                      fprintf(stderr, "[EXECUTE_EXPRESSION]: %s addition not "
                          "supported, exiting\n",
                          ncl_type_to_string(left.result_type));
                      exit(1);
                  }
                }
                break;
              case MINUS:
                if(left.result_type == right.result_type) {
                  switch(left.result_type) {
                    case NCL_DOUBLE:
                      the_result.result.the_double = left.result.the_double
                        - right.result.the_double;
                      the_result.result_type = NCL_DOUBLE;
                      return the_result;
                    case NCL_INTEGER:
                      the_result.result.the_integer = left.result.the_integer
                        - right.result.the_integer;
                      the_result.result_type = NCL_INTEGER;
                      return the_result;
                    default:
                      fprintf(stderr, "[EXECUTE_EXPRESSION]: %s subtraction not"
                          " supported, exiting\n",
                          ncl_type_to_string(left.result_type));
                      exit(1);
                  }
                }
                break;
              case STAR:
                if(left.result_type == right.result_type) {
                  switch(left.result_type) {
                    case NCL_DOUBLE:
                      the_result.result.the_double = left.result.the_double
                        * right.result.the_double;
                      the_result.result_type = NCL_DOUBLE;
                      return the_result;
                    case NCL_INTEGER:
                      the_result.result.the_integer = left.result.the_integer
                        * right.result.the_integer;
                      the_result.result_type = NCL_INTEGER;
                      return the_result;
                    default:
                      fprintf(stderr, "[EXECUTE_EXPRESSION]: %s multiplication "
                          "not supported, exiting\n",
                          ncl_type_to_string(left.result_type));
                      exit(1);
                  }
                }
                break;
              case SLASH:
                if(left.result_type == right.result_type) {
                  switch(left.result_type) {
                    case NCL_DOUBLE:
                      the_result.result.the_double = left.result.the_double
                        / right.result.the_double;
                      the_result.result_type = NCL_DOUBLE;
                      return the_result;
                    case NCL_INTEGER:
                      the_result.result.the_integer = left.result.the_integer
                        / right.result.the_integer;
                      the_result.result_type = NCL_INTEGER;
                      return the_result;
                    default:
                      fprintf(stderr, "[EXECUTE_EXPRESSION]: %s division not "
                          "supported, exiting\n",
                          ncl_type_to_string(left.result_type));
                      exit(1);
                  }
                }
                break;
              case PERCENT:
                if(left.result_type == right.result_type) {
                  switch(left.result_type) {
                    case NCL_INTEGER:
                      the_result.result.the_integer = left.result.the_integer
                        % right.result.the_integer;
                      the_result.result_type = NCL_INTEGER;
                      return the_result;
                    default:
                      fprintf(stderr, "[EXECUTE_EXPRESSION]: %s modulus not "
                          "supported, exiting\n",
                          ncl_type_to_string(left.result_type));
                      exit(1);
                  }
                }
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
      }
    } else if(head->leaf) {
      size_t literal_len = 0;
      switch(head->leaf->category) {
        case INTEGER:
          value.result_type = NCL_INTEGER;
          value.result.the_integer = atoi(head->leaf->literal);
          return value;
        case DOUBLE:
          value.result_type = NCL_DOUBLE;
          value.result.the_double = atof(head->leaf->literal);
          return value;
        case TRUE:
          value.result_type = NCL_BOOL;
          value.result.the_bool = 1;
          return value;
        case FALSE:
          value.result_type = NCL_BOOL;
          value.result.the_bool = 0;
          return value;
        case NAME:
          value.result_type = NCL_LOOKUP;
          literal_len = strnlen(head->leaf->literal, MAX_NAME);
          value.result.the_string = calloc(literal_len + 1, sizeof(char));
          strncpy(value.result.the_string, head->leaf->literal,
              literal_len);
          return value;
        case STRING:
          value.result_type = NCL_STRING;
          literal_len = strnlen(head->leaf->literal, MAX_NAME);
          value.result.the_string = calloc(literal_len + 1, sizeof(char));
          strncpy(value.result.the_string, head->leaf->literal,
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
