#include <stdio.h>
#include <stdlib.h>
#include "../inc/heap.h"

struct node{

  char item;
  int frequency;

  Node *left;
  Node *right;

};

struct heap {
  int max_size;
  int size;
  Node **data;
};

void swap(Node **a, Node **b) {
  Node aux = **a;
  **a = **b;
  **b = aux;
}

Heap* create_heap(int size) {
  Heap *heap = (Heap*)malloc(sizeof(Heap));
  heap->data = (Node**)malloc(size * sizeof(Node*));
  heap->max_size = size;
  heap->size = 0;

  return heap;
}

int get_parent_index(Heap *heap, int i) {
  return i/2;
}

int get_left_index(Heap *heap, int i) {
  return 2*i;
}

int get_right_index(Heap *heap, int i) {
  return 2*i + 1;
}

void enqueue(Heap *heap, Node *value) {

  if (heap->size >= heap->max_size) {
    printf("Heap is full!");
  } else {
    heap->data[++heap->size] = value;
    int key_index = heap->size;
    int parent_index = get_parent_index(heap, heap->size);

    while (parent_index >= 1 && heap->data[key_index]->frequency < heap->data[parent_index]->frequency) {
      swap(&heap->data[key_index], &heap->data[parent_index]);
      key_index = parent_index;
      parent_index = get_parent_index(heap, key_index);
    }
  }
}

Node* dequeue(Heap *heap) {
  Node* value = heap->data[1];

  heap->data[1] = heap->data[heap->size];
  heap->size--;
  min_heapify(heap, 1);

  return value;
}

void min_heapify(Heap *heap, int i) {
  int lowest;
  int left_index = get_left_index(heap, i);
  int right_index = get_right_index(heap, i);

  if (left_index <= heap->size && heap->data[left_index]->frequency < heap->data[i]->frequency)
    lowest = left_index;
  else
    lowest = i;

  if (right_index <= heap->size && heap->data[right_index]->frequency < heap->data[lowest]->frequency)
    lowest = right_index;

  if (heap->data[i]->frequency != heap->data[lowest]->frequency) {
    swap(&heap->data[i], &heap->data[lowest]);
    min_heapify(heap, lowest);
  }
}
/* Recieves an item and its frequency, returns nodes */
Node* create_node(char item, int frequency){

  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->item = item;
  newNode->frequency = frequency;

  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;

}
/* Returns a huffman tree, requires a min heap */
Node* heap_to_tree(Heap* heap){

  int i = 0;
  Node* bt = NULL;

  while(heap->size > 0){

    if(i%2 == 0){
      if(i != 0) enqueue(heap, bt);
      bt = create_node('*', 0);
      bt->left = dequeue(heap);
      bt->frequency += bt->left->frequency;
    }

    else{
      bt->right = dequeue(heap);
      bt->frequency += bt->right->frequency;
    }

    i++;
  }

  return bt;

}

Node* create_tree_node(char item, Node *left, Node *right) {
  Node *new = (Node *) malloc(sizeof(Node));
  new->item = item;
  new->left = left;
  new->right = right;

  return new;
}

Node* str_to_tree(char* str, int* i){
  if(str[*i] == '*'){
    ++(*i);
    Node* left = str_to_tree(str, i);
    ++(*i);
    return create_tree_node('*', left, str_to_tree(str, i));
  } else if(str[*i] == '\\'){
    ++(*i);
    return create_tree_node(str[*i], NULL, NULL);
  }
  return create_tree_node(str[*i], NULL, NULL);
}

Node* get_left_tree(Node* bt){

  return bt->left;

}

Node* get_right_tree(Node* bt){

  return bt->right;

}

char get_tree_item(Node* bt){

  return bt->item;

}

// Checks is "bt" is a leaf
int is_leaf(Node* bt){

  if(bt->left == NULL && bt->right == NULL) return 1;
  else return 0;

}

int calculate_tree_size(Node* bt, int size){

  ++size;
  if(is_leaf(bt)){
    if(bt->item == '*' || bt->item == '\\') size++;
    return size;
  }
  size = calculate_tree_size(bt->left, size);
  size = calculate_tree_size(bt->right, size);

  return size;

}

// Test function to print a binary tree
void print_tree(Node* bt){

  if(bt == NULL) return;

  printf("%c = %d\n", bt->item, bt->frequency);

  printf("left of %c = %d: \n", bt->item, bt->frequency);
  print_tree(bt->left);
  printf("right of %c = %d: \n", bt->item, bt->frequency);
  print_tree(bt->right);

  return;

}

void print_tree_in_file(Node* bt, FILE *dest_file){

  if(bt == NULL) return;
  if((bt->item == '*' || bt->item == '\\') && is_leaf(bt)){
    putc('\\', dest_file);
  }
  putc(bt->item, dest_file);

  print_tree_in_file(bt->left, dest_file);
  print_tree_in_file(bt->right, dest_file);

  return;

}

void free_tree(Node* bt){
    
  if(bt == NULL){
    return;
  }
    
  free_tree(bt->left);
  free_tree(bt->right);

  free(bt);

   
}
