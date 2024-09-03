%output "parser.c"
%defines "parser.h"
%define parse.error verbose
%define parse.lac full

%{
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "types.h"
#include "parser.h"
#include "tables.h"
#include "FuncStack.h"

int yylex(void);
void yyerror(const char *s);

int yylex_destroy(void);
AST* check_var();
int check_size();
AST* new_var();
AST* new_fun();
AST* check_fun();
void check_params();

AST* unify_bin_node(AST* l, AST* r,
                    NodeKind kind, const char* op, Unif (*unify)(Type,Type));

//void check_assign(Type l, Type r);
void check_size_bin_op(int size1, int size2, const char* op);
void check_size_bin_node(AST* l, AST* r, const char* op);
void check_bool_expr(const char* cmd, Type t);
AST* check_if_then(AST *e, AST *b);
AST* check_if_then_else(AST *e, AST *b1, AST *b2);
AST* check_repeat(AST *b, AST *e);
void check_params_types_sizes(Type type, int size);
void assign_size_error(int size1, int size2);
void check_return_types(Type type);
AST* check_assign(AST* l, AST* r,
                   Unif (*unify)(Type,Type)) ;
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
AST *root;
%}

%define api.value.type {AST*}
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
    : global_declarations { root = $1; }
    ;

global_declarations
    :
      global_declarations global_declaration { 
          add_child($1, $2); 
          $$ = $1; 
      }
    | global_declaration { 
          $$ = new_subtree(PROGRAM_NODE, NO_TYPE, 0, 1, $1); 
      }
    ;

global_declaration
    : function_declaration { $$ = $1; }
    | variable_declaration { $$ = $1; }
    ;

function_declaration
    : type_specifier ID {
         strcpy(last_func_decl,VarSave); $2=new_fun(); 
         } 
      OPEN_PARENTHESES parameter_list CLOSE_PARENTHESES compound_statement {
        $$ = new_subtree(FUN_DECL_NODE, last_decl_type, sizeof(int), 2, $2, $6); 
      }
    ;

parameter_list
    : parameter_list COMMA parameter { SomaQtdParam(last_func_decl, ft);add_child($1, $3); $$ = $1;  }
    | parameter { SomaQtdParam(last_func_decl, ft); 
         $$ = new_subtree(PARAM_LIST_NODE, NO_TYPE, 0, 1, $1); 
      } 
    | /* empty */
    ;

parameter
    : type_specifier ID { $$=new_var(); }
    ;

variable_declaration
    : type_specifier init_declarator_list SEMICOLON{
        $$ = new_subtree(VAR_DECL_NODE, last_decl_type, 0, 1, $2); 
    }
    ;

init_declarator_list
    : init_declarator{ 
          $$ = new_subtree(VAR_LIST_NODE, NO_TYPE, 0, 1, $1); 
      }
    | init_declarator_list COMMA init_declarator{ 
          add_child($1, $3); 
          $$ = $1; 
      }
    ;

init_declarator
    : ID { $$= new_var(); }
    | ID { $1=new_var(); } ASSIGNMENT expression {
        $$ = new_subtree(ASSIGN_NODE, get_node_type($1), sizeof(int), 2, $1, $3); 
    }
    | ID OPEN_BRACKET INT_NUMBER{ ArraySize=atoi(yytext); $1=new_var(); } CLOSE_BRACKET array_initialization {
        $$ = new_subtree(ARRAY_DECL_NODE, get_node_type($1), sizeof(int), 1, $1); 
    }
    ;

array_initialization
    : ASSIGNMENT OPEN_KEYS initializer_list CLOSE_KEYS{
        $$ = $3;
    }
	| /* empty */
    ;

initializer_list
    : initializer
    | initializer_list COMMA initializer
    ;

initializer
    : expression { $$ = $1; }
    | array_initialization
    ;
type_specifier
    : INT { last_decl_type = INT_TYPE; $$ = $1; }
    | FLOAT { last_decl_type = FLOAT_TYPE; $$ = $1; }
    | CHAR { last_decl_type = CHAR_TYPE; $$ = $1; }
    | VOID { last_decl_type = VOID_TYPE; $$ = $1; }
    ;


compound_statement
    : OPEN_KEYS statement_list CLOSE_KEYS
    ;

statement_list
    : statement_list statement // { $$ = new_subtree(BLOCK_NODE, NO_TYPE, 0,1, $1); } { add_child($1, $2); }
    | /* empty */
    ;

statement
    : expression_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | return_statement { $$ = $1; }
    | variable_declaration { $$ = $1; }
    | CONTINUE SEMICOLON { $$ = $1; }
    ;

expression_statement
    : expression SEMICOLON { $$ = $1; }
    | SEMICOLON
    ;

selection_statement
    : IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement { $$ = check_if_then($3, $5) ;}
    | IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement ELSE statement { $$ = check_if_then_else($3, $5 , $7); }
    ;

iteration_statement
    : WHILE OPEN_PARENTHESES expression CLOSE_PARENTHESES statement { $$ = check_repeat($5, $3); }
    ;

return_statement
    : RETURN expression SEMICOLON { check_return_types(get_node_type($2)); }
    | RETURN SEMICOLON { check_return_types(VOID_TYPE); }
    ;

expression
    : assignment_expression
    ;

assignment_expression
    : ID { $1=check_var(); } assignment_operator expression { $$=check_assign($1, $4, unify_assign); }
    | binary_expression { $$=$1; }
    ;

assignment_operator
    : ASSIGNMENT { $$ = $1; }
    | ADD_ASSIGN { $$ = $1; }
    | SUB_ASSIGN { $$ = $1; }
    | MUL_ASSIGN { $$ = $1; }
    | DIV_ASSIGN { $$ = $1; }
    | MOD_ASSIGN { $$ = $1; }
    ;

binary_expression
    : binary_expression PLUS binary_expression { $$ = unify_bin_node($1, $3, PLUS_NODE, "+", unify_arith_op);
                                                 check_size_bin_node($1, $3, "+");/*se saiu é igual*/ set_node_size($$, get_node_size($1)); }
    | binary_expression MINUS binary_expression { $$ = unify_bin_node($1, $3, MINUS_NODE, "-", unify_arith_op); 
                                                check_size_bin_node($1, $3,"-"); set_node_size($$, get_node_size($1)); }
    | binary_expression TIMES binary_expression { $$ = unify_bin_node($1, $3, TIMES_NODE, "*", unify_arith_op); 
                                                check_size_bin_node($1, $3,"*"); set_node_size($$, get_node_size($1)); }
    | binary_expression OVER binary_expression { $$ = unify_bin_node($1, $3, OVER_NODE, "/", unify_arith_op); 
                                                check_size_bin_node($1, $3,"/"); set_node_size($$, get_node_size($1)); }
    | binary_expression PERCENT binary_expression { $$ = unify_bin_node($1, $3, PERCENT_NODE, "%", unify_arith_percent); 
                                                    check_size_bin_node($1, $3,"%"); set_node_size($$, get_node_size($1)); }
    | binary_expression LESS_THAN binary_expression { $$= unify_bin_node($1, $3, LESS_THAN_NODE, "<", unify_relational); 
                                                    check_size_bin_node($1, $3,"<"); set_node_size($$, get_node_size($1)); }
    | binary_expression GREATER_THAN binary_expression { $$ = unify_bin_node($1, $3, GREATER_THAN_NODE, ">", unify_relational); 
                                                        check_size_bin_node($1, $3,">"); set_node_size($$, get_node_size($1)); }
    | binary_expression LESS_THAN_OR_EQUAL binary_expression { $$ = unify_bin_node($1, $3, LESS_THAN_OR_EQUAL_NODE, "<=", unify_relational); 
                                                                check_size_bin_node($1, $3,"<="); set_node_size($$, get_node_size($1)); }
    | binary_expression GREATER_THAN_OR_EQUAL binary_expression { $$ = unify_bin_node($1, $3, GREATER_THAN_OR_EQUAL_NODE, ">=", unify_relational); 
                                                                check_size_bin_node($1, $3,">="); set_node_size($$, get_node_size($1)); }
    | binary_expression EQUALS binary_expression { $$ = unify_bin_node($1, $3, EQUALS_NODE, "==", unify_relational); 
                                                        check_size_bin_node($1, $3,"=="); set_node_size($$, get_node_size($1)); }
    | binary_expression NOT_EQUALS binary_expression { $$ = unify_bin_node($1, $3, NOT_EQUALS_NODE, "!=", unify_relational); 
                                                        check_size_bin_node($1, $3,"!="); set_node_size($$, get_node_size($1)); }
    | binary_expression LOGICAL_AND binary_expression { $$ = unify_bin_node($1, $3, LOGICAL_AND_NODE, "&&", unify_relational); 
                                                        check_size_bin_node($1, $3,"&&"); set_node_size($$, get_node_size($1)); }
    | binary_expression LOGICAL_OR binary_expression { $$ = unify_bin_node($1, $3, LOGICAL_OR_NODE, "||", unify_relational); 
                                                        check_size_bin_node($1, $3,"||"); set_node_size($$, get_node_size($1)); }
    | cast_expression
    ;

unary_operator
    : PLUS { $$=$1; }
    | MINUS { $$=$1; }
    | ADDRESS { $$=$1; }
    | LOGICAL_NOT { $$=$1; }
    ;

unary_expression
    : postfix_expression { $$=$1; }
    | unary_operator cast_expression { $$=$2; }
    | INCREMENT ID { $2=check_var(); $$=$2; }
    | DECREMENT ID { $2=check_var(); $$=$2; }
    ;

cast_expression
    : unary_expression { $$=$1; }
    | OPEN_PARENTHESES type_specifier CLOSE_PARENTHESES cast_expression { $$=$4; }
    ;

postfix_expression
    : primary_expression { $$=$1; }
	| ID { check_fun(); strcpy(last_func_call,VarSave); } OPEN_PARENTHESES argument_expression_list CLOSE_PARENTHESES { check_params();QtdParam=0; }
    | ID { $1=check_var(); $$ = $1; } OPEN_BRACKET expression CLOSE_BRACKET
    | ID { $1=check_var(); $$ = $1; } INCREMENT
    | ID { $1=check_var(); $$ = $1; } DECREMENT
    ;


argument_expression_list
    : assignment_expression { check_params_types_sizes(get_node_type($1), get_node_size($1)); QtdParam=1; $$=$1; }
    | argument_expression_list COMMA assignment_expression { check_params_types_sizes(get_node_type($1), get_node_size($1)); } { QtdParam++; }
	| /* empty */ { QtdParam=0; }
    ;

primary_expression
    : ID { $$ = check_var(); $$ = $1; }
    | INT_NUMBER { $$ = $1; }
    | REAL_NUMBER { $$ = $1; }
    | CHAR_ASCII { $$ = $1; }
    | OPEN_PARENTHESES expression CLOSE_PARENTHESES { $$= $2; }
    | STRING { $$ = $1; }
    ;

%%

int main(void) {
    st = create_str_table();
    DEBUG_PRINT("Criado str table");

    ft = create_func_table();
    DEBUG_PRINT("Criado func table");
    
    fs = init_stack();
    DEBUG_PRINT("Inicializado a stack");

    VarSave = malloc(sizeof(char) * 128);
    DEBUG_PRINT("Alocada memória para VarSave");

    DEBUG_PRINT("Início da análise");
    if (yyparse() == 0) {
        printf("PARSE SUCCESSFUL!\n");
    } else {
        printf("PARSE FAILED!\n");
    }
    printf("\n\n");
    print_str_table(st); printf("\n\n");
    print_table(ft); printf("\n\n");

    print_dot(root);

    free_str_table(st);
    free_table(ft);
    free(VarSave);
    free_tree(root);
    yylex_destroy();
    return 0;
}


void yyerror (char const *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

AST* check_var() {
    int lookup= lookup_func(ft, last_func_decl);
    int idx = lookup_var_in_func(ft,VarSave, last_func_decl);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, VarSave);
        exit(EXIT_FAILURE);
    }
    return new_node(VAR_USE_NODE,idx,get_typevar_in_func(ft, idx, last_func_decl, lookup),
                    get_sizevar_in_func(ft, idx, last_func_decl, lookup));
}

int check_size(){
    int lookup= lookup_func(ft, last_func_decl);
    int idx = lookup_var_in_func(ft,VarSave, last_func_decl);
    return get_sizevar_in_func(ft, idx, last_func_decl, lookup);
    
}

AST* new_var() {
    int idx = lookup_var_in_func(ft,VarSave, last_func_decl);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                yylineno, VarSave, get_linevar_in_func(ft,last_func_decl, idx));
        exit(EXIT_FAILURE);
    }
    add_var_in_func(ft, VarSave, last_func_decl, yylineno, last_decl_type, ArraySize);
    AST*aux= new_node(VAR_DECL_NODE, idx, last_decl_type,ArraySize);
    ArraySize=0;
    return aux;
}



AST* new_fun(){
	int idx = lookup_func(ft, last_func_decl);
    if (idx != -1) {
        printf("SEMANTIC ERROR (%d): Function '%s' already declared at line %d.\n",
                yylineno, last_func_decl, get_line_func(ft, idx));
        exit(EXIT_FAILURE);
    }
    add_func(ft, last_func_decl, yylineno, last_decl_type);
    return new_node(FUN_DECL_NODE, idx, last_decl_type,0);
}

AST* check_fun(){
	int idx = lookup_func(ft, VarSave);
    if (idx == -1) {
        printf("SEMANTIC ERROR (%d): Function '%s' was not declared.\n",
                yylineno, VarSave);
        exit(EXIT_FAILURE);
    }
    return new_node(FUN_USE_NODE, idx, last_decl_type,0);
    
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

AST* create_conv_node(Conv conv, AST *n) {
    switch(conv) {
        case C2I:  return new_subtree(C2I_NODE, INT_TYPE, 0 ,1, n);  // char -> int
        case C2F:  return new_subtree(C2F_NODE, FLOAT_TYPE, 0, 1, n);  // char -> float
        case I2F:  return new_subtree(I2F_NODE, FLOAT_TYPE, 0, 1, n);  // int -> float
        case I2C:  return new_subtree(I2C_NODE, CHAR_TYPE, 0, 1, n);  // int -> char
        case I2B:  return new_subtree(I2B_NODE, BOOL_TYPE, 0, 1, n);  // int -> bool
        case F2B:  return new_subtree(F2B_NODE, BOOL_TYPE, 0, 1, n);  // float -> bool
        case C2B:  return new_subtree(C2B_NODE, BOOL_TYPE, 0, 1, n);  // char -> bool
        case F2I:  return new_subtree(F2I_NODE, INT_TYPE, 0, 1, n);  // float -> int
        case NONE: return n;  // Nenhuma conversão necessária
        default:
            printf("INTERNAL ERROR: invalid conversion of types!\n");
            exit(EXIT_FAILURE);
    }
}

AST* unify_bin_node(AST* l, AST* r,NodeKind kind,
                  const char* op, Unif (*unify)(Type,Type)) {

    Type lt = get_node_type(l);
    Type rt = get_node_type(r);
    Unif unif = unify(lt, rt);
    
    if (unif.type == NO_TYPE) {
        type_error(op, lt, rt);
    }

    l = create_conv_node(unif.lc, l);
    r = create_conv_node(unif.rc, r);
    return new_subtree(kind, unif.type, 0, 2, l, r);
}

/*
void check_size_bin_op(int size1, int size2,const char* op){
    if(size1!=size2){
        printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%d' and RHS is '%d'.\n",
           yylineno, op, size1, size2 );
        exit(EXIT_FAILURE);
    }

}
*/

void check_size_bin_node(AST* l, AST* r, const char* op){
    int size1 = get_node_size(l);
    int size2 = get_node_size(r);
    
    if(size1!=size2){
        printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%d' and RHS is '%d'.\n",
           yylineno, op, size1, size2 );
        exit(EXIT_FAILURE);
    }
    
}

AST* check_assign(AST* l, AST* r,
                   Unif (*unify)(Type,Type)) {
    Type lt = get_node_type(l);
    Type rt = get_node_type(r);
    
    int lt_size=get_node_size(l);
    int rt_size=get_node_size(r);
    Unif unif = unify(lt, rt);
    if (unif.type == NO_TYPE) {
        type_error("=", lt, rt);
    }
    if(lt_size!=rt_size){
        assign_size_error(lt_size,rt_size);
    }

    l = create_conv_node(unif.lc, l);
    r = create_conv_node(unif.rc, r);
    return new_subtree(ASSIGN_NODE, NO_TYPE, 0, 2, l, r);
}

void assign_size_error(int size1, int size2){
    if(size1!=size2){
        printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%d' and RHS is '%d'.\n",
           yylineno, "=", size1, size2 );
        exit(EXIT_FAILURE);
    }
}




void check_bool_expr(const char* cmd, Type t) {
    if (t != BOOL_TYPE) {
        printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
           yylineno, cmd, get_text(t), get_text(BOOL_TYPE));
        exit(EXIT_FAILURE);
    }
}

AST* check_if_then(AST *e, AST *b) {
    check_bool_expr("if", get_node_type(e));
    return new_subtree(IF_NODE, NO_TYPE, 0, 2, e, b);
}

AST* check_if_then_else(AST *e, AST *b1, AST *b2) {
    check_bool_expr("if", get_node_type(e));
    return new_subtree(IF_NODE, NO_TYPE, 0, 3, e, b1, b2);
}

AST* check_repeat(AST *b, AST *e) {
    check_bool_expr("repeat", get_node_type(e));
    return new_subtree(REPEAT_NODE, NO_TYPE, 0, 2, b, e);
}


void check_params_types_sizes(Type type, int size)
    {
    int idx = lookup_func(ft, last_func_call);
    int aux=QtdParam+1;
    if(type!=get_typevar_in_func(ft, QtdParam, last_func_call,idx)){
        printf("SEMANTIC ERROR (%d): The parameter %d of '%s' call is %s, but at the function declarator(%d) is %s\n",
                yylineno,aux, last_func_call,get_text(get_typevar_in_func(ft, QtdParam, last_func_call, idx)), get_line_func(ft, idx),get_text(type));
        exit(EXIT_FAILURE);
    }
    if(size!=get_sizevar_in_func(ft, QtdParam, last_func_call,idx)){
        printf("SEMANTIC ERROR (%d): The size of parameter %d of '%s' call is %d , but at the function declarator(%d) is %d\n",
                yylineno,aux, last_func_call,get_sizevar_in_func(ft, QtdParam, last_func_call, idx), get_line_func(ft, idx),size);
        exit(EXIT_FAILURE);
    }
}

void check_return_types(Type type){
    int idx = lookup_func(ft, last_func_decl);
    if(type!=get_typertn(ft, idx)){
        printf("SEMANTIC ERROR (%d): The return type of %s is %s, but the function is returning %s\n",
                yylineno, last_func_decl,get_text(get_typertn(ft, idx)),get_text(type));
        exit(EXIT_FAILURE);
    }
}