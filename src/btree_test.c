#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "pmalloc.h"
#include "collection_test.h"
#include "btree.h"
#include "btree_test.h"

void btree_test()
{
  struct node __far *root;
  char __far *testString1 = "The quick brown fox";
  char __far *testString2 = "Jumped over your mom";

  printf("BTree Test\r\r");	

  btree_insert(&root, 5, newNode(5));
  btree_insert(&root, 15, newNode(15));
  btree_insert(&root, 25, newNode(25));
  btree_insert(&root, 10, newNode(10));
  btree_insert(&root, 20, newNode(20));
  btree_insert(&root, 30, newNode(30));  
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");
  btree_iterate_backward(root, &printNode, testString2);
  printf("\r");

  btree_delete(&root, 10);
  btree_delete(&root, 20);
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");

  btree_delete(&root, 5);
  btree_delete(&root, 15);
  btree_iterate_forward(root, &printNode, testString2);
  printf("\r");

  /*
  btree_insert(&root, 10, NULL);
  btree_insert(&root, 10, NULL);
  btree_insert(&root, 10, NULL);
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");

  btree_delete(&root, 10);  
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");

  btree_delete(&root, 10);  
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");

  btree_delete(&root, 10);  
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");

  btree_delete(&root, 10);  
  btree_iterate_forward(root, &printNode, testString2);
  printf("\r");

  btree_delete(&root, 10);  
  btree_iterate_forward(root, &printNode, testString1);
  printf("\r");
  */
}

void printNode(void __far *node, void __far *param)
{
  printf(" %s %d \r", (char *)param, ((struct node *)node)->key); 
}

struct btreeTestData __far *newNode(unsigned int testData)
{
  struct btreeTestData __far *new = pmalloc_malloc(pm, sizeof(struct btreeTestData));
  new->testData = testData;
  return new;
}