#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct node {
   char* name;
   int line;
   struct node *next;
} Var_table;

struct node *head = NULL;
struct node *current = NULL;

Var_table* createVarTable(){
    
    Var_table *head = NULL;

    return head;
};
//display the list
void printVars(Var_table* table) {
//    struct node *ptr = head;
   struct node *ptr = table;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d, %s) ",ptr->line,ptr->name);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//insert link at the first location
void addVar(Var_table** table ,int line, char* str) {
   //create a link

   struct node *link = (struct node*) malloc(sizeof(struct node));
   
	
   link->line = line;
   link->name = malloc( sizeof(char) * strlen (str)); 

   strcpy(link->name, str);
	
   //point it to old first node
   link->next = *table;

   //point first to new first node
   *table = link;

//    return table;
}

//delete first item
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

//is list empty
bool isEmpty(Var_table* table) {
   return table == NULL;
}

int lengthVarTable(Var_table* table) {
   int length = 0;
   struct node *current;
	
   for(current = table; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given line
struct node* findVar(Var_table* table,int line) {

   //start from the first link
   struct node* current = table;

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
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

//find a link with given line
int varExist(Var_table* table,int line) {

   //start from the first link
   struct node* current = table;

   //if list is empty
   if(table == NULL) {
      return 0;
   }

   //navigate through list
   while(current->line != line) {
	
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

// void sort(Var_table* table) {

//    int i, j, k, templine, tempData;
//    struct node *current;
//    struct node *next;
	
//    int size = lengthVarTable(table);
//    k = size ;
	
//    for ( i = 0 ; i < size - 1 ; i++, k-- ) {
//       current = table;
//       next = table->next;
		
//       for ( j = 1 ; j < k ; j++ ) {   

//          if ( current->data > next->data ) {
//             tempData = current->data;
//             current->data = next->data;
//             next->data = tempData;

//             templine = current->line;
//             current->line = next->line;
//             next->line = templine;
//          }
			
//          current = current->next;
//          next = next->next;
//       }
//    }   
// }

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

void freeVars(Var_table** table){
   struct node* current = *table;
   struct node* next;
	
   while (current != NULL) {
      next  = current->next;
      free(current->name);
      free(current);
      current = next;
   }
	*table = NULL;
}
// void main() {

//    Var_table* table = createTable();
//   insertVarTable(&table, 1, 10);
//   insertVarTable(&table, 2, 20);
// //    insertVarTable(3,30);
// //    insertVarTable(4,1);
// //    insertVarTable(5,40);
// //    insertVarTable(6,56); 

//    printf("Original List: "); 
	
//    //print list
//    printList(table);
//    deleteFirst(&table);
//    printList(table);

// //    while(!isEmpty()) {            
// //       struct node *temp = deleteFirst();
// //       printf("\nDeleted value:");
// //       printf("(%d,%d) ",temp->line,temp->data);
// //    }  
	
// //    printf("\nList after deleting all items: ");
// //    printList();
// //    insertVarTable(1,10);
// //    insertVarTable(2,20);
// //    insertVarTable(3,30);
// //    insertVarTable(4,1);
// //    insertVarTable(5,40);
// //    insertVarTable(6,56);
   
// //    printf("\nRestored List: ");
// //    printList();
// //    printf("\n");  

// //    struct node *foundLink = find(4);
	
// //    if(foundLink != NULL) {
// //       printf("Element found: ");
// //       printf("(%d,%d) ",foundLink->line,foundLink->data);
// //       printf("\n");  
// //    } else {
// //       printf("Element not found.");
// //    }

// //    delete(4);
// //    printf("List after deleting an item: ");
// //    printList();
// //    printf("\n");
// //    foundLink = find(4);
	
// //    if(foundLink != NULL) {
// //       printf("Element found: ");
// //       printf("(%d,%d) ",foundLink->line,foundLink->data);
// //       printf("\n");
// //    } else {
// //       printf("Element not found.");
// //    }
	
// //    printf("\n");
// //    sort();
	
// //    printf("List after sorting the data: ");
// //    printList();
	
// //    reverse(&head);
// //    printf("\nList after reversing the data: ");
// //    printList();
// }
