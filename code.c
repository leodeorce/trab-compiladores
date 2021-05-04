#include <stdlib.h>
#include <stdio.h>
#include "code.h"
#include "instruction.h"
#include "list.h"

// ===== Tabelas ==============

extern Str_table *st;
extern Var_table *vt;

// ===== Memória ==============

Instr code[INSTR_MEM_SIZE];
int next_instr;

// ===== Emits ================

void emit(OpCode op, Operand o1, Operand o2, Operand o3)
{
    code[next_instr].op = op;
    code[next_instr].o1 = o1;
    code[next_instr].o2 = o2;
    code[next_instr].o3 = o3;
    next_instr++;
}

#define emit0(op)             \
    Operand o;                \
    sprintf(o.as_reg, "\0");  \
    emit(op, o, o, o)         \

#define emit1(op, o1)         \
    Operand o;                \
    sprintf(o.as_reg, "\0");  \
    emit(op, o1, o, o)

#define emit2(op, o1, o2)     \
    Operand o;                \
    sprintf(o.as_reg, "\0");  \
    emit(op, o1, o2, o)

#define emit3(op, o1, o2, o3) \
    emit(op, o1, o2, o3)

// ===== Prints ===============

#define TRACE
#ifdef TRACE
#define trace(msg) printf("TRACE: %s\n", msg)
#else
#define trace(msg)
#endif

#define LINE_SIZE 80

void get_instruction_string(Instr instr, char *s)
{
    // Usar malloc
}

void write_instruction(int addr)
{
    Instr instr = code[addr];
    char instr_str[LINE_SIZE];                  // Trocar por malloc
    get_instruction_string(instr, instr_str);
    printf("%s\n", instr_str);
}

void dump_program()
{
    for (int addr = 0; addr < next_instr; addr++) {
        write_instruction(addr);
    }
}

void dump_str_table()
{
    printf(".data:\n");
    // int table_size = lengthStrTable(st);     // Implementar
    // for (int i = 0; i < table_size; i++) {
        //
    // }
}

void print_data(const char* name)
{
    // Como uma variável pode ser undefined, não sabemos
    // o espaço que ela ocupará ao ser inicializada.
    // Logo alocamos o maior espaço.
    printf("    %s: .double 0\n", name);
}

// ===== Caminhando a AST =====

int int_regs_count;

// Como TypeScript considera apenas um tipo 'number' para inteiros e floats,
// todo número que não é índice será considerado 'double'.
int double_regs_count;

#define new_int_reg() \
    int_regs_count++

#define new_double_reg() \
    double_regs_count++  \
    double_regs_count++

int rec_emit_code(AST *ast);

// ----------------------------

// Para saber se uma declaração inicializa a variável.
int declareAssign = 0;

Operand new_oper_reg(RegType regType, int num)
{
    Operand operand;
    switch(regType) {
        case T: sprintf(operand.as_reg, "$t%d", num); break;
        case F: sprintf(operand.as_reg, "$f%d", num); break;
        case A: sprintf(operand.as_reg, "$a0");       break;
        case V: sprintf(operand.as_reg, "$v0");       break;
    }
    return operand;
}

Operand new_oper_addr(int num)
{
    Operand operand;
    sprintf(operand.as_addr, "($t%d)", num);
    return operand;
}

Operand new_oper_label(const char* label)
{
    Operand operand;
    sprintf(operand.as_label, "%s", label);
    return operand;
}

int emit_assign(AST *ast)
{
    trace("emit_assign");
    AST *leftChild = get_child(ast, 0);
    AST *rightChild = get_child(ast, 1);
    declareAssign = 1;
    int x = rec_emit_code(leftChild);
    declareAssign = 0;
    int y = rec_emit_code(rightChild);
    Operand o1 = new_oper_reg(T, x);
    Operand o2 = new_oper_addr(y);
    emit2(sw, o1, o2);
    return -1;
}

int emit_num_val(AST *ast)
{
    trace("emit_num_val");
    //
    // return x;
}

int emit_plus(AST *ast)
{
    //
    // return x;
}

int emit_var_decl(AST *ast)
{
    trace("emit_var_decl");
    int x = get_idx(ast);
    char* name = getName(vt, x);
    print_data(name);
    if(declareAssign == 1) {
        x = new_int_reg();
        Operand o1 = new_oper_reg(T, x);
        Operand o2 = new_oper_label(name);
        emit2(la, o1, o2);
    }
    return x;
}

int emit_var_use(AST *ast)
{
    //
    // return x;
}

// ----------------------------

int rec_emit_code(AST *ast)
{
    trace("rec_emit_code");
    switch(get_kind(ast)) {

        case ASSIGN_NODE:   return emit_assign(ast);
        case NUM_VAL_NODE:  return emit_num_val(ast);
        // case PLUS_NODE:     return emit_plus(ast);
        case VAR_DECL_NODE: return emit_var_decl(ast);
        // case VAR_USE_NODE:  return emit_var_use(ast);

        default:
            fprintf(stderr, "NodeKind inválido: %s\n", kind2str(get_kind(ast)));
            exit(EXIT_FAILURE);
    }
}

// ----------------------------

void emit_code(AST *ast)
{
    next_instr = 0;
    int_regs_count = 0;
    double_regs_count = 0;
    dump_str_table();
    rec_emit_code(ast);
    // dump_program();
}