# Compiler & Flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Target
TARGET = mazeRunner

# Source structure
SRCDIRS := src/design src/utils src/utils/game src/var
SOURCES := $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))
OBJECTS := $(SOURCES:.cpp=.o)

# Default rule
all: $(TARGET)

# Build target
$(TARGET): $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile main.cpp separately
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Generic rule for .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	-del /Q $(subst /,\,$(OBJECTS)) main.o $(TARGET) 2>nul || exit 0

