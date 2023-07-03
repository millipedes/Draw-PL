%option nounput noinput noyywrap yylineno

%{
#include "parser.tab.h"
#include "language/include/ast.h"

#define IS_UNNECESSARY_TOK(t) ((t == COMMA)       \
                              || (t == LPAR)      \
                              || (t == RPAR)      \
                              || (t == LBRACE)    \
                              || (t == RBRACE)    \
                              || (t == CANVAS)    \
                              || (t == COLOR)     \
                              || (t == RECTANGLE) \
                              || (t == LINE)      \
                              || (t == FROM)      \
                              || (t == TO)        \
                              || (t == IN)        \
                              || (t == FOR)       \
                              || (t == RANGE)     \
                              || (t == ELLIPSE)   \
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
"in"                   { return allocate_ast(IN); }
"to"                   { return allocate_ast(TO); }
"for"                  { return allocate_ast(FOR); }
"true"                 { return allocate_ast(TRUE); }
"line"                 { return allocate_ast(LINE); }
"from"                 { return allocate_ast(FROM); }
"east"                 { return allocate_ast(EAST); }
"west"                 { return allocate_ast(WEST); }
"color"                { return allocate_ast(COLOR); }
"false"                { return allocate_ast(FALSE); }
"break"                { return allocate_ast(BREAK); }
"point"                { return allocate_ast(POINT); }
"south"                { return allocate_ast(SOUTH); }
"write"                { return allocate_ast(WRITE); }
"range"                { return allocate_ast(RANGE); }
"north"                { return allocate_ast(NORTH); }
"canvas"               { return allocate_ast(CANVAS); }
"circle"               { return allocate_ast(CIRCLE); }
"square"               { return allocate_ast(SQUARE); }
"append"               { return allocate_ast(APPEND); }
"ellipse"              { return allocate_ast(ELLIPSE); }
"rectangle"            { return allocate_ast(RECTANGLE); }

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
