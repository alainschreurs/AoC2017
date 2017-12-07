CC=g++
LDFLAGS=
CPPFLAGS=
CXXFLAGS=

SRC_DIR=puzzles
BIN_DIR=bin
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
BIN_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.exe,$(SRC_FILES))

all: $(BIN_FILES)

$(BIN_DIR)/%.exe: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -o $@ $<
	
clean:
	rm $(BIN_FILES)