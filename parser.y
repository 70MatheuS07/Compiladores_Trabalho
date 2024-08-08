%output "parser.c"
%defines "parser.h"
%define parse.error verbose
%define parse.lac full
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "types.h"
#include "tables.h"

int yylex(void);
void yyerror(const char *s);

int yylex_destroy(void);
void check_var();
void new_var();
void new_fun();
void check_fun();
void check_params();

extern int yylineno;
extern char *yytext;
char *VarSave;
char last_func_decl[128];
char last_func_call[128];
int QtdParam=0;
StrTable *st;
VarTable *vt;
FuncTable *ft;
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
%start program



%%

program
    : global_declarations
    ;

global_declarations
    : global_declarations global_declaration
    | /* empty */
    ;

global_declaration
    : function_declaration
    | variable_declaration
    ;

function_declaration
    : type_specifier ID {strcpy(last_func_decl,VarSave);new_fun();} OPEN_PARENTHESES parameter_list CLOSE_PARENTHESES compound_statement 
    ;

parameter_list
    : parameter_list COMMA parameter {SomaQtdParam(last_func_decl, ft);}
    | parameter {SomaQtdParam(last_func_decl, ft);}
    | /* empty */
    ;

parameter
    : type_specifier ID {new_var();}
    ;

variable_declaration
    : type_specifier init_declarator_list SEMICOLON
    ;

init_declarator_list
    : init_declarator
    | init_declarator_list COMMA init_declarator
    ;	

init_declarator
    : ID {new_var();}
    | ID {new_var();}ASSIGNMENT expression 
    | ID {new_var();}OPEN_BRACKET INT_NUMBER CLOSE_BRACKET array_initialization 
    ;

array_initialization
    : ASSIGNMENT OPEN_KEYS initializer_list CLOSE_KEYS
	| /* empty */
    ;

initializer_list
    : initializer
    | initializer_list COMMA initializer
    ;

initializer
    : expression
    | array_initialization
    ;
type_specifier
    : INT { last_decl_type = INT_TYPE; }
    | DOUBLE { last_decl_type = DOUBLE_TYPE; }
    | FLOAT { last_decl_type = FLOAT_TYPE; }
    | CHAR { last_decl_type = CHAR_TYPE; }
    | VOID { last_decl_type = VOID_TYPE; }
    ;


compound_statement
    : OPEN_KEYS statement_list CLOSE_KEYS
    ;

statement_list
    : statement_list statement
    | /* empty */
    ;

statement
    : expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | return_statement
    | variable_declaration
    | CONTINUE SEMICOLON
    ;

expression_statement
    : expression SEMICOLON
    | SEMICOLON
    ;

selection_statement
    : IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement
    | IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement ELSE statement
    ;

iteration_statement
    : WHILE OPEN_PARENTHESES expression CLOSE_PARENTHESES statement
    ;

return_statement
    : RETURN expression SEMICOLON
    | RETURN SEMICOLON
    ;

expression
    : assignment_expression
    ;

assignment_expression
    : ID {check_var();} assignment_operator expression
    | binary_expression
    ;

assignment_operator
    : ASSIGNMENT
    | ADD_ASSIGN
    | SUB_ASSIGN
    | MUL_ASSIGN
    | DIV_ASSIGN
    | MOD_ASSIGN
    ;

binary_expression
    : binary_expression PLUS binary_expression
    | binary_expression MINUS binary_expression
    | binary_expression TIMES binary_expression
    | binary_expression OVER binary_expression
    | binary_expression PERCENT binary_expression
    | binary_expression LESS_THAN binary_expression
    | binary_expression GREATER_THAN binary_expression
    | binary_expression LESS_THAN_OR_EQUAL binary_expression
    | binary_expression GREATER_THAN_OR_EQUAL binary_expression
    | binary_expression EQUALS binary_expression
    | binary_expression NOT_EQUALS binary_expression
    | binary_expression LOGICAL_AND binary_expression
    | binary_expression LOGICAL_OR binary_expression
    | cast_expression
    ;

unary_operator
    : PLUS
    | MINUS
    | ADDRESS
    | LOGICAL_NOT
    ;

unary_expression
    : postfix_expression
    | unary_operator cast_expression
    | INCREMENT ID {check_var();}
    | DECREMENT ID {check_var();}
    ;

cast_expression
    : unary_expression
    | OPEN_PARENTHESES type_specifier CLOSE_PARENTHESES cast_expression
    ;

postfix_expression
    : primary_expression
	| ID {check_fun();strcpy(last_func_call,VarSave);}OPEN_PARENTHESES argument_expression_list CLOSE_PARENTHESES{check_params();QtdParam=0;}
    | ID {check_var();}OPEN_BRACKET expression CLOSE_BRACKET
    | ID {check_var();}INCREMENT
    | ID {check_var();}DECREMENT
    ;


argument_expression_list
    : assignment_expression {QtdParam=1;}
    | argument_expression_list COMMA assignment_expression{QtdParam++;}
	| /* empty */{QtdParam=0;}
    ;

primary_expression
    : ID {check_var();}
    | INT_NUMBER
    | REAL_NUMBER
    | OPEN_PARENTHESES expression CLOSE_PARENTHESES
    | STRING
    ;

%%

int main(void) {
	st = create_str_table();
    ft= create_func_table();
	VarSave= malloc(sizeof(char)*128);
    if (yyparse() == 0) {
        printf("PARSE SUCCESSFUL!\n");
    } else {
        printf("PARSE FAILED!\n");
    }
	printf("\n\n");
    print_str_table(st); printf("\n\n");
    print_table(ft); printf("\n\n");

    free_str_table(st);
    free_table(ft);
	free(VarSave);
    yylex_destroy();
    return 0;
}

void yyerror (char const *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

void check_var() {
    int idx = lookup_var_in_func(ft,VarSave, last_func_decl);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, VarSave);
        exit(EXIT_FAILURE);
    }
}

void new_var() {
    int idx = lookup_var_in_func(ft,VarSave, last_func_decl);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                yylineno, VarSave, get_linevar_in_func(ft,last_func_decl, idx));
        exit(EXIT_FAILURE);
    }
    add_var_in_func(ft, VarSave, last_func_decl, yylineno, last_decl_type);
}

void new_fun(){
	int idx = lookup_func(ft, last_func_decl);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): Function '%s' already declared at line %d.\n",
                yylineno, last_func_decl, get_line_func(ft, idx));
        exit(EXIT_FAILURE);
    }
    add_func(ft, last_func_decl, yylineno, last_decl_type);
}

void check_fun(){
	int idx = lookup_func(ft, VarSave);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): Function '%s' was not declared.\n",
                yylineno, VarSave);
        exit(EXIT_FAILURE);
    }
    
}

void check_params(){
    int idx = lookup_func(ft, last_func_call);
    if(!VerificaQtdParam(last_func_call, ft,  QtdParam)){
        printf("SEMANTIC ERROR (%d): Function '%s' was declared with %d params in (%d), but the function call has %d params\n",
                yylineno, last_func_call, get_qtdparams(ft, idx), get_line_func(ft, idx), QtdParam);
        exit(EXIT_FAILURE);
    }
}