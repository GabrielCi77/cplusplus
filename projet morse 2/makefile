CXX=g++
# (vr: j'en avais assez des warnings)
CXXFLAGS=-Wall -ggdb -Wno-stringop-truncation
RM=rm -f

morse :  morse.o decenc.o inout.o wavfile.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
	$(RM) morse.o decenc.o inout.o wavfile.o

# vr: pourquoi veux-tu recompiler morse.cpp quand decenc.pp ou inout.cpp sont modifiés ? ils ne sont pas inclus dedans 
# morse.o : morse.cpp decenc.h decenc.cpp inout.cpp inout.h 
morse.o : morse.cpp decenc.h inout.h 
decenc.o : decenc.h decenc.cpp
inout.o : inout.cpp inout.h

%.o: %.cpp;
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) morse decenc.o morse.o inout.o morse.wav texte.txt morse.txt
