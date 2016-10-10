#include <stdio.h>
#include "../inc/huffman_tree.h"

#ifndef TABLE_H
#define TABLE_H

  typedef struct bit_node BitNode;

  typedef struct table Table;

  /* Creates a new table
   * Requires size of the table
   * Returns a table
   */
  Table* create_table(int size);
  
  /* Creates a new bit node
   * Requires the item char
   * Returns a bit node
   */
  BitNode* create_bit_node(char item);

  /* Adds BitNodes to a list
   * Requires the table, the position of the list in the table and the char to be added
   */
  void add_to_list(Table* list, unsigned char position, char bit);
  
  /* Function that sets the table of huffman "binaries" of each char present in the file
   * Requires a binary tree, a table, the next character in the code(that should be an empty string) and a code(that should also be an empty string)
   */
  void fill_table(Node* bt, Table* table, char* code, char* string);

  /* Writes the coded chars in the destination file
   * Requires the origin file content, the origin file size, a pointer to the destination file and the table with the "binaries" of each char in the origin file
   * Returns the trash size
   */
  int write_in_file(unsigned char *file_content, size_t file_size, FILE *dest_file, Table* table);

  /* Print huff binary table with the huff binaries each char in the file
   * Requires a table and the size
   */
  void print_table(Table* table, int size);

  /* Frees a table 
   * Reuires a table and the size
  */
  void free_table(Table *table, int size);

#endif
