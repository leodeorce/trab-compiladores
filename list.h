#ifndef LIST_H
#define LIST_H

#include "types.h"


// ----------- Var_table -----------

struct node_var;
typedef struct node_var Var_table;

// Inicia tabela
Var_table* createVarTable(void);

// Escreve os itens da tabela
void printVars(Var_table* table);

// Insere novo item no início da tabela
int addVar(Var_table** table, int line, const char* str, Type type);

// Deleta o primeiro item da tabela
void deleteVarFirst(Var_table** table);

// Retorna o tamanho da tabela
int lengthVarTable(Var_table* table);

// Modifica o tipo de uma variavel especifica
void changeVarType(Var_table* table, int idx, Type type);

// Verifica se uma variavel existe na tabela e retorna seu indice ou -1 caso nao exista
int findVar(Var_table* table, const char* name);

// Libera a tabela
void freeVars(Var_table** table);

// Retorna a linha na qual uma variavel foi declarada
int getLine(Var_table* table, int idx);

// Retorna o tipo de uma variavel
Type getType(Var_table* table, int idx);

// Retorna o nome de uma variavel
char* getName(Var_table* table, int idx);


// ---------- Str_table -----------

struct node_str;
typedef struct node_str Str_table;

// Inicia tabela
Str_table* createStrTable();

// Escreve os itens da tabela
void printStrs(Str_table* table);

// Insere novo item no início da tabela
int addStr(Str_table** table, const char* str);

// Retorna o tamanho de uma tabela de strings
int lengthStrTable(Str_table* table);

// Retorna um item da tabela a partir de um identificador
char* getStr(Str_table* table, int idx);

// Libera a tabela
void freeStrs(Str_table** table);


#endif // TABLES_H