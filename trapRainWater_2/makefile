prog = main
CC = c++
CXXFLAGS = -Wall -g -std=c++1y

$(prog) : $(prog).o
	$(CC) $^ -o $@
$(prog).o : $(prog).cpp
	$(CC) $(CXXFLAGS) -c $^ -o $@

clean :
	rm $(prog) $(prog).o
