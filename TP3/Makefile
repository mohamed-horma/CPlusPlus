CXX=g++
CXXFLAGS=-Wall -Wextra -g -O2 -std=c++11 -Iinclude
SRC=src/matrix.cpp src/main.cpp
OBJ=$(SRC:.cpp=.o)
EXECS=tp3

.PHONY: all clean mrproper

all: depend $(EXECS)

$(EXECS): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@



clean:
	rm -f $(OBJ) $(EXECS) 

mrproper: clean
	rm -f $(EXECS)