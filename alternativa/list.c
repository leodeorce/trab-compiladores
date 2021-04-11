#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

struct node {
   char* name;
   int line;
   Type type;
   struct node *next;
};


// -------- Var_table ---------

Var_table* createVarTable(void) {
    return NULL;
}

void printVars(Var_table* table) {

   int i = 0;
   
   struct node *ptr = table;
   printf("---------Tabela de Variaveis-------\n");
	
   while(ptr != NULL) {
      printf("Pos %d\t-- name: %s,\tline: %d,\ttype: %s\n", i, ptr->name, ptr->line, get_text(ptr->type));
      ptr = ptr->next;
      i++;
   }
}

void addVar(Var_table** table, int line, const char* str, Type type) {

   struct node *link = (struct node*) malloc(sizeof(struct node));
   	
   link->line = line;
   link->name = malloc( sizeof(char) * (strlen (str) + 1)); 
   strcpy(link->name, str);

   link->type = type;   
   link->next = *table;

   *table = link;
}

void changeVarType(Var_table* table, const char* name, Type type) {
  
  struct node* var = findVar(table, name);

  if(var != NULL) {
     var->type = type;
  }
}

void deleteVarFirst(Var_table** table) {

   Var_table* aux = *table;
   struct node *tempLink = aux;
	
   free(tempLink->name);
   free(tempLink);

   aux = aux->next;
   
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

struct node* findVar(Var_table* table, const char* name) {

	// Caso lista vazia
	if(table == NULL) {
		return NULL;
	}

	struct node* current = table;

	while(strcmp(current->name, name) != 0) {

		// Caso chegou ao final
		if(current->next == NULL) {
			return NULL;
		}

		current = current->next;
	}

	return current;
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

Type getType(struct node* item) {
   return item->type;
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

   int i = 0;
   struct node_str *ptr = table;
   printf("---------Tabela de Strings-------\n");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("Pos %d\t-- line: %d,\tstring: %s\n", i, ptr->key, ptr->str);
      ptr = ptr->next;
      i++;
   }
}

void addStr(Str_table** table, int key, const char* str) {

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

void freeStrs(Str_table** table) {

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
Var_table* delete(Var_table* table, int line) {

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