
BIN ?= murmur
SRC = murmurhash.c
CFLAGS += -std=c99 -Wall -I. -DMURMURHASH_WANTS_HTOLE32=1
PREFIX ?= /usr/local
MANPREFIX ?= $(PREFIX)/share/man
MAN_FILES = $(wildcard man/*.md)
LIB ?= libmurmurhash.so
INCLUDE ?= murmurhash.h

all: $(LIB) $(BIN) example

$(LIB):
	$(CC) -shared $(SRC) $(CFLAGS) -o $(LIB)

$(BIN):
	$(CC) main.c $(SRC) $(CFLAGS) -o $(BIN)

clean:
	rm -f test
	rm -f $(BIN)
	rm -f $(LIB)
	rm -f example

example: example.c murmurhash.c
	$(CC) $^ -o $@

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
