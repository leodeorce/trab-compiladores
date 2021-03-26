#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <stdbool.h>

#include "list.h"

void main()
{

    Var_table *table = createVarTable();
    addVar(&table, 1, "a");
    addVar(&table, 2, "b");

    printf("Original List: ");

    //print list
    printVars(table);
    deleteVarFirst(&table);
    printVars(table);
    addVar(&table, 3, "c");
    printVars(table);
    printf("\ntamanho -> %d\n",  lengthVarTable(table));
    
    int teste = varExist(table ,"ccc");

    printf("A variavel 'ccc' com já foi inserido? -> %d \n", teste);
    freeVars(&table);
    printVars(table);

    //    while(!isEmpty()) {
    //       struct node *temp = deleteVarFirst();
    //       printf("\nDeleted value:");
    //       printf("(%d,%d) ",temp->key,temp->data);
    //    }

    //    printf("\nList after deleting all items: ");
    //    printVars();
    //    addVar(1,10);
    //    addVar(2,20);
    //    addVar(3,30);
    //    addVar(4,1);
    //    addVar(5,40);
    //    addVar(6,56);

    //    printf("\nRestored List: ");
    //    printVars();
    //    printf("\n");

    //    struct node *foundLink = find(4);

    //    if(foundLink != NULL) {
    //       printf("Element found: ");
    //       printf("(%d,%d) ",foundLink->key,foundLink->data);
    //       printf("\n");
    //    } else {
    //       printf("Element not found.");
    //    }

    //    delete(4);
    //    printf("List after deleting an item: ");
    //    printVars();
    //    printf("\n");
    //    foundLink = find(4);

    //    if(foundLink != NULL) {
    //       printf("Element found: ");
    //       printf("(%d,%d) ",foundLink->key,foundLink->data);
    //       printf("\n");
    //    } else {
    //       printf("Element not found.");
    //    }

    //    printf("\n");
    //    sort();

    //    printf("List after sorting the data: ");
    //    printVars();

    //    reverse(&head);
    //    printf("\nList after reversing the data: ");
    //    printVars();
}