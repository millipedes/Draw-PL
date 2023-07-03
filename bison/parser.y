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

%token <the_ast> STRING ENDMARKER NEWLINE COMMENT FALSE TRUE BREAK FOR CANVAS
%token <the_ast> COLOR RECTANGLE CIRCLE ELLIPSE SQUARE LINE TO FROM POINT RANGE
%token <the_ast> APPEND NORTH EAST SOUTH WEST WRITE NAME INTEGER DOUBLE LPAR
%token <the_ast> RPAR LSQB RSQB COMMA PLUS MINUS STAR SLASH VBAR AMPER LESS
%token <the_ast> GREATER EQUAL PERCENT LBRACE RBRACE EQEQUAL NOTEQUAL LESSEQUAL
%token <the_ast> GREATEREQUAL DOUBLESLASH IN

%type <the_ast> canvas_declaration color_declaration star_NEWLINE_stmt statement
%type <the_ast> shape_declaration rectangle_declaration shape point_declaration
%type <the_ast> pick_NEWLINE_stmt ellipse_declaration line_declaration
%type <the_ast> to_declaration from_declaration for_loop

%%

program
  : canvas_declaration LBRACE star_NEWLINE_stmt RBRACE {
    $1 = add_child($1, $3);
    head = $1;
    return ENDMARKER;
  }
  ;

canvas_declaration
  : CANVAS LPAR color_declaration COMMA STRING COMMA INTEGER COMMA INTEGER RPAR {
    $$ = init_ast(NULL, IN_CANVAS_DECLARATION);
    $$ = add_child($$, $3);
    $$ = add_child($$, $5);
    $$ = add_child($$, $7);
    $$ = add_child($$, $9);
  }
  ;

color_declaration
  : COLOR LPAR INTEGER COMMA INTEGER COMMA INTEGER RPAR {
    $$ = init_ast(NULL, IN_COLOR_DECLARATION);
    $$ = add_child($$, $3);
    $$ = add_child($$, $5);
    $$ = add_child($$, $7);
  }
  ;

star_NEWLINE_stmt
  : pick_NEWLINE_stmt star_NEWLINE_stmt {
    $$ = init_ast(NULL, IN_STAR_NEWLINE_STMT);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
  }
  | NEWLINE
  ;

pick_NEWLINE_stmt
  : statement {
    $$ = init_ast(NULL, IN_PICK_NEWLINE_STMT);
    $$ = add_child($$, $1);
  }
  | NEWLINE
  ;

statement
  : shape_declaration
  | for_loop
  | COMMENT
  ;

for_loop
  : FOR NAME IN RANGE LPAR INTEGER RPAR LBRACE star_NEWLINE_stmt RBRACE {
    $$ = init_ast(NULL, IN_FOR_LOOP);
    $$ = add_child($$, $2);
    $$ = add_child($$, $6);
    $$ = add_child($$, $9);
  }
  ;

shape_declaration
  : NAME EQUAL shape {
    $$ = init_ast(NULL, IN_SHAPE_DECLARATION);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
    $$ = add_child($$, $3);
  }
  ;

shape
  : rectangle_declaration
  | ellipse_declaration
  | point_declaration
  | line_declaration
  ;

rectangle_declaration
  : RECTANGLE LPAR DOUBLE COMMA DOUBLE COMMA point_declaration RPAR {
    $$ = init_ast(NULL, IN_RECTANGLE_DECLARATION);
    $$ = add_child($$, $3);
    $$ = add_child($$, $5);
    $$ = add_child($$, $7);
  }
  ;

ellipse_declaration
  : ELLIPSE LPAR DOUBLE COMMA DOUBLE COMMA point_declaration RPAR {
    $$ = init_ast(NULL, IN_ELLIPSE_DECLARATION);
    $$ = add_child($$, $3);
    $$ = add_child($$, $5);
    $$ = add_child($$, $7);
  }
  ;

point_declaration
  : POINT LPAR DOUBLE COMMA DOUBLE RPAR {
    $$ = init_ast(NULL, IN_POINT_DECLARATION);
    $$ = add_child($$, $3);
    $$ = add_child($$, $5);
  }
  ;

line_declaration
  : LINE LPAR from_declaration COMMA to_declaration RPAR {
    $$ = init_ast(NULL, IN_LINE_DECLARATION);
    $$ = add_child($$, $3);
    $$ = add_child($$, $5);
  }
  ;

to_declaration
  : TO LPAR shape RPAR {
    $$ = init_ast(NULL, IN_TO_DECLARATION);
    $$ = add_child($$, $3);
  }
  | TO LPAR NAME RPAR {
    $$ = init_ast(NULL, IN_TO_DECLARATION);
    $$ = add_child($$, $3);
  }
  ;

from_declaration
  : FROM LPAR shape RPAR {
    $$ = init_ast(NULL, IN_FROM_DECLARATION);
    $$ = add_child($$, $3);
  }
  | FROM LPAR NAME RPAR {
    $$ = init_ast(NULL, IN_FROM_DECLARATION);
    $$ = add_child($$, $3);
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
  }
  return NULL;
}
