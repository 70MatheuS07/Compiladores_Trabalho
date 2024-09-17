%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%option yylineno
%{
    //#define DEBUG_MODE
    #include <string.h>
    #include <stdlib.h>
    #include "types.h"
    #include "ast.h"
    #include "parser.h"
    #include "tables.h"
    extern StrTable *st;
    extern char * VarSave;

    #ifdef DEBUG_MODE
        #define DEBUG_PRINT(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
    #else
        #define DEBUG_PRINT(fmt, ...)
    #endif
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

{IGNORE}            { /* Ignora espaços, tabs e novas linhas */ }
{COMMENT_LINE}      { /* Ignora comentários de linha */ }
{COMMENT_FULL}      { /* Ignora comentários de bloco */ }

"++"                { DEBUG_PRINT("Token: '++'\n"); return INCREMENT; }
"--"                { DEBUG_PRINT("Token: '--'\n"); return DECREMENT; }
"+"                 { DEBUG_PRINT("Token: '+'\n"); return PLUS; }
"-"                 { DEBUG_PRINT("Token: '-'\n"); return MINUS; }
"*"                 { DEBUG_PRINT("Token: '*'\n"); return TIMES; }
"/"                 { DEBUG_PRINT("Token: '/'\n"); return OVER; }
"%"                 { DEBUG_PRINT("Token: '%'\n"); return PERCENT; }

">"                 { DEBUG_PRINT("Token: '>'\n"); return GREATER_THAN; }
"<"                 { DEBUG_PRINT("Token: '<'\n"); return LESS_THAN; }
">="                { DEBUG_PRINT("Token: '>='\n"); return GREATER_THAN_OR_EQUAL; }
"<="                { DEBUG_PRINT("Token: '<='\n"); return LESS_THAN_OR_EQUAL; }
"=="                { DEBUG_PRINT("Token: '=='\n"); return EQUALS; }
"!="                { DEBUG_PRINT("Token: '!='\n"); return NOT_EQUALS; }

"+="                { DEBUG_PRINT("Token: '+='\n"); return ADD_ASSIGN; }
"-="                { DEBUG_PRINT("Token: '-='\n"); return SUB_ASSIGN; }
"*="                { DEBUG_PRINT("Token: '*='\n"); return MUL_ASSIGN; }
"/="                { DEBUG_PRINT("Token: '/='\n"); return DIV_ASSIGN; }
"%="                { DEBUG_PRINT("Token: '%='\n"); return MOD_ASSIGN; }

"="                 { DEBUG_PRINT("Token: '='\n"); return ASSIGNMENT; }

"&&"                { DEBUG_PRINT("Token: '&&'\n"); return LOGICAL_AND; }
"&"                 { DEBUG_PRINT("Token: '&'\n"); return ADDRESS; }
"||"                { DEBUG_PRINT("Token: '||'\n"); return LOGICAL_OR; }
"!"                 { DEBUG_PRINT("Token: '!'\n"); return LOGICAL_NOT; }

"("                 { DEBUG_PRINT("Token: '(' \n"); return OPEN_PARENTHESES; }
")"                 { DEBUG_PRINT("Token: ')'\n"); return CLOSE_PARENTHESES; }
"["                 { DEBUG_PRINT("Token: '['\n"); return OPEN_BRACKET; }
"]"                 { DEBUG_PRINT("Token: ']'\n"); return CLOSE_BRACKET; }
"{"                 { DEBUG_PRINT("Token: '{'\n"); return OPEN_KEYS; }
"}"                 { DEBUG_PRINT("Token: '}'\n"); return CLOSE_KEYS; }

";"                 { DEBUG_PRINT("Token: ';'\n"); return SEMICOLON; }
","                 { DEBUG_PRINT("Token: ','\n"); return COMMA; }

char                { DEBUG_PRINT("Token: 'char'\n"); return CHAR; }
continue            { DEBUG_PRINT("Token: 'continue'\n"); return CONTINUE; }
else                { DEBUG_PRINT("Token: 'else'\n"); return ELSE; }
float               { DEBUG_PRINT("Token: 'float'\n"); return FLOAT; }
while               { DEBUG_PRINT("Token: 'while'\n"); return WHILE; }
if                  { DEBUG_PRINT("Token: 'if'\n"); return IF; }
int                 { DEBUG_PRINT("Token: 'int'\n"); return INT; }
return              { DEBUG_PRINT("Token: 'return'\n"); return RETURN; }
void                { DEBUG_PRINT("Token: 'void'\n"); return VOID; }
scanf               { DEBUG_PRINT("Token: 'scanf'\n"); return SCANF; } 
printf              { DEBUG_PRINT("Token: 'printf'\n"); return PRINTF; } 

{CHAR}          {yylval = new_node(CHAR_VAL_NODE, (int)yytext[1], 0,CHAR_TYPE, 0); 
                  DEBUG_PRINT("Token: CHAR_ASCII, Value: %c\n", (char) yytext[1]); 
                  return CHAR_ASCII; }

{STRING}        { yylval = new_node(STR_VAL_NODE, add_string(st, yytext), 0, NO_TYPE, 0); 
                  DEBUG_PRINT("Token: STRING, Value: %s\n", yytext); return STRING;}

{ID}            { strcpy(VarSave, yytext); DEBUG_PRINT("Token: ID, Value: %s\n", yytext); return ID; }

{INT_NUMBER}    { yylval = new_node(INT_VAL_NODE, atoi(yytext),0 ,INT_TYPE, 0); 
                  DEBUG_PRINT("Token: INT_NUMBER, Value: %d\n", atoi(yytext)); 
                  return INT_NUMBER; }

{REAL_NUMBER}   { yylval = new_node(REAL_VAL_NODE, 0, 0,FLOAT_TYPE, 0);
                  set_float_data(yylval, (float) atof(yytext)); 
                  DEBUG_PRINT("Token: REAL_NUMBER, Value: %f\n", atof(yytext)); 
                  return REAL_NUMBER; }

.                { printf("LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext); exit(EXIT_FAILURE); }

%%
