OBJS = src/huffman.c src/heap.c
DEPS = inc/heap.h


compile:
	gcc $(OBJS) $(DEPS) -o huffman -lm

clean:
	rm -f huffman
