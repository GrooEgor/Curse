.PHONY: clean all run testing

BIN_DIR := bin/
SRC_DIR := src/
BUILD_DIR := build/
BUILD_TEST_DIR := build/test/
FLAG := -Wall -Wextra

all: $(BIN_DIR)alphabet $(BIN_DIR)test

$(BUILD_DIR)main.o: main.cpp
	g++ $(FLAG) 
run:

testing:

clean:
