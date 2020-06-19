.PHONY: clean all run testing

BIN_DIR := ./bin/
SRC_DIR := ./src/
BUILD_DIR := ./build/src/
BUILD_TEST_DIR := ./build/test/
TEST_DIR := ./test/
FLAG := -Wall -Wextra
STD_FLAG := -std=c++11

all: $(BIN_DIR)alphabet $(BIN_DIR)test

$(BIN_DIR)alphabet: $(BUILD_DIR)main.o $(BUILD_DIR)input.o $(BUILD_DIR)output.o
	g++ $(FLAG) $(BUILD_DIR)main.o $(BUILD_DIR)input.o $(BUILD_DIR)output.o -o $(BIN_DIR)alphabet

$(BUILD_DIR)main.o: $(SRC_DIR)main.cpp
	g++ $(FLAG) -c $(SRC_DIR)main.cpp -o $(BUILD_DIR)main.o $(STD_FLAG)

$(BUILD_DIR)input.o: $(SRC_DIR)input.cpp
	g++ $(FLAG) -c $(SRC_DIR)input.cpp -o $(BUILD_DIR)input.o $(STD_FLAG)

$(BUILD_DIR)output.o: $(SRC_DIR)output.cpp
	g++ $(FLAG) -c $(SRC_DIR)output.cpp -o $(BUILD_DIR)output.o $(STD_FLAG)

$(BIN_DIR)test: $(BUILD_TEST_DIR)input_test.o $(BUILD_TEST_DIR)output_test.o $(BUILD_DIR)input.o $(BUILD_DIR)output.o
	g++ $(BUILD_TEST_DIR)input_test.o  $(BUILD_TEST_DIR)output_test.o $(BUILD_DIR)input.o $(BUILD_DIR)output.o -o $(BIN_DIR)test

$(BUILD_TEST_DIR)input_test.o: $(TEST_DIR)input_test.cpp 
	g++ -I thirdparty -I src -c $(TEST_DIR)input_test.cpp -o $(BUILD_TEST_DIR)input_test.o $(STD_FLAG)

$(BUILD_TEST_DIR)output_test.o: $(TEST_DIR)output_test.cpp 
	g++ -I thirdparty -I src -c $(TEST_DIR)output_test.cpp -o $(BUILD_TEST_DIR)output_test.o $(STD_FLAG)

run:
	$(BIN_DIR)alphabet ./example/words.txt

testing:
	$(BIN_DIR)test

clean:
	rm -rf $(BUILD_DIR)*.o $(BUILD_TEST_DIR)*.o $(BIN_DIR)alphabet $(BIN_DIR)test