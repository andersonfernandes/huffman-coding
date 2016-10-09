#include <stdio.h>
#include "../inc/huffman_tree.h"

#ifndef TABLE_H
#define TABLE_H

  typedef struct bit_node BitNode;

  typedef struct table Table;

  Table* create_table(int size);

  BitNode* create_bit_node(char item);

  void add_to_list(Table* list, unsigned char position, char bit);

  void fill_table(Node* bt, Table* table, char* code, char* string);

  int write_in_file(unsigned char *file_content, size_t file_size, FILE *dest_file, Table* table);

  void print_table(Table* table, int size);

#endif
