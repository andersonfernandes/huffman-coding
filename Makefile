OBJS = src/huffman.c
DEPS = src/heap.c
DEPS_HEAP = inc/heap.h

compile:
	gcc $(OBJS) $(DEPS) $(DEPS_HEAP) -o huffman

clean:
	rm -f huffman
