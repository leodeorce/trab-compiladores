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

    // Operações sobre registradores
    ADD,
    ADDd,
    MOVE,
    MOVd,

    // Operações sobre memória
    LA,
    Ld,
    LI,
    LW,
    Sd,
    SW,

    // Chamada de sistema
    SYSCALL,

} OpCode;

// Representação em string de opcodes.
static char* OpStr[] = {
    "add", "add.d", "move", "mov.d",
    "la", "l.d", "li", "lw", "s.d", "sw",
    "syscall",
};

// Número de argumentos para cada opcode.
static int OpCount[] = {
    3,  // add
    3,  // add.d
    2,  // move
    2,  // move.d
    2,  // la
    2,  // l.d
    2,  // li
    2,  // lw
    2,  // s.d
    2,  // sw
    0,  // syscall
};

typedef enum {
    T,  // $t0 -> $t9
    F,  // $f0 -> $f30 (só os pares)
    A,  // $a0
    V,  // $v0
    Z,  // $zero
} RegType;

// Quádrupla.
typedef struct {
    OpCode op;
    char *o1;
    char *o2;
    char *o3;
} Instr;

#endif // INSTRUCTION_H