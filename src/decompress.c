#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../inc/decompress.h"
#include "../inc/huffman_tree.h"

int is_bit_i_set(unsigned char c, int i) {
	unsigned char mask = 1 << i;
	return mask & c;
}

void decompress(unsigned char *file_content, long int file_size, char *dest_filename) {
  /* Analizes the first two bytes to get the tree size and the trash size */
  int trash_size = 0, tree_size = file_content[1];          // Set the trash size to 0 and the tree size to the byte1
  unsigned char byte1 = file_content[0];
  unsigned char byte2 = file_content[1];

  int i, j;
  for(i = 0, j = 8; i < 5; ++i, ++j) {                      // Traverses the byte1 from right to left to calculate the rest of the tree size,
    if(is_bit_i_set(byte1, i))                              // starting the byte index with 8, if the bit is set, calculates de decimal 
      tree_size += pow(2, j);                               // value of the bit and sum to the tree size
  }

  trash_size = byte1 >> 5;                                  // Get the first 3 bits of byte1 for the trash size

  char tree_str[tree_size+1];
  for(i = 2; i < tree_size+2; ++i) {                        // Get the the tree nodes of the file, starting from the byte 2 to tree_size+2
    tree_str[i-2] = file_content[i];
  }
  tree_str[tree_size] = '\0';

  i = 0;
  Node *tree = str_to_tree(tree_str, &i);                   // Rebuild the tree from the string
  Node *aux_tree = tree;                                    // Creates an aux node to keep the root node on the tree pointer

  FILE *dest_file = fopen(dest_filename, "w");              // Opens the destination file


  for(i = tree_size + 2; i < file_size - 1; ++i) {          // Traverses each bit of the remaining text of the file until the before last byte
    for(j = 7; j >= 0; --j) {                               
      if(is_bit_i_set(file_content[i], j)) {                // If the bit is set go to the right child
        aux_tree = get_right_tree(aux_tree);
      } else {                                              // If not go to the right
        aux_tree = get_left_tree(aux_tree);
      }

      if(is_leaf(aux_tree)) {
        putc(get_tree_item(aux_tree), dest_file);          // Put the char on the destination file if reach a leaf
        aux_tree = tree;                                   // Rollback the aux_tree to the root of the  tree to start the search of the next byte
      }
    }
  }

  /* The last byte is analysed  */
  for(i = 7; i >= trash_size; --i) {
    if(is_bit_i_set(file_content[file_size - 1], i)) {
      aux_tree = get_right_tree(aux_tree);
    } else {
      aux_tree = get_left_tree(aux_tree);
    }

    if(is_leaf(aux_tree)) {
      putc(get_tree_item(aux_tree), dest_file);
      aux_tree = tree;
    }
  }

  free_tree(tree);
  fclose(dest_file);
}
