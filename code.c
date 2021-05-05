#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "code.h"
#include "instruction.h"
#include "list.h"

// ===== Tabelas ==============

extern Str_table *st;
extern Var_table *vt;

// ===== Memória ==============

Instr code[INSTR_MEM_SIZE];
int next_instr;

void free_instr(void) {
    for(int i = 0; i < next_instr; i++) {
        free(code[i].o1);
        free(code[i].o2);
        free(code[i].o3);
    }
}

// ===== Emits ================

void emit(OpCode op, char *o1, char *o2, char *o3)
{
    code[next_instr].op = op;
    code[next_instr].o1 = o1;
    code[next_instr].o2 = o2;
    code[next_instr].o3 = o3;
    next_instr++;
}

#define emit0(op)      \
    emit(op, NULL, NULL, NULL)  \

#define emit1(op, o1)  \
    emit(op, o1, NULL, NULL)

#define emit2(op, o1, o2) \
    emit(op, o1, o2, NULL)

#define emit3(op, o1, o2, o3) \
    emit(op, o1, o2, o3)

// ===== Prints ===============

// Habilitar TRACE abaixo para imprimir debugs
// #define TRACE
#ifdef TRACE
#define trace(msg) printf("TRACE: %s\n", msg)
#else
#define trace(msg)
#endif

#define LINE_SIZE 1000

void get_instruction_string(Instr instr, char *str)
{
    // trace("get_instruction_string");
    OpCode op = instr.op;
    str += sprintf(str, "    %s", OpStr[op]);
    int op_count = OpCount[op];
    if (op_count == 1) {
        sprintf(str, " %s", instr.o1);
    } else if (op_count == 2) {
        sprintf(str, " %s, %s", instr.o1, instr.o2);
    } else if (op_count == 3) {
        sprintf(str, " %s, %s, %s", instr.o1, instr.o2, instr.o3);
    }
}

void write_instruction(int addr)
{
    // trace("write_instruction");
    Instr instr = code[addr];
    char instr_str[LINE_SIZE];
    get_instruction_string(instr, instr_str);
    printf("%s\n", instr_str);
}

void dump_program()
{
    trace("dump_program");
    printf("\n.text:\n");
    printf("\n.global main\n");
    printf("\nmain:\n");
    for (int addr = 0; addr < next_instr; addr++) {
        write_instruction(addr);
    }
}

void dump_str_table()
{
    trace("dump_str_table");
    printf(".data:\n");
    char* str;
    int table_size = lengthStrTable(st);
    for (int i = 0; i < table_size; i++) {
        str = getStr(st, i);
        printf("    string%d: .asciiz %s\n", i, str);
    }
}

void print_data_null(const char* name)
{
    trace("print_data_null");
    // Como uma variável pode ser undefined, não sabemos
    // o espaço que ela ocupará ao ser inicializada.
    // Logo alocamos o maior espaço.
    printf("    %s: .double 0\n", name);
}

void print_data_double(const char* name, double val)
{
    trace("print_data_double");
    printf("    %s: .double %f\n", name, val);
}

// ===== Caminhando a AST =====

int int_regs_count;

// Como TypeScript considera apenas um tipo 'number' para inteiros e floats,
// todo número que não é índice será considerado 'double'.
int double_regs_count;

int temp_number_count;

#define new_int_reg() \
    int_regs_count++

#define new_double_reg() \
    double_regs_count++; \
    double_regs_count++

#define new_temp_number() \
    temp_number_count++

int rec_emit_code(AST *ast);

// ----------------------------

char* get_oper_reg(RegType regType, int num)
{
    trace("get_oper_reg");
    char operand[10];
    switch(regType) {
        case T: sprintf(operand, "$t%d", num); break;
        case F: sprintf(operand, "$f%d", num); break;
        case A: sprintf(operand, "$a%d", num); break;
        case V: sprintf(operand, "$v%d", num); break;
        case Z: sprintf(operand, "$zero");     break;
    }
    return strdup(operand);
}

char* get_oper_addr(int num)
{
    trace("get_oper_addr");
    char operand[10];
    sprintf(operand, "0($t%d)", num);
    return strdup(operand);
}

char* get_oper_label(const char* label)
{
    trace("get_oper_label");
    char *operand = (char*) malloc(strlen(label) + 1);
    sprintf(operand, "%s", label);
    return operand;
}

char* get_oper_double(double val)
{
    trace("get_oper_double");
    char operand[500];
    sprintf(operand, "%f", val);
    return strdup(operand);
}

char* get_oper_int(int val)
{
    trace("get_oper_int");
    char operand[50];
    sprintf(operand, "%d", val);
    return strdup(operand);
}

int emit_assign(AST *ast)
{
    trace("emit_assign");
    AST *leftChild = get_child(ast, 0);
    AST *rightChild = get_child(ast, 1);
    int x = rec_emit_code(leftChild);
    int y = rec_emit_code(rightChild);
    char *o1, *o2;
    Type type = getType(vt, x);
    NodeKind leftKind = get_kind(leftChild);
    if(leftKind == VAR_DECL_NODE) {
        const char *name = getName(vt, x);
        x = new_int_reg();
        o1 = get_oper_reg(T, x);
        o2 = get_oper_label(name);
        emit2(LA, o1, o2);
    }
    o2 = get_oper_addr(x);
    if(type == NUMBER_TYPE || type == BOOLEAN_TYPE) {
        o1 = get_oper_reg(F, y);
        emit2(Sd, o1, o2);
    } else if(type == STRING_TYPE) {
        o1 = get_oper_reg(T, y);
        emit2(SW, o1, o2);
    } else {
        // Considerar verificar NodeKind caso seja VAR_USE
        // para checar tipo pela tabela e não pelo node
        // (requer criar nodes de conversão undefined -> outros)
        Type rightType = get_node_type(rightChild);
        if(rightType == STRING_TYPE) {
            o1 = get_oper_reg(T, y);
            emit2(Sd, o1, o2);
        } else {
            o1 = get_oper_reg(F, y);
            emit2(SW, o1, o2);
        }
    }
    return -1;
}

int emit_begin(AST *ast) {
    trace("emit_begin");
    rec_emit_code(get_child(ast, 0));
    return -1;
}

int emit_block(AST *ast) {
    trace("emit_block");
    int childCount = get_child_count(ast);
    for(int i = 0; i < childCount; i++) {
        rec_emit_code(get_child(ast, i));
        int_regs_count = 0;
        double_regs_count = 0;
    }
    return -1;
}

int emit_num_val(AST *ast)
{
    trace("emit_num_val");
    double val = get_double_data(ast);
    char tempName[100];
    char *name = tempName;
    int tempNumber = new_temp_number();
    sprintf(name, "temp%d", tempNumber);  // Necessário para carregar um valor float
    print_data_double(tempName, val);     // em um registrador $f# no simulador MARS.
    int x = new_double_reg();
    char *o1 = get_oper_reg(F, x);
    char *o2 = get_oper_label(tempName);
    emit2(Ld, o1, o2);
    return x;
}

int emit_plus(AST *ast)
{
    trace("emit_plus");
    AST *leftChild = get_child(ast, 0);
    AST *rightChild = get_child(ast, 1);
    int x = rec_emit_code(leftChild);
    int y = rec_emit_code(rightChild);
    int z = new_double_reg();
    char *o1 = get_oper_reg(F, z);
    char *o2, *o3;
    char *o4, *o5;
    NodeKind leftKind = get_kind(leftChild);
    NodeKind rightKind = get_kind(rightChild);
    if(leftKind == VAR_USE_NODE) {
        o5 = get_oper_addr(x);
        int newReg = new_double_reg();
        o4 = get_oper_reg(F, newReg);
        emit2(Ld, o4, o5);
        o2 = strdup(o4);
    } else {
        o2 = get_oper_reg(F, x);
    }
    if(rightKind == VAR_USE_NODE) {
        o5 = get_oper_addr(y);
        int newReg = new_double_reg();
        o4 = get_oper_reg(F, newReg);
        emit2(Ld, o4, o5);
        o3 = strdup(o4);
    } else {
        o3 = get_oper_reg(F, y);
    }
    emit3(ADDd, o1, o2, o3);
    return z;
}

int emit_print(AST *ast)
{
    trace("emit_print");
    AST *child = get_child(ast, 0);
    int x = rec_emit_code(child);
    char *o1 = get_oper_reg(V, 0);
    char *o2;
    NodeKind kind = get_kind(child);
    if(kind == STR_VAL_NODE) {
        o2 = get_oper_int(4);
        emit2(LI, o1, o2);
        o1 = get_oper_reg(A, 0);
        o2 = get_oper_reg(T, x);
        emit2(MOVE, o1, o2);
    } else if(kind == VAR_USE_NODE) {
        o2 = get_oper_int(4);
        emit2(LI, o1, o2);
        o1 = get_oper_reg(A, 0);
        o2 = get_oper_addr(x);
        emit2(LW, o1, o2);
    } else {
        o2 = get_oper_int(3);
        emit2(LI, o1, o2);
        o1 = get_oper_reg(F, 12);
        o2 = get_oper_reg(F, x);
        emit2(MOVd, o1, o2);
    }
    emit0(SYSCALL);
    return -1;
}

int emit_str_val(AST *ast)
{
    trace("emit_str_val");
    int idx = get_idx(ast);
    char strLabel[100];
    char *label = strLabel;
    sprintf(label, "string%d", idx);
    int x = new_int_reg();
    char *o1 = get_oper_reg(T, x);
    char *o2 = get_oper_label(strLabel);
    emit2(LA, o1, o2);
    return x;
}

int emit_var_decl(AST *ast)
{
    trace("emit_var_decl");
    int x = get_idx(ast);
    char* name = getName(vt, x);
    print_data_null(name);
    return x;
}

int emit_var_use(AST *ast)
{
    trace("emit_var_use");
    int idx = get_idx(ast);
    const char* name = getName(vt, idx);
    int x = new_int_reg();
    char *o1 = get_oper_reg(T, x);
    char *o2 = get_oper_label(name);
    emit2(LA, o1, o2);
    return x;
}

int emit_n2s(AST *ast)
{
    trace("emit_n2s");
    AST *child = get_child(ast, 0);
    int x = rec_emit_code(child);
    return x;
}

// ----------------------------

int rec_emit_code(AST *ast)
{
    trace("rec_emit_code");
    switch(get_kind(ast)) {

        case ASSIGN_NODE:   return emit_assign(ast);
        case BEGIN_NODE:    return emit_begin(ast);
        case BLOCK_NODE:    return emit_block(ast);
        case BOOL_VAL_NODE: return emit_num_val(ast);
        case NUM_VAL_NODE:  return emit_num_val(ast);
        case PLUS_NODE:     return emit_plus(ast);
        case PRINT_NODE:    return emit_print(ast);
        case STR_VAL_NODE:  return emit_str_val(ast);
        case VAR_DECL_NODE: return emit_var_decl(ast);
        case VAR_USE_NODE:  return emit_var_use(ast);

        case N2S_NODE:      return emit_n2s(ast);

        default:
            fprintf(stderr, "NodeKind inválido: %s\n", kind2str(get_kind(ast)));
            exit(EXIT_FAILURE);
    }
}

// ----------------------------

void emit_code(AST *ast)
{
    trace("emit_code");
    next_instr = 0;
    int_regs_count = 0;
    double_regs_count = 0;
    temp_number_count = 0;
    dump_str_table();
    rec_emit_code(ast);
    dump_program();
    free_instr();
}