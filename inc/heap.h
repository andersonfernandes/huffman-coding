#ifndef HEAP_H
#define HEAP_H

  typedef struct node Node;

  typedef struct heap Heap;

  Heap* create_heap(int size);

  int get_parent_index(Heap *heap, int i);

  int get_left_index(Heap *heap, int i);

  int get_right_index(Heap *heap, int i);

  int get_size(Heap *heap);

  Node* value_of(Heap *heap, int i);

  void enqueue(Heap *heap, Node *value);

  Node* dequeue(Heap *heap);

  void min_heapify(Heap *heap, int i);

  Node* create_node(char item, int frequency);

#endif
