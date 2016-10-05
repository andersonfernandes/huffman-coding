#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/heap.h"

char* compress(char *file_content, size_t file_size){
	int i, frequency[256] = {0};
  Heap* queue = create_heap(256);
  Node* bt = NULL;  
	int tree_letters;
	
	for(i = 0; i < file_size; i++){

    ++frequency[file_content[i]];                          /* Counts the frequency of every character in the file */

  }

  for(i = 0; i < 256; i++){
    if(frequency[i] > 0){
      tree_letters++;
      enqueue(queue, create_node(i, frequency[i]));        /* Uses the index of the array as the char and the value of each index as the frequency when creating nodes */
      
    }
  }
  
  bt = heap_to_tree(queue);

  //print_tree(bt);
	char* compress_table[2][tree_letters];



  /* To do: transform binary tree "bt" into the coding for each character */
}

/**
void fill_table(Node* bt, char table[2][], int table_size, char* code, int size){

  if(bt == NULL) return;
  
  if(bt->item != '*') ;

  printf("left of %c = %d: \n", bt->item, bt->frequency);
  print_tree(bt->left);
  printf("right of %c = %d: \n", bt->item, bt->frequency);
  print_tree(bt->right);
 
  return;

}
/**
