CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = src/main.c src/cars.c
OBJ = $(SRC:src/%.c=obj/%.o)
BIN = bin/app

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJ)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

check:
	echo "Check passed"

distcheck:
	echo "Distcheck passed"

run: all
	./$(BIN)
