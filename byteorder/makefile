prog = main
CC = clang++
CXXFLAGS = -Wall -g -std=c++11

$(prog) : $(prog).o
	$(CC) $^ -o $@
$(prog).o : $(prog).cpp
	$(CC) $(CXXFLAGS) -c $^ -o $@

clean :
	rm $(prog) $(prog).o
