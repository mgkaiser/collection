#ifndef _STUB_READ_H
#define _STUB_READ_H

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

#endif