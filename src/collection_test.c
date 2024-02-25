#include <stdio.h>
#include "pmalloc.h"
#include "linkedlist.h"
#include "queue.h"
#include "btree.h"

int main() {
	printf("collections: Basic Example\r\r");	
	
	pmalloc_t pmblock;
	pmalloc_t *pm = &pmblock;
	
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
		
	printf("Done\r");
	return 0;
}