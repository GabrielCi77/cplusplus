CXX=g++
CXXFLAGS=-Wall -ggdb
RM=rm -f

liste :  main.o test.o
	$(CXX) $(CXXFLAGS) $^ -o $@
	$(RM) test.o main.o


main.o : main.cpp test.h intlist.h
test.o : test.cpp test.h intlist.h

%.o: %.cpp;
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) liste test.o main.o 