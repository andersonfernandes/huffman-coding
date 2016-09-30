OBJS = src/huffman.c
DEPS =

compile:
	gcc $(OBJS) $(DEPS) -o huffman

clean:
	rm -f huffman
