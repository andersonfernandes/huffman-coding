OBJS = src/huffman.c src/huffman_tree.c src/heap.c src/table.c src/compress.c src/decompress.c
DEPS = inc/huffman_tree.h inc/heap.h inc/table.h inc/compress.h inc/decompress.h


compile:
	gcc $(OBJS) $(DEPS) -o huffman -lm

clean:
	rm -f huffman
