//#ifndef _BTREE_TEST_H
//#define _BTREE_TEST_H

  #include "btree.h"

  struct btreeTestData  
  {
    struct node header;
    unsigned int testData;
  };

  void btree_test();
  void printNode(void __far *node, __far void* param);
  struct btreeTestData __far *newNode(unsigned int testData);

//#endif