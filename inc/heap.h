#ifndef HEAP_H
#define HEAP_H

  typedef struct node Node;

  typedef struct heap Heap;

  Heap* create_heap(int size);

  int get_parent_index(Heap *heap, int i);

  int get_left_index(Heap *heap, int i);

  int get_right_index(Heap *heap, int i);

  Node* value_of(Heap *heap, int i);

  void enqueue(Heap *heap, Node *value);

  Node* dequeue(Heap *heap);

  void min_heapify(Heap *heap, int i);

  Node* create_node(char item, int frequency);

  Node* heap_to_tree(Heap* heap);

  Node* get_left_tree(Node* bt);

  Node* get_right_tree(Node* bt);

  char get_tree_item(Node* bt);

  int is_leaf(Node* bt);

  void print_tree(Node* bt);

#endif