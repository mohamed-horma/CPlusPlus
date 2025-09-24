CXX=g++
CXXFLAGS=-Wall -Wextra -O2 -std=c++11
SRC=src/complex.cpp src/main.cpp
OBJ=$(SRC:.cpp=.o)
EXECS=tp2

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