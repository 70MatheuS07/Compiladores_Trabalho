%output "parser.c"
%defines "parser.h"
%define parse.error verbose
%define parse.lac full
%{

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "types.h"
#include "tables.h"

int yylex(void);
void yyerror(const char *s);

int yylex_destroy(void);
void check_var();
void new_var();

extern int yylineno;
extern char *yytext;

StrTable *st;
VarTable *vt;
Type last_decl_type;
%}

%token INCREMENT DECREMENT PLUS MINUS TIMES OVER PERCENT
%token GREATER_THAN LESS_THAN GREATER_THAN_OR_EQUAL LESS_THAN_OR_EQUAL EQUALS NOT_EQUALS
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token ASSIGNMENT LOGICAL_AND ADDRESS LOGICAL_OR LOGICAL_NOT
%token OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_BRACKET CLOSE_BRACKET OPEN_KEYS CLOSE_KEYS
%token SEMICOLON COMMA
%token CHAR CONTINUE DOUBLE ELSE FLOAT
%token WHILE IF INT RETURN
%token VOID
%token STRING ID INT_NUMBER REAL_NUMBER

%left PLUS MINUS

%right ASSIGNMENT ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

%left LOGICAL_AND LOGICAL_OR ADDRESS
%left PERCENT OVER TIMES
%nonassoc EQUALS NOT_EQUALS 
%nonassoc GREATER_THAN_OR_EQUAL LESS_THAN_OR_EQUAL GREATER_THAN LESS_THAN
%precedence CLOSE_PARENTHESES
%precedence ELSE
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
	| ID  INCREMENT
	| ID  DECREMENT
	| OPEN_PARENTHESES type_name CLOSE_PARENTHESES OPEN_KEYS initializer_list CLOSE_KEYS
	| OPEN_PARENTHESES type_name CLOSE_PARENTHESES OPEN_KEYS initializer_list COMMA CLOSE_KEYS
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA assignment_expression
	;

unary_expression
	: postfix_expression
	| INCREMENT ID
	| DECREMENT ID
	| unary_operator cast_expression
	;

unary_operator
	: PLUS
	| MINUS
	| ADDRESS
	| LOGICAL_NOT
	;

cast_expression
	: unary_expression
	| OPEN_PARENTHESES type_name CLOSE_PARENTHESES cast_expression
	;

binary_expression
	: cast_expression
	| binary_expression TIMES cast_expression
	| binary_expression OVER cast_expression
	| binary_expression PERCENT cast_expression
	| binary_expression PLUS binary_expression
	| binary_expression MINUS binary_expression
	| binary_expression LESS_THAN binary_expression
	| binary_expression GREATER_THAN binary_expression
	| binary_expression LESS_THAN_OR_EQUAL binary_expression
	| binary_expression GREATER_THAN_OR_EQUAL binary_expression
	| binary_expression EQUALS binary_expression
	| binary_expression NOT_EQUALS binary_expression
	| binary_expression ADDRESS binary_expression
	| binary_expression LOGICAL_AND binary_expression
	| binary_expression LOGICAL_OR binary_expression
	;

assignment_expression
	: binary_expression
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
	: direct_declarator
	| direct_declarator ASSIGNMENT initializer
	;

type_specifier
	: VOID
	| CHAR		{last_decl_type = CHAR_TYPE;}
	| INT		{last_decl_type = INT_TYPE;}
	| FLOAT		{last_decl_type = FLOAT_TYPE;}
	| DOUBLE 	{last_decl_type = DOUBLE_TYPE;}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	;

direct_declarator
	: ID { new_var(); }
	| OPEN_PARENTHESES direct_declarator CLOSE_PARENTHESES
	| direct_declarator OPEN_BRACKET assignment_expression CLOSE_BRACKET
	| direct_declarator OPEN_BRACKET CLOSE_BRACKET
	| direct_declarator OPEN_PARENTHESES parameter_list CLOSE_PARENTHESES
	| direct_declarator OPEN_PARENTHESES identifier_list CLOSE_PARENTHESES
	| direct_declarator OPEN_PARENTHESES CLOSE_PARENTHESES
	;

parameter_list
	: parameter_declaration
	| parameter_list COMMA parameter_declaration
	;

parameter_declaration
	: declaration_specifiers direct_declarator
	| declaration_specifiers direct_abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: ID { new_var(); }
	| identifier_list COMMA ID { new_var(); }
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list direct_abstract_declarator
	;

direct_abstract_declarator
	: OPEN_PARENTHESES direct_abstract_declarator CLOSE_PARENTHESES
	| OPEN_BRACKET CLOSE_BRACKET
	| OPEN_BRACKET assignment_expression CLOSE_BRACKET
	| direct_abstract_declarator OPEN_BRACKET CLOSE_BRACKET
	| direct_abstract_declarator OPEN_BRACKET assignment_expression CLOSE_BRACKET
	| OPEN_PARENTHESES CLOSE_PARENTHESES
	| OPEN_PARENTHESES parameter_list CLOSE_PARENTHESES
	| direct_abstract_declarator OPEN_PARENTHESES CLOSE_PARENTHESES
	| direct_abstract_declarator OPEN_PARENTHESES parameter_list CLOSE_PARENTHESES
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
	: OPEN_BRACKET binary_expression CLOSE_BRACKET
	;

statement
	: compound_statement
	| SEMICOLON
	| expression SEMICOLON
	| selection_statement
	| WHILE OPEN_PARENTHESES expression CLOSE_PARENTHESES statement
	| CONTINUE SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

compound_statement
	: OPEN_KEYS CLOSE_KEYS
	| OPEN_KEYS block_item_list CLOSE_KEYS
	;

block_item_list
	: declaration
	| statement
	| block_item_list declaration
	| block_item_list statement
	;

selection_statement
	: IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement
	| IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement ELSE statement
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
	: declaration_specifiers direct_declarator declaration_list compound_statement
	| declaration_specifiers direct_declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

%%

int main(void) {
	st = create_str_table();
    vt = create_var_table();
    if (yyparse() == 0) {
        printf("PARSE SUCCESSFUL!\n");
    } else {
        printf("PARSE FAILED!\n");
    }
	printf("\n\n");
    print_str_table(st); printf("\n\n");
    print_var_table(vt); printf("\n\n");

    free_str_table(st);
    free_var_table(vt);
    yylex_destroy();  
    return 0;
}

void yyerror (char const *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

void check_var() {
    int idx = lookup_var(vt, yytext);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, yytext);
        exit(EXIT_FAILURE);
    }
}

void new_var() {
    int idx = lookup_var(vt, yytext);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                yylineno, yytext, get_line(vt, idx));
        exit(EXIT_FAILURE);
    }
    add_var(vt, yytext, yylineno, last_decl_type);
}