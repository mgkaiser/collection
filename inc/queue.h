#ifndef _QUEUE_H
#define _QUEUE_H

struct queueItem
{
  struct queueItem __far *next;
};

struct queue
{
  struct queueItem __far *dequeue;
  struct queueItem __far *enqueue;
};

void queue_init(struct queue __far *queue);
void queue_enqueue(struct queue __far *queue, void __far *data);
void __far *queue_dequeue(struct queue __far *queue);

#endif