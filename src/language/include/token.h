#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LITERAL_LEN 1024

extern char * category_to_string(int category);

typedef struct TOKEN_T {
  char * literal;
  int category;
  int line_no;
} * token;

token init_token(int category, char * literal, int line_no);
void debug_token(token the_token);
void free_token(token the_token);

#endif
