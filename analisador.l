%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%{
    #include "parser.h"
    #include <stdio.h>

    void process_token(const char* tk){
        printf("%d: %s -> %s\n", yylineno, yytext, tk);
    }
%}

INT_NUMBER      [0-9]+
REAL_NUMBER     [0-9]+"."[0-9]+
LETTER          [a-zA-Z]
ID              [a-zA-Z_][a-zA-Z0-9_]*
STRING          \"[^"]*\"
COMMENT_FULL    \/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/
COMMENT_LINE    \/\/.*
IGNORE          [ \t\n]+

%%

{IGNORE}            {  }
{COMMENT_LINE}      {  }
{COMMENT_FULL}      {  }


"++"                { return INCREMENT; }
"--"                { return DECREMENT; } 
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return TIMES; }
"/"                 { return OVER; }   

">"                 { return GREATER_THAN; }
"<"                 { return LESS_THAN; }
">="                { return GREATER_THAN_OR_EQUAL; }
"<="                { return LESS_THAN_OR_EQUAL; }
"=="                { return EQUALS; }
"!="                { return NOT_EQUALS; }

"+="                { return ADD_ASSIGN; }
"-="                { return SUB_ASSIGN; }
"*="                { return MUL_ASSIGN; }
"/="                { return DIV_ASSIGN; }
"%="                { return MOD_ASSIGN; }

"="                 { return ASSIGNMENT; }

"&&"                { return LOGICAL_AND; }
"&"                 { return ADDRESS; }
"||"                { return LOGICAL_OR; }
"!"                 { return LOGICAL_NOT; }

"("                 { return OPEN_PARENTHESES; }
")"                 { return CLOSE_PARENTHESES; }
"["                 { return OPEN_BRACKET; }
"]"                 { return CLOSE_BRACKET; }
"{"                 { return OPEN_KEYS; }
"}"                 { return CLOSE_KEYS; }

"."                 { return DOT; }
";"                 { return SEMICOLON; }
","                 { return COMMA; }

auto                { return AUTO; }
break               { return BREAK; }
char                { return CHAR; }
const               { return CONST; }
continue            { return CONTINUE; }
double              { return DOUBLE; }
else                { return ELSE; }
enum                { return ENUM; }
extern              { return EXTERN; }
float               { return FLOAT; }
while               { return WHILE; }
if                  { return IF; }
int                 { return INT; }
long                { return LONG; }
register            { return REGISTER; }
return              { return RETURN; }
short               { return SHORT; }
signed              { return SIGNED; }
sizeof              { return SIZEOF; }
static              { return STATIC; }
struct              { return STRUCT; }
typedef             { return TYPEDEF; }
union               { return UNION; }
unsigned            { return UNSIGNED; }
void                { return VOID; }
volatile            { return VOLATILE; }

{STRING}        { return STRING; }
{ID}            { return ID; }
{INT_NUMBER}    { return INT_NUMBER; }
{REAL_NUMBER}   { return REAL_NUMBER; }

.                { printf("LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext);
                exit(EXIT_FAILURE); }

%%