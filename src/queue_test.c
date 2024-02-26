#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "pmalloc.h"
#include "collection_test.h"
#include "queue.h"
#include "queue_test.h"

void queue_test()
{
  struct queue queue;
  struct queueTestData __far *queueItem;
  int i;

  printf("Queue Test\r\r");	
  
  printf("Queue Init\r");
  queue_init(&queue);
  printf("\r");
  printf("Press ENTER key to Continue\r");  
	getchar();  

  printf("Enqueue\r");
  pmalloc_dump_stats(pm);
  for (i =1; i < 10;  i++)
  {
      queue_enqueue(&queue, newQueueItem(i));
  }
  pmalloc_dump_stats(pm);
  printf("\r");
  printf("Press ENTER key to Continue\r");  
	getchar();  

  printf("Dequeue\r");
  pmalloc_dump_stats(pm);
  do 
  {
      queueItem = (struct queueTestData *)queue_dequeue(&queue);
      if (queueItem != NULL) 
      {
        printf("%d\r", queueItem->testData);
        pmalloc_free(pm, queueItem);
      }
  } while (queueItem != NULL);  
  pmalloc_dump_stats(pm);
  printf("\r");
    
}

struct queueTestData __far *newQueueItem(unsigned int testData)
{
  struct queueTestData __far *new = pmalloc_malloc(pm, sizeof(struct  queueTestData));
  new->testData = testData;
  return new;
}