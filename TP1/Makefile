CXX=g++
CXXFLAGS=-Wall -Wextra -O2 -std=c++11
SRC= src/main.cpp src/book.cpp src/logical-gate.cpp
OBJS=$(SRC:.cpp=.o)
EXECS= tp1

.PHONY : all clean mrpropre

all : depend $(EXECS)

$(EXECS): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(EXECS)

mrpropre : clean
	rm -f $(EXECS)
