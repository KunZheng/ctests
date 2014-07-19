BIN = bin

CC = gcc
CFLAG = -g 

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, $(BIN)/%, $(SRC))


all: CHECK_DIR $(OBJ)

$(OBJ):$(BIN)/%:%.c
	$(CC) $(CFLAG) $^ -o $@

CHECK_DIR:
	@mkdir -p $(BIN)

clean:
	rm $(BIN)/* -f
