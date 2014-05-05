
SRC = murmurhash.c
CFLAGS += -std=c99 -Wall -I.

clean:
	rm -f test

test:
	$(CC) test.c $(SRC) $(CFLAGS) -o test
	./test

.PHONY: test
