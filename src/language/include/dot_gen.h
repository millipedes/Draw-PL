#ifndef DOT_GEN_H
#define DOT_GEN_H

#include "language/include/ast.h"
#include "parser.tab.h"

char * escape(char * s);
char * pretty_print_name(ast t);
void print_branch(ast t, FILE * f);
void print_leaf(ast t, FILE * f);
void print_graph2(ast t, FILE * f);
void print_graph(ast t, char * filename);

#endif
