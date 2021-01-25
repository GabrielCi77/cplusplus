CXX=g++
CXXFLAGS=-Wall -ggdb
RM=rm -f

morse :  morse.o decenc.o inout.o wavfile.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	$(RM) morse.o decenc.o inout.o wavfile.o

morse.o : morse.cpp decenc.h decenc.cpp inout.cpp inout.h 
decenc.o : decenc.h decenc.cpp
inout.o : inout.cpp inout.h

%.o: %.cpp;
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) morse decenc.o morse.o inout.o morse.wav texte.txt morse.txt