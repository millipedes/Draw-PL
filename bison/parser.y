%{
#include "language/include/ast.h"

extern int yylex();
extern char * yytext;
ast head;

int yyerror(char * s);
char * category_to_string(int category);
%}

%debug

%code requires {
  #include "language/include/ast.h"
}

%union {
  ast the_ast;
}

%token <the_ast> STRING ENDMARKER NEWLINE COMMENT FALSE TRUE BREAK FOR CANVAS COLOR
%token <the_ast> RECTANGLE CIRCLE ELLIPSE SQUARE LINE TO FROM POINT RANGE APPEND
%token <the_ast> NORTH EAST SOUTH WEST WRITE NAME INTEGER DOUBLE LPAR RPAR LSQB RSQB
%token <the_ast> COMMA PLUS MINUS STAR SLASH VBAR AMPER LESS GREATER EQUAL PERCENT
%token <the_ast> LBRACE RBRACE EQEQUAL NOTEQUAL LESSEQUAL GREATEREQUAL DOUBLESLASH
%token <the_ast> INTERNAL_NODE

%type <the_ast> canvas_declaration color_declaration

%%

program
  : canvas_declaration LBRACE RBRACE {
    head = $1;
    free_ast($2);
    free_ast($3);
    return ENDMARKER;
  }
  ;

canvas_declaration
  : CANVAS LPAR color_declaration COMMA STRING COMMA INTEGER COMMA INTEGER RPAR {
    $$ = init_ast(NULL, INTERNAL_NODE);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
    $$ = add_child($$, $3);
    $$ = add_child($$, $4);
    $$ = add_child($$, $5);
    $$ = add_child($$, $6);
    $$ = add_child($$, $7);
    $$ = add_child($$, $8);
    $$ = add_child($$, $9);
    $$ = add_child($$, $10);
  }
  ;

color_declaration
  : COLOR LPAR INTEGER COMMA INTEGER COMMA INTEGER RPAR {
    $$ = init_ast(NULL, INTERNAL_NODE);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
    $$ = add_child($$, $3);
    $$ = add_child($$, $4);
    $$ = add_child($$, $5);
    $$ = add_child($$, $6);
    $$ = add_child($$, $7);
    $$ = add_child($$, $8);
  }
  ;

%%

int yyerror(char * s) {
  fprintf(stderr, "Error: `%s`\n", s);
  exit(1);
}

char * category_to_string(int category) {
  switch(category) {
    case STRING:        return "string";
    case ENDMARKER:     return "endmarker";
    case NEWLINE:       return "newline";
    case COMMENT:       return "comment";
    case FALSE:         return "false";
    case TRUE:          return "true";
    case BREAK:         return "break";
    case FOR:           return "for";
    case CANVAS:        return "canvas";
    case COLOR:         return "color";
    case RECTANGLE:     return "rectangle";
    case CIRCLE:        return "circle";
    case ELLIPSE:       return "ellipse";
    case SQUARE:        return "square";
    case LINE:          return "line";
    case TO:            return "to";
    case FROM:          return "from";
    case POINT:         return "point";
    case RANGE:         return "range";
    case APPEND:        return "append";
    case NORTH:         return "north";
    case EAST:          return "east";
    case SOUTH:         return "south";
    case WEST:          return "west";
    case WRITE:         return "write";
    case NAME:          return "name";
    case INTEGER:       return "integer";
    case DOUBLE:        return "double";
    case LPAR:          return "lpar";
    case RPAR:          return "rpar";
    case LSQB:          return "lsqb";
    case RSQB:          return "rsqb";
    case COMMA:         return "comma";
    case PLUS:          return "plus";
    case MINUS:         return "minus";
    case STAR:          return "star";
    case SLASH:         return "slash";
    case VBAR:          return "vbar";
    case AMPER:         return "amper";
    case LESS:          return "less";
    case GREATER:       return "greater";
    case EQUAL:         return "equal";
    case PERCENT:       return "percent";
    case LBRACE:        return "lbrace";
    case RBRACE:        return "rbrace";
    case EQEQUAL:       return "eqequal";
    case NOTEQUAL:      return "notequal";
    case LESSEQUAL:     return "lessequal";
    case GREATEREQUAL:  return "greaterequal";
    case DOUBLESLASH:   return "doubleslash";
    case INTERNAL_NODE: return "internal node";
  }
  return NULL;
}
