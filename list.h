#ifndef LIST_H
#define LIST_H

// #include "list.h";

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

struct node* findVar(Var_table* table,int key);

int varExist(Var_table* table, int key);

void freeVars(Var_table** table);

#endif // TABLES_H