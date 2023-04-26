CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
LDLIBS = -lncurses

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = hw6

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

run: $(EXEC)
	TERM=xterm-256color ./$(EXEC)
