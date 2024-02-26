#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "queue.h"

void queue_init(struct queue __far *queue)
{
  queue->dequeue = NULL;
  queue->enqueue = NULL;  
}

void queue_enqueue(struct queue __far *queue, void __far *data)
{  
  struct queueItem __far *newItem = (struct queueItem __far*)data;  
  newItem->next = NULL;    
  if (queue->enqueue != NULL) queue->enqueue->next = newItem;
  if (queue->dequeue == NULL) queue->dequeue = newItem;
  queue->enqueue = newItem;  
}

void __far *queue_dequeue(struct queue __far *queue)
{
  struct queueItem __far *current;
  if (queue->dequeue == NULL) return NULL;
  if (queue->dequeue == queue->enqueue) queue->enqueue = NULL;
  current = queue->dequeue;  
  queue->dequeue = current->next;
  return current;
}
