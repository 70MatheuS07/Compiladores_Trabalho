%output "parser.c"
%defines "parser.h"
%define parse.error verbose
%define parse.lac full
%{

#include <stdio.h>


int yylex(void);
void yyerror(const char *s);
%}

%token INCREMENT DECREMENT PLUS MINUS TIMES OVER PERCENT
%token GREATER_THAN LESS_THAN GREATER_THAN_OR_EQUAL LESS_THAN_OR_EQUAL EQUALS NOT_EQUALS
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token ASSIGNMENT LOGICAL_AND ADDRESS LOGICAL_OR LOGICAL_NOT
%token OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_BRACKET CLOSE_BRACKET OPEN_KEYS CLOSE_KEYS
%token DOT SEMICOLON COMMA
%token CHAR CONTINUE DOUBLE ELSE FLOAT
%token WHILE IF INT RETURN
%token VOID
%token STRING ID INT_NUMBER REAL_NUMBER

%left PLUS MINUS
%left TIMES OVER
%nonassoc LESS_THAN EQUALS GREATER_THAN
%right ASSIGNMENT

%start translation_unit

%%

primary_expression
	: ID
	| INT_NUMBER 
	| REAL_NUMBER
	| STRING
	| OPEN_PARENTHESES expression CLOSE_PARENTHESES
	;

postfix_expression
	: primary_expression
	| postfix_expression OPEN_BRACKET expression CLOSE_BRACKET
	| postfix_expression OPEN_PARENTHESES CLOSE_PARENTHESES
	| postfix_expression OPEN_PARENTHESES argument_expression_list CLOSE_PARENTHESES
	| postfix_expression DOT ID
	| postfix_expression INCREMENT
	| postfix_expression DECREMENT
	| OPEN_PARENTHESES type_name CLOSE_PARENTHESES OPEN_KEYS initializer_list CLOSE_KEYS
	| OPEN_PARENTHESES type_name CLOSE_PARENTHESES OPEN_KEYS initializer_list COMMA CLOSE_KEYS
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA assignment_expression
	;

unary_expression
	: postfix_expression
	| INCREMENT unary_expression
	| DECREMENT unary_expression
	| unary_operator cast_expression
	;

unary_operator
	: ADDRESS
	| TIMES
	| PLUS
	| MINUS
	| LOGICAL_NOT
	;

cast_expression
	: unary_expression
	| OPEN_PARENTHESES type_name CLOSE_PARENTHESES cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression TIMES cast_expression
	| multiplicative_expression OVER cast_expression
	| multiplicative_expression PERCENT cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression PLUS multiplicative_expression
	| additive_expression MINUS multiplicative_expression
	;

shift_expression
	: additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression LESS_THAN shift_expression
	| relational_expression GREATER_THAN shift_expression
	| relational_expression LESS_THAN_OR_EQUAL shift_expression
	| relational_expression GREATER_THAN_OR_EQUAL shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQUALS relational_expression
	| equality_expression NOT_EQUALS relational_expression
	;

and_expression
	: equality_expression
	| and_expression ADDRESS equality_expression
	;

exclusive_or_expression
	: and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression LOGICAL_AND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression LOGICAL_OR logical_and_expression
	;

conditional_expression
	: logical_or_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: ASSIGNMENT
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	;

expression
	: assignment_expression
	| expression COMMA assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers SEMICOLON
	| declaration_specifiers init_declarator_list SEMICOLON
	;

declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list COMMA init_declarator
	;

init_declarator
	: declarator
	| declarator ASSIGNMENT initializer
	;

type_specifier
	: VOID
	| CHAR
	| INT
	| FLOAT
	| DOUBLE
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: ID
	| OPEN_PARENTHESES declarator CLOSE_PARENTHESES
	| direct_declarator OPEN_BRACKET assignment_expression CLOSE_BRACKET
	| direct_declarator OPEN_BRACKET TIMES CLOSE_BRACKET
	| direct_declarator OPEN_BRACKET CLOSE_BRACKET
	| direct_declarator OPEN_PARENTHESES parameter_type_list CLOSE_PARENTHESES
	| direct_declarator OPEN_PARENTHESES identifier_list CLOSE_PARENTHESES
	| direct_declarator OPEN_PARENTHESES CLOSE_PARENTHESES
	;

pointer
	: TIMES
	| TIMES pointer
	;

parameter_type_list
	: parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list COMMA parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: ID
	| identifier_list COMMA ID
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: OPEN_PARENTHESES abstract_declarator CLOSE_PARENTHESES
	| OPEN_BRACKET CLOSE_BRACKET
	| OPEN_BRACKET assignment_expression CLOSE_BRACKET
	| direct_abstract_declarator OPEN_BRACKET CLOSE_BRACKET
	| direct_abstract_declarator OPEN_BRACKET assignment_expression CLOSE_BRACKET
	| OPEN_BRACKET TIMES CLOSE_BRACKET
	| direct_abstract_declarator OPEN_BRACKET TIMES CLOSE_BRACKET
	| OPEN_PARENTHESES CLOSE_PARENTHESES
	| OPEN_PARENTHESES parameter_type_list CLOSE_PARENTHESES
	| direct_abstract_declarator OPEN_PARENTHESES CLOSE_PARENTHESES
	| direct_abstract_declarator OPEN_PARENTHESES parameter_type_list CLOSE_PARENTHESES
	;

initializer
	: assignment_expression
	| OPEN_KEYS initializer_list CLOSE_KEYS
	| OPEN_KEYS initializer_list COMMA CLOSE_KEYS
	;

initializer_list
	: initializer
	| designation initializer
	| initializer_list COMMA initializer
	| initializer_list COMMA designation initializer
	;

designation
	: designator_list ASSIGNMENT
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: OPEN_BRACKET constant_expression CLOSE_BRACKET
	| DOT ID
	;

statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

compound_statement
	: OPEN_KEYS CLOSE_KEYS
	| OPEN_KEYS block_item_list CLOSE_KEYS
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: SEMICOLON
	| expression SEMICOLON
	;

selection_statement
	: IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement
	| IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement ELSE statement
	;

iteration_statement
	: WHILE OPEN_PARENTHESES expression CLOSE_PARENTHESES statement
	;

jump_statement
	: CONTINUE SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
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