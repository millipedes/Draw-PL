%{
#include "language/include/ast.h"

extern int yylex();
extern char * yytext;
ast head;
int tree_id; // This is hear to produce .dot files (graphviz for tree analysis)

int yyerror(char * s);
char * category_to_string(int category);
%}

%debug

%left PLUS MINUS
%left STAR SLASH PERCENT
%left LESS GREATER LESSEQUAL GREATEREQUAL

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
%token <the_ast> GREATEREQUAL DOUBLESLASH IN IF HEIGHT WIDTH MAJOR_AXIS
%token <the_ast> MINOR_AXIS THICKNESS

%type <the_ast> canvas_declaration color_declaration star_NEWLINE_stmt statement
%type <the_ast> shape_assignment rectangle_declaration shape point_declaration
%type <the_ast> pick_NEWLINE_stmt ellipse_declaration line_declaration
%type <the_ast> to_declaration from_declaration for_loop expression
%type <the_ast> expression_assignment if_stmt expression_list
%type <the_ast> rectangle_parameter rectangle_parameters height_declaration
%type <the_ast> width_declaration major_axis_declaration minor_axis_declaration
%type <the_ast> ellipse_parameters ellipse_parameter thickness_declartaion
%type <the_ast> canvas_parameter canvas_parameters

%%

program
  : canvas_declaration LBRACE star_NEWLINE_stmt RBRACE {
    tree_id = 0;
    $1 = add_child($1, $3);
    head = $1;
    return ENDMARKER;
  }
  | expression
  ;

canvas_declaration
  : CANVAS LPAR canvas_parameters RPAR {
    $$ = init_ast(NULL, IN_CANVAS_DECLARATION);
    $$ = add_child($$, $3);
  }
  ;

canvas_parameters
  : canvas_parameters COMMA canvas_parameter {
    $$ = init_ast(NULL, IN_CANVAS_PARAMETERS);
    $$ = add_child($$, $1);
    $$ = add_child($$, $3);
  }
  | canvas_parameter
  ;

canvas_parameter
  : height_declaration
  | width_declaration
  | color_declaration
  | STRING
  ;

color_declaration
  : COLOR LPAR expression COMMA expression COMMA expression RPAR {
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
  | NEWLINE { $$ = NULL; }
  ;

pick_NEWLINE_stmt
  : statement {
    $$ = init_ast(NULL, IN_PICK_NEWLINE_STMT);
    $$ = add_child($$, $1);
  }
  | NEWLINE { $$ = NULL; }
  ;

statement
  : shape_assignment
  | for_loop
  | COMMENT
  | expression_assignment
  | if_stmt
  ;

if_stmt
  : IF LPAR expression RPAR LBRACE star_NEWLINE_stmt RBRACE {
    $$ = init_ast(NULL, IN_IF_STMT);
    $$ = add_child($$, $3);
    $$ = add_child($$, $6);
  }
  ;

for_loop
  : FOR NAME IN RANGE LPAR expression RPAR LBRACE star_NEWLINE_stmt RBRACE {
    $$ = init_ast(NULL, IN_FOR_LOOP);
    $$ = add_child($$, $2);
    $$ = add_child($$, $6);
    $$ = add_child($$, $9);
  }
  | FOR NAME IN RANGE LPAR expression COMMA expression RPAR LBRACE star_NEWLINE_stmt RBRACE {
    $$ = init_ast(NULL, IN_FOR_LOOP);
    $$ = add_child($$, $2);
    $$ = add_child($$, $6);
    $$ = add_child($$, $8);
    $$ = add_child($$, $11);
  }
  ;

expression_assignment
  : NAME EQUAL expression {
    $$ = init_ast(NULL, IN_EXPRESSION_ASSIGNMENT);
    $$ = add_child($$, $1);
    $$ = add_child($$, $2);
    $$ = add_child($$, $3);
  }
  ;

expression_list
  : expression
  | expression_list COMMA expression {
    $$ = init_ast(NULL, IN_EXPRESSION_LIST);
    $$ = add_child($$, $1);
    $$ = add_child($$, $3);
  }
  ;

expression : DOUBLE
           | INTEGER
           | NAME
           | STRING
           | NAME LSQB expression RSQB {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
             $$ = add_child($$, $4);
           }
           | LSQB RSQB {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
           }
           | LSQB expression_list RSQB {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
           }
           | TRUE
           | FALSE
           | expression PLUS expression {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
           }
           | expression MINUS expression {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
           }
           | expression STAR expression {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
           }
           | expression SLASH expression {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
           }
           | expression PERCENT expression {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
           }
           | expression LESS expression {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
           }
           | expression GREATER expression {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
           }
           | expression LESSEQUAL expression {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
           }
           | expression GREATEREQUAL expression {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
             $$ = add_child($$, $3);
           }
           | MINUS expression {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $1);
             $$ = add_child($$, $2);
           }
           | LPAR expression RPAR {
             $$ = init_ast(NULL, IN_EXPRESSION);
             $$ = add_child($$, $2);
           }
           ;

shape_assignment
  : NAME EQUAL shape {
    $$ = init_ast(NULL, IN_SHAPE_ASSIGNMENT);
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
  | color_declaration
  ;

rectangle_declaration
  : RECTANGLE LPAR rectangle_parameters RPAR {
    $$ = init_ast(NULL, IN_RECTANGLE_DECLARATION);
    $$ = add_child($$, $3);
  }
  ;

rectangle_parameters
  : rectangle_parameters COMMA rectangle_parameter {
    $$ = init_ast(NULL, IN_RECTANGLE_PARAMETERS);
    $$ = add_child($$, $1);
    $$ = add_child($$, $3);
  }
  | rectangle_parameter
  ;

rectangle_parameter
  : color_declaration
  | point_declaration
  | height_declaration
  | width_declaration
  | thickness_declartaion
  ;

height_declaration
  : HEIGHT LPAR expression RPAR {
    $$ = init_ast(NULL, IN_HEIGHT_DECLARATION);
    $$ = add_child($$, $3);
  }
  ;

width_declaration
  : WIDTH LPAR expression RPAR {
    $$ = init_ast(NULL, IN_WIDTH_DECLARATION);
    $$ = add_child($$, $3);
  }
  ;

ellipse_declaration
  : ELLIPSE LPAR ellipse_parameters RPAR {
    $$ = init_ast(NULL, IN_ELLIPSE_DECLARATION);
    $$ = add_child($$, $3);
  }
  ;

ellipse_parameters
  : ellipse_parameters COMMA ellipse_parameter {
    $$ = init_ast(NULL, IN_ELLIPSE_PARAMETERS);
    $$ = add_child($$, $1);
    $$ = add_child($$, $3);
  }
  | ellipse_parameter
  ;

ellipse_parameter
  : color_declaration
  | point_declaration
  | major_axis_declaration
  | minor_axis_declaration
  | thickness_declartaion
  ;

minor_axis_declaration
  : MINOR_AXIS LPAR expression RPAR {
    $$ = init_ast(NULL, IN_MAJOR_AXIS_DECLARATION);
    $$ = add_child($$, $3);
  }
  ;

major_axis_declaration
  : MAJOR_AXIS LPAR expression RPAR {
    $$ = init_ast(NULL, IN_MINOR_AXIS_DECLARATION);
    $$ = add_child($$, $3);
  }
  ;

thickness_declartaion
  : THICKNESS LPAR expression RPAR {
    $$ = init_ast(NULL, IN_THICKNESS_DECLARATION);
    $$ = add_child($$, $3);
  }
  ;

point_declaration
  : POINT LPAR expression COMMA expression RPAR {
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
  | TO LPAR expression RPAR {
    $$ = init_ast(NULL, IN_TO_DECLARATION);
    $$ = add_child($$, $3);
  }
  ;

from_declaration
  : FROM LPAR shape RPAR {
    $$ = init_ast(NULL, IN_FROM_DECLARATION);
    $$ = add_child($$, $3);
  }
  | FROM LPAR expression RPAR {
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
