
BIN ?= murmur
SRC = murmurhash.c
CFLAGS += -std=c99 -Wall -I.
PREFIX ?= /usr/local
MANPREFIX ?= $(PREFIX)/share/man
MAN_FILES = $(wildcard man/*.md)
LIB ?= libmurmurhash.so
INCLUDE ?= murmurhash.h

all: $(LIB) $(BIN)

$(LIB):
	$(CC) -shared $(SRC) $(CFLAGS) -o $(LIB)

$(BIN):
	$(CC) main.c $(SRC) $(CFLAGS) -o $(BIN)

clean:
	rm -f test
	rm -f $(BIN)
	rm -f $(LIB)

example:
	$(CC) murmurhash_example.c -lmurmurhash -o murmurhash_example

test:
	$(CC) test.c $(SRC) $(CFLAGS) -o test
	./test

install: $(BIN) $(LIB)
	install $(BIN) $(PREFIX)/bin
	install $(LIB) $(PREFIX)/lib
	install $(INCLUDE) $(PREFIX)/include
	install man/*.1 $(MANPREFIX)/man1

docs: $(MAN_FILES)

$(MAN_FILES):
	curl -# -F page=@$(@) -o $(@:%.md=%) http://mantastic.herokuapp.com

.PHONY: test $(MAN_FILES)
