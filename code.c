#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "code.h"
#include "instruction.h"
#include "tables.h"

// #define TRACE
#ifdef TRACE
#define trace(msg) printf("TRACE: %s\n", msg)
#else
#define trace(msg)
#endif

// ----------------------------------------------------------------------------
// Tables ---------------------------------------------------------------------

extern StrTable *st;
extern VarTable *vt;
extern FuncTable *ft;

// ----------------------------------------------------------------------------
// Code memory ----------------------------------------------------------------

Instr code[INSTR_MEM_SIZE];
int next_instr;

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

void check_int_registers(){
    if(int_regs_count==10){
        int_regs_count = 0;
    }
}
    

void check_float_registers(){
    if(float_regs_count==25){
        int_regs_count = 0;
    }
        

}


void emit(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int emit_program(AST *ast)
{
    trace("Emit program");
    rec_emit_code(get_child(ast, 0));
}

int emit_fun_decl(AST *ast)
{
    trace("Emit fun_decl");
    rec_emit_code(get_child(ast, 0)); // var_list
    rec_emit_code(get_child(ast, 1)); // block
}

int emit_param_list(AST *ast)
{
    trace("Emit param_list");
    int size = get_child_count(ast);
    if (size == 0)
    {
        return -1;
    }
    else
    {
        printf("param_list size: %d\n", size);
        for (int i = 0; i < size; i++)
        {
            rec_emit_code(get_child(ast, i));
        }
    }
}

int emit_block(AST *ast)
{
    trace("Emit block");
    int size = get_child_count(ast);
    for (int i = 0; i < size; i++)
    {
        rec_emit_code(get_child(ast, i));
    }
}

int emit_write(AST *ast)
{
    trace("Emit write");
    AST *expr = get_child(ast, 0);
    int x = rec_emit_code(expr);

    NodeKind kind = get_kind(expr);
    if (get_kind(expr) == STR_VAL_NODE)
    {
        emit("li $v0, %d\n", 4);
    }

    else
    {
        int var_idx = get_data(expr);

        int pos_func = get_pos_fun(expr);
        Type expr_type = get_node_type(expr);
        switch (expr_type)
        {
        case INT_TYPE:
            emit("  move $a0 %s\n", RegTempInt[x]);
            emit("  li $v0, %d\n",  1);
            ;
            break;
        case FLOAT_TYPE:
            emit("  move $f12 %s\n", RegTempInt[x]);
            emit("  li $v0, %d\n",  2);
            ;
            break;
        case CHAR_TYPE:
            emit("  move $a0 %s\n", RegTempInt[x]);
            emit("  li $v0, %d\n", 11);
            ;
            break;
        case NO_TYPE:
        default:
            fprintf(stderr, "Invalid type: %s!\n", get_text(expr_type));
            exit(EXIT_FAILURE);
        }
    }

    emit("  syscall\n\n");
}

int emit_str_val(AST *ast)
{
    int c = get_data(ast);
    emit("  la $a0, string%d\n", c);
    return 4;
}

int emit_int_val(AST *ast)
{
    check_int_registers();
    int x = new_int_reg();
    int c = get_data(ast);
    emit("  li %s, %d\n", RegTempInt[x], c);
    return x;
}

int emit_real_val(AST *ast)
{
    //  Obter um novo registrador de ponto flutuante
    check_float_registers();
    int x = new_float_reg();

    //  Obter o valor de ponto flutuante (imediato) da AST
    float c = get_data(ast); // `c` agora é um valor float

    // Interpretar o valor float como uma representação binária de 32 bits
    int int_representation;
    memcpy(&int_representation, &c, sizeof(int_representation));

    //  Carregar a representação binária do float como imediato em um registrador inteiro
    emit("  li $t0, %d\n", int_representation);

    //  Mover o valor do registrador inteiro para o registrador de ponto flutuante
    emit("  mtc1 $t0, %s\n", RegTempFloat[x]);

    // Retorna o índice do registrador de ponto flutuante usado
    return x;
}

int emit_char_val(AST *ast)
{
    check_int_registers();
    int x = new_int_reg();
    int c = get_data(ast);
    emit("  li %s, '%c'\n", RegTempInt[x], c);
    return x;
}

int emit_var_list(AST *ast)
{
    trace("Emit var_list");
    int size = get_child_count(ast);
    for (int i = 0; i < size; i++)
    {
        rec_emit_code(get_child(ast, i));
    }
}

int emit_assign(AST *ast)
{
    trace("Emit assign");
    AST *rexpr = get_child(ast, 1);
    int x = rec_emit_code(rexpr);
    int var_idx = get_data(get_child(ast, 0));
    int pos_func = get_pos_fun(get_child(ast, 0));
    Type var_type = get_typevar_in_func(ft, var_idx, pos_func);

    switch (var_type)
    {
    case INT_TYPE:

        emit("  sw %s, var%d%d\n\n", RegTempInt[x], pos_func, var_idx);
        break;

    case FLOAT_TYPE:

        emit("  s.s %s, var%d%d\n\n", RegTempFloat[x], pos_func, var_idx);
        break;

    case CHAR_TYPE:

        emit("  sb %s, var%d%d\n\n", RegTempInt[x], pos_func, var_idx);
        break;

    default:
        fprintf(stderr, "Invalid type: %s!\n", pos_func, var_idx);
        break;
    }
}

int emit_plus(AST *ast)
{
    int x;
    int y = rec_emit_code(get_child(ast, 0));
    int z = rec_emit_code(get_child(ast, 1));
    if (get_node_type(ast) == FLOAT_TYPE)
    {
        check_float_registers();
        x = new_float_reg();
        emit("  add.s %s, %s, %s\n", RegTempFloat[x], RegTempFloat[y], RegTempFloat[z]);
    }
    else if (get_node_type(ast) == INT_TYPE)
    {
        check_int_registers();
        x = new_int_reg();
        emit("  add %s, %s, %s\n", RegTempInt[x], RegTempInt[y], RegTempInt[z]);
    }
    return x;
}

int emit_minus(AST *ast)
{
    int x;
    int y = rec_emit_code(get_child(ast, 0));
    int z = rec_emit_code(get_child(ast, 1));
    if (get_node_type(ast) == FLOAT_TYPE)
    {
        check_float_registers();
        x = new_float_reg();
        emit("  sub.s %s, %s, %s\n", RegTempFloat[x], RegTempFloat[y], RegTempFloat[z]);
    }
    else
    {
        check_int_registers();
        x = new_int_reg();
        emit("  sub %s, %s, %s\n", RegTempInt[x], RegTempInt[y], RegTempInt[z]);
    }
    return x;
}

int emit_times(AST *ast)
{
    int x;
    int y = rec_emit_code(get_child(ast, 0));
    int z = rec_emit_code(get_child(ast, 1));
    if (get_node_type(ast) == FLOAT_TYPE)
    {
        check_float_registers();
        x = new_float_reg();
        emit("  mul.s %s, %s, %s\n", RegTempFloat[x], RegTempFloat[y], RegTempFloat[z]);
    }
    else
    {
        check_int_registers();
        x = new_int_reg();
        emit("  mul %s, %s, %s\n", RegTempInt[x], RegTempInt[y], RegTempInt[z]);
    }
    return x;
}

int emit_over(AST *ast)
{
    int x;
    int y = rec_emit_code(get_child(ast, 0));  // Avalia o primeiro operando
    int z = rec_emit_code(get_child(ast, 1));  // Avalia o segundo operando
    
    if (get_node_type(ast) == FLOAT_TYPE)
    {
        check_float_registers();  // Verifica se há registradores float disponíveis
        x = new_float_reg();      // Aloca um novo registrador float
        emit("  div.s %s, %s, %s\n", RegTempFloat[x], RegTempFloat[y], RegTempFloat[z]);  // Emite código para divisão de float
    }
    else
    {
        check_int_registers();  // Verifica se há registradores inteiros disponíveis
        emit("  div %s, %s\n", RegTempInt[y], RegTempInt[z]);  // Realiza a divisão de inteiros (o resultado vai para `lo` e `hi`)
        x = new_int_reg();      // Aloca um novo registrador inteiro
        emit("  mflo %s\n", RegTempInt[x]);  // Move o quociente de `lo` para o registrador de destino
    }
    
    return x;  // Retorna o registrador que contém o resultado
}

int emit_var_use(AST *ast)
{
    int x;

    int var_idx = get_data(ast);

    int pos_func = get_pos_fun(ast);

    Type var_type = get_typevar_in_func(ft, var_idx, pos_func);
    switch (var_type)
    {
    case INT_TYPE:
        check_int_registers();
        x = new_int_reg();
        emit("  lw %s, var%d%d\n", RegTempInt[x], pos_func, var_idx);
        break;

    case FLOAT_TYPE:
        check_float_registers();
        x = new_float_reg();
        emit("  s.s %s, var%d%d\n", RegTempFloat[x], pos_func, var_idx);
        break;

    case CHAR_TYPE:
        check_int_registers();
        x = new_int_reg();
        emit("  sb %s, var%d%d\n", RegTempInt[x], pos_func, var_idx);
        break;

    default:
        fprintf(stderr, "Invalid type: %s!\n", get_text(var_type));
        break;
    }
    return x;
}

int emit_increment(AST *ast)
{

    AST *var = get_child(ast, 0);

    int x = rec_emit_code(var);

    int var_idx = get_data(var);

    int pos_func = get_pos_fun(var);

    Type var_type = get_typevar_in_func(ft, var_idx, pos_func);
    if (var_type == INT_TYPE)
    {

        emit("  addi %s, %s ,%d\n", RegTempInt[x], RegTempInt[x], 1);
        emit (" sw %s, var%d%d\n", RegTempInt[x], pos_func, var_idx);
    }
    else
    {
        check_float_registers();
        int y = new_float_reg();
        check_int_registers();
        int a = new_int_reg();

        emit("  li %s %s\n", RegTempInt[a], "0x3F800000"); // 0x3F800000 é 1.0 em IEEE 754
        int_regs_count--;
        emit("  mtc1 %s, %s\n", RegTempInt[a], RegTempFloat[y]);
        emit("  add.s %s, %s, %s\n", RegTempFloat[x], RegTempFloat[x], RegTempFloat[y]);
        emit("  s.s %s var%d%d\n", RegTempFloat[x], pos_func, var_idx);
    }
    printf("\n\n");
}

int emit_decrement(AST *ast)
{

    AST *var = get_child(ast, 0);
    int x = rec_emit_code(var);
    int var_idx = get_data(var);
    int pos_func = get_pos_fun(var);
    Type var_type = get_typevar_in_func(ft, var_idx, pos_func);
    if (var_type == INT_TYPE)
    {

        emit("  subi %s, %s ,%d\n", RegTempInt[x], RegTempInt[x], 1);
        emit (" sw %s, var%d%d\n", RegTempInt[x], pos_func, var_idx);
    }
    else
    {
        check_float_registers();
        int y = new_float_reg();
        check_int_registers();
        int a = new_int_reg();

        emit("  li %s %s\n", RegTempInt[a], "0x3F800000"); // 0x3F800000 é 1.0 em IEEE 754
        int_regs_count--;
        emit("  mtc1 %s, %s\n", RegTempInt[a], RegTempFloat[y]);
        emit("  sub.s %s, %s, %s\n", RegTempFloat[x], RegTempFloat[x], RegTempFloat[y]);
        emit("  s.s %s var%d%d\n", RegTempFloat[x], pos_func, var_idx);
    }
}

int emit_return(AST *ast)
{
    rec_emit_code(get_child(ast, 0));
}

int emit_array_decl(AST *ast)
{
    trace("array_decl");

    // Pega tamanho do vetor
    AST *child_init = get_child(ast, 1);
    int size = get_node_size(get_child(ast, 0));

    // Se o tamanho do array não foi definido
    if (size == 0) {
        fprintf(stderr, "Erro: Array sem tamanho especificado!\n");
        exit(EXIT_FAILURE);
    }

    // Obtém o índice da variável e a posição da função
    int var_idx = get_data(get_child(ast, 0));
    int pos_func = get_pos_fun(get_child(ast, 0));

    // Obtém o tipo da variável
    Type var_type = get_typevar_in_func(ft, var_idx, pos_func);

    // Prepara o array para inicialização
    switch (var_type) {
        case INT_TYPE:
            for (int i = 0; i < size; i++) {
                printf("li $t0, %d\n", get_data(get_child(child_init, i)));
                printf("sw $t0, var%d%d+%d\n\n", pos_func, var_idx, i*2);
            }
            break;

        case FLOAT_TYPE:
            for (int i = 0; i < size; i++) {
                
            }
            break;

        case CHAR_TYPE:
            for (int i = 0; i < size; i++) {
                
            }
            break;

        case NO_TYPE:
        default:
            fprintf(stderr, "Invalid type: %s!\n", get_text(var_type));
            exit(EXIT_FAILURE);
    }
}

// ----------------------------------------------------------------------------

// Prints ----------------------------------------------------------------------

#define LINE_SIZE 80
#define MAX_STR_SIZE 128

void get_instruction_string(Instr instr, char *s)
{
    OpCode op = instr.op;
    s += sprintf(s, "%s", OpStr[op]);
    int op_count = OpCount[op];
    if (op_count == 1)
    {
        sprintf(s, " %d", instr.o1);
    }
    else if (op_count == 2)
    {
        sprintf(s, " %d, %d", instr.o1, instr.o2);
    }
    else if (op_count == 3)
    {
        sprintf(s, " %d, %d, %d", instr.o1, instr.o2, instr.o3);
    }
}

void dump_str_table()
{
    int table_size = get_str_table_size(st);
    for (int i = 0; i < table_size; i++)
    {
        printf("string%d: .asciiz %s\n", i, get_string(st, i));
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
                if(get_size(vTable, j) > 0){
                    printf("    var%d%d: .space %d\n", i,j, get_size(vTable, j));
                }
                else
                {
                    printf("    var%d%d: .word 0\n",i,j);
                }
            }
            if (tipo == FLOAT_TYPE)
            {
                printf("    var%d%d: .float 0.0\n", i,j);
            }
            if (tipo == CHAR_TYPE)
            {
                if(get_size(vTable, j) > 0){
                    printf("    var%d%d: .space %d\n", i,j, get_size(vTable, j));
                }
                else
                {
                    printf("    var%d%d: .byte '0'\n", i,j);
                }
            }
        }
    }

    printf("\n");
}


void emit_func_decl(){
    
}

void write_instruction(int addr)
{
    Instr instr = code[addr];
    char instr_str[LINE_SIZE];
    get_instruction_string(instr, instr_str);
    printf("%s\n", instr_str);
}

void dump_program()
{
    printf("next_instr: %d\n", next_instr);
    for (int addr = 0; addr < next_instr; addr++)
    {
        write_instruction(addr);
    }
}
// -----------------------------------------------------------------------------

// ----------------------------------------------------------------------------

int rec_emit_code(AST *ast)
{
    switch (get_kind(ast))
    {
        // Essa é a base para o t8.c
    case PROGRAM_NODE:
        emit_program(ast);
        break;
    case FUN_DECL_NODE:
        emit_fun_decl(ast);
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
        break;
    case VAR_LIST_NODE:
        emit_var_list(ast);
        break;
    case ASSIGN_NODE:
        emit_assign(ast);
        break;
        // case ASSIGN_NODE:   emit_assign(ast);    break;
        // case EQUALS_NODE:   emit_eq(ast);        break;
        // case BLOCK_NODE:    emit_block(ast);     break;
        // case BOOL_VAL_NODE: emit_bool_val(ast);  break;
        // case IF_NODE:       emit_if(ast);        break;
    case INT_VAL_NODE:
        emit_int_val(ast);
        break;
        // case LT_NODE:       emit_lt(ast);        break;
    case MINUS_NODE:
        emit_minus(ast);
        break;
    case OVER_NODE:
        emit_over(ast);
        break;
    case PLUS_NODE:
        emit_plus(ast);
        break;
        // case READ_NODE:     emit_read(ast);      break;
    case REAL_VAL_NODE:
        emit_real_val(ast);
        break;
        // case REPEAT_NODE:   emit_repeat(ast);    break;

    case TIMES_NODE:
        emit_times(ast);
        break;
        // case VAR_DECL_NODE: emit_var_decl(ast);  break;
        // case VAR_LIST_NODE: emit_var_list(ast);  break;
    case VAR_USE_NODE:
        emit_var_use(ast);
        break;
        // case FUN_DECL_NODE: emit_fun_decl(ast);  break;
        // case B2I_NODE:      emit_b2i(ast);       break;
        // case B2R_NODE:      emit_b2r(ast);       break;
        // case B2S_NODE:      emit_b2s(ast);       break;
        // case I2F_NODE:      emit_i2r(ast);       break;
        //  Mudei I2S_NODE para I2C_NODE
        // case I2C_NODE:      emit_i2s(ast);       break;
        // case R2S_NODE:      emit_r2s(ast);       break;
        // case PARAM_LIST_NODE: emit_param_list(ast); break;
    case INCREMENT_NODE:
        emit_increment(ast);
        break;
    case DECREMENT_NODE:
        emit_decrement(ast);
        break;
    // case C2F_NODE: emit_c2f(ast); break;
    case RETURN_NODE:
        emit_return(ast);
        break;
        // case ARRAY_DECL_NODE: emit_array_decl(ast); break;
        // case ARRAY_ACCESS_NODE: emit_array_acess(ast); break;
        // case GREATER_THAN_NODE: emit_greather_than(ast); break;
        // case LESS_THAN_NODE: emit_less_than(ast); break;
        // case GREATER_THAN_OR_EQUAL_NODE: emit_greather_than_or_equal(ast); break;
        // case LESS_THAN_OR_EQUAL_NODE: emit_less_than_or_equal(ast); break;
    case CHAR_VAL_NODE:
        emit_char_val(ast);
        break;
        // case LOGICAL_OR_NODE: emit_logical_or(ast); break;
        // case NOT_EQUALS_NODE: emit_not_equals(ast); break;
        // case LOGICAL_AND_NODE: emit_logical_and(ast); break;
        // case SUB_ASSIGN_NODE: emit_sub_assign(ast); break;
        // case DIV_ASSIGN_NODE: emit_div_assign(ast); break;
        // case MUL_ASSIGN_NODE: emit_mul_assign(ast); break;
        // case MOD_ASSIGN_NODE: emit_mod_assign(ast); break;
        // case C2I_NODE: emit_c2i(ast); break;

        case ARRAY_DECL_NODE:
            emit_array_decl(ast);
            break;

        default:
            fprintf(stderr, "Invalid kind: %s!\n", kind2str(get_kind(ast)));
        exit(EXIT_FAILURE);
    }
}

void emit_code(AST *ast)
{
    next_instr = 0;
    int_regs_count = 0;
    float_regs_count = 0;
    printf(".data\n");
    dump_str_table();
    dump_var_table();
    int_regs_count = 0;
    float_regs_count = 2;
    printf(".text\n");
    printf(".globl main\n\n");
    printf("main:\n");
    rec_emit_code(ast);
}