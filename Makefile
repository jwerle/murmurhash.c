
BIN ?= murmur
SRC = murmurhash.c
CFLAGS += -std=c99 -Wall -I.
PREFIX ?= /usr/local
MANPREFIX ?= $(PREFIX)/share/man
MAN_FILES = $(wildcard man/*.md)

$(BIN):
	$(CC) main.c $(SRC) $(CFLAGS) -o $(BIN)

clean:
	rm -f test
	rm -f $(BIN)

test:
	$(CC) test.c $(SRC) $(CFLAGS) -o test
	./test

install: $(BIN)
	install $(BIN) $(PREFIX)/bin
	install man/*.1 $(MANPREFIX)/man1

docs: $(MAN_FILES)

$(MAN_FILES):
	curl -# -F page=@$(@) -o $(@:%.md=%) http://mantastic.herokuapp.com

.PHONY: test $(MAN_FILES)
