#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/heap.h"
#include "../inc/table.h"

char* compress(char *file_content, size_t file_size){
  int i, frequency[256] = {0};
  Heap* queue = create_heap(256);
  Node* bt = NULL;
  
  for(i = 0; i < file_size; i++){

    ++frequency[file_content[i]];                          /* Counts the frequency of every character in the file */

  }

  for(i = 0; i < 256; i++){
    if(frequency[i] > 0){
      
      enqueue(queue, create_node(i, frequency[i]));        /* Uses the index of the array as the char and the value of each index as the frequency when creating nodes */
      
    }
  }
  
  bt = heap_to_tree(queue);
  free(queue);
  //print_tree(bt);

  Table* table = create_table(256);
  //printf("\n%d\n\n", 256);

  char empty_string[9] = "";                               /* Empty string used to allocate the memory space needed for the max huff binary code of a letter */

  //take the char as the array index and the code as "binary". i.e: table[char].binary = 010101
  fill_table(bt, table, "", empty_string);                 /* Transforms binary tree "bt" into the coding for each character */

  //print_table(table, 256);
  
}