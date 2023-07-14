%option nounput noinput noyywrap yylineno

%{
#include "parser.tab.h"
#include "language/include/ast.h"

#define IS_UNNECESSARY_TOK(t) ((t == COMMA)        \
                              || (t == LPAR)       \
                              || (t == RPAR)       \
                              || (t == LBRACE)     \
                              || (t == RBRACE)     \
                              || (t == CANVAS)     \
                              || (t == COLOR)      \
                              || (t == RECTANGLE)  \
                              || (t == LINE)       \
                              || (t == FROM)       \
                              || (t == TO)         \
                              || (t == IN)         \
                              || (t == FOR)        \
                              || (t == IF)         \
                              || (t == RANGE)      \
                              || (t == THICKNESS)  \
                              || (t == MAJOR_AXIS) \
                              || (t == MINOR_AXIS) \
                              || (t == NEWLINE)    \
                              || (t == HEIGHT)     \
                              || (t == WIDTH)      \
                              || (t == ELLIPSE)    \
                              || (t == POINT))

int allocate_ast(int category);
void print_unmatched_quote(char * literal, int line_no);
%}
%%

'(\\.|''|[^'\n])*'        |
\"(\\.|\"\"|[^\"\n])*\"   { return allocate_ast(STRING); }

'(\\.|''|[^'\n])*[\n]     |
\"(\\.|\"\"|[^\"\n])*[\n] { print_unmatched_quote(yytext, yylineno); }

<<EOF>>                   { return allocate_ast(ENDMARKER); }
\\[\n][ \t]*

[\n\v\f\r]+               { return allocate_ast(NEWLINE); }

[ \t]

#.*                    { return allocate_ast(COMMENT); }
"append"               { return allocate_ast(APPEND); }
"break"                { return allocate_ast(BREAK); }
"color"                { return allocate_ast(COLOR); }
"east"                 { return allocate_ast(EAST); }
"for"                  { return allocate_ast(FOR); }
"height"               { return allocate_ast(HEIGHT); }
"width"                { return allocate_ast(WIDTH); }
"if"                   { return allocate_ast(IF); }
"in"                   { return allocate_ast(IN); }
"line"                 { return allocate_ast(LINE); }
"to"                   { return allocate_ast(TO); }
"true"                 { return allocate_ast(TRUE); }
"from"                 { return allocate_ast(FROM); }
"west"                 { return allocate_ast(WEST); }
"false"                { return allocate_ast(FALSE); }
"point"                { return allocate_ast(POINT); }
"south"                { return allocate_ast(SOUTH); }
"write"                { return allocate_ast(WRITE); }
"range"                { return allocate_ast(RANGE); }
"north"                { return allocate_ast(NORTH); }
"minor_axis"           { return allocate_ast(MINOR_AXIS); }
"major_axis"           { return allocate_ast(MAJOR_AXIS); }
"canvas"               { return allocate_ast(CANVAS); }
"circle"               { return allocate_ast(CIRCLE); }
"square"               { return allocate_ast(SQUARE); }
"ellipse"              { return allocate_ast(ELLIPSE); }
"rectangle"            { return allocate_ast(RECTANGLE); }
"thickness"            { return allocate_ast(THICKNESS); }

[A-Za-z_][A-Za-z0-9_]* { return allocate_ast(NAME); }

[0-9_]+                     |
[0-9_]+(e|E)[-+]?[0-9]*     { return allocate_ast(INTEGER); }

"."[0-9]+                        |
"."[0-9]+(e|E)[-+]?[0-9]*        |
[0-9]+"."[0-9]+            |
[0-9]+"."[0-9]+(e|E)[-+]?[0-9]* { return allocate_ast(DOUBLE); }

"("                             { return allocate_ast(LPAR); }
")"                             { return allocate_ast(RPAR); }
"["                             { return allocate_ast(LSQB); }
"]"                             { return allocate_ast(RSQB); }
","                             { return allocate_ast(COMMA); }
"+"                             { return allocate_ast(PLUS); }
"-"                             { return allocate_ast(MINUS); }
"*"                             { return allocate_ast(STAR); }
"/"                             { return allocate_ast(SLASH); }
"|"                             { return allocate_ast(VBAR); }
"&"                             { return allocate_ast(AMPER); }
"<"                             { return allocate_ast(LESS); }
">"                             { return allocate_ast(GREATER); }
"="                             { return allocate_ast(EQUAL); }
"%"                             { return allocate_ast(PERCENT); }
"{"                             { return allocate_ast(LBRACE); }
"}"                             { return allocate_ast(RBRACE); }
"=="                            { return allocate_ast(EQEQUAL); }
"!="                            { return allocate_ast(NOTEQUAL); }
"<="                            { return allocate_ast(LESSEQUAL); }
">="                            { return allocate_ast(GREATEREQUAL); }
"//"                            { return allocate_ast(DOUBLESLASH); }
%%

int allocate_ast(int category) {
  if(!IS_UNNECESSARY_TOK(category))
    yylval.the_ast = init_ast(init_token(category, yytext, yylineno), category);
  else
    yylval.the_ast = NULL;
  return category;
}

void print_unmatched_quote(char * literal, int line_no) {
  fprintf(stderr, "[LEXER]: Unmatched quote: `%s` on line %d\n", literal,
    line_no);
}
