CC      = gcc
CFLAGS  = -g -std=c89  -ansi -pedantic 
CFLAGS += -Wall -Werror -Wextra -Wpedantic -Wstrict-aliasing
#CFLAGS += -Wno-pointer-arith -Wno-newline-eof -Wno-unused-parameter -Wno-gnu-statement-expression
#CFLAGS += -Wno-gnu-compound-literal-initializer -Wno-gnu-zero-variadic-macro-arguments
CFLAGS += -Iinclude
LDFLAGS  =

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = bin


.PHONY: all clean dirs
.SILENT: clean

all: dirs suzku

dirs:
	mkdir -p ./$(BIN)

suzku: $(OBJ)
	$(CC) -o $(BIN)/suzku $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)
