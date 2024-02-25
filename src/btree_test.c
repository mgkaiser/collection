#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "pmalloc.h"
#include "collection_test.h"
#include "btree.h"
#include "btree_test.h"

void btree_test()
{

  // Always initialize root to NULL for an empty tree
  struct node __far *root = NULL;

  char __far *testString1 = "Walking Forward";
  char __far *testString2 = "Walking Backward";
  char __far *testString3 = "Search Result";

  printf("BTree Test\r\r");	

  printf("---------------------\r");
	printf(" - freemem:  %lu\r", pm->freemem);
	printf(" - totalmem: %lu\r", pm->totalmem);
  printf("---------------------\r");
  printf("\r");
  
  printf("Insert Head and Tail\r");	
  btree_insert(&root, 5, newNode(5));
  btree_insert(&root, 15, newNode(15));
  btree_insert(&root, 25, newNode(25));
  btree_insert(&root, 10, newNode(10));
  btree_insert(&root, 20, newNode(20));
  btree_insert(&root, 30, newNode(30)); 
  printf("\r"); 

  printf("Walk forward\r");	
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");

  printf("Walk backward\r");	
  btree_iterate_backward(root, &printNode, testString2);
  printf("\r");
  
  printf("Search\r");	
  struct node __far *result = btree_search(root, 20);
  if (result != NULL) {
    printNode(result, testString3);
  }
  printf("\r");

  printf("Delete middle\r");	
  btree_delete(&root, 10);
  btree_delete(&root, 20);
  btree_delete(&root, 15);
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");

  printf("Delete head\r");	
  btree_delete(&root, 5);  
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");

  printf("Delete tail\r");	  
  btree_delete(&root, 30);
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");

  printf("Delete last item\r");	
  btree_delete(&root, 25);  
  btree_iterate_forward(root, &printNode, testString2);
  printf("\r");

  printf("---------------------\r");
	printf(" - freemem:  %lu\r", pm->freemem);
	printf(" - totalmem: %lu\r", pm->totalmem);
  printf("---------------------\r");
  printf("\r");

}

void printNode(void __far *node, void __far *param)
{
  printf(" %s %ld \r", (char *)param, ((struct node *)node)->key); 
}

struct btreeTestData __far *newNode(unsigned long testData)
{
  struct btreeTestData __far *new = pmalloc_malloc(pm, sizeof(struct btreeTestData));
  new->testData = testData;
  return new;
}