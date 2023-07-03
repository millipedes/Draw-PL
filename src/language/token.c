#include "include/token.h"

token init_token(int category, char * literal, int line_no) {
  token the_token = calloc(1, sizeof(struct TOKEN_T));
  size_t literal_len = strnlen(literal, LITERAL_LEN);
  the_token->literal = calloc(literal_len + 1, sizeof(char));
  strncpy(the_token->literal, literal, literal_len);
  the_token->category = category;
  the_token->line_no = line_no;
  return the_token;
}

void debug_token(token the_token) {
  printf("`%17s`, %17d, %17s\n", the_token->literal,
      the_token->line_no, category_to_string(the_token->category));
}

void free_token(token the_token) {
  if(the_token) {
    if(the_token->literal)
      free(the_token->literal);
    free(the_token);
  }
}
