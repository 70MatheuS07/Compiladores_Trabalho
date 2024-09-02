%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "types.h"

// Variável global para armazenar a árvore sintática
AST *syntax_tree;
AST *root; // Raiz da AST

void yyerror(const char *s);
%}

%union {
    int ival;
    float fval;
    char *sval;
    AST *ast;
}

%token INTEGER FLOAT
%type <ast> expression term factor

%%

program:
      global_declarations { 
          root = new_subtree(PROGRAM_NODE, NO_TYPE, 0, 1, $1); 
          syntax_tree = root;
          print_dot(syntax_tree); 
          free_tree(syntax_tree); 
      }
    ;

global_declarations:
      global_declarations global_declaration { 
          add_child($1, $2); 
          $$ = $1; 
      }
    | global_declaration { 
          $$ = new_subtree(PROGRAM_NODE, NO_TYPE, 0, 1, $1); 
      }
    | /* empty */ { 
          $$ = NULL; 
      }
    ;

global_declaration:
      function_declaration { 
          $$ = $1; 
      }
    | variable_declaration { 
          $$ = $1; 
      }
    ;

function_declaration:
      type_specifier ID { 
          strcpy(last_func_decl, VarSave); 
          $2 = new_fun(); 
      } 
      OPEN_PARENTHESES parameter_list CLOSE_PARENTHESES compound_statement { 
          $$ = new_subtree(FUNCTION_DECL_NODE, last_decl_type, sizeof(int), 2, $2, $6); 
      }
    ;

parameter_list:
      parameter_list COMMA parameter { 
          SomaQtdParam(last_func_decl, ft); 
          add_child($1, $3); 
          $$ = $1; 
      }
    | parameter { 
          SomaQtdParam(last_func_decl, ft); 
          $$ = new_subtree(PARAM_LIST_NODE, NO_TYPE, 0, 1, $1); 
      }
    | /* empty */ { 
          $$ = NULL; 
      }
    ;

parameter:
      type_specifier ID { 
          $$ = new_var(); 
      }
    ;

variable_declaration:
      type_specifier init_declarator_list SEMICOLON { 
          $$ = new_subtree(VAR_DECL_NODE, last_decl_type, 0, 1, $2); 
      }
    ;

init_declarator_list:
      init_declarator_list COMMA init_declarator { 
          add_child($1, $3); 
          $$ = $1; 
      }
    | init_declarator { 
          $$ = new_subtree(VAR_LIST_NODE, NO_TYPE, 0, 1, $1); 
      }
    ;

init_declarator:
      ID { 
          $$ = new_var(); 
      }
    | ID ASSIGNMENT expression { 
          AST *var_node = new_var();
          $$ = new_subtree(ASSIGN_NODE, get_node_type(var_node), sizeof(int), 2, var_node, $3); 
      }
    | ID OPEN_BRACKET INT_NUMBER CLOSE_BRACKET array_initialization { 
          ArraySize = atoi(yytext); 
          AST *var_node = new_var(); 
          $$ = new_subtree(ARRAY_DECL_NODE, get_node_type(var_node), sizeof(int), 1, var_node); 
      }
    ;

array_initialization:
      ASSIGNMENT OPEN_KEYS initializer_list CLOSE_KEYS { 
          $$ = $3; 
      }
    | /* empty */ { 
          $$ = NULL; 
      }
    ;

initializer_list:
      initializer_list COMMA initializer { 
          add_child($1, $3); 
          $$ = $1; 
      }
    | initializer { 
          $$ = new_subtree(INIT_LIST_NODE, NO_TYPE, 0, 1, $1); 
      }
    ;

initializer:
      expression { 
          $$ = $1; 
      }
    | array_initialization { 
          $$ = $1; 
      }
    ;

type_specifier:
      INT { 
          last_decl_type = INT_TYPE; 
      }
    | FLOAT { 
          last_decl_type = FLOAT_TYPE; 
      }
    | CHAR { 
          last_decl_type = CHAR_TYPE; 
      }
    | VOID { 
          last_decl_type = VOID_TYPE; 
      }
    ;

compound_statement:
      OPEN_KEYS statement_list CLOSE_KEYS { 
          $$ = new_subtree(BLOCK_NODE, NO_TYPE, 0, 1, $2); 
      }
    ;

statement_list:
      statement_list statement { 
          add_child($1, $2); 
          $$ = $1; 
      }
    | /* empty */ { 
          $$ = NULL; 
      }
    ;

statement:
      expression_statement { 
          $$ = $1; 
      }
    | compound_statement { 
          $$ = $1; 
      }
    | selection_statement { 
          $$ = $1; 
      }
    | iteration_statement { 
          $$ = $1; 
      }
    | return_statement { 
          $$ = $1; 
      }
    | variable_declaration { 
          $$ = $1; 
      }
    | CONTINUE SEMICOLON { 
          $$ = new_node(CONTINUE_NODE, 0, NO_TYPE, 0); 
      }
    ;

expression_statement:
      expression SEMICOLON { 
          $$ = $1; 
      }
    | SEMICOLON { 
          $$ = NULL; 
      }
    ;

selection_statement:
      IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement { 
          $$ = check_if_then($3, $5); 
      }
    | IF OPEN_PARENTHESES expression CLOSE_PARENTHESES statement ELSE statement { 
          $$ = check_if_then_else($3, $5, $7); 
      }
    ;

iteration_statement:
      WHILE OPEN_PARENTHESES expression CLOSE_PARENTHESES statement { 
          $$ = check_repeat($5, $3); 
      }
    ;

return_statement:
      RETURN expression SEMICOLON { 
          $$ = new_subtree(RETURN_NODE, get_node_type($2), sizeof(int), 1, $2); 
          check_return_types(get_node_type($2)); 
      }
    | RETURN SEMICOLON { 
          $$ = new_node(RETURN_NODE, 0, VOID_TYPE, 0); 
          check_return_types(VOID_TYPE); 
      }
    ;

expression:
      assignment_expression { 
          $$ = $1; 
      }
    ;

assignment_expression:
      ID assignment_operator expression { 
          $$ = check_assign($1, $3, unify_assign); 
      }
    | binary_expression { 
          $$ = $1; 
      }
    ;

assignment_operator:
      ASSIGNMENT
    | ADD_ASSIGN
    | SUB_ASSIGN
    | MUL_ASSIGN
    | DIV_ASSIGN
    | MOD_ASSIGN
    ;

binary_expression:
      binary_expression PLUS binary_expression { 
          $$ = unify_bin_node($1, $3, PLUS_NODE, "+", unify_arith_op);
          check_size_bin_node($1, $3, "+");
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression MINUS binary_expression { 
          $$ = unify_bin_node($1, $3, MINUS_NODE, "-", unify_arith_op); 
          check_size_bin_node($1, $3, "-"); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression TIMES binary_expression { 
          $$ = unify_bin_node($1, $3, TIMES_NODE, "*", unify_arith_op); 
          check_size_bin_node($1, $3, "*"); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression OVER binary_expression { 
          $$ = unify_bin_node($1, $3, OVER_NODE, "/", unify_arith_op); 
          check_size_bin_node($1, $3, "/"); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression PERCENT binary_expression { 
          $$ = unify_bin_node($1, $3, PERCENT_NODE, "%", unify_arith_percent); 
          check_size_bin_node($1, $3, "%"); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression LESS_THAN binary_expression { 
          $$= unify_bin_node($1, $3, LESS_THAN_NODE, "<", unify_relational); 
          check_size_bin_node($1, $3, "<"); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression GREATER_THAN binary_expression { 
          $$ = unify_bin_node($1, $3, GREATER_THAN_NODE, ">", unify_relational); 
          check_size_bin_node($1, $3, ">"); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression LESS_THAN_OR_EQUAL binary_expression { 
          $$ = unify_bin_node($1, $3, LESS_THAN_OR_EQUAL_NODE, "<=", unify_relational); 
          check_size_bin_node($1, $3, "<="); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression GREATER_THAN_OR_EQUAL binary_expression { 
          $$ = unify_bin_node($1, $3, GREATER_THAN_OR_EQUAL_NODE, ">=", unify_relational); 
          check_size_bin_node($1, $3, ">="); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression EQUALS binary_expression { 
          $$ = unify_bin_node($1, $3, EQUALS_NODE, "==", unify_relational); 
          check_size_bin_node($1, $3, "=="); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression NOT_EQUALS binary_expression { 
          $$ = unify_bin_node($1, $3, NOT_EQUALS_NODE, "!=", unify_relational); 
          check_size_bin_node($1, $3, "!="); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression LOGICAL_AND binary_expression { 
          $$ = unify_bin_node($1, $3, LOGICAL_AND_NODE, "&&", unify_relational); 
          check_size_bin_node($1, $3, "&&"); 
          set_node_size($$, get_node_size($1)); 
      }
    | binary_expression LOGICAL_OR binary_expression { 
          $$ = unify_bin_node($1, $3, LOGICAL_OR_NODE, "||", unify_relational); 
          check_size_bin_node($1, $3, "||"); 
          set_node_size($$, get_node_size($1)); 
      }
    | cast_expression { 
          $$ = $1; 
      }
    ;

unary_operator:
      PLUS
    | MINUS
    | ADDRESS
    | LOGICAL_NOT
    ;

unary_expression:
      postfix_expression { 
          $$ = $1; 
      }
    | unary_operator cast_expression { 
          $$ = $2; 
      }
    | INCREMENT ID { 
          $$ = new_subtree(INCREMENT_NODE, NO_TYPE, 0, 1, check_var()); 
      }
    | DECREMENT ID { 
          $$ = new_subtree(DECREMENT_NODE, NO_TYPE, 0, 1, check_var()); 
      }
    ;

cast_expression:
      unary_expression { 
          $$ = $1; 
      }
    | OPEN_PARENTHESES type_specifier CLOSE_PARENTHESES cast_expression { 
          $$ = $4; 
      }
    ;

postfix_expression:
      primary_expression { 
          $$ = $1; 
      }
    | ID OPEN_PARENTHESES argument_expression_list CLOSE_PARENTHESES { 
          check_fun(); 
          strcpy(last_func_call, VarSave); 
          check_params();
          $$ = new_subtree(FUNCTION_CALL_NODE, NO_TYPE, 0, 1, check_var()); 
          QtdParam = 0; 
      }
    | ID OPEN_BRACKET expression CLOSE_BRACKET { 
          $$ = new_subtree(ARRAY_ACCESS_NODE, NO_TYPE, 0, 2, check_var(), $3); 
      }
    | ID INCREMENT { 
          $$ = new_subtree(INCREMENT_NODE, NO_TYPE, 0, 1, check_var()); 
      }
    | ID DECREMENT { 
          $$ = new_subtree(DECREMENT_NODE, NO_TYPE, 0, 1, check_var()); 
      }
    ;

argument_expression_list:
      assignment_expression { 
          check_params_types_sizes(get_node_type($1), get_node_size($1)); 
          QtdParam = 1; 
          $$ = $1; 
      }
    | argument_expression_list COMMA assignment_expression { 
          check_params_types_sizes(get_node_type($3), get_node_size($3)); 
          add_child($1, $3); 
          QtdParam++; 
          $$ = $1; 
      }
    | /* empty */ { 
          QtdParam = 0; 
          $$ = NULL; 
      }
    ;

primary_expression:
      ID { 
          $$ = check_var(); 
      }
    | INT_NUMBER { 
          $$ = new_node(INTEGER_NODE, $1, INT_TYPE, sizeof(int)); 
      }
    | REAL_NUMBER { 
          $$ = new_node(FLOAT_NODE, $1, FLOAT_TYPE, sizeof(float)); 
      }
    | CHAR_ASCII { 
          $$ = new_node(CHAR_NODE, $1, CHAR_TYPE, sizeof(char)); 
      }
    | OPEN_PARENTHESES expression CLOSE_PARENTHESES { 
          $$ = $2; 
      }
    | STRING { 
          $$ = new_node(STRING_NODE, 0, STRING_TYPE, strlen(yytext)); 
      }
    ;

%%
