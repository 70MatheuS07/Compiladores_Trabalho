%{
    #include <stdio.h>
%}

%option noyywrap

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
{COMMENT_LINE}                          { printf("%s -> COMMENT_LINE\n", yytext); }
{COMMENT_FULL}                          { printf("%s -> COMMENT_FULL\n", yytext); }


"++"                { printf("%s -> INCREMENT\n", yytext); }
"--"                { printf("%s -> DECREMENT\n", yytext); } 
"+"                 { printf("%s -> PLUS\n", yytext); }
"-"                 { printf("%s -> MINUS\n", yytext); }
"*"                 { printf("%s -> TIMES\n", yytext); }
"/"                 { printf("%s -> OVER\n", yytext); }   

">"                 { printf("%s -> GREATER_THAN\n", yytext); }
"<"                 { printf("%s -> LESS_THAN\n", yytext); }
">="                { printf("%s -> GREATER_THAN_OR_EQUAL\n", yytext); }
"<="                { printf("%s -> LESS_THAN_OR_EQUAL\n", yytext); }
"=="                { printf("%s -> EQUALS\n", yytext); }
"!="                { printf("%s -> NOT_EQUALS\n", yytext); }

"="                 { printf("%s -> ASSIGNMENT\n", yytext); }

"&&"                { printf("%s -> LOGICAL_AND\n", yytext); }
"&"                 { printf("%s -> ADRESS\n", yytext); }    
"||"                { printf("%s -> LOGICAL_OR\n", yytext); }
"!"                 { printf("%s -> LOGICAL_NOT\n", yytext); }

"("                 { printf("%s -> OPEN_PARENTHESES\n", yytext); }
")"                 { printf("%s -> CLOSE_PARENTHESES\n", yytext); }
"{"                 { printf("%s -> OPEN_KEYS\n", yytext); }
"}"                 { printf("%s -> CLOSE_KEYS\n", yytext); }

"."                 { printf("%s -> DOT\n", yytext); }
";"                 { printf("%s -> SEMICOLON\n", yytext); }
","                 { printf("%s -> COMMA\n", yytext); }

auto            { printf("%s -> AUTO\n", yytext); }
break           { printf("%s -> BREAK\n", yytext); }
char            { printf("%s -> CHAR\n", yytext); }
const           { printf("%s -> CONST\n", yytext); }
continue        { printf("%s -> CONTINUE\n", yytext); }
double          { printf("%s -> DOUBLE\n", yytext); }
else            { printf("%s -> ELSE\n", yytext); }
enum            { printf("%s -> ENUM\n", yytext); }
extern          { printf("%s -> EXTERN\n", yytext); }
float           { printf("%s -> FLOAT\n", yytext); }
for             { printf("%s -> FOR\n", yytext); }
if              { printf("%s -> IF\n", yytext); }
int             { printf("%s -> INT\n", yytext); }
long            { printf("%s -> LONG\n", yytext); }
register        { printf("%s -> REGISTER\n", yytext); }
return          { printf("%s -> RETURN\n", yytext); }
short           { printf("%s -> SHORT\n", yytext); }
signed          { printf("%s -> SIGNED\n", yytext); }
sizeof          { printf("%s -> SIZEOF\n", yytext); }
static          { printf("%s -> STATIC\n", yytext); }
struct          { printf("%s -> STRUCT\n", yytext); }
switch          { printf("%s -> SWITCH\n", yytext); }
typedef         { printf("%s -> TYPEDEF\n", yytext); }
union           { printf("%s -> UNION\n", yytext); }
unsigned        { printf("%s -> UNSIGNED\n", yytext); }
void            { printf("%s -> VOID\n", yytext); }
volatile        { printf("%s -> VOLATILE\n", yytext); }

{STRING}        { printf("%s -> STRING\n", yytext); }
{ID}            { printf("%s -> ID\n", yytext); }
{INT_NUMBER}    { printf("%s -> INT_NUMBER\n", yytext); }
{REAL_NUMBER}   { printf("%s -> REAL_NUMBER\n", yytext); }

.                { printf("LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext);
                exit(EXIT_FAILURE); }

%%

int main(){
    yylex();
    return 0;
}