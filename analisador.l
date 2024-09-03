%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%option yylineno
%{
    #include "debug.h"
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

{IGNORE}            { /* Ignora espaços, tabs e novas linhas */ }
{COMMENT_LINE}      { /* Ignora comentários de linha */ }
{COMMENT_FULL}      { /* Ignora comentários de bloco */ }

"++"                { DEBUG_PRINT("Token: '++'"); return INCREMENT; }
"--"                { DEBUG_PRINT("Token: '--'"); return DECREMENT; }
"+"                 { DEBUG_PRINT("Token: '+'"); return PLUS; }
"-"                 { DEBUG_PRINT("Token: '-'"); return MINUS; }
"*"                 { DEBUG_PRINT("Token: '*'"); return TIMES; }
"/"                 { DEBUG_PRINT("Token: '/'"); return OVER; }
"%"                 { DEBUG_PRINT("Token: '%'"); return PERCENT; }

">"                 { DEBUG_PRINT("Token: '>'"); return GREATER_THAN; }
"<"                 { DEBUG_PRINT("Token: '<'"); return LESS_THAN; }
">="                { DEBUG_PRINT("Token: '>='"); return GREATER_THAN_OR_EQUAL; }
"<="                { DEBUG_PRINT("Token: '<='"); return LESS_THAN_OR_EQUAL; }
"=="                { DEBUG_PRINT("Token: '=='"); return EQUALS; }
"!="                { DEBUG_PRINT("Token: '!='"); return NOT_EQUALS; }

"+="                { DEBUG_PRINT("Token: '+='"); return ADD_ASSIGN; }
"-="                { DEBUG_PRINT("Token: '-='"); return SUB_ASSIGN; }
"*="                { DEBUG_PRINT("Token: '*='"); return MUL_ASSIGN; }
"/="                { DEBUG_PRINT("Token: '/='"); return DIV_ASSIGN; }
"%="                { DEBUG_PRINT("Token: '%='"); return MOD_ASSIGN; }

"="                 { DEBUG_PRINT("Token: '='"); return ASSIGNMENT; }

"&&"                { DEBUG_PRINT("Token: '&&'"); return LOGICAL_AND; }
"&"                 { DEBUG_PRINT("Token: '&'"); return ADDRESS; }
"||"                { DEBUG_PRINT("Token: '||'"); return LOGICAL_OR; }
"!"                 { DEBUG_PRINT("Token: '!'"); return LOGICAL_NOT; }

"("                 { DEBUG_PRINT("Token: '('"); return OPEN_PARENTHESES; }
")"                 { DEBUG_PRINT("Token: ')'"); return CLOSE_PARENTHESES; }
"["                 { DEBUG_PRINT("Token: '['"); return OPEN_BRACKET; }
"]"                 { DEBUG_PRINT("Token: ']'"); return CLOSE_BRACKET; }
"{"                 { DEBUG_PRINT("Token: '{'"); return OPEN_KEYS; }
"}"                 { DEBUG_PRINT("Token: '}'"); return CLOSE_KEYS; }

";"                 { DEBUG_PRINT("Token: ';'"); return SEMICOLON; }
","                 { DEBUG_PRINT("Token: ','"); return COMMA; }

char                { DEBUG_PRINT("Token: 'char'"); return CHAR; }
continue            { DEBUG_PRINT("Token: 'continue'"); return CONTINUE; }
else                { DEBUG_PRINT("Token: 'else'"); return ELSE; }
float               { DEBUG_PRINT("Token: 'float'"); return FLOAT; }
while               { DEBUG_PRINT("Token: 'while'"); return WHILE; }
if                  { DEBUG_PRINT("Token: 'if'"); return IF; }
int                 { DEBUG_PRINT("Token: 'int'"); return INT; }
return              { DEBUG_PRINT("Token: 'return'"); return RETURN; }
void                { DEBUG_PRINT("Token: 'void'"); return VOID; }

{CHAR}          { yylval = new_node(CHAR_VAL_NODE, 0, CHAR_TYPE, 0);
                  set_char_data(yylval, (char) yytext[1]); 
                  DEBUG_PRINT("Token: CHAR_ASCII"); 
                  return CHAR_ASCII; }

{STRING}        { add_string(st, yytext); DEBUG_PRINT("Token: STRING"); return STRING; }

{ID}            { strcpy(VarSave, yytext); DEBUG_PRINT("Token: ID"); return ID; }

{INT_NUMBER}    { yylval = new_node(INT_VAL_NODE, atoi(yytext), INT_TYPE, 0); 
                  DEBUG_PRINT("Token: INT_NUMBER"); 
                  return INT_NUMBER; }

{REAL_NUMBER}   { yylval = new_node(REAL_VAL_NODE, 0, FLOAT_TYPE, 0);
                  set_float_data(yylval, (float) atof(yytext)); 
                  DEBUG_PRINT("Token: REAL_NUMBER"); 
                  return REAL_NUMBER; }

.                { printf("LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext); exit(EXIT_FAILURE); }

%%
