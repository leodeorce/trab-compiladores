#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"
//#include "types.h"

struct node {
   char* name;
   int line;
   Type type;
   struct node *next;
};

// struct node *head = NULL;
// struct node *current = NULL;


// -------- Var_table ---------

Var_table* createVarTable() {
    Var_table *head = NULL;
    return head;
};

void printVars(Var_table* table) {

   // struct node *ptr = head;
   struct node *ptr = table;
   printf("\n---------Tabela de Variaveis-------\n");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("linha-> %d\t\t | nome-> %s | \t\t type->  %s\n", ptr->line, ptr->name, get_text(ptr->type));
      ptr = ptr->next;
   }
	
   printf(" \n");
}

void addVar(Var_table** table ,int line, char* str, Type type) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   	
   link->line = line;
   link->name = malloc( sizeof(char) * (strlen (str) + 1)); 
   strcpy(link->name, str);

   link->type = type; 
   
   //point it to old first node
   link->next = *table;

   //point first to new first node
   *table = link;
}

void changeVarType(Var_table** table, char* key_var, Type type) {
  
  struct node* var = findVar(table, key_var);

  if(var != NULL) {
     var->type = type;
  }
}

void deleteVarFirst(Var_table** table) {

   //save reference to first link
   Var_table* aux = *table;
   struct node *tempLink = aux;
	
   free(tempLink->name);
   free(tempLink);
   //mark next to first link as first 
   aux = aux->next;
   
   //change reference origes
   *table = aux;
}

int lengthVarTable(Var_table* table) {

   int length = 0;
   struct node *current;
	
   for(current = table; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

struct node* findVar(Var_table** table, char* str) {

   //start from the first link
   struct node* current = *table;

   //if list is empty
   if(current == NULL) {
      return NULL;
   }

   //navigate through list
   while(strcmp(current->name, str)) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

int varExist(Var_table* table, char* str) {

   //start from the first link
   struct node* current = table;

   //if list is empty
   if(table == NULL) {
      return 0;
   }

   //navigate through list
   while(strcmp(current->name, str)) {
	
      //if it is last node
      if(current->next == NULL) {
         return 0;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return 1;
}

void freeVars(Var_table** table) {

   struct node* current = *table;
   struct node* next;
	
   while (current != NULL) {
      next = current->next;
      free(current->name);
      free(current);
      current = next;
   }
	*table = NULL;
}

int getLine(struct node* item) {
   return item->line;
}


// ----------- Str_table -----------

struct node_str {
   char* str;
   int key;
   struct node_str *next;
};

Str_table* createStrTable() {
    Str_table *head = NULL;
    return head;
};

void printStrs(Str_table* table) {

   // struct node *ptr = head;
   struct node_str *ptr = table;
     printf("\n---------Tabela de Strings-------\n");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("linha-> %d\t | string-> %s \n", ptr->key, ptr->str);
      ptr = ptr->next;
   }
	
   printf("\n");
}

void addStr(Str_table** table ,int key, char* str) {

   struct node_str *link = (struct node_str*) malloc(sizeof(struct node));
   
	link->key = key;
   link->str = malloc( sizeof(char) * (strlen (str) + 1)); 

   strcpy(link->str, str);
	
   link->next = *table;
   *table = link;
}

struct node_str* getStr(Str_table* table, int key) {

   struct node_str* current = table;

   if(table == NULL) {
      return NULL;
   }

   while(current->key != key) {

	   if(current->next == NULL) {
         return NULL;
      } 
      else {
         current = current->next;
      }
   }      
	
   return current;
}

void freeStrs(Str_table** table){

   struct node_str* current = *table;
   struct node_str* next;
	
   while (current != NULL) {
      next = current->next;
      free(current->str);
      free(current);
      current = next;
   }

	*table = NULL;
}


// ------ Utils ------

void reverse(struct node** head_ref) {

   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}

bool isEmpty(Var_table* table) {
   return table == NULL;
}

//delete a link with given line
Var_table* delete(Var_table* table,int line) {

   //start from the first link
   Var_table* current = table;
   Var_table* previous = NULL;
	
   //if list is empty
   if(table == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->line != line) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == table) {
      //change first to point to next link
      table = table->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}