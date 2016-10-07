OBJS = src/huffman.c src/heap.c src/table.c
DEPS = inc/heap.h inc/table.h


compile:
	gcc $(OBJS) $(DEPS) -o huffman

clean:
	rm -f huffman
