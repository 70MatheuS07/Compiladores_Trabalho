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

%left PLUS MINUS
%left TIMES OVER
%nonassoc LESS_THAN EQUALS GREATER_THAN
%right ASSIGNMENT

%start initial

%%

initial
	: pre_program program
	;

pre_program
	: struct_declaration
	| struct_declaration pre_program
	| typedef_struct_declaration
	| typedef_struct_declaration pre_program
	;

struct_declaration
	: STRUCT ID OPEN_KEYS struct_declaration_list CLOSE_KEYS SEMICOLON
	;

typedef_struct_declaration
	: TYPEDEF STRUCT ID OPEN_KEYS struct_declaration_list CLOSE_KEYS ID SEMICOLON
	;

program
	: INT ID OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_KEYS content CLOSE_KEYS
	;

content
	: ID ID SEMICOLON
	| ID ID SEMICOLON content
	| type_specifier ID SEMICOLON
	| type_specifier ID SEMICOLON content
	| type_specifier string SEMICOLON
	| type_specifier string SEMICOLON content
	| ID DOT ID ASSIGNMENT initializer SEMICOLON
	| ID DOT ID ASSIGNMENT initializer SEMICOLON content
	| ID DOT string ASSIGNMENT initializer SEMICOLON
	| ID DOT string ASSIGNMENT initializer SEMICOLON content
	| RETURN INT_NUMBER SEMICOLON
	;

string
	: ID OPEN_BRACKET INT_NUMBER CLOSE_BRACKET
	| ID OPEN_BRACKET CLOSE_BRACKET
	| ID OPEN_BRACKET ID CLOSE_BRACKET
	;

initializer
	: INT_NUMBER
	| REAL_NUMBER
	| STRING
	;

struct_declaration_list
	: type_specifier ID SEMICOLON
	| type_specifier ID SEMICOLON struct_declaration_list
	| type_specifier string SEMICOLON
	| type_specifier string SEMICOLON struct_declaration_list
	;

unary_operator
	: ADDRESS
	| TIMES
	| PLUS
	| MINUS
	| LOGICAL_NOT
	;

assignment_operator
	: ASSIGNMENT
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	;

type_qualifier
	: CONST
	| VOLATILE
	;

jump_statement
    : CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

expression
    : STRING
    | INT
    ;

expression_statement
	: SEMICOLON
	| expression SEMICOLON
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