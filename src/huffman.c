#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node Node;

struct node{

  char item;
  int frequency;
  Node *next;
  
  Node *left;
  Node *right;

};

void help();

int main(int argc, char const *argv[]) {
  FILE *file;
  char *src_filename, *dest_filename, option[3];
  char *file_content;
  size_t file_size;
  int i, frequency[256] = {0};
  

  if(argc == 1) {
    help();
  } else {
    if(argc == 2 && strcmp(argv[1], "-help") == 0) {
      help();
      return 0;
    } else if(argc != 4) {
      printf("Invalid arguments! See 'huffman -help' for more information. \n");
      exit(1);
    }

    src_filename = malloc(strlen(argv[1]) * sizeof(char));
    dest_filename = malloc(strlen(argv[2]) * sizeof(char));

    strcpy(src_filename, argv[1]);
    strcpy(dest_filename, argv[2]);
    strcpy(option, argv[3]);

    if(strcmp(option, "-c") != 0 && strcmp(option, "-d") != 0) {
      printf("Invalid option! See 'huffman -help' for more information.\n");
      exit(1);
    }

    file = fopen(src_filename, "r");

    if(file == NULL) {
      printf("The source file does not exist!\n");
      exit(1);
    }

    fseek(file, 0, SEEK_END);                             /* Set the pointer to the end of the file */
    file_size = ftell(file);                              /* Return the position of the pointer on the file */
    rewind(file);                                         /* Rollback the pointer to the beginning of thee file */
    file_content = malloc((file_size + 1) * (sizeof(char)));
    fread(file_content, sizeof(char), file_size, file);   /* Read the content of the file */
    fclose(file);
    file_content[file_size] = 0;
  }

  for(i = 0; i < file_size; i++){

    ++frequency[file_content[i]];                          /* Counts the frequency of every character in the file */

  }

  /* Use the index of the array as the char and the value of each index as the frequency when creating nodes */

  return 0;
}

void help() {
  printf("Huffman Help\n\n");

  printf("Usage: huffman [source_filename_path] [destination_filename_path] [options]\n\n");

  printf("Options:\n");
  printf("%s\n", "-c: Compress the source file to the destination file");
  printf("%s\n", "-d: Decompress the source file to the destination file");

  exit(0);
}

