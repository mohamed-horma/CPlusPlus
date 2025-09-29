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


simpleTest: simpleTest.cpp src/complex.cpp
	$(CXX) -fno-elide-constructors $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(EXECS) simpleTest

mrproper: clean
	rm -f $(EXECS)