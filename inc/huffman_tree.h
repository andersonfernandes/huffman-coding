#include <stdio.h>
#include "heap.h"

#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

  typedef struct node Node;
  struct node{
    char item;
    int frequency;

    Node *left;
    Node *right;
  };

  /* Creates a huffman tree based on a heap
   * Requires a min heap
   * Returns a huffman tree.
   */
  Node* heap_to_tree(Heap* heap);

  /* Creates a new tree node
   * Requires the item char, left and right huffman tree nodes
   * Returns a huffman tree node
   */
  Node* create_tree_node(char item, Node *left, Node *right);

  /* Rebuild the tree based on a string
   * Requires a huffman tree as pre-order string, and a index pointer(must point to a variable with 0 when the function is called)
   * Returns a huffman tree
   */
  Node* str_to_tree(char* str, int* i);

  /* Checks if the given tree is a leaf
   * Requires a huffman tree node
   * Returns a integer indicating if the tree node is a leaf
   */
  int is_leaf(Node* bt);

  Node* get_left_tree(Node* bt);

  Node* get_right_tree(Node* bt);

  char get_tree_item(Node* bt);

  /* Calculates recursively the count of node of the given tree
   * Requires a huffman tree, and a counter to the size(must be 0 if the function is called from the root)
   * Returns a integer indicating the tree size
   */
  int calculate_tree_size(Node* bt, int size);

  /* Print the tree in pre-order in the given file.
   * Requires a huffman tree, and the destination file(already open)
   */
  void print_tree_in_file(Node* bt, FILE *dest_file);

  /* Free recursively each node of the given tree.
   * Requires a huffman tree node
   */
  void free_tree(Node* bt);

#endif
