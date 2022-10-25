#! /bin/bash
SRC = ../src
INC = ../include
OBJ = ../obj
CC = gcc

OBJS = $(OBJ)/main.o $(OBJ)/roman.o

bin: $(OBJS)
	gcc -o $@ $(OBJS)

$(OBJS): $(OBJ)/%.o: $(SRC)/%.c
	mkdir -p $(OBJ)
	gcc -c -w $< -o $@ -I $(INC)

clean:
	rm -rf $(OBJS) $(OBJ) bin output.txt
