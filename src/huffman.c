#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void help();

int main(int argc, char const *argv[]) {
  FILE *file;
  char *src_filename, *dest_filename, option[3];

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

    char chr;

    while((chr = fgetc(file)) != EOF) {
      printf("%c", chr);
    }
  }

  fclose(file);
  return 0;
}

void help() {
  printf("Huffman Help\n\n");

  printf("Usage: io [source_filename_path] [destination_filename_path] [options]\n\n");

  printf("Options:\n");
  printf("%s\n", "-c: Compress the source file to the destination file");
  printf("%s\n", "-h: Decompress the source file to the destination file");

  exit(0);
}
