CXX=gcc
CXXFLAGS=-Wall -Wextra -Iinclude
FLAGS=-lncurses

SRC=src
OBJ=obj
BIN=bin
TARGET=$(BIN)/rouge

SRCFILES=$(shell find $(SRC) -name '*.c')
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCFILES))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(FLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ) $(BIN)

.PHONY: clean 
