#ifndef LIST_H
#define LIST_H

// #include "list.h";
#include "types.h"


// ----------- Var_table -----------

struct node;
typedef struct node Var_table;

// Inicia tabela
Var_table* createVarTable(void);

// Escreve os itens da tabela
void printVars(Var_table* table);

// Insere novo item no início da tabela
void addVar(Var_table** table, int line, char* str, Type type);

// Deleta o primeiro item da tabela
void deleteVarFirst(Var_table** table);

// Retorna o tamanho da tabela
int lengthVarTable(Var_table* table);

// Modifica o tipo de uma variavel especifica
void changeVarType(Var_table* table, char* name, Type type);

// Verifica se uma variavel existe na tabela e retorna seu link
struct node* findVar(Var_table* table, char* name);

// Libera a tabela
void freeVars(Var_table** table);

// Retorna a linha na qual uma variavel foi declarada
int getLine(struct node* item);


// ---------- Str_table -----------

struct node_str;
typedef struct node_str Str_table;

// Inicia tabela
Str_table* createStrTable();

// Escreve os itens da tabela
void printStrs(Str_table* table);

// Insere novo item no início da tabela
void addStr(Str_table** table, int key, char* str);

// Retorna um item da tabela a partir de um identificador
struct node_str* getStr(Str_table* table, int key);

// Libera a tabela
void freeStrs(Str_table** table);


#endif // TABLES_H