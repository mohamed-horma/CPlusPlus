CXX=g++
CXXFLAGS=-Wall -Wextra -g -O2 -std=c++11 -Iinclude
SRC= src/set_test.cpp include/Set.h
OBJ=$(SRC:.cpp=.o)
EXECS=tp5

.PHONY: all clean mrproper

all: depend $(EXECS)

$(EXECS): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@



clean:
	rm -f tp5 set_test.o

mrproper: clean
	rm -f tp5 set_test.o