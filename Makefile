# Compiler options
CC := gcc
CFLAGS := -fsanitize=address -g -lm
LDLIBS := -lstdc++

# Directories
SRC_DIR := .
PREPROCESS_DIR := preprocess
PROCESS_DIR := process
FUNCTIONS_DIR := functions
CONVERTION_DIR := convertion
UTILS_DIR := Utils
LINKEDLIST_DIR := LinkedList
BUILD_DIR := build

# Source files
TEST_SOURCE := test.cpp
RUN_SOURCE := main.cpp
PREPROCESS_SOURCES := $(wildcard $(PREPROCESS_DIR)/*.cpp)
PROCESS_SOURCES := $(wildcard $(PROCESS_DIR)/*.cpp)
FUNCTIONS_SOURCES := $(wildcard $(FUNCTIONS_DIR)/*.cpp)
CONVERTION_SOURCES := $(wildcard $(CONVERTION_DIR)/*.cpp)
UTILS_SOURCES := $(wildcard $(UTILS_DIR)/*.cpp)
LINKEDLIST_SOURCES := $(wildcard $(LINKEDLIST_DIR)/*.cpp)
OBJECTS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(PREPROCESS_SOURCES) $(PROCESS_SOURCES) $(FUNCTIONS_SOURCES) $(CONVERTION_SOURCES) $(UTILS_SOURCES) $(LINKEDLIST_SOURCES))

# Target
TEST_EXECUTABLE := test
RUN_EXECUTABLE := run

# Default target
.DEFAULT_GOAL := $(RUN_EXECUTABLE)

# Build rule for test
$(BUILD_DIR)/$(TEST_SOURCE:.cpp=.o): $(TEST_SOURCE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build rule for run
$(BUILD_DIR)/$(RUN_SOURCE:.cpp=.o): $(RUN_SOURCE)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build rule for other source files
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Link rule for test
$(TEST_EXECUTABLE): $(BUILD_DIR)/$(TEST_SOURCE:.cpp=.o) $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

# Link rule for run
$(RUN_EXECUTABLE): $(BUILD_DIR)/$(RUN_SOURCE:.cpp=.o) $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

# Phony targets
.PHONY: clean test run

# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(TEST_EXECUTABLE) $(RUN_EXECUTABLE)

# Test rule
test: $(TEST_EXECUTABLE)

# Run rule
run: $(RUN_EXECUTABLE)