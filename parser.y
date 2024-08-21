%output "parser.c"
%defines "parser.h"
%define parse.error verbose
%define parse.lac full
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "parser.h"
#include "tables.h"
#include "FuncStack.h"

int yylex(void);
void yyerror(const char *s);

int yylex_destroy(void);
Type check_var();
void new_var();
void new_fun();
void check_fun();
void check_params();
Type unify_bin_op(Type l, Type r,
                  const char* op, Type (*unify)(Type,Type));

//void check_assign(Type l, Type r);
void check_bool_expr(const char* cmd, Type t);
void check_params_types(Type type);
void check_return_types(Type type);
void check_assign(Type l, Type r);
extern int yylineno;
extern char *yytext;
char *VarSave;
char last_func_decl[128];
char last_func_call[128];

int ArraySize=0;
int QtdParam=0;
FunctionStack *fs;
StrTable *st;
VarTable *vt;
FuncTable *ft;
Type last_decl_type;
%}
%define api.value.type {Type}
%token INCREMENT DECREMENT PLUS MINUS TIMES OVER PERCENT
%token GREATER_THAN LESS_THAN GREATER_THAN_OR_EQUAL LESS_THAN_OR_EQUAL EQUALS NOT_EQUALS
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token ASSIGNMENT LOGICAL_AND ADDRESS LOGICAL_OR LOGICAL_NOT
%token OPEN_PARENTHESES CLOSE_PARENTHESES OPEN_BRACKET CLOSE_BRACKET OPEN_KEYS CLOSE_KEYS
%token SEMICOLON COMMA
%token CHAR CONTINUE  ELSE FLOAT
%token WHILE IF INT RETURN
%token VOID
%token STRING ID INT_NUMBER REAL_NUMBER CHAR_ASCII

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
    | ID OPEN_BRACKET INT_NUMBER{ArraySize=atoi(yytext);new_var();} CLOSE_BRACKET array_initialization 
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
    : IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement { check_bool_expr("if", $3); }
    | IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement ELSE statement { check_bool_expr("if", $3); }
    ;

iteration_statement
    : WHILE OPEN_PARENTHESES expression CLOSE_PARENTHESES statement { check_bool_expr("while", $3); }
    ;

return_statement
    : RETURN expression SEMICOLON{check_return_types($2);}{pop(fs);}
    | RETURN SEMICOLON{check_return_types(VOID_TYPE);}{pop(fs);}
    ;

expression
    : assignment_expression
    ;

assignment_expression
    : ID {$1=check_var();} assignment_operator expression { check_assign($1, $4 ); }
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
    : binary_expression PLUS binary_expression  { $$ = unify_bin_op($1, $3, "+", unify_arith_op); }
    | binary_expression MINUS binary_expression { $$ = unify_bin_op($1, $3, "-", unify_arith_op); }
    | binary_expression TIMES binary_expression { $$ = unify_bin_op($1, $3, "*", unify_arith_op); }
    | binary_expression OVER binary_expression  { $$ = unify_bin_op($1, $3, "/", unify_arith_op); }
    | binary_expression PERCENT binary_expression   { $$ = unify_bin_op($1, $3, "%", unify_arith_percent); }
    | binary_expression LESS_THAN binary_expression { $$ = unify_bin_op($1, $3, "<", unify_relational); }
    | binary_expression GREATER_THAN binary_expression  { $$ = unify_bin_op($1, $3, ">", unify_relational); }
    | binary_expression LESS_THAN_OR_EQUAL binary_expression    { $$ = unify_bin_op($1, $3, "<=", unify_relational); }
    | binary_expression GREATER_THAN_OR_EQUAL binary_expression { $$ = unify_bin_op($1, $3, ">=", unify_relational); }
    | binary_expression EQUALS binary_expression        { $$ = unify_bin_op($1, $3, "==", unify_relational); }
    | binary_expression NOT_EQUALS binary_expression    { $$ = unify_bin_op($1, $3, "!=", unify_relational); }
    | binary_expression LOGICAL_AND binary_expression   { $$ = unify_bin_op($1, $3, "&&", unify_relational); }
    | binary_expression LOGICAL_OR binary_expression    { $$ = unify_bin_op($1, $3, "||", unify_relational); }
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
    | INCREMENT ID {$2=check_var();}
    | DECREMENT ID {$2=check_var();}
    ;

cast_expression
    : unary_expression
    | OPEN_PARENTHESES type_specifier CLOSE_PARENTHESES cast_expression
    ;

postfix_expression
    : primary_expression
	| ID {check_fun();strcpy(last_func_call,VarSave);}OPEN_PARENTHESES argument_expression_list CLOSE_PARENTHESES{check_params();QtdParam=0;}
    | ID {$1=check_var();}OPEN_BRACKET expression CLOSE_BRACKET
    | ID {$1=check_var();}INCREMENT
    | ID {$1=check_var();}DECREMENT
    ;


argument_expression_list
    : assignment_expression {check_params_types($1);QtdParam=1;}
    | argument_expression_list COMMA assignment_expression{ check_params_types($1);}{QtdParam++;}
	| /* empty */{QtdParam=0;}
    ;

primary_expression
    : ID { $$ = check_var();}
    | INT_NUMBER {$$ = INT_TYPE;}
    | REAL_NUMBER {$$ = FLOAT_TYPE;}
    | CHAR_ASCII {$$ = CHAR_TYPE;}
    | OPEN_PARENTHESES expression CLOSE_PARENTHESES { $$ = $2; }
    | STRING
    ;

%%

int main(void) {
	st = create_str_table();
    ft= create_func_table();
    fs= init_stack();
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

Type check_var() {
    int lookup= lookup_func(ft, last_func_decl);
    int idx = lookup_var_in_func(ft,VarSave, last_func_decl);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, VarSave);
        exit(EXIT_FAILURE);
    }
    return get_typevar_in_func(ft, idx, last_func_decl, lookup);
}

void new_var() {
    int idx = lookup_var_in_func(ft,VarSave, last_func_decl);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                yylineno, VarSave, get_linevar_in_func(ft,last_func_decl, idx));
        exit(EXIT_FAILURE);
    }
    add_var_in_func(ft, VarSave, last_func_decl, yylineno, last_decl_type, ArraySize);
    ArraySize=0;
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
    push(fs,VarSave);
    
}

void check_params(){
    int idx = lookup_func(ft, last_func_call);
    if(!VerificaQtdParam(last_func_call, ft,  QtdParam)){
        printf("SEMANTIC ERROR (%d): Function '%s' was declared with %d params in (%d), but the function call has %d params\n",
                yylineno, last_func_call, get_qtdparams(ft, idx), get_line_func(ft, idx), QtdParam);
        exit(EXIT_FAILURE);
    }
}



// ----------------------------------------------------------------------------

// Type checking and inference.

void type_error(const char* op, Type t1, Type t2) {
    printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%s' and RHS is '%s'.\n",
           yylineno, op, get_text(t1), get_text(t2));
    exit(EXIT_FAILURE);
}

void type_warning(const char* op, Type t1, Type t2) {
    printf("WARNING (%d): possible loss of precision or unexpected behavior for operator '%s'. LHS is '%s' and RHS is '%s'.\n",
           yylineno, op, get_text(t1), get_text(t2));
}

Type unify_bin_op(Type l, Type r,
                  const char* op, Type (*unify)(Type,Type)) {
    Type unif = unify(l, r);
    
    if (unif == NO_TYPE) {
        type_error(op, l, r);
    }
    return unif;
}

void check_assign(Type l, Type r) {
    if (l == CHAR_TYPE && !(r == CHAR_TYPE ||r== INT_TYPE)) type_error("=", l, r);
    if (l == INT_TYPE  && (r == FLOAT_TYPE )) type_warning("=", l, r);
    else if (l == INT_TYPE  && !(r==INT_TYPE|| r==CHAR_TYPE)) type_error("=", l, r);
    if (l == FLOAT_TYPE && !(r==FLOAT_TYPE||r==INT_TYPE|| r==CHAR_TYPE))  type_error("=", l, r);
    
}


void check_bool_expr(const char* cmd, Type t) {
    if (t != BOOL_TYPE) {
        printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
           yylineno, cmd, get_text(t), get_text(BOOL_TYPE));
        exit(EXIT_FAILURE);
    }
}

void check_params_types(Type type){
    int idx = lookup_func(ft, last_func_call);
    int aux=QtdParam+1;
    if(type!=get_typevar_in_func(ft, QtdParam, last_func_call,idx)){
        printf("SEMANTIC ERROR (%d): The parameter %d of '%s' call is %s, but at the function declarator(%d) is %s ",
                yylineno,aux, last_func_call,get_text(get_typevar_in_func(ft, QtdParam, last_func_call, idx)), get_line_func(ft, idx),get_text(type));
        exit(EXIT_FAILURE);
    }
}

void check_return_types(Type type){
    int idx = lookup_func(ft, peek(fs));
    printf("%d", idx);
    if(type!=get_typertn(ft, idx)){
        printf("SEMANTIC ERROR (%d): The return type of %s is %s, but the function is returning %s ",
                yylineno, last_func_call,get_text(get_typertn(ft, idx)),get_text(type));
        exit(EXIT_FAILURE);
    }
}