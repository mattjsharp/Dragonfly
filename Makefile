.PHONY: all test clean

# Compiler
CXX := g++
CXXFLAGS := -std=c++17 -Iinclude -fPIC

# Library name
TARGET := libdragonfly.a

# Source files
SRCS := $(wildcard src/*.cpp)

# Build directory
BUILD_DIR := build

# Object files: src/foo.cpp -> build/foo.o
OBJS := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Default rule
all: $(TARGET)

# Build static library
$(TARGET): $(OBJS)
	ar rcs $@ $^

# Pattern rule: compile src → build
$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET) test
