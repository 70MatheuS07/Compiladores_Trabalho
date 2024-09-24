#ifndef INSTRUCTION_H
#define INSTRUCTION_H

// Definição de quantidade de registradores inteiros e de ponto flutuante no MIPS.
#define INT_REGS_COUNT   32     // $0 to $31: registradores inteiros.
#define FLOAT_REGS_COUNT 32     // $f0 to $f31: registradores de ponto flutuante.

// Tamanho da memória de instruções e dados.
#define INSTR_MEM_SIZE  1024    // instr_mem[]: espaço para as instruções.
#define DATA_MEM_SIZE   1024    // data_mem[]: espaço para dados.

// Definição dos opcodes das principais instruções do MIPS.
typedef enum {
    // Aritmética com inteiros
    ADD,            // add $d, $s, $t
    SUB,            // sub $d, $s, $t
    MUL,            // mul $d, $s, $t
    DIV,            // div $s, $t ; $LO <- $s / $t, $HI <- resto
    ADDI,           // addi $t, $s, imm
    LI,             // li $t, imm            ; carrega imediato em registrador

    // Aritmética com ponto flutuante (single precision)
    ADD_S,          // add.s $f1, $f2, $f3
    SUB_S,          // sub.s $f1, $f2, $f3
    MUL_S,          // mul.s $f1, $f2, $f3
    DIV_S,          // div.s $f1, $f2, $f3

    // Operações lógicas
    AND,            // and $d, $s, $t
    OR,             // or $d, $s, $t
    XOR,            // xor $d, $s, $t
    NOR,            // nor $d, $s, $t

    // Comparações
    SLT,            // slt $d, $s, $t       ; $d <- ($s < $t)
    SLTI,           // slti $t, $s, imm      ; $t <- ($s < imm)

    // Branches e jumps
    BEQ,            // beq $s, $t, offset    ; se $s == $t, salta para offset
    BNE,            // bne $s, $t, offset    ; se $s != $t, salta para offset
    J,              // j target              ; salta para target
    JAL,            // jal target            ; $ra <- PC + 4, PC <- target
    JR,             // jr $s                 ; PC <- $s

    // Operações de carga e armazenamento
    LW,             // lw $t, offset($s)     ; carrega word
    SW,             // sw $t, offset($s)     ; armazena word
    LWC1,           // lwc1 $f1, offset($s)  ; carrega word em registrador float
    SWC1,           // swc1 $f1, offset($s)  ; armazena word de registrador float
    LA,             // la $t, label          ; carrega o endereço do label em $t

    // System call
    SYSCALL         // syscall
} OpCode;

// Quantidade de operandos para cada instrução.
static int OpCount[] = {
    3,  // ADD
    3,  // SUB
    3,  // MUL
    2,  // DIV
    3,  // ADDI
    2,  // LI
    3,  // ADD_S
    3,  // SUB_S
    3,  // MUL_S
    3,  // DIV_S
    3,  // AND
    3,  // OR
    3,  // XOR
    3,  // NOR
    3,  // SLT
    3,  // SLTI
    3,  // BEQ
    3,  // BNE
    1,  // J
    1,  // JAL
    1,  // JR
    3,  // LW
    3,  // SW
    3,  // LWC1
    3,  // SWC1
    2,  // LA
    0   // SYSCALL
};

// Representação das strings das instruções no formato MIPS para MARS.
static char* OpStr[] = {
    "add",      // ADD
    "sub",      // SUB
    "mul",      // MUL
    "div",      // DIV
    "addi",     // ADDI
    "li",       // LI
    "add.s",    // ADD_S
    "sub.s",    // SUB_S
    "mul.s",    "div.s",    // MUL_S, DIV_S
    "and",      // AND
    "or",       // OR
    "xor",      // XOR
    "nor",      // NOR
    "slt",      // SLT
    "slti",     // SLTI
    "beq",      // BEQ
    "bne",      // BNE
    "j",        // J
    "jal",      // JAL
    "jr",       // JR
    "lw",       // LW
    "sw",       // SW
    "lwc1",     // LWC1
    "swc1",     // SWC1
    "la",       // LA
    "syscall"   // SYSCALL
};

// Definição da estrutura de instrução MIPS.
typedef struct {
    OpCode op;    // Operação (opcode)
    int o1;       // Operando 1 (registrador ou imediato)
    int o2;       // Operando 2 (registrador ou offset)
    int o3;       // Operando 3 (registrador ou imediato)
} Instr;

#endif