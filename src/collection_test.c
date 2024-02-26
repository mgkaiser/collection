#include <stdio.h>
#include "collection_test.h"
#include "btree_test.h"
#include "queue_test.h"
#include "linkedlist.h"
#include "pmalloc.h"
#include "stub_read.h"

int main() {
	char ch;

	printf("Collections: Basic Example\r\r");	

	// Set the pointer to the heap header	
	pmalloc_t pmblock;
	pm = &pmblock;
	
	// Initialise our pmalloc
	pmalloc_init(pm);	
	
	// Add memory to the heap
	pmalloc_addblock(pm, (void __far *)0x300000, 0x100000);			

	// Linked List tests

	// Queue tests
	printf("Press ENTER key to Continue\r");  
	getchar();  
	queue_test();

	// BTree tests	
	printf("Press ENTER key to Continue\r");  
	getchar();  
	btree_test();
		
	printf("Press ENTER key to Continue\r");  
	getchar();  
	printf("Done\r");
	return 0;
}