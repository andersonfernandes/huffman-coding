#include <stdio.h>
#include <stdlib.h>
#include "../inc/huffman_tree.h"
#include "../inc/heap.h"

Node* heap_to_tree(Heap* heap) {

  int i = 0;
  Node* bt = NULL;

  while(get_size(heap) > 0){

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

Node* str_to_tree(char* str, int* i) {
  if(str[*i] == '*'){
    ++(*i);
    Node* left = str_to_tree(str, i);
    ++(*i);
    return create_tree_node('*', left, str_to_tree(str, i));
  }

  if(str[*i] == '\\') ++(*i);

  return create_tree_node(str[*i], NULL, NULL);
}

int is_leaf(Node* bt){

  if(bt->left == NULL && bt->right == NULL) return 1;
  else return 0;

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

void print_tree(Node* bt){

  if(bt == NULL) return;

  printf("%c = %d\n", bt->item, bt->frequency);

  printf("left of %c = %d: \n", bt->item, bt->frequency);
  print_tree(bt->left);
  printf("right of %c = %d: \n", bt->item, bt->frequency);
  print_tree(bt->right);

  return;

}
