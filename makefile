.PHONY: clean all run 

BIN_DIR := ./bin/
SRC_DIR := ./src/
BUILD_DIR := ./build/
BUILD_TEST_DIR := ./build/test/
TEST_DIR := ./test/
FLAG := -Wall -Wextra

all: $(BIN_DIR)alphabet 

$(BIN_DIR)alphabet: $(BUILD_DIR)main.o $(BUILD_DIR)input.o $(BUILD_DIR)output.o
	g++ $(FLAG) $(BUILD_DIR)main.o $(BUILD_DIR)input.o $(BUILD_DIR)output.o -o $(BIN_DIR)alphabet

$(BUILD_DIR)main.o: $(SRC_DIR)main.cpp
	g++ $(FLAG)  -c $(SRC_DIR)main.cpp -o $(BUILD_DIR)main.o

$(BUILD_DIR)input.o: $(SRC_DIR)input.cpp
	g++ $(FLAG)  -c $(SRC_DIR)input.cpp -o $(BUILD_DIR)input.o

$(BUILD_DIR)output.o: $(SRC_DIR)output.cpp
	g++ $(FLAG)  -c $(SRC_DIR)output.cpp -o $(BUILD_DIR)output.o

run:
	$(BIN_DIR)alphabet

clean:
	rm -rf $(BUILD_DIR)*.o $(BIN_DIR)alphabet $(BIN_DIR)testing