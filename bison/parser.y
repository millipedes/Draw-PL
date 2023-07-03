%{
#include "language/include/ast.h"

extern int yylex();
extern char * yytext;
ast * head;

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

%token <ast> STRING ENDMARKER NEWLINE COMMENT FALSE TRUE BREAK FOR CANVAS COLOR
%token <ast> RECTANGLE CIRCLE ELLIPSE SQUARE LINE TO FROM POINT RANGE APPEND
%token <ast> NORTH EAST SOUTH WEST WRITE NAME INTEGER DOUBLE LPAR RPAR LSQB RSQB
%token <ast> COMMA PLUS MINUS STAR SLASH VBAR AMPER LESS GREATER EQUAL PERCENT
%token <ast> LBRACE RBRACE EQEQUAL NOTEQUAL LESSEQUAL GREATEREQUAL DOUBLESLASH

%%

start
  :  { return ENDMARKER; }
  ;

%%

int yyerror(char * s) {
  fprintf(stderr, "Error: `%s`\n", s);
  exit(1);
}

char * category_to_string(int category) {
  switch(category) {
    case STRING:       return "string";
    case ENDMARKER:    return "endmarker";
    case NEWLINE:      return "newline";
    case COMMENT:      return "comment";
    case FALSE:        return "false";
    case TRUE:         return "true";
    case BREAK:        return "break";
    case FOR:          return "for";
    case CANVAS:       return "canvas";
    case COLOR:        return "color";
    case RECTANGLE:    return "rectangle";
    case CIRCLE:       return "circle";
    case ELLIPSE:      return "ellipse";
    case SQUARE:       return "square";
    case LINE:         return "line";
    case TO:           return "to";
    case FROM:         return "from";
    case POINT:        return "point";
    case RANGE:        return "range";
    case APPEND:       return "append";
    case NORTH:        return "north";
    case EAST:         return "east";
    case SOUTH:        return "south";
    case WEST:         return "west";
    case WRITE:        return "write";
    case NAME:         return "name";
    case INTEGER:      return "integer";
    case DOUBLE:       return "double";
    case LPAR:         return "lpar";
    case RPAR:         return "rpar";
    case LSQB:         return "lsqb";
    case RSQB:         return "rsqb";
    case COMMA:        return "comma";
    case PLUS:         return "plus";
    case MINUS:        return "minus";
    case STAR:         return "star";
    case SLASH:        return "slash";
    case VBAR:         return "vbar";
    case AMPER:        return "amper";
    case LESS:         return "less";
    case GREATER:      return "greater";
    case EQUAL:        return "equal";
    case PERCENT:      return "percent";
    case LBRACE:       return "lbrace";
    case RBRACE:       return "rbrace";
    case EQEQUAL:      return "eqequal";
    case NOTEQUAL:     return "notequal";
    case LESSEQUAL:    return "lessequal";
    case GREATEREQUAL: return "greaterequal";
    case DOUBLESLASH:  return "doubleslash";
  }
  return NULL;
}
