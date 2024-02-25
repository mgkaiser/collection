#include <stdio.h>
#include "collection_test.h"
#include "btree_test.h"
#include "pmalloc.h"
#include "linkedlist.h"
#include "queue.h"
#include "btree.h"

int main() {
	printf("Collections: Basic Example\r\r");	

	// Set the pointer to the heap header	
	pmalloc_t pmblock;
	pm = &pmblock;
	
	// Initialise our pmalloc
	pmalloc_init(pm);
	#ifdef DEBUG
	pmalloc_dump_stats(pm);
	#endif
	
	// Add memory to the heap
	pmalloc_addblock(pm, (void __far *)0x300000, 0x100000);	
	#ifdef DEBUG
	pmalloc_dump_stats(pm);
	#endif	

	// Linked List tests

	// Queue tests

	// BTree tests	
	btree_test();
		
	printf("Done\r");
	return 0;
}