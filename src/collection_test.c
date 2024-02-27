#include <stdio.h>
#include "collection_test.h"
#include "btree_test.h"
#include "queue_test.h"
#include "linkedlist.h"
#include "pmalloc.h"
#include "stub_read.h"

pmalloc_t pmblock;

void initHeap();

int main() {
	char ch;

	printf("Collections: Basic Example\r\r");	

	// Init Heap
	initHeap();
	
	// Linked List tests

	// Queue tests	
	queue_test();

	// BTree tests		 
	btree_test();	
			
	printf("Done\r");
	return 0;
}

void initHeap() {

	// Set the pointer to the heap header		
	pm = &pmblock;
	
	// Initialise our pmalloc
	pmalloc_init(pm);	
	
	// Add memory to the heap
	pmalloc_addblock(pm, (void __far *)0x300000, 0x100000);			
}