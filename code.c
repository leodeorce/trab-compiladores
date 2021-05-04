#include <stdlib.h>
#include <stdio.h>
#include "code.h"
#include "instruction.h"
#include "tables.h"

// ===== Tabelas ==============

extern StrTable *st;
extern VarTable *vt;

// ===== Memória ==============

Instr code[INSTR_MEM_SIZE];
int next_instr;

// ===== Emits ================

void emit(OpCode op, int o1, int o2, int o3)
{
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

// ===== Prints ===============

#define LINE_SIZE 80

void get_instruction_string(Instr instr, char *s) {
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
    int table_size = lengthStrTable(st);     // Implementar
    for (int i = 0; i < table_size; i++) {
        //
    }
}

// ===== Caminhando a AST =====

int int_regs_count;
int float_regs_count;

#define new_int_reg() \
    int_regs_count++

#define new_double_reg() \
    double_regs_count++

int rec_emit_code(AST *ast);

// ----------------------------

int emit_assign(AST *ast) {
    //
    return -1;
}

int emit_plus(AST *ast) {
	//
	return x;
}

int emit_eq(AST *ast) {
	//
	return x;
}

int emit_var_use(AST *ast) {
	//
	return x;
}

// ----------------------------

int rec_emit_code(AST *ast)
{
    switch(get_kind(ast)) {
        case ASSIGN_NODE:   return emit_assign(ast);
        case PLUS_NODE:     return emit_plus(ast);
        case VAR_DECL_NODE: return emit_eq(ast);
        case VAR_USE_NODE:  return emit_var_use(ast);

        default:
            fprintf(stderr, "Invalid kind: %s!\n", kind2str(get_kind(ast)));
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
    dump_program();
}