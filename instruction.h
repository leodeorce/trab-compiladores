#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#define INT_REGS_COUNT    18      // $t0 -> $t9 + $s0 -> $s7
#define DOUBLE_REGS_COUNT 16      // ($f0, $f1) -> ($f30, $f31)

// Como o tamanho do segmento de texto é muito grande
// (0x1000000 - 0x00040000 = 0xFFC0000 = 268 173 312 bytes),
// vamos simplificar para um tamanho menor.
#define INSTR_MEM_SIZE 256000
#define DATA_MEM_SIZE  196608    // Com base no padrão do simulador MARS

// Opcodes.
typedef enum {

    // Operações aritméticas
    add

} OpCode;

// Representação em string de opcodes.
static char* OpStr[] = {
    "add"
};

// Número de argumentos para cada opcode.
static int OpCount[] = {
    3  // add
};

// Quádrupla:
// Como TypeScript considera apenas um tipo 'number' para inteiros e floats,
// todo número que não é índice será considerado 'double'.
typedef struct {
    OpCode op;
    int o1;
    int o2;
    int o3;
} Instr;
