#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

// Make BTree multi index
// tree root contains an array of roots
// header structure is an array
// add unsigned char indexNum
// add "reindex"
// delete and re-add should reindex a single node

#include "btree.h"

// Internal methods
struct node __far *btree_insert_internal(struct node __far *root, int key, void __far *value);
struct node __far *btree_delete_internal(struct node __far *root, int key);
struct node __far *btree_find_minimum(struct node __far *root);
struct node __far *btree_new_node(int key, void __far *value);

struct node __far *btree_search(struct node __far *root, int key)
{
  if(root==NULL || root->key==key) //if root->key is x then the element is found
    return root;
  else if(key > root->key) // x is greater, so we will search the right subtree
    return btree_search(root->right_child, key);
  else //x is smaller than the key, so we will search the left subtree
    return btree_search(root->left_child, key);
}

//function to find the minimum value in a node
struct node __far *btree_find_minimum(struct node __far *root)
{
  if(root == NULL)
    return NULL;
  else if(root->left_child != NULL) // node with minimum value will have no left child
    return btree_find_minimum(root->left_child); // left most element will be minimum
  return root;
}

//function to create a node
struct node __far *btree_new_node(int key, void __far *value)
{
  struct node __far *p = (struct node *)value;  
  p->key = key;  
  p->left_child = NULL;
  p->right_child = NULL;
  return p;
}

struct node __far *btree_insert(struct node __far **root, int key, void __far *value)
{
  struct node __far *node = btree_insert_internal(*root, key, value);  
  if (*root == NULL) *root = node;
  return node;
}

struct node __far *btree_insert_internal(struct node __far *root, int key, void __far *value)
{
  //searching for the place to insert
  if(root==NULL)  return btree_new_node(key, value);
  else if(key > root->key) // x is greater. Should be inserted to right
    root->right_child = btree_insert_internal(root->right_child, key, value);
  else // x is smaller should be inserted to left
     root->left_child = btree_insert_internal(root->left_child, key, value);
  return root;
}

void btree_delete(struct node __far **root, int key)
{
  *root = btree_delete_internal(*root, key);
}

// funnction to delete a node
struct node __far *btree_delete_internal(struct node __far *root, int key)
{
  //searching for the item to be deleted
  if(root == NULL)
    return NULL;
  if (key > root->key)
    root->right_child = btree_delete_internal(root->right_child, key);
  else if(key < root->key)
    root->left_child = btree_delete_internal(root->left_child, key);
  else
  {
    //No Children
    if(root->left_child==NULL && root->right_child==NULL)
    {
      free(root);
      return NULL;
    }

    //One Child
    else if(root->left_child==NULL || root->right_child==NULL)
    {
      struct node __far *temp;
      if(root->left_child==NULL)
          temp = root->right_child;
      else
          temp = root->left_child;
      free(root);
      return temp;
    }

    //Two Children
    else
    {
      struct node __far *temp = btree_find_minimum(root->right_child);
      root->key = temp->key;
      root->right_child = btree_delete_internal(root->right_child, temp->key);
    }
  }
  return root;
}

void btree_iterate_forward(struct node __far *root, void (*iterator)(void __far *node, void __far *param), void __far *param)
{
  if(root != NULL) // checking if the root is not null
  {
    btree_iterate_forward(root->left_child, iterator, param);   // visiting left child
    if (iterator != NULL) (*iterator)(root, param);        
    btree_iterate_forward(root->right_child, iterator, param);  // visiting right child
  }
}

void btree_iterate_backward(struct node __far *root, void (*iterator)(void __far *node, void __far *param), void __far *param)
{
  if(root!=NULL) // checking if the root is not null
  {
    btree_iterate_backward(root->right_child, iterator, param); // visiting right child
    if (iterator != NULL) (*iterator)(root, param);                
    btree_iterate_backward(root->left_child, iterator, param);  // visiting left child
  }
}
