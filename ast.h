#ifndef AST_H
#define AST_H

#include "types.h"

typedef enum {
    ASSIGN_NODE,
    EQ_NODE,
    BLOCK_NODE,
    CHAR_VAL_NODE,
    BOOL_VAL_NODE,
    IF_NODE,
    INT_VAL_NODE,
    LT_NODE,
    MINUS_NODE,
    OVER_NODE,
    PLUS_NODE,
    PERCENT_NODE,
    LESS_THAN_NODE,
    GREATER_THAN_NODE,
    LESS_THAN_OR_EQUAL_NODE,
    GREATER_THAN_OR_EQUAL_NODE,
    EQUALS_NODE,
    NOT_EQUALS_NODE,
    LOGICAL_AND_NODE,
    LOGICAL_OR_NODE,
    PROGRAM_NODE,
    READ_NODE,
    REAL_VAL_NODE,
    REPEAT_NODE,
    STR_VAL_NODE,
    TIMES_NODE,
    FUN_DECL_NODE,
    FUN_USE_NODE,
    VAR_DECL_NODE,
    VAR_LIST_NODE,
    VAR_USE_NODE,
    WRITE_NODE,
    PARAM_LIST_NODE,
    ARRAY_DECL_NODE,
    INIT_LIST_NODE,
    CONTINUE_NODE,
    INCREMENT_NODE,
    DECREMENT_NODE,
    ARRAY_ACCESS_NODE,
    RETURN_NODE,

    C2I_NODE,
    C2F_NODE,
    I2F_NODE,
    I2C_NODE,
    I2B_NODE,
    F2B_NODE,
    C2B_NODE,
    F2I_NODE,
} NodeKind;

struct node; // Opaque structure to ensure encapsulation.

typedef struct node AST;

AST* new_node(NodeKind kind, int data,int posFun, Type type, int size) ;
void add_child(AST *parent, AST *child);
AST* get_child(AST *parent, int idx);

AST* new_subtree(NodeKind kind, Type type, int size ,int child_count, ...);

NodeKind get_kind(AST *node);
char* kind2str(NodeKind kind);

int get_data(AST *node);
int get_pos_fun(AST*node);
void set_float_data(AST *node, float data);
float get_float_data(AST *node);
void set_char_data(AST *node, char data); 

Type get_node_type(AST *node);
int get_child_count(AST *node);

void set_node_size(AST *node, int size);
int get_node_size(AST *node);

void print_tree(AST *ast);
void print_dot(AST *ast);

void free_tree(AST *ast);

#endif
