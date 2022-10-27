CC      = gcc
CFLAGS  = -ggdb -std=c89  -ansi -pedantic 
CFLAGS += -Wall -Werror -Wextra -Wpedantic -Wstrict-aliasing

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = bin
HDR = $(wildcard src/*.h)
GCH = $(HDR:.h=.h.gch)


.PHONY: all dirs clean

all: dirs headers suzaku

headers: $(GCH)

dirs:
	mkdir -p ./$(BIN)

suzaku: $(OBJ)
	$(CC) -o $(BIN)/$@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

%.h.gch: %.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(BIN) $(OBJ) $(GCH)
