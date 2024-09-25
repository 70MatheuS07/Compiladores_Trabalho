#include <stdlib.h>
#include <stdio.h>
#include "code.h"
#include "instruction.h"
#include "tables.h"

// ----------------------------------------------------------------------------
// Tables ---------------------------------------------------------------------

extern StrTable *st;
extern VarTable *vt;
extern FuncTable *ft;

// ----------------------------------------------------------------------------
// Code memory ----------------------------------------------------------------

Instr code[INSTR_MEM_SIZE];
int next_instr;

//isso vai ser usado para os operandos, podem ser tanto string como intei
union {
        int   imm_int;
        char reg[100] ;
        float imm_float;
        char imm_char;
    } oprd;

// ----------------------------------------------------------------------------
// Emits ----------------------------------------------------------------------

void emit(OpCode op, int o1, int o2, int o3) {
    code[next_instr].op = op;
    code[next_instr].o1 = o1;
    code[next_instr].o2 = o2;
    code[next_instr].o3 = o3;
    next_instr++;
}

#define emit0(op) \
    emit(op, 0, 0, 0)

#define emit1(op, o1) \
    emit(op, o1, 0, 0)

#define emit2(op, o1, o2) \
    emit(op, o1, o2, 0)

#define emit3(op, o1, o2, o3) \
    emit(op, o1, o2, o3)

int emit_program(AST *ast)
{
    rec_emit_code(get_child(ast, 0));
}

int emit_param_list(AST *ast)
{
    int size = get_child_count(ast);
    if (size == 0) {
        return;
    }
    else
    {
        printf("param_list size: %d\n", size);
        for (int i = 0; i < size; i++) {
            rec_emit_code(get_child(ast, i));
        }
    }
}

int emit_block(AST *ast)
{
    int size = get_child_count(ast);
    for (int i = 0; i < size; i++) {
        rec_emit_code(get_child(ast, i));
    }
}

int emit_write(AST *ast)
{
    AST *expr = get_child(ast, 0);
    int x = rec_emit_code(expr);
    Type expr_type = get_node_type(expr);

    switch(expr_type){
        case INT_TYPE:   emit2(SYSCALL, 4, x); break;
        case FLOAT_TYPE: emit2(SYSCALL, 5, x); break;
        case : emit2(SYSCALL, 7, x); break;
        case NO_TYPE:
        default:
            fprintf(stderr, "Invalid type: %s!\n", get_text(expr_type));
            exit(EXIT_FAILURE);
    }


int emit_str_val(AST *ast) {
    int x = new_int_reg();
    int c = get_data(ast);
    emit2(LDIi, x, c);
    return x;


// ----------------------------------------------------------------------------

// Prints ----------------------------------------------------------------------
void dump_str_table()
{
    int table_size = get_str_table_size(st);
    for (int i = 0; i < table_size; i++)
    {
        printf("    string%d: asciiz %s\n", i, get_string(st, i));
    }
}

void dump_var_table()
{
    int sizeft = get_function_table_size(ft);
    for (int i = 0; i < sizeft; i++)
    {
        VarTable *vTable = get_var_table(ft, i);
        int sizevt = get_var_table_size(vTable);
        for (int j = 0; j < sizevt; j++)
        {
            Type tipo = get_type(vTable, j);
            if (tipo == INT_TYPE)
            {
                printf("    %s: .word 0\n", get_name(vTable, j));
            }
            if (tipo == FLOAT_TYPE)
            {
                printf("    %s: .float 0.0\n", get_name(vTable, j));
            }
            if(tipo == CHAR_TYPE)
            {
                printf("    %s: .byte '0'\n", get_name(vTable, j));
            }
        }
    }
}
// -----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// AST Traversal --------------------------------------------------------------

int int_regs_count;
int float_regs_count;

#define new_int_reg() \
    int_regs_count++

#define new_float_reg() \
    float_regs_count++

int rec_emit_code(AST *ast);
// ----------------------------------------------------------------------------

int rec_emit_code(AST *ast)
{
    switch (get_kind(ast))
    {
     //Essa é a base para o t8.c
    case PROGRAM_NODE:
        emit_program(ast);
        break;
    case PARAM_LIST_NODE:
        emit_param_list(ast);
        break;
    case BLOCK_NODE:
        emit_block(ast);
        break;
    case WRITE_NODE:
        emit_write(ast);
        break;
    case STR_VAL_NODE:
        emit_str_val(ast);
        //break;
        // case ASSIGN_NODE:   emit_assign(ast);    break;
        // case EQUALS_NODE:   emit_eq(ast);        break;
        // case BLOCK_NODE:    emit_block(ast);     break;
        // case BOOL_VAL_NODE: emit_bool_val(ast);  break;
        // case IF_NODE:       emit_if(ast);        break;
        // case INT_VAL_NODE:  emit_int_val(ast);   break;
        // case LT_NODE:       emit_lt(ast);        break;
        // case MINUS_NODE:    emit_minus(ast);     break;
        // case OVER_NODE:     emit_over(ast);      break;
        // case PLUS_NODE:     emit_plus(ast);      break;
        // case PROGRAM_NODE:  emit_program(ast);   break;
        // case READ_NODE:     emit_read(ast);      break;
        // case REAL_VAL_NODE: emit_real_val(ast);  break;
        // case REPEAT_NODE:   emit_repeat(ast);    break;
        // case STR_VAL_NODE:  emit_str_val(ast);   break;
        // case TIMES_NODE:    emit_times(ast);     break;
        // case VAR_DECL_NODE: emit_var_decl(ast);  break;
        // case VAR_LIST_NODE: emit_var_list(ast);  break;
        // case VAR_USE_NODE:  emit_var_use(ast);   break;
        // case WRITE_NODE:    emit_write(ast);     break;
        // case FUN_DECL_NODE: emit_fun_decl(ast);  break;
        // case B2I_NODE:      emit_b2i(ast);       break;
        // case B2R_NODE:      emit_b2r(ast);       break;
        // case B2S_NODE:      emit_b2s(ast);       break;
        // case I2F_NODE:      emit_i2r(ast);       break;
        //  Mudei I2S_NODE para I2C_NODE
        // case I2C_NODE:      emit_i2s(ast);       break;
        // case R2S_NODE:      emit_r2s(ast);       break;
        // case PARAM_LIST_NODE: emit_param_list(ast); break;
        // case INCREMENT_NODE: emit_increment(ast); break;
        // case DECREMENT_NODE: emit_decrement(ast); break;
        // case C2F_NODE: emit_c2f(ast); break;
        // case RETURN_NODE: emit_return(ast); break;
        // case ARRAY_DECL_NODE: emit_array_decl(ast); break;
        // case ARRAY_ACCESS_NODE: emit_array_acess(ast); break;
        // case GREATER_THAN_NODE: emit_greather_than(ast); break;
        // case LESS_THAN_NODE: emit_less_than(ast); break;
        // case GREATER_THAN_OR_EQUAL_NODE: emit_greather_than_or_equal(ast); break;
        // case LESS_THAN_OR_EQUAL_NODE: emit_less_than_or_equal(ast); break;
        // case CHAR_VAL_NODE: emit_char_val(ast); break;
        // case LOGICAL_OR_NODE: emit_logical_or(ast); break;
        // case NOT_EQUALS_NODE: emit_not_equals(ast); break;
        // case LOGICAL_AND_NODE: emit_logical_and(ast); break;
        // case SUB_ASSIGN_NODE: emit_sub_assign(ast); break;
        // case DIV_ASSIGN_NODE: emit_div_assign(ast); break;
        // case MUL_ASSIGN_NODE: emit_mul_assign(ast); break;
        // case MOD_ASSIGN_NODE: emit_mod_assign(ast); break;
        // case C2I_NODE: emit_c2i(ast); break;

        // default:
        //  fprintf(stderr, "Invalid kind: %s!\n", kind2str(get_kind(ast)));
        // exit(EXIT_FAILURE);
    }
}

void emit_code(AST *ast)
{
    next_instr = 0;
    int_regs_count = 0;
    float_regs_count = 0;
    printf(".data:\n");
    dump_str_table();
    dump_var_table();
}