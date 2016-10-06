#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../inc/heap.h"

int is_bit_i_set(unsigned char c, int i) {
	unsigned char mask = 1 << i;
	return mask & c;
}

char* decompress(unsigned char *file_content, size_t file_size) {
  int trash_size = 0, tree_size = file_content[1]; /* tree_size está incompleto aqui, será preciso calcular os bits restantes do primeiro byte */
  unsigned char first_byte = file_content[0];
  unsigned char second_byte = file_content[1];

  int i, j;
  for(i = 0, j = 8; i < 5; ++i, ++j) {
    if(is_bit_i_set(first_byte, i))
      tree_size += pow(2, j);
  }

  trash_size = first_byte >> 5;

  char tree_str[tree_size+1];
  for(i = 2; i < tree_size+2; ++i) {
    tree_str[i-2] = file_content[i];
  }
  tree_str[tree_size] = '\0';

	return NULL;
}
