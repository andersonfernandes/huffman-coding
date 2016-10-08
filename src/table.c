#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/heap.h"
#include "../inc/table.h"

struct bit_node{

  char bit;
  BitNode* next;

};

struct table{

  BitNode* first;
  BitNode* last;   

};

Table* create_table(int size){

  int i;
  Table* table = (Table*)malloc(size*sizeof(Table));
  for(i = 0; i < size; i++){

    table[i].first = NULL;
    table[i].last = NULL;

  }
  return table;

}

BitNode* create_bit_node(char item){

  BitNode* newNode = (BitNode*)malloc(sizeof(BitNode));
  newNode->bit = item;
  newNode->next = NULL;
  return newNode;

}

void add_to_list(Table* list, unsigned char position, char bit){

  BitNode* newNode = create_bit_node(bit);
  if(list[position].first == NULL){
    list[position].first = newNode;
    list[position].last = newNode;
  }
  else{
    list[position].last->next = newNode;
    list[position].last = newNode;
  }

}

// Function that sets the huff binaries of each char present in the file
// Recieves a binary tree, a table, a code and a string(that should be both empty strings)
void fill_table(Node* bt, Table* table, char* next_binary, char* code){

  strcat(code, next_binary);

  if(is_leaf(bt)){
    
    //take the char as the array index and the code as "binary"
    int i;
    for(i = 0; i < strlen(code); i++){
      add_to_list(table, get_tree_item(bt), code[i]);
    }

    return;

  }

  fill_table(get_left_tree(bt), table, "0", code);
  code[strlen(code)-1] = '\0';
  fill_table(get_right_tree(bt), table, "1", code);
  code[strlen(code)-1] = '\0';

  return;

}

int write_in_file(unsigned char *file_content, size_t file_size, FILE *dest_file, Table *table){
  
  int i, j = 7;
  BitNode* current = NULL;
  unsigned char byte;
  
  for(i = 0; i < file_size; i++){
    current = table[file_content[i]].first;
    printf("%c", file_content[i]);
    for(; j >= 0; j--){
      //printf("%d", j);
      //printf("%c", current->bit);
      if(current->bit == '1'){        
        (byte |= 1<<j);
      }

      //printf("%c", current->bit);
      if(current->next == NULL){
        //printf("\n");
        if(i == file_size-1){
          putc(byte, dest_file);
          //printf("\n\n");
          //printf("%d\n", byte);
          break;
        }
        else if(j == 0){
          putc(byte, dest_file);
          //printf("\n\n");
          //printf("%d\n", byte);
          j = 8;
          byte = 0;
        }
        
        j--;
        break;
      }
      current = current->next;
      if(j == 0){
        putc(byte, dest_file);
        //printf("\n\n");
        //printf("%d\n", byte);
        j = 8;
        byte = 0;
        
      }
    }
  }
  printf("%d\n", i);
  return j;
}

// Test function to print huff binary table with the huff binaries each char in the file
void print_table(Table* table, int size){
  int i;
  for(i = 0; i < size; i++){
    if(table[i].first != NULL){

      BitNode* second = table[i].first;
      printf("%c = ", i);
      while(second != NULL){

        printf("%c", second->bit);
        second = second->next;

      }
      printf("\n");
    }

  }

  return;

}
//test function
void create_temp_file(unsigned char* file_content, size_t file_size, Table* table){
  int i;
  BitNode* current;
  FILE* temp = fopen("temp.txt", "w");
  for(i = 0; i < file_size; i++){
    current = table[file_content[i]].first;
    while(current != NULL){

      putc(current->bit, temp);
      current = current->next;

    }
    putc(' ', temp);
  }
  fclose(temp);

}