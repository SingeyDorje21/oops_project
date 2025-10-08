# Compiler and flags
CXX := g++
CXXFLAGS := -Iinclude -Wall -Wextra -std=c++17

# Folders
SRC_DIR := src
INC_DIR := include
BUILD_DIR := build

# Executable name
TARGET := $(BUILD_DIR)/smartParkingSystem.exe

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compiling
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/*.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure build dir exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean rule
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

# Run program
run: all
	$(TARGET)
