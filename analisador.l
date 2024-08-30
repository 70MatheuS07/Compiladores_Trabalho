%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%option yylineno
%{
    #include <string.h>
    #include <stdlib.h>
    #include "types.h"
    #include "ast.h"
    #include "parser.h"
    #include "tables.h"
    extern StrTable *st;
    extern char * VarSave;
%}

INT_NUMBER      [0-9]+
REAL_NUMBER     [0-9]+"."[0-9]+
CHAR            \'[^']\'
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
"%"                 { return PERCENT; }

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


";"                 { return SEMICOLON; }
","                 { return COMMA; }

char                { return CHAR; }
continue            { return CONTINUE; }
else                { return ELSE; }
float               { return FLOAT; }
while               { return WHILE; }
if                  { return IF; }
int                 { return INT; }
return              { return RETURN; }
void                { return VOID; }

{CHAR}          { yylval = new_node(REAL_VAL_NODE, 0, REAL_TYPE);
                  set_char_data(yylval, (char) yytext[1]); 
                  return CHAR_ASCII;}
{STRING}        { add_string( st, yytext); return STRING; }
{ID}            { strcpy(VarSave, yytext); return ID; }
{INT_NUMBER}    { yylval = new_node(INT_VAL_NODE, atoi(yytext), INT_TYPE); 
                  return INT_NUMBER; }
{REAL_NUMBER}   { yylval = new_node(REAL_VAL_NODE, 0, REAL_TYPE);
                  set_float_data(yylval, (float) atof(yytext)); 
                  return REAL_NUMBER; }

.                { printf("LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext);
                exit(EXIT_FAILURE); }

%%