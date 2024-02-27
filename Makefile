CC=gcc
CFLAGS=-Wall -Wextra -pedantic -g -std=gnu11
LDFLAGS=-fsanitize=address -fsanitize=leak -fsanitize=undefined -lm
LIBS=-lX11 -lm
BIN=main
SRC_PATH=src

all: $(BIN)

$(BIN): $(SRC_PATH)/*.c
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS) $(LDFLAGS)

clean:
	rm -f *.o $(BIN)
