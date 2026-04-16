CXX = g++

CXXFLAGS = -std=c++11 -Wall

OBJS = main.o lcs.o menu.o

EXEC = run

TEXT_FILES = 

run: $(OBJS)
				$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

main.o : lcs.hpp
lcs.o : stack.hpp lcs.hpp
menu.o : menu.hpp lcs.hpp

clean :
				rm -f $(EXEC) $(TEXT_FILES) $(OBJS)