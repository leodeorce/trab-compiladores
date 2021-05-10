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
        free(code[i].label);
    }
}

// ===== Emits ================

void emit(OpCode op, char *o1, char *o2, char *o3, char *label)
{
    code[next_instr].op = op;
    code[next_instr].o1 = o1;
    code[next_instr].o2 = o2;
    code[next_instr].o3 = o3;
    code[next_instr].label = label;
    next_instr++;
}

void emitL(char *label)
{
    code[next_instr].op = LABEL;
    code[next_instr].o1 = NULL;
    code[next_instr].o2 = NULL;
    code[next_instr].o3 = NULL;
    code[next_instr].label = label;
    next_instr++;
}

#define emit0(op)                    \
    emit(op, NULL, NULL, NULL, NULL)

#define emit1(op, o1)                \
    emit(op, o1, NULL, NULL, NULL)

#define emit2(op, o1, o2)            \
    emit(op, o1, o2, NULL, NULL)

#define emit3(op, o1, o2, o3)        \
    emit(op, o1, o2, o3, NULL)

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
    if(op == LABEL) {
        char *label = instr.label;
        str += sprintf(str, "\n%s:", label);
    } else {
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

void print_data_null(const char *name)
{
    trace("print_data_null");
    // Como uma variável pode ser undefined, não sabemos
    // o espaço que ela ocupará ao ser inicializada.
    // Logo alocamos o maior espaço dentre os possíveis tipos.
    printf("    %s: .double 0\n", name);
}

void print_data_double(const char *name, double val)
{
    trace("print_data_double");
    printf("    %s: .double %f\n", name, val);
}

void print_data_str(const char *name, const char *str)
{
    trace("print_data_str");
    printf("    %s: .asciiz \"%s\"\n", name, str);
}

void print_label(const char *label)
{
    trace("print_label");
    printf("    %s:\n", label);
}

void dump_str_table(void)
{
    trace("dump_str_table");
    printf(".data:\n");
    char* str;
    int table_size = lengthStrTable(st);
    for (int i = 0; i < table_size; i++) {
        str = getStr(st, i);
        char label[100];
        sprintf(label, "string%d", i);
        print_data_str(label, str);
    }
}

// ===== Caminhando a AST =====

int int_regs_count;

// Como TypeScript considera apenas um tipo 'number' para inteiros e floats,
// todo número que não é índice será considerado 'double'.
int double_regs_count;

int temp_number_count;

int boolcheck_number_count;
int compcheck_number_count;
int ifcheck_number_count;
int whilecheck_number_count;
int andcheck_number_count;

// Auxiliam na escrita de valores booleanos em stdout.
int true_str_loaded = 0;
int false_str_loaded = 0;
int true_temp_idx;
int false_temp_idx;

// Auxiliam no uso dos valores 0 e 1
int one_double_loaded = 0;
int zero_double_loaded = 0;
int one_temp_idx;
int zero_temp_idx;

#define new_int_reg() \
    int_regs_count++

#define new_double_reg() \
    double_regs_count++; \
    double_regs_count++

#define new_temp_number() \
    temp_number_count++

#define new_boolcheck_number() \
    boolcheck_number_count++

#define new_compcheck_number() \
    compcheck_number_count++

#define new_ifcheck_number() \
    ifcheck_number_count++
    
#define new_whilecheck_number() \
    whilecheck_number_count++
    
#define new_andcheck_number() \
    andcheck_number_count++

int rec_emit_code(AST *ast);

// ----------------------------

int true_str_addr(void)
{
    int addr;
    int x;
    if(true_str_loaded == 0) {
        x = new_temp_number();
        char label[100];
        sprintf(label, "temp%d", x);
        char str[5] = "true";
        print_data_str(label, str);
        true_temp_idx = x;
        true_str_loaded = 1;
    }
    addr = true_temp_idx;
    return addr;
}

int false_str_addr(void)
{
    int addr;
    int y;
    if(false_str_loaded == 0) {
        y = new_temp_number();
        char label[100];
        sprintf(label, "temp%d", y);
        char str[6] = "false";
        print_data_str(label, str);
        false_temp_idx = y;
        false_str_loaded = 1;
    }
    addr = false_temp_idx;
    return addr;
}

int one_double_addr(void)
{
    int addr;
    int x;
    if(one_double_loaded == 0) {
        x = new_temp_number();
        char label[100];
        sprintf(label, "temp%d", x);
        print_data_double(label, 1);
        one_temp_idx = x;
        one_double_loaded = 1;
    }
    addr = one_temp_idx;
    return addr;
}

int zero_double_addr(void)
{
    int addr;
    int x;
    if(zero_double_loaded == 0) {
        x = new_temp_number();
        char label[100];
        sprintf(label, "temp%d", x);
        print_data_double(label, 0);
        zero_temp_idx = x;
        zero_double_loaded = 1;
    }
    addr = zero_temp_idx;
    return addr;
}

char* get_oper_reg(RegType regType, int num)
{
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
    char operand[10];
    sprintf(operand, "0($t%d)", num);
    return strdup(operand);
}

char* get_oper_label(const char* label)
{
    char *operand = (char*) malloc(strlen(label) + 1);
    sprintf(operand, "%s", label);
    return operand;
}

char* get_oper_double(double val)
{
    char operand[500];
    sprintf(operand, "%f", val);
    return strdup(operand);
}

char* get_oper_int(int val)
{
    char operand[50];
    sprintf(operand, "%d", val);
    return strdup(operand);
}

int emit_and(AST *ast)
{
    trace("emit_and");
    AST *leftChild = get_child(ast, 0);
    AST *rightChild = get_child(ast, 1);
    int x = rec_emit_code(leftChild);
    int y = rec_emit_code(rightChild);
    int z = new_double_reg();
    char *o1, *o2;
    char *o3, *o4;
    NodeKind leftKind = get_kind(leftChild);
    NodeKind rightKind = get_kind(rightChild);

    // Resgata valor booleano da esquerda
    if(leftKind == VAR_USE_NODE) {
        o4 = get_oper_addr(x);
        int newReg = new_double_reg();
        o3 = get_oper_reg(F, newReg);
        emit2(Ld, o3, o4);
        o1 = get_oper_reg(F, newReg);
    } else {
        o1 = get_oper_reg(F, x);
    }
    
    // Prepara registrador com double 0
    int zeroReg = new_double_reg();
    o3 = get_oper_reg(F, zeroReg);
    int zeroDoubleAddr = zero_double_addr();
    char zeroTemp[10];
    sprintf(zeroTemp, "temp%d", zeroDoubleAddr);
    o4 = get_oper_label(zeroTemp);
    emit2(Ld, o3, o4);

    // Seta condição se lado esquerdo é falso
    o2 = get_oper_reg(F, zeroReg);
    emit2(CEQd, o1, o2);

    // Cria labels para:
    // i.   AND é falso e devemos retornar registrador com valor 0.
    // ii.  Lado esquerdo é verdadeiro e devemos checar o lado direito.
    // iii. AND é verdadeiro e devemos retornar registrador com valor 1.
    char *label;
    int andCheckNum;
    char labelLeftTrue[100];
    andCheckNum = new_andcheck_number();
    sprintf(labelLeftTrue, "AndLeftTrue%d", andCheckNum);
    char labelTrue[100];
    sprintf(labelTrue, "AndCheckTrue%d", andCheckNum);
    char labelFalse[100];
    sprintf(labelFalse, "AndCheckFalse%d", andCheckNum);
    char labelEnd[100];
    sprintf(labelEnd, "AndCheckEnd%d", andCheckNum);

    // Salto para AndCheckFalse caso lado esquerdo seja 0
    o1 = get_oper_label(labelFalse);
    emit1(BC1T, o1);

    // Continua para AndLeftTrue caso lado esquerdo seja 1
    label = get_oper_label(labelLeftTrue);
    emitL(label);
    if(rightKind == VAR_USE_NODE) {
        o4 = get_oper_addr(y);
        int newReg = new_double_reg();
        o3 = get_oper_reg(F, newReg);
        emit2(Ld, o3, o4);
        o1 = get_oper_reg(F, newReg);
    } else {
        o1 = get_oper_reg(F, y);
    }
    o2 = get_oper_reg(F, zeroReg);
    emit2(CEQd, o1, o2);

    // Salto para AndCheckFalse caso lado direito seja 0
    o1 = get_oper_label(labelFalse);
    emit1(BC1T, o1);

    // Continua para AndCheckTrue caso lado direito também seja 1
    // Armazena 1 em um registrador $f# cujo id será retornado
    label = get_oper_label(labelTrue);
    emitL(label);
    int oneReg = new_double_reg();
    o1 = get_oper_reg(F, oneReg);
    int oneDoubleAddr = one_double_addr();
    char oneTemp[10];
    sprintf(oneTemp, "temp%d", oneDoubleAddr);
    o2 = get_oper_label(oneTemp);
    emit2(Ld, o1, o2);
    o1 = get_oper_reg(F, z);
    o2 = get_oper_reg(F, oneReg);
    emit2(MOVd, o1, o2);
    label = get_oper_label(labelEnd);
    emit1(J, label);

    // Armazena 0 em um registrador $f# cujo id será retornado
    label = get_oper_label(labelFalse);
    emitL(label);
    o1 = get_oper_reg(F, z);
    o2 = get_oper_reg(F, zeroReg);
    emit2(MOVd, o1, o2);
    label = get_oper_label(labelEnd);
    emit1(J, label);

    label = get_oper_label(labelEnd);
    emitL(label);

    return z;
}

int emit_arithmetic(AST *ast, OpCode op)
{
    trace("emit_arithmetic");
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
        o2 = get_oper_reg(F, newReg);
    } else {
        o2 = get_oper_reg(F, x);
    }
    if(rightKind == VAR_USE_NODE) {
        o5 = get_oper_addr(y);
        int newReg = new_double_reg();
        o4 = get_oper_reg(F, newReg);
        emit2(Ld, o4, o5);
        o3 = get_oper_reg(F, newReg);
    } else {
        o3 = get_oper_reg(F, y);
    }
    emit3(op, o1, o2, o3);
    return z;
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
    NodeKind rightKind = get_kind(rightChild);
    if(rightKind == VAR_USE_NODE) {
        int newReg = new_double_reg();
        o1 = get_oper_reg(F, newReg);
        o2 = get_oper_addr(y);
        emit2(Ld, o1, o2);
        o1 = get_oper_reg(F, newReg);
        o2 = get_oper_addr(x);
        emit2(Sd, o1, o2);
    } else {
        o2 = get_oper_addr(x);
        if(type == NUMBER_TYPE || type == BOOLEAN_TYPE) {
            o1 = get_oper_reg(F, y);
            emit2(Sd, o1, o2);
        } else {
            o1 = get_oper_reg(T, y);
            emit2(SW, o1, o2);
        }
    }
    return -1;
}

int emit_begin(AST *ast)
{
    trace("emit_begin");
    rec_emit_code(get_child(ast, 0));
    char *o1 = get_oper_reg(V, 0);
    char *o2 = get_oper_int(10);
    emit2(LI, o1, o2);
    emit0(SYSCALL);
    return -1;
}

int emit_block(AST *ast)
{
    trace("emit_block");
    int childCount = get_child_count(ast);
    for(int i = 0; i < childCount; i++) {
        rec_emit_code(get_child(ast, i));
        int_regs_count = 0;
        double_regs_count = 0;
    }
    return -1;
}

int emit_compare(AST *ast, OpCode op1, OpCode op2)
{
    trace("emit_compare");
    AST *leftChild = get_child(ast, 0);
    AST *rightChild = get_child(ast, 1);
    int x = rec_emit_code(leftChild);
    int y = rec_emit_code(rightChild);
    char *o1, *o2;
    char *o3, *o4;
    NodeKind leftKind = get_kind(leftChild);
    NodeKind rightKind = get_kind(rightChild);
    if(leftKind == VAR_USE_NODE) {
        o4 = get_oper_addr(x);
        int newReg = new_double_reg();
        o3 = get_oper_reg(F, newReg);
        emit2(Ld, o3, o4);
        o1 = get_oper_reg(F, newReg);
    } else {
        o1 = get_oper_reg(F, x);
    }
    if(rightKind == VAR_USE_NODE) {
        o4 = get_oper_addr(y);
        int newReg = new_double_reg();
        o3 = get_oper_reg(F, newReg);
        emit2(Ld, o3, o4);
        o2 = get_oper_reg(F, newReg);
    } else {
        o2 = get_oper_reg(F, y);
    }
    emit2(op1, o1, o2);

    // Cria labels para saltos
    char *label;
    int returnReg, compCheckNum;
    char labelA[100];
    compCheckNum = new_compcheck_number();
    sprintf(labelA, "CompCheckA%d", compCheckNum);
    char labelB[100];
    sprintf(labelB, "CompCheckB%d", compCheckNum);
    char labelEnd[100];
    sprintf(labelEnd, "CompCheckEnd%d", compCheckNum);

    // Salto depende do OpCode op2
    o1 = get_oper_label(labelA);
    emit1(op2, o1);

    // Armazena 0 em um registrador $f# caso não ocorra salto
    label = get_oper_label(labelB);
    emitL(label);
    returnReg = new_double_reg();
    o1 = get_oper_reg(F, returnReg);
    int zeroDoubleAddr = zero_double_addr();
    char zeroTemp[10];
    sprintf(zeroTemp, "temp%d", zeroDoubleAddr);
    o2 = get_oper_label(zeroTemp);
    emit2(Ld, o1, o2);
    o1 = get_oper_label(labelEnd);
    emit1(J, o1);

    // Armazena 1 em um registrador $f# caso ocorra salto
    label = get_oper_label(labelA);
    emitL(label);
    o1 = get_oper_reg(F, returnReg);
    int oneDoubleAddr = one_double_addr();
    char oneTemp[10];
    sprintf(oneTemp, "temp%d", oneDoubleAddr);
    o2 = get_oper_label(oneTemp);
    emit2(Ld, o1, o2);

    label = get_oper_label(labelEnd);
    emitL(label);

    return returnReg;
}

int emit_div(AST *ast)
{
    trace("emit_div");
    return emit_arithmetic(ast, DIVd);
}

int emit_eq(AST *ast)
{
    trace("emit_eq");
    return emit_compare(ast, CEQd, BC1T);
}

int emit_gt(AST *ast)
{
    trace("emit_gt");
    return emit_compare(ast, CLEd, BC1F);
}

int emit_if(AST *ast)
{
    trace("emit_if");
    AST *firstChild = get_child(ast, 0);
    AST *secondChild = get_child(ast, 1);
    AST *thirdChild = get_child(ast, 2);
    int x = rec_emit_code(firstChild);
    char *o1, *o2;
    char *label;
    int ifCheckNum;

    int newReg = new_double_reg();
    o1 = get_oper_reg(F, newReg);
    int zeroDoubleAddr = zero_double_addr();
    char zeroTemp[10];
    sprintf(zeroTemp, "temp%d", zeroDoubleAddr);
    o2 = get_oper_label(zeroTemp);
    emit2(Ld, o1, o2);
    
    o1 = get_oper_reg(F, x);
    o2 = get_oper_reg(F, newReg);
    emit2(CEQd, o1, o2);

    char labelTrue[100];
    ifCheckNum = new_ifcheck_number();
    sprintf(labelTrue, "IfCheckTrue%d", ifCheckNum);
    char labelFalse[100];
    sprintf(labelFalse, "IfCheckFalse%d", ifCheckNum);
    char labelEnd[100];
    sprintf(labelEnd, "IfCheckEnd%d", ifCheckNum);

    if(thirdChild != NULL) {
        // if
        o1 = get_oper_label(labelTrue);
        emit1(BC1T, o1);
        // then
        label = get_oper_label(labelFalse);
        emitL(label);
        x = rec_emit_code(secondChild);
        o1 = get_oper_label(labelEnd);
        emit1(J, o1);
        // else
        label = get_oper_label(labelTrue);
        emitL(label);
        x = rec_emit_code(thirdChild);
    } else {
        // if
        o1 = get_oper_label(labelEnd);
        emit1(BC1T, o1);
        // then
        label = get_oper_label(labelFalse);
        emitL(label);
        x = rec_emit_code(secondChild);
    }

    label = get_oper_label(labelEnd);
    emitL(label);

    return -1;
}

int emit_ineq(AST *ast)
{
    trace("emit_ineq");
    return emit_compare(ast, CEQd, BC1F);
}

int emit_lt(AST *ast)
{
    trace("emit_lt");
    return emit_compare(ast, CLTd, BC1T);
}

int emit_mult(AST *ast)
{
    trace("emit_mult");
    return emit_arithmetic(ast, MULd);
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
    return emit_arithmetic(ast, ADDd);
}

int emit_print(AST *ast)
{
    trace("emit_print");
    AST *child = get_child(ast, 0);
    int x = rec_emit_code(child);
    char *o1, *o2, *label;
    NodeKind kind = get_kind(child);
    if(kind == STR_VAL_NODE || kind == U2S_NODE) {
        o1 = get_oper_reg(V, 0);
        o2 = get_oper_int(4);
        emit2(LI, o1, o2);
        o1 = get_oper_reg(A, 0);
        o2 = get_oper_reg(T, x);
        emit2(MOVE, o1, o2);
    } else if(kind == VAR_USE_NODE) {
        o1 = get_oper_reg(V, 0);
        o2 = get_oper_int(4);
        emit2(LI, o1, o2);
        o1 = get_oper_reg(A, 0);
        o2 = get_oper_addr(x);
        emit2(LW, o1, o2);
    } else if(kind == B2S_NODE) {

        // Carrega o tipo de syscall em $a0
        o1 = get_oper_reg(V, 0);
        o2 = get_oper_int(4);
        emit2(LI, o1, o2);

        // Cria os labels a serem usados
        int boolCheckNum;
        char labelFalse[100];
        boolCheckNum = new_boolcheck_number();
        sprintf(labelFalse, "BoolCheckFalse%d", boolCheckNum);
        char labelTrue[100];
        sprintf(labelTrue, "BoolCheckTrue%d", boolCheckNum);
        char labelEnd[100];
        sprintf(labelEnd, "BoolCheckEnd%d", boolCheckNum);

        // Avalia expressão condicional
        int zeroRegNum = new_double_reg();
        o1 = get_oper_reg(F, zeroRegNum);
        int zeroDoubleAddr = zero_double_addr();
        char zeroTemp[10];
        sprintf(zeroTemp, "temp%d", zeroDoubleAddr);
        o2 = get_oper_label(zeroTemp);
        emit2(Ld, o1, o2);
        o1 = get_oper_reg(F, x);
        o2 = get_oper_reg(F, zeroRegNum);
        emit2(CEQd, o1, o2);

        o1 = get_oper_label(labelFalse);
        emit1(BC1T, o1);

        // Imprime o resultado como 'true'
        label = get_oper_label(labelTrue);
        emitL(label);
        int regTrue = new_int_reg();
        o1 = get_oper_reg(T, regTrue);
        int trueStrAddr = true_str_addr();
        char tempNameTrue[10];
        sprintf(tempNameTrue, "temp%d", trueStrAddr);
        o2 = get_oper_label(tempNameTrue);
        emit2(LA, o1, o2);
        o1 = get_oper_reg(A, 0);
        o2 = get_oper_reg(T, regTrue);
        emit2(MOVE, o1, o2);

        // Salto incondicional após 'true'
        o1 = get_oper_label(labelEnd);
        emit1(J, o1);

        // Imprime o resultado como 'false'
        label = get_oper_label(labelFalse);
        emitL(label);
        int regFalse = new_int_reg();
        o1 = get_oper_reg(T, regFalse);
        int falseStrAddr = false_str_addr();
        char tempNameFalse[10];
        sprintf(tempNameFalse, "temp%d", falseStrAddr);
        o2 = get_oper_label(tempNameFalse);
        emit2(LA, o1, o2);
        o1 = get_oper_reg(A, 0);
        o2 = get_oper_reg(T, regFalse);
        emit2(MOVE, o1, o2);

        // Label para salto incondicional
        label = get_oper_label(labelEnd);
        emitL(label);

    } else if(kind == N2S_NODE) {
        o1 = get_oper_reg(V, 0);
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

int emit_sub(AST *ast)
{
    trace("emit_sub");
    return emit_arithmetic(ast, SUBd);
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

int emit_b2s(AST *ast)
{
    trace("emit_b2s");
    AST *child = get_child(ast, 0);
    int x = rec_emit_code(child);
    NodeKind kind = get_kind(child);
    if(kind == VAR_USE_NODE) {
        int newReg = new_double_reg();
        char *o1 = get_oper_reg(F, newReg);
        char *o2 = get_oper_addr(x);
        emit2(Ld, o1, o2);
        x = newReg;
    }
    return x;
}

int emit_n2s(AST *ast)
{
    trace("emit_n2s");
    AST *child = get_child(ast, 0);
    int x = rec_emit_code(child);
    NodeKind kind = get_kind(child);
    if(kind == VAR_USE_NODE) {
        int newReg = new_double_reg();
        char *o1 = get_oper_reg(F, newReg);
        char *o2 = get_oper_addr(x);
        emit2(Ld, o1, o2);
        x = newReg;
    }
    return x;
}

int emit_u2s(AST *ast)
{
    trace("emit_u2s");
    char tempName[10];
    int tempNumber = new_temp_number();
    sprintf(tempName, "temp%d", tempNumber);
    char tempStr[10] = "undefined";
    print_data_str(tempName, tempStr);
    int x = new_double_reg();
    char *o1 = get_oper_reg(T, x);
    char *o2 = get_oper_label(tempName);
    emit2(LA, o1, o2);
    return x;
}

int emit_while(AST *ast)
{
    trace("emit_while");
    AST *leftChild = get_child(ast, 0);
    AST *rightChild = get_child(ast, 1);
    char *label;

    char labelCond[100];
    int whileCheckNumber = new_whilecheck_number();
    sprintf(labelCond, "WhileCond%d", whileCheckNumber);
    char labelTrue[100];
    sprintf(labelTrue, "WhileTrue%d", whileCheckNumber);
    char labelEnd[100];
    sprintf(labelEnd, "WhileEnd%d", whileCheckNumber);

    label = get_oper_label(labelCond);
    emitL(label);
    int x = rec_emit_code(leftChild);
    NodeKind kind = get_kind(leftChild);
    char *o1, *o2, *o3, *o4;
    if(kind == VAR_USE_NODE) {
        o2 = get_oper_addr(x);
        int newReg = new_double_reg();
        o1 = get_oper_reg(F, newReg);
        emit2(Ld, o1, o2);
        o1 = get_oper_reg(F, newReg);
    } else {
        o1 = get_oper_reg(F, x);
    }
    int zeroDoubleAddr = zero_double_addr();
    char zeroTemp[10];
    sprintf(zeroTemp, "temp%d", zeroDoubleAddr);
    o4 = get_oper_label(zeroTemp);
    int zeroReg = new_double_reg();
    o3 = get_oper_reg(F, zeroReg);
    emit2(Ld, o3, o4);
    o2 = get_oper_reg(F, zeroReg);
    emit2(CEQd, o1, o2);
    o1 = get_oper_label(labelEnd);
    emit1(BC1T, o1);

    label = get_oper_label(labelTrue);
    emitL(label);
    rec_emit_code(rightChild);
    o1 = get_oper_label(labelCond);
    emit1(J, o1);

    label = get_oper_label(labelEnd);
    emitL(label);
    return -1;
}

// ----------------------------

int rec_emit_code(AST *ast)
{
    trace("rec_emit_code");
    switch(get_kind(ast)) {

        // TODO: emit_or
        case AND_NODE:      return emit_and(ast);
        case ASSIGN_NODE:   return emit_assign(ast);
        case BEGIN_NODE:    return emit_begin(ast);
        case BLOCK_NODE:    return emit_block(ast);
        case BOOL_VAL_NODE: return emit_num_val(ast);
        case DIV_NODE:      return emit_div(ast);
        case EQ_NODE:       return emit_eq(ast);
        case GT_NODE:       return emit_gt(ast);
        case IF_NODE:       return emit_if(ast);
        case INEQ_NODE:     return emit_ineq(ast);
        case LT_NODE:       return emit_lt(ast);
        case MULT_NODE:     return emit_mult(ast);
        case NUM_VAL_NODE:  return emit_num_val(ast);
        case PLUS_NODE:     return emit_plus(ast);
        case PRINT_NODE:    return emit_print(ast);
        case STR_VAL_NODE:  return emit_str_val(ast);
        case SUB_NODE:      return emit_sub(ast);
        case VAR_DECL_NODE: return emit_var_decl(ast);
        case VAR_USE_NODE:  return emit_var_use(ast);
        case WHILE_NODE:    return emit_while(ast);

        case B2S_NODE:      return emit_b2s(ast);
        case N2S_NODE:      return emit_n2s(ast);
        case U2S_NODE:      return emit_u2s(ast);

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
    boolcheck_number_count = 0;
    compcheck_number_count = 0;
    ifcheck_number_count = 0;
    whilecheck_number_count = 0;
    andcheck_number_count = 0;
    dump_str_table();
    rec_emit_code(ast);
    dump_program();
    free_instr();
}