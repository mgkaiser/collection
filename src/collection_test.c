#include <stdio.h>
#include "collection_test.h"
#include "btree_test.h"
#include "queue_test.h"
#include "linkedlist.h"
#include "pmalloc.h"

#define SETIN ( (void (*)(char) ) 0x1038) 
#define GETCH ( (char (*)(void) ) 0x1048) 

size_t _Stub_read (int fd, void *buf, size_t count) {  

 	char n = 0;	
	size_t c = 0;

	// If we're tying to read from the keyboard
	if (fd == 0) {		

		// Select the keyboard
		SETIN(0);

		// Get a character	
		do {
			n = GETCH();		
		} while (n == 0);

		// Did we get it
		if (n != 0) {

			// Add it to the bufffer
			*((char *)buf) = n;

			// Bump up the count
			c++;

		}
		
	}
  
  return c;	
}

int main() {
	char ch;

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