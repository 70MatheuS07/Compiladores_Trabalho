%{
    #include <stdio.h>
%}

%option noyywrap

DIGIT           [0-9]+
LETTER          [a-zA-Z]
ID              [a-zA-Z][a-zA-Z0-9]*
WHITESPACE      [ ]
ABERTURA        [(]
FECHAMENTO      [)]
COMENTARIO_I    [/*]
COMENTARIO_F    [*/]

%%

if              { printf("%s -> IF\n", yytext); }
else            { printf("%s -> ELSE\n", yytext); }
for             { printf("%s -> FOR\n", yytext); }
main            { printf("%s -> MAIN\n", yytext); }
#include        { printf("%s -> INCLUDE\n", yytext); }
printf          { printf("%s -> PRINTF\n", yytext); }
return          { printf("%s -> RETURN\n", yytext); }

{ABERTURA}                              { printf("%s -> OPEN_PARENTHESES\n", yytext); }
{FECHAMENTO}                            { printf("%s -> CLOSE_PARENTHESES\n", yytext); }
{COMENTARIO_I}+{LETTER}+{COMENTARIO_F} { printf("%s -> COMMENT\n", yytext); }
{DIGIT}+{ID}+                           { printf("%s -> ERRO\n", yytext); }
{WHITESPACE}                            { printf("%s -> WHITESPACE\n", yytext); }
{DIGIT}                                 { printf("%s -> DIGIT\n", yytext); }
{ID}                                    { printf("%s -> ID\n", yytext); }


"+"                 { printf("%s -> PLUS\n", yytext); }
"-"                 { printf("%s -> MINUS\n", yytext); }
"*"                 { printf("%s -> TIMES\n", yytext); }
"/"                 { printf("%s -> OVER\n", yytext); }
"++"                { printf("%s -> INCREMENT\n", yytext); }

">"                 { printf("%s -> GREATER_THAN\n", yytext); }
"<"                 { printf("%s -> LESS_THAN\n", yytext); }
">="                { printf("%s -> GREATER_THAN_OR_EQUAL\n", yytext); }
"<="                { printf("%s -> LESS_THAN_OR_EQUAL\n", yytext); }
"=="                { printf("%s -> EQUALS\n", yytext); }
"!="                { printf("%s -> NOT_EQUALS\n", yytext); }

"="                 { printf("%s -> ASSIGNMENT\n", yytext); }

"&&"                { printf("%s -> LOGICAL_AND\n", yytext); }
"||"                { printf("%s -> LOGICAL_OR\n", yytext); }
"!"                 { printf("%s -> LOGICAL_NOT\n", yytext); }

"{"                 { printf("%s -> OPEN_KEYS\n", yytext); }
"}"                 { printf("%s -> CLOSE_KEYS\n", yytext); }

"."                 { printf("%s -> DOT\n", yytext); }
";"                 { printf("%s -> SEMICOLON\n", yytext); }
","                 { printf("%s -> COMMA\n", yytext); }

[[:^space:]]+;

%%

int main(){
    yylex();
    return 0;
}