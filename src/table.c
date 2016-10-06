#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/heap.h"
#include "../inc/table.h"

int ind = 0;

struct table{

  char item;
  char binary[9];  

};

Table* create_table(int size){

  Table* table = (Table*)malloc(sizeof(Table)*size);
  return table;

}

// Function that sets the huff binaries of each char present in the file
// Recieves a binary tree, a table, a code and a string(that should be both empty strings)
void fill_table(Node* bt, Table* table, char* next_binary, char* code){

  strcat(code, next_binary);

  if(is_leaf(bt)){
    
    table[ind].item = get_tree_item(bt);
    strcpy(table[ind].binary, code);
    ++ind;
    return;

  }

  fill_table(get_left_tree(bt), table, "0", code);
  code[strlen(code)-1] = '\0';
  fill_table(get_right_tree(bt), table, "1", code);
  code[strlen(code)-1] = '\0';

  return;

}
// Test function to print huff binary table with the huff binaries each char in the file
void print_table(Table* table, int size){
  int i;
  for(i = 0; i < size; i++){

    printf("%c = %s\n", table[i].item, table[i].binary);

  }

  return;

}