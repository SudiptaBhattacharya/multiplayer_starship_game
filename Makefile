# Compiler
CXX = clang++

# Compiler flags (includes SFML directory for headers)
CXXFLAGS = -std=c++17 -I/opt/homebrew/opt/sfml/include -I./include

# Linker flags (link with SFML libraries)
LDFLAGS = -L/opt/homebrew/opt/sfml/lib -lsfml-network -lsfml-system -lsfml-window -lsfml-graphics

# Directories
SRC_DIR = ./src
TEST_DIR = ./tests
BUILD_DIR = ./build
INCLUDE_DIR = ./include

# Source files (add your .cpp files here)
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Test files (add your test .cpp files here)
TESTS = $(wildcard $(TEST_DIR)/*.cpp)

# Object files (corresponding .o files)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Object files for tests
TEST_OBJS = $(TESTS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Target executable
TARGET = $(BUILD_DIR)/game
TEST_TARGET = $(BUILD_DIR)/test_runner

# Default target: build the executable
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile each source file to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile each test file to object files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link the test executable
$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CXX) $(OBJS) $(TEST_OBJS) -o $(TEST_TARGET) $(LDFLAGS)

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean target: remove all object files and the executable
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET) $(TEST_TARGET)

# Add a target to run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)
