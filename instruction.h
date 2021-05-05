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
    CEQd,
    MOVE,
    MOVd,

    // Operações sobre memória
    LA,
    Ld,
    LI,
    LW,
    Sd,
    SW,

    // Saltos
    BC1T,
    BEQ,
    J,

    // Chamada de sistema
    SYSCALL,

    // Nenhum
    LABEL,

} OpCode;

// Representação em string de opcodes.
static char* OpStr[] = {
    "add", "add.d", "c.eq.d", "move", "mov.d",
    "la", "l.d", "li", "lw", "s.d", "sw",
    "bc1t", "beq", "j",
    "syscall",
    "",
};

// Número de argumentos para cada opcode.
static int OpCount[] = {
    3,  // add
    3,  // add.d
    2,  // c.eq.d
    2,  // move
    2,  // move.d
    2,  // la
    2,  // l.d
    2,  // li
    2,  // lw
    2,  // s.d
    2,  // sw
    1,  // bc1t
    3,  // beq
    1,  // j
    0,  // syscall
    0,  // label
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
    char *label;
} Instr;

#endif // INSTRUCTION_H