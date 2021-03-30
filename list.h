#ifndef LIST_H
#define LIST_H

// #include "list.h";
#include "types.h"


struct node;
typedef struct node Var_table;



//start table
Var_table* createVarTable();


//display the list
void printVars(Var_table* table);

//insert link at the first location
void addVar(Var_table** table ,int key, char* str);

//delete first item
void deleteVarFirst(Var_table** table);

int lengthVarTable(Var_table* table);

struct node* findVar(Var_table** table, char* str);

void changeVarType(Var_table** table, char* key_var, Type type);

int varExist(Var_table* table, char* str);

void freeVars(Var_table** table);


// ---------- Str_table-----------

struct node_str;
typedef struct node_str Str_table;

Str_table* createStrTable();

void printStrs(Str_table* table);

void addStr(Str_table** table ,int key, char* str);

struct node_str* getStr(Str_table* table, int key);

void freeStrs(Str_table** table);


#endif // TABLES_H