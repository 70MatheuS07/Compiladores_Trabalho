%output "parser.c"
%defines "parser.h"
%define parse.error verbose
%define parse.lac full
%{

#include <stdio.h>


int yylex(void);
void yyerror(const char *s);
%}

%token INCREMENT DECREMENT PLUS MINUS TIMES OVER
%token GREATER_THAN LESS_THAN GREATER_THAN_OR_EQUAL LESS_THAN_OR_EQUAL EQUALS NOT_EQUALS
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token ASSIGNMENT LOGICAL_AND ADDRESS LOGICAL_OR LOGICAL_NOT
%token OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_BRACKET CLOSE_BRACKET OPEN_KEYS CLOSE_KEYS
%token DOT SEMICOLON COMMA
%token AUTO BREAK CHAR CONST CONTINUE DOUBLE ELSE ENUM EXTERN FLOAT
%token WHILE IF INT LONG REGISTER RETURN SHORT SIGNED SIZEOF STATIC
%token STRUCT TYPEDEF UNION UNSIGNED VOID VOLATILE
%token STRING ID INT_NUMBER REAL_NUMBER

%start start

%%

start: INT ID OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_KEYS content CLOSE_KEYS ;

content:
    var_decl
    | posfix_op
    | content
    | return
    ;

var_decl:
    type ID ASSIGNMENT expr SEMICOLON
    | type ID ASSIGNMENT SEMICOLON
    ;

posfix_op:
    ID INCREMENT
    | ID DECREMENT
    ;

type:
    INT
    | FLOAT
    | DOUBLE
    | CHAR
    ;

expr:
expr NOT_EQUALS expr
    | expr LESS_THAN_OR_EQUAL expr
    | expr GREATER_THAN_OR_EQUAL expr
    | expr LESS_THAN expr
    | expr GREATER_THAN expr
    | expr EQUALS expr
    | expr PLUS expr
    | expr MINUS expr
    | expr TIMES expr
    | expr OVER expr
    | OPEN_PARENTHESES expr CLOSE_PARENTHESES
    | INT_NUMBER
    | REAL_NUMBER
    | STRING
    | ID
    ;

return:
    RETURN INT
    | RETURN
    ;

%%

int main(void) {
    if (yyparse() == 0) {
        printf("PARSE SUCCESSFUL!\n");
    } else {
        printf("PARSE FAILED!\n");
    }
    return 0;
}