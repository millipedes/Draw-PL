// dot -Tpng foo.dot > foo.png
#include "include/dot_gen.h"

char * escape(char * s) {
  char * s2 = malloc(strlen(s)+4);
  if(s[0] == '\"') {
    if(s[strlen(s)-1] != '\"') {
      fprintf(stderr, "What is it?!\n");
    }
  sprintf(s2, "\\%s", s);
  strcat(s2+strlen(s2) - 1, "\\\"");
  return s2;
  } else return s;
}

char * pretty_print_name(ast t) {
  char *s2 = malloc(40);
  if(t->leaf == NULL) {
    sprintf(s2, "%s#%d", internal_node_type_to_string(t->category),
        t->category % 10);
    return s2;
  } else {
    sprintf(s2,"%s:%d", escape(t->leaf->literal), t->leaf->category);
    return s2;
  }
}

void print_branch(ast t, FILE * f) {
   fprintf(f, "N%d [shape=box label=\"%s\"];\n", t->tree_id, pretty_print_name(t));
}

void print_leaf(ast t, FILE * f) {
  const char * s = NULL;
  if(t->category) {
    s = internal_node_type_to_string(t->category);
  } else
    s = category_to_string(t->leaf->category);
  // print_branch(t, f);
  fprintf(f, "N%d [shape=box style=dotted label=\" %s \\n ", t->tree_id, s);
  fprintf(f, "literal = %s \\l lineno = %d \\l\"];\n", escape(t->leaf->literal),
  t->line_no);
}

void print_graph2(ast t, FILE * f) {
  int i = 0;
  if (t->leaf != NULL) {
    print_leaf(t, f);
    return;
  }
  print_branch(t, f);
  for(i=0; i < t->no_children; i++) {
    if (t->children[i] != NULL) {
      fprintf(f, "N%d -> N%d;\n", t->tree_id, t->children[i]->tree_id);
      print_graph2(t->children[i], f);
    }
    else {
      fprintf(f, "N%d -> N%d;\n", t->tree_id, t->tree_id);
      fprintf(f, "N%d [label=\"%s\"];\n", t->tree_id, "Empty rule");
    }
  }
}

void print_graph(ast t, char *filename) {
  FILE *f = fopen(filename, "w");
  fprintf(f, "digraph {\n");
  print_graph2(t, f);
  fprintf(f,"}\n");
  fclose(f);
}

