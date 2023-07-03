%option nounput noinput noyywrap yylineno

%{
#include "parser.tab.h"
#include "language/include/ast.h"

token yytoken = NULL;

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
"False"                { return allocate_ast(FALSE); }
"True"                 { return allocate_ast(TRUE); }
"break"                { return allocate_ast(BREAK); }
"for"                  { return allocate_ast(FOR); }
"canvas"               { return allocate_ast(CANVAS); }
"color"                { return allocate_ast(COLOR); }
"rectangle"            { return allocate_ast(RECTANGLE); }
"circle"               { return allocate_ast(CIRCLE); }
"ellipse"              { return allocate_ast(ELLIPSE); }
"square"               { return allocate_ast(SQUARE); }
"line"                 { return allocate_ast(LINE); }
"to"                   { return allocate_ast(TO); }
"from"                 { return allocate_ast(FROM); }
"point"                { return allocate_ast(POINT); }
"range"                { return allocate_ast(RANGE); }
"append"               { return allocate_ast(APPEND); }
"north"                { return allocate_ast(NORTH); }
"east"                 { return allocate_ast(EAST); }
"south"                { return allocate_ast(SOUTH); }
"west"                 { return allocate_ast(WEST); }
"write"                { return allocate_ast(WRITE); }

[A-Za-z_][A-Za-z0-9_]* { return allocate_ast(NAME); }

[0-9][0-9_]+                     |
[0-9][0-9_]+(e|E)[-+]?[0-9]*     { return allocate_ast(INTEGER); }

[0-9][0-9_]*"."?                 |
[0-9][0-9_]*"."?(e|E)[-+]?[0-9]* |
"."[0-9]+                        |
"."[0-9]+(e|E)[-+]?[0-9]*        |
[0-9][0-9_]*"."[0-9]+            |
[0-9][0-9_]*"."[0-9]+(e|E)[-+]?[0-9]* { return allocate_ast(DOUBLE); }

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
  yytoken = init_token(category, yytext, yylineno);
  yylval.the_ast = init_ast(init_token(category, yytext, yylineno), category);
  free_ast(yylval.the_ast);
  return category;
}

void print_unmatched_quote(char * literal, int line_no) {
  fprintf(stderr, "[LEXER]: Unmatched quote: `%s` on line %d\n", literal,
    line_no);
}
