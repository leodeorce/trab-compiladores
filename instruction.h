#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#define TEMP_REGS_COUNT   10      // $t0 -> $t9
#define DOUBLE_REGS_COUNT 16      // ($f0, $f1) -> ($f30, $f31)

// Como o tamanho do segmento de texto é muito grande
// (0x1000000 - 0x00040000 = 0xFFC0000 = 268 173 312 bytes),
// vamos simplificar para um tamanho menor.
#define INSTR_MEM_SIZE 256000
#define DATA_MEM_SIZE  196608    // Com base no padrão do simulador MARS

// Opcodes.
typedef enum {

    // Operações aritméticas
    ADD,

    // Operações sobre memória
    LA,
    Ld,
    Sd,
    SW,

} OpCode;

// Representação em string de opcodes.
static char* OpStr[] = {
    "add",
    "la",
    "l.d",
    "s.d",
    "sw",
};

// Número de argumentos para cada opcode.
static int OpCount[] = {
    3,  // add
    2,  // la
    2,  // l.d
    2,  // s.d
    2,  // sw
};

typedef enum {
    T,  // $t0 -> $t9
    F,  // $f0 -> $f30 (só os pares)
    A,  // $a0
    V   // $v0
} RegType;

// Quádrupla.
typedef struct {
    OpCode op;
    char *o1;
    char *o2;
    char *o3;
} Instr;

#endif // INSTRUCTION_H