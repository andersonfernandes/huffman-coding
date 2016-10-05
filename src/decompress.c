#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/heap.h"

int is_bit_i_set(unsigned char c, int i) {
	unsigned char mask = 1 << i;
	return mask & c;
}

char* decompress(char *file_content, size_t file_size) {
	unsigned char trash_size = file_content[0];
	trash_size = trash_size >> 5;

	return NULL;
}
