#ifndef _BTREE_H
#define _BTREE_H

struct node
{
  long key;                       // The key of the node
  struct node __far *right_child; // right child
  struct node __far *left_child;  // left child    
};

struct node __far *btree_search(struct node __far *root, long key);
struct node __far *btree_insert(struct node __far **root, long key, void __far *value);
void btree_delete(struct node __far **root, long key);
void btree_iterate_forward(struct node __far *root, void (*iterator)(void __far *node, void __far *param), void __far *param);
void btree_iterate_backward(struct node __far *root, void (*iterator)(void __far *node, void __far *param), void __far *param);
unsigned long btree_orderedHash(char *s, const char *charset, long n);

#endif