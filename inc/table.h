#ifndef TABLE_H
#define TABLE_H

  #include "heap.h"

  typedef struct table Table;

  Table* create_table(int size);

  void fill_table(Node* bt, Table* table, char* code, char* string);

  void print_table(Table* table, int size);

#endif