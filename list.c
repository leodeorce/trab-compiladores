#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

static struct node_var* getNode(Var_table* table, int idx);

struct node_var {
   char *name;
   int  line;
   Type type;
   struct node_var *next;
};

// -------- Var_table ---------

Var_table* createVarTable(void) {
    return NULL;
}

void printVars(Var_table* table) {

   int i = 0;
   
   struct node_var *ptr = table;
   printf("---------Tabela de Variaveis-------\n");
	
   while(ptr != NULL) {
      printf("Pos %-4d-- name: %-10s\tline: %-4d\ttype: %s\n",
         i, ptr->name, ptr->line, get_text(ptr->type));
      ptr = ptr->next;
      i++;
   }
}

int addVar(Var_table** table, int line, const char* str, Type type) {

   struct node_var *link = (struct node_var*) malloc(sizeof(struct node_var));
   	
   link->line = line;
   link->name = malloc(sizeof(char) * (strlen (str) + 1)); 
   strcpy(link->name, str);

   link->type = type;
   link->next = NULL;

   int i = 0;

   if(*table != NULL) {

      struct node_var *current = *table;

      while(current->next != NULL) {
         current = current->next;
         i++;
      }

      i++;
      current->next = link;
   }
   else
      *table = link;

   return i;
}

void changeVarType(Var_table* table, int idx, Type type) {
   struct node_var* node = getNode(table, idx);
   if(node != NULL) node->type = type;
}

void deleteVarFirst(Var_table** table) {

   Var_table *aux = *table;
   struct node_var *tempLink = aux;
	
   free(tempLink->name);
   free(tempLink);

   aux = aux->next;
   
   *table = aux;
}

int lengthVarTable(Var_table* table) {

   int length = 0;
   struct node_var *current;
	
   for(current = table; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

int findVar(Var_table* table, const char *name) {

	// Caso lista vazia
	if(table == NULL) {
		return -1;
	}

	struct node_var *current = table;
   int i = 0;

	while(strcmp(current->name, name) != 0) {

		// Caso chegou ao final
		if(current->next == NULL) {
			return -1;
		}

		current = current->next;
      i++;
	}

	return i;
}

void freeVars(Var_table** table) {

   struct node_var *current = *table;
   struct node_var *next;
	
   while (current != NULL) {
      next = current->next;
      free(current->name);
      free(current);
      current = next;
   }

	*table = NULL;
}

int getLine(Var_table* table, int idx) {
   struct node_var* node = getNode(table, idx);
   if(node == NULL) return -1;
	return node->line;
}

Type getType(Var_table* table, int idx) {
   struct node_var* node = getNode(table, idx);
   if(node == NULL) return NO_TYPE;
   return node->type;
}

char* getName(Var_table* table, int idx) {
   struct node_var* node = getNode(table, idx);
   if(node == NULL) return NULL;
   return node->name;
}

static struct node_var* getNode(Var_table* table, int idx) {
   if(table == NULL || idx < 0)
      return NULL;
   struct node_var* current = table;
   for(int i = 0; i < idx; i++) {
      if(current == NULL)
         return NULL;
      current = current->next;
   }
   return current;
}

// ----------- Str_table -----------

struct node_str {
   char *str;
   struct node_str *next;
};

Str_table* createStrTable() {
    return NULL;
};

void printStrs(Str_table* table) {

   int i = 0;
   struct node_str *ptr = table;
   printf("---------Tabela de Strings-------\n");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("Pos %-4d-- string: %s\n", i, ptr->str);
      ptr = ptr->next;
      i++;
   }
}

int addStr(Str_table** table, const char* str) {

   struct node_str *link = (struct node_str*) malloc(sizeof(struct node_str));
   link->str = malloc(sizeof(char) * (strlen(str) + 1));
   strcpy(link->str, str);
   link->next = NULL;

   int i = 0;
	   
   if(*table != NULL) {

      struct node_str *current = *table;

      while(current->next != NULL) {
         current = current->next;
         i++;
      }

      i++;
      current->next = link;

   } else
      *table = link;

   return i;
}

int lengthStrTable(Str_table* table) {
   int length = 0;
   struct node_str *current;
   for(current = table; current != NULL; current = current->next) {
      length++;
   }
   return length;
}

char* getStr(Str_table* table, int idx) {
   struct node_str *current = table;
   if(table == NULL) {
      return NULL;
   }
   for(int i = 0; i < idx; i++) {
	   if(current->next == NULL) {
         return NULL;
      }
      current = current->next;
   }      
   return current->str;
}

void freeStrs(Str_table** table) {

   struct node_str *current = *table;
   struct node_str *next;
	
   while (current != NULL) {
      next = current->next;
      free(current->str);
      free(current);
      current = next;
   }

	*table = NULL;
}

// ------ Utils ------

//delete a link with given line
Var_table* delete(Var_table* table, int line) {

   //start from the first link
   Var_table *current = table;
   Var_table *previous = NULL;
	
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