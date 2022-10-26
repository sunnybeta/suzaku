CC      = gcc
CFLAGS  = -ggdb -std=c89  -ansi -pedantic 
CFLAGS += -Wall -Werror -Wextra -Wpedantic -Wstrict-aliasing
CFLAGS += -Iinclude
LDFLAGS  =

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = bin


.PHONY: all clean
.SILENT: clean

all: dirs suzku

dirs:
	mkdir -p ./$(BIN)

suzku: $(OBJ)
	$(CC) -o $(BIN)/$@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)
