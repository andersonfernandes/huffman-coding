#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/heap.h"
#include "../inc/table.h"

char* compress(char *file_content, size_t file_size, char *dest_filename){
  int i, frequency[256] = {0};
  Heap* queue = create_heap(256);
  Node* bt = NULL;
  int tree_size = 0; 
  unsigned char byte1;
  unsigned char byte2;

  for(i = 0; i < file_size; i++){

    ++frequency[file_content[i]];                          /* Counts the frequency of every character in the file */

  }

  for(i = 0; i < 256; i++){
    if(frequency[i] > 0){
      
      enqueue(queue, create_node(i, frequency[i]));        /* Uses the index of the array as the char and the value of each index as the frequency when creating nodes */
      
    }
  }
  
  bt = heap_to_tree(queue);
  tree_size = calculate_tree_size(bt, 0);
  free(queue);
  print_tree(bt);

  Table* table = create_table(256);
  printf("\n%d\n\n", tree_size);

  char* empty_string = (char*)calloc(9, sizeof(char));      /* Empty string used to allocate the memory space needed for the max huff binary code of a letter */

  //take the char as the array index and the code as "binary". i.e: table[char].binary = 010101
  fill_table(bt, table, "", empty_string);                 /* Transforms binary tree "bt" into the coding for each character */
  
  free(empty_string);

  print_table(table, 256);
  byte1 = (tree_size>>8);
  byte2 = tree_size;

  FILE* dest_file = fopen(dest_filename, "w");

  putc(dest_file, 0);
  putc(dest_file, byte2);
  print_tree_in_file(bt, dest_file);
  int trash = write_in_file(file_content, file_size, dest_file, table);
  rewind(dest_file);

  trash = trash<<5;
  byte1 |= trash;
  fprintf(dest_file, "%c", byte);

  fclose(dest_file);
  
}