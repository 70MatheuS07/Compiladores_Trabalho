
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "tables.h"
#include "types.h"

#define CHILDREN_LIMIT 20 // Don't try this at home, kids... :P

struct node {
    NodeKind kind;
    union {
        int   as_int;
        float as_float;
        char as_char;
    } data;
    Type type;
    int posFun;
    int size;
    int count;
    AST* child[CHILDREN_LIMIT];
};

AST* new_node(NodeKind kind, int data,int posFun, Type type, int size) {
    AST* node = malloc(sizeof * node);

    node->kind = kind;
    node->data.as_int = data;
    node->posFun=posFun;
    node->type = type;
    node->size=size;
    node->count = 0;
    for (int i = 0; i < CHILDREN_LIMIT; i++) {
        node->child[i] = NULL;
    }
    return node;
}

void add_child(AST *parent, AST *child) {
    if (parent->count == CHILDREN_LIMIT) {
        fprintf(stderr, "Cannot add another child!\n");
        exit(1);
    }
    if(parent==NULL || child==NULL){
        printf("AAAAAAAAAAAAAAAAAAAAAAA\n");
    }
    parent->child[parent->count] = child;
    parent->count++;
}

AST* get_child(AST *parent, int idx) {
    return parent->child[idx];
}

AST* new_subtree(NodeKind kind, Type type, int size ,int child_count, ...) {
    if (child_count > CHILDREN_LIMIT) {
        fprintf(stderr, "Too many children as arguments!\n");
        exit(1);
    }


    AST* node = new_node(kind, 0, 0,type, size);

    va_list ap;
    va_start(ap, child_count);
    for (int i = 0; i < child_count; i++) {
        add_child(node, va_arg(ap, AST*));
    }
    va_end(ap);
    return node;
}

NodeKind get_kind(AST *node) {
    return node->kind;
}

int get_data(AST *node) {
    return node->data.as_int;
}

void set_float_data(AST *node, float data) {
    node->data.as_float = data;
}


void set_char_data(AST *node, char data) {
    node->data.as_char = data;
}

float get_float_data(AST *node) {
    return node->data.as_float;
}

Type get_node_type(AST *node) {
    return node->type;
}

int get_child_count(AST *node) {
    return node->count;
}

void free_tree(AST *tree) {
    if (tree == NULL) return;
    for (int i = 0; i < tree->count; i++) {
        free_tree(tree->child[i]);
    }
    free(tree);
}

// Dot output.

int nr;

extern FuncTable *ft;;

char* kind2str(NodeKind kind) {
    switch(kind) {
        case ASSIGN_NODE:               return "=";
        case EQ_NODE:                   return "==";
        case BLOCK_NODE:                return "block";
        case CHAR_VAL_NODE:             return "char_val";
        case BOOL_VAL_NODE:             return "bool_val";
        case IF_NODE:                   return "if";
        case INT_VAL_NODE:              return "int_val";
        case LT_NODE:                   return "<";
        case MINUS_NODE:                return "-";
        case OVER_NODE:                 return "/";
        case PLUS_NODE:                 return "+";
        case PERCENT_NODE:              return "%";
        case LESS_THAN_NODE:            return "<";
        case GREATER_THAN_NODE:         return ">";
        case LESS_THAN_OR_EQUAL_NODE:   return "<=";
        case GREATER_THAN_OR_EQUAL_NODE:return ">=";
        case EQUALS_NODE:               return "==";
        case NOT_EQUALS_NODE:           return "!=";
        case LOGICAL_AND_NODE:          return "&&";
        case LOGICAL_OR_NODE:           return "||";
        case PROGRAM_NODE:              return "program";
        case READ_NODE:                 return "read";
        case REAL_VAL_NODE:             return "real_val";
        case REPEAT_NODE:               return "repeat";
        case STR_VAL_NODE:              return "str_val";
        case TIMES_NODE:                return "*";
        case FUN_DECL_NODE:             return "fun_decl";
        case FUN_USE_NODE:              return "fun_use";
        case VAR_DECL_NODE:             return "var_decl";
        case VAR_LIST_NODE:             return "var_list";
        case VAR_USE_NODE:              return "var_use";
        case WRITE_NODE:                return "write";
        case PARAM_LIST_NODE:           return "param_list";
        case ARRAY_DECL_NODE:           return "array_decl";
        case INIT_LIST_NODE:            return "init_list";
        case CONTINUE_NODE:             return "continue";
        case INCREMENT_NODE:            return "++";
        case DECREMENT_NODE:            return "--";
        case ARRAY_ACCESS_NODE:         return "array_access";
        case RETURN_NODE:               return "return";
        case C2I_NODE:                  return "C2I";
        case C2F_NODE:                  return "C2F";
        case I2F_NODE:                  return "I2F";
        case I2C_NODE:                  return "I2C";
        case I2B_NODE:                  return "I2B";
        case F2B_NODE:                  return "F2B";
        case C2B_NODE:                  return "C2B";
        case F2I_NODE:                  return "F2I";
        default:                        return "ERROR!!";
    }
}

int has_data(NodeKind kind) {
    switch(kind) {
        case BOOL_VAL_NODE:
        case INT_VAL_NODE:
        case REAL_VAL_NODE:
        case STR_VAL_NODE:
        case VAR_DECL_NODE:
        case VAR_USE_NODE:
            return 1;
        default:
            return 0;
    }
}

void set_node_size(AST *node, int size){
    node->size = size;
}

int get_node_size(AST *node){
    return node->size;
}

int print_node_dot(AST *node) {
    int my_nr = nr++;

    fprintf(stderr, "node%d[label=\"", my_nr);
    if (node->type != NO_TYPE) {
        fprintf(stderr, "(%s) ", get_text(node->type));
    }
    if (node->kind == VAR_DECL_NODE || node->kind == VAR_USE_NODE) {
        fprintf(stderr, "%s@", get_namevar_in_func(ft, node->data.as_int,node->posFun));
    }
    else
    if(node->kind == FUN_DECL_NODE || node->kind == FUN_USE_NODE){
        fprintf(stderr, "%s@", get_name_func(ft, node->data.as_int));
    }
     else {
        fprintf(stderr, "%s", kind2str(node->kind));
    }
    if (has_data(node->kind)) {
        if (node->kind == REAL_VAL_NODE) {
            fprintf(stderr, "%.2f", node->data.as_float);
        } else if (node->kind == STR_VAL_NODE) {
            fprintf(stderr, "@%d", node->data.as_int);
        } else {
            fprintf(stderr, "%d", node->data.as_int);
        }
    }
    fprintf(stderr, "\"];\n");

    for (int i = 0; i < node->count; i++) {
        int child_nr = print_node_dot(node->child[i]);
        fprintf(stderr, "node%d -> node%d;\n", my_nr, child_nr);
    }
    return my_nr;
}

void print_dot(AST *tree) {
    nr = 0;
    fprintf(stderr, "digraph {\ngraph [ordering=\"out\"];\n");
    print_node_dot(tree);
    fprintf(stderr, "}\n");
}

void print_tree_names(AST *node, int indent) {
    if (node == NULL) {
        return;
    }

    // Imprime os espaços correspondentes ao nível de indentação
    for (int i = 0; i < indent; i++) {
        printf("  "); // Dois espaços por nível de indentação
    }

    // Obtém o nome do nó através da função kind2str e imprime
    printf("%s\n", kind2str(get_kind(node)));

    // Itera sobre os filhos do nó atual e imprime recursivamente
    int child_count = get_child_count(node);
    for (int i = 0; i < child_count; i++) {
        AST *child = get_child(node, i);
        print_tree_names(child, indent + 1); // Aumenta a indentação para o próximo nível
    }
}