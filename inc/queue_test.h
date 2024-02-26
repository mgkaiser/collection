#ifndef _QUEUE_TEST_H
#define _QUEUE_TEST_H

#include "queue.h"

struct queueTestData
{
  struct queueItem header;
  unsigned int testData;
};

void queue_test();
struct queueTestData __far *newQueueItem(unsigned int testData);

#endif
