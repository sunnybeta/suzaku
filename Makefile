CC        = cc
CFLAGS    = -ggdb -std=c89  -ansi -pedantic 
CFLAGS   += -Wall -Werror -Wextra -Wpedantic -Wstrict-aliasing
INCFLAGS  = -Iinclude
LDFLAGS   = 

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
BIN = bin


.PHONY: all dirs clean

all: dirs suzaku

dirs:
	mkdir -p ./$(BIN)

suzaku: $(OBJ)
	$(CC) -o $(BIN)/$@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)
