prog = main
CC = clang++
CXXFLAGS = -Wall -g -std=c++1y -O2

$(prog) : $(prog).o
	$(CC) $^ -o $@
$(prog).o : $(prog).cpp
	$(CC) $(CXXFLAGS) -c $^ -o $@

clean :
	rm $(prog) $(prog).o
