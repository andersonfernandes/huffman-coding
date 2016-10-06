#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/heap.h"
#include "../inc/table.h"

char* compress(char *file_content, size_t file_size){
  int i, frequency[256] = {0};
  Heap* queue = create_heap(256);
  Node* bt = NULL;  
  int tree_letters = 0;

  
  for(i = 0; i < file_size; i++){

    ++frequency[file_content[i]];                          /* Counts the frequency of every character in the file */

  }

  for(i = 0; i < 256; i++){
    if(frequency[i] > 0){
      tree_letters++;
      enqueue(queue, create_node(i, frequency[i]));        /* Uses the index of the array as the char and the value of each index as the frequency when creating nodes */
      
    }
  }
  Table* table = create_table(tree_letters);
  bt = heap_to_tree(queue);
  //print_tree(bt);

  //printf("\n%d\n", tree_letters);

  char empty_string[9] = "";  //empty string used to allocate the memory space needed for the max huff binary code of a letter

  fill_table(bt, table, "", empty_string);                 /* Transforms binary tree "bt" into the coding for each character */

  //print_table(table, tree_letters);
  
}