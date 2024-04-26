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

%%

statement
	: expression_statement
	| iteration_statement
	| jump_statement
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
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

struct_or_union
	: STRUCT
	| UNION
	;

type_qualifier
	: CONST
	| VOLATILE
	;

jump_statement
    :
	| CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

iteration_statement
	: WHILE OPEN_PARENTHESES expression CLOSE_PARENTHESES statement
	;

expression
    :
    | STRING
    | INT
    ;

expression_statement
	: ';'
	| expression ';'
	;

declaration
	: declaration_specifiers ';'
	;