
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "list.h"

// ----------------------------------------------------------------------------

extern Str_table *st;
extern Var_table *vt;

typedef union {
    int   as_int;
    float as_float;
    double as_number
} Word;

// ----------------------------------------------------------------------------

// Data stack -----------------------------------------------------------------

#define STACK_SIZE 100

Word stack[STACK_SIZE];
int sp; // stack pointer

// All these ops should have a boundary check, buuuut... X_X

// ------------------- Add e retira Numbers da pilha -------------
void pushN(double x){
    stack[++sp].as_number = x;
}

double popN(){
   return stack[sp--].as_number;
}
// -------------------------------------------------------------


void pushi(int x) {
    stack[++sp].as_int = x;
}

int popi() {
    return stack[sp--].as_int;
}

void pushf(float x) {
    stack[++sp].as_float = x;
}

float popf() {
    return stack[sp--].as_float;
}

void init_stack() {
    for (int i = 0; i < STACK_SIZE; i++) {
        stack[i].as_int = 0;
    }
    sp = -1;
}

void print_stack() {
    printf("*** STACK: ");
    for (int i = 0; i <= sp; i++) {
        printf("%d ", stack[i].as_int);
    }
    printf("\n");
}

// ----------------------------------------------------------------------------

// Variables memory -----------------------------------------------------------

#define MEM_SIZE 100

Word mem[MEM_SIZE];

void storei(int addr, int val) {
    mem[addr].as_int = val;
}

int loadi(int addr) {
    return mem[addr].as_int;
}

// ---------- Le e cria Number na pilha ----------

double loadN(int addr) {
    return mem[addr].as_number;
}

void storeN(int addr, double val){
    mem[addr].as_number = val;
}

//--------------------------------------------------

void storef(int addr, float val) {
    mem[addr].as_float = val;
}

float loadf(int addr) {
    return mem[addr].as_float;
}

void init_mem() {
    for (int addr = 0; addr < MEM_SIZE; addr++) {
        mem[addr].as_int = 0;
    }
}

// ----------------------------------------------------------------------------

// #define TRACE
#ifdef TRACE
#define trace(msg) printf("TRACE: %s\n", msg)
#else
#define trace(msg)
#endif

#define MAX_STR_SIZE 128
static char str_buf[MAX_STR_SIZE];
#define clear_str_buf() str_buf[0] = '\0'

void rec_run_ast(AST *ast);

// -----------Read Numberrr=--------------
void read_number(int var_idx){
    double x;
    printf("read (Number): ");
    scanf("%lf", &x);
    storeN(var_idx, x);
}
//---------------------------------------



void read_bool(int var_idx) {
    int x;
    do {
        printf("read (bool - 0 = false, 1 = true): ");
        scanf("%d", &x);
    } while (x != 0 && x != 1);
    storei(var_idx, x);
}

void read_str(int var_idx) {
    printf("read (str): ");
    clear_str_buf();
    scanf("%s", str_buf);   // Did anyone say Buffer Overflow..? ;P
    storei(var_idx, addStr(&st, str_buf));
}

// --------------Printa um number -----------------
void write_number(){
    printf("%lf\n", popN());
}
//-----------------------------------------------



void write_bool() {
    popi() == 0 ? printf("false\n") : printf("true\n");
}

// Helper function to write strings.
void escape_str(const char* s, char *n) {
    int i = 0, j = 0;
    char c;
    while ((c = s[i++]) != '\0') {
        if (c == '"') { continue; }
        else if (c == '\\' && s[i] == 'n') {
            n[j++] = '\n';
            i++;
        } else {
            n[j++] = c;
        }
    }
    n[j] = '\0';
}

void write_str() {
    int s = popi(); // String pointer
    clear_str_buf();
    escape_str(get_str(st, s), str_buf);
    printf(str_buf); // Weird language semantics, if printing a string, no new line.
}

#define run_bin_op()                \
    AST *lexpr = get_child(ast, 0); \
    AST *rexpr = get_child(ast, 1); \
    rec_run_ast(lexpr);             \
    rec_run_ast(rexpr)

// ------------------- Soma number ------------------
void plus_number(AST *ast) {
    run_bin_op();
    double r = popN();
    double l = popN();
    pushN(l + r);
}
// -------------------------------------------------


void plus_bool(AST *ast) {
    run_bin_op();
    int r = popi();
    int l = popi();
    pushi(l || r); // Can't add l and r here because of overflow (>1).
}

void plus_str(AST *ast) {
    run_bin_op();
    int r = popi();
    int l = popi();
    clear_str_buf();
    strcat(str_buf, get_str(st, l));
    strcat(str_buf, get_str(st, r));
    pushi(addStr(st, str_buf));
}



// ---------------- Roda outras aridades ----------------------
void run_other_arith_number(AST *ast, int (*int_op)(int,int)) {
    run_bin_op();
    if (get_node_type(ast) == NUMBER_TYPE) {
        double r = popN();
        double l = popN();
        pushN(int_op(l,r));
    } 
    else { // Result must be REAL_TYPE.
        printf("ver qq faz quando não for number");
    }
}
// ---------------------------------------------------

// ------------ Subitração com Number ---------------
double number_minus(double l, double r){
     return l - r;
    }
// -------------------------------------------------


// --------------- Divisão com Number---------------------
double number_over(double l, double r) {
    return l / r;
}
// ----------------------------------------------------


// ----------- Multiplicaçao com Number ----------------------
double number_times(double l, double r) {
    return l * r;
}


// ***************** RUM CMP 2 ************************
void run_cmp_2(AST *ast, int (*number_cmp)(int,int), int (*str_cmp)(char*,char*)) {
    run_bin_op();
    if (get_node_type(ast) == STRING_TYPE) {
        int r = popi();
        int l = popi();
        pushi(str_cmp(get_str(st, l), get_str(st, r)));
    }
    else { // Result is REAL_TYPE.
        double r = popN();
        double l = popN();
        pushi(number_cmp(l,r));
    }
}
// *****************************************

// ************ Igualdede entre numeros ************
int number_eq(double l, double r){
    return l == r;
}
// *********************************



int str_eq(char *l, char *r) {
    return (strcmp(l, r) == 0);
}


// ************* Mernor que com Bumber ***************
int number_lt(double l, double r) {
    return l < r;
}
// *************8*******************************


int str_lt(char *l, char *r) {
    return (strcmp(l, r) < 0);
}

// ----------------------------------------------------------------------------




// -------------------------Roda atribuição de numeros*********************
void run_assign_2(AST *ast) {
    trace("assign");
    AST *rexpr = get_child(ast, 1);
    rec_run_ast(rexpr);
    int var_idx = get_double_data(get_child(ast, 0));
    Type var_type = getType(vt, var_idx);
    // if (var_type == REAL_TYPE) {
    if (var_type == NUMBER_TYPE) {
        storeN(var_idx, popN());
    } else {
        // storei(var_idx, popi());
        printf("Ve qq vai fazer quando não for numero");
    }
}
// ****************************************


// *************** Iqualdade entre numero*****************
void run_eq_2(AST *ast) {
    trace("eq");
    run_cmp_2(ast, number_eq, str_eq);
}
// *******************************


void run_block(AST *ast) {
    trace("block");
    int size = get_child_count(ast);
    for (int i = 0; i < size; i++) {
        rec_run_ast(get_child(ast, i));
    }
}

void run_bool_val(AST *ast) {
    trace("bool_val");
    pushi(get_double_data(ast));
}

void run_if(AST *ast) {
    trace("if");
    rec_run_ast(get_child(ast, 0));
    int test = popi();
    if (test == 1) {
        rec_run_ast(get_child(ast, 1));
    } else if (test == 0 && get_child_count(ast) == 3) {
        rec_run_ast(get_child(ast, 2));
    }
}

// --------------- Run NUMBER val ---------------------
void run_number_val(AST *ast){
    trace("numeber_val");
    pushN(get_double_data(ast));
}
// ------------------------------------

// --------------- Rum lt --------------
void run_lt_2(AST *ast) {
    trace("lt");
    run_cmp_2(ast, number_lt, str_lt);
}
// --------------- Rum lt --------------



// ------------ Rum Minus --------------
void run_minus_2(AST *ast) {
    trace("minus");
    run_other_arith_number(ast, number_minus);
}
// ----------------------------------------

// ---------------- Rum Oven -------------------------
void run_over_2(AST *ast) {
    trace("over");
    run_other_arith_number(ast, number_over);
}
// ---------------- =-------------------------

// --------------------- Roda Soma-----------------
void run_plus_2(AST *ast) {
    trace("plus");
    Type plus_type = get_node_type(ast);
    switch(plus_type) {
        case NUMBER_TYPE:       plus_number(ast);     break;
        case BOOLEAN_TYPE:      plus_bool(ast);       break;
        case STRING_TYPE:       plus_str(ast);        break;
        case NO_TYPE:
        default:
            fprintf(stderr, "Invalid type: %s!\n", get_text(plus_type));
            exit(EXIT_FAILURE);
    }
}
// --------------------------------------



void run_program(AST *ast) {
    trace("program");
    rec_run_ast(get_child(ast, 0)); // run var_list
    rec_run_ast(get_child(ast, 1)); // run block
}


// ------------ rUM READ------------------------
void run_read(AST *ast) {
    trace("read");
    int var_idx = get_double_data(get_child(ast, 0));
    Type var_type = getType(vt, var_idx);
    switch(var_type) {
        case NUMBER_TYPE:       read_number(var_idx);   break;
        case BOOLEAN_TYPE:      read_bool(var_idx);    break;
        case STRING_TYPE:       read_str(var_idx);     break;
        case NO_TYPE:
        default:
            fprintf(stderr, "Invalid type: %s!\n", get_text(var_type));
            exit(EXIT_FAILURE);
    }
}
// ---------------------------------


void run_repeat(AST *ast) {
    trace("repeat");
    int again = 1;
    while (again) {
        rec_run_ast(get_child(ast, 0)); // Run body.
        rec_run_ast(get_child(ast, 1)); // Run test.
        again = !popi();
    }
}

void run_str_val(AST *ast) {
    trace("str_val");
    pushi(get_double_data(ast));
}

// --------------m Multiplicação ----------------------
void run_times_2(AST *ast) {
    trace("times");
    run_other_arith_number(ast, number_times);
}
// --------------m Multiplicação ----------------------


void run_var_decl(AST *ast) {
    trace("var_decl");
    // Nothing to do, memory was already cleared upon initialization.
}


// -------------------- Rum Var 2------------------
void run_var_use_2(AST *ast) {
    trace("var_use");
    int var_idx = get_double_data(ast);
    if (get_node_type(ast) == NUMBER_TYPE) {
        pushf(loadN(var_idx));
    } else {
        // pushi(loadi(var_idx));
        printf("ver oq fazer quando n e numero");
    }
}
// -------------------- Rum Var 2------------------



// ------------------- Run weit var 2------------
void run_write_2(AST *ast) {
    trace("write");
    AST *expr = get_child(ast, 0);
    rec_run_ast(expr);
    Type expr_type = get_node_type(expr);
    switch(expr_type) {
        case NUMBER_TYPE:   write_number();    break;
        case BOOLEAN_TYPE:  write_bool();      break;
        case STRING_TYPE:   write_str();       break;
        case NO_TYPE:
        default:
            fprintf(stderr, "Invalid type: %s!\n", get_text(expr_type));
            exit(EXIT_FAILURE);
    }
}
// ------------------- Run weit var 2------------



// -------------------uSANDOOOOO--------------
void run_b2s(AST* ast) {
    rec_run_ast(get_child(ast, 0));
    clear_str_buf();
    popi() == 0 ? sprintf(str_buf, "false") : sprintf(str_buf, "true");
    pushi(addStr(st, str_buf));
}
// -------------------uSANDOOOOO--------------



// ***************** N2S*******************
void run_n2s(AST* ast) {
    rec_run_ast(get_child(ast, 0));
    clear_str_buf();
    sprintf(str_buf, "%fl", popN());
    pushN(addStr(st, str_buf));
}
// ***********************************

void debug(AST *ast, char* kid_name){
    printf("Rodando ->> %s \n", kid_name);
}

void not_function(char* kid_name){
    printf("Criara uma função para ->> %s \n", kid_name);
}

void rec_run_ast(AST *ast) {
    switch(get_kind(ast)) {

        // ---------- Aproveitamento das funções do professor--------
        case BEGIN_NODE:            run_program(ast), debug(ast, "BEGIN_NODE") ;   break;  

        case ASSIGN_NODE:          run_assign_2(ast), debug(ast, "ASSIGN_NODE");             break;
        case EQ_NODE:              run_eq_2(ast), debug(ast, "ASSIGN_NODE");                 break;
        case IF_NODE:              run_if(ast), debug(ast, "ASSIGN_NODE");                 break;
        case BLOCK_NODE:           run_block(ast), debug(ast, "ASSIGN_NODE");              break;
        case BOOL_VAL_NODE:        run_bool_val(ast), debug(ast, "ASSIGN_NODE");           break;

        case DIV_NODE:             run_over_2(ast), debug(ast, "ASSIGN_NODE");             break; 
        case MULT_NODE:            run_times_2(ast), debug(ast, "ASSIGN_NODE");              break; 
        case PLUS_NODE:            run_plus_2(ast), debug(ast, "ASSIGN_NODE");             break; 
        case PRINT_NODE:           run_write_2(ast), debug(ast, "ASSIGN_NODE");            break;
        case SUB_NODE:             run_minus_2(ast), debug(ast, "ASSIGN_NODE");            break;
        case STR_VAL_NODE:         run_str_val(ast), debug(ast, "ASSIGN_NODE");            break;
        case VAR_DECL_NODE:        run_var_decl(ast), debug(ast, "ASSIGN_NODE");           break;
        case WHILE_NODE:           run_repeat(ast), debug(ast, "ASSIGN_NODE");             break;
        case NUM_VAL_NODE:         run_number_val(ast), debug(ast, "ASSIGN_NODE");         break; 
        case VAR_USE_NODE:         run_read(ast);               break;

        case LT_NODE:               run_lt_2(ast), debug(ast, "ASSIGN_NODE");              break; 

        case  B2S_NODE:             run_b2s(ast), debug(ast, "ASSIGN_NODE");               break;
        case  N2S_NODE:             run_n2s(ast), debug(ast, "ASSIGN_NODE");               break;

        //-----------------Tem que implementar--------------------
        case GT_EQ_NODE:            debug(ast, "GT_EQ_NODE");   break; 
        case GT_NODE:               debug(ast, "GT_NODE");      break; 
        case INEQ_NODE:             debug(ast, "INEQ_NODE");    break; 
        case LT_EQ_NODE:            debug(ast, "LT_EQ_NODE");   break; 
        case OR_NODE:               debug(ast, "OR_NODE");      break; 


        case  B2U_NODE:             debug(ast, "B2U_NODE");     break;
        case  N2U_NODE:             debug(ast, "N2U_NODE");     break;
        case  S2U_NODE:             debug(ast, "S2U_NODE");     break;
        case  U2S_NODE:             debug(ast, "U2S_NODE");     break;

        default:
            fprintf(stderr, "Invalid kind: %s!\n", kind2str(get_kind(ast)));
            exit(EXIT_FAILURE);
    }
}

// ----------------------------------------------------------------------------


   // case INT_VAL_NODE:  run_int_val(ast);   break;
        // case LT_NODE:       run_lt(ast);        break;
        // case MINUS_NODE:    run_minus(ast);     break;
        // case OVER_NODE:     run_over(ast);      break;
        // case PLUS_NODE:     run_plus(ast);      break;
        // case PROGRAM_NODE:  run_program(ast);   break;
        // case READ_NODE:     run_read(ast);      break;
        // case REAL_VAL_NODE: run_real_val(ast);  break;
        // case REPEAT_NODE:   run_repeat(ast);    break;
        // case STR_VAL_NODE:  run_str_val(ast);   break;
        // case TIMES_NODE:    run_times(ast);     break;
        // case VAR_DECL_NODE: run_var_decl(ast);  break;
        // case VAR_LIST_NODE: run_var_list(ast);  break;
        // case VAR_USE_NODE:  run_var_use(ast);   break;
        // case WRITE_NODE:    run_write(ast);     break;

        // case B2I_NODE:      run_b2i(ast);       break;
        // case B2R_NODE:      run_b2r(ast);       break;
        // case B2S_NODE:      run_b2s(ast);       break;
        // case I2R_NODE:      run_i2r(ast);       break;
        // case I2S_NODE:      run_i2s(ast);       break;
        // case R2S_NODE:      run_r2s(ast);       break;



void run_ast(AST *ast) {
    init_stack();
    init_mem();
    rec_run_ast(ast);
}
