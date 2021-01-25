#include <map>
#include "decenc.h"
#include <iostream>
using namespace std;

//on utilisera un dictionnaire pour passer d'un monde a l'autre

map<char, string> enc = {{'A', ".-"},{'B', "-..."},{'C', "-.-."},{'D', "-.."},{'E', "."},{'F', "..-."},{'G', "--."},{'H', "...."},{'I', ".."},{'J', ".---"},
  {'K', "-.-"},{'L', ".-.."},{'M', "--"},{'N', "-."},{'O', "---"},{'P', ".--."},{'Q', "--.-"},{'R', ".-."},{'S', "..."},{'T', "-"},{'U', "..-"},{'V', "...-"},
  {'W', ".--"},{'X', "-..-"},{'Y', "-.--"},{'Z', "--.."},{'0', "-----"},{'1', ".----"},{'2', "..---"},{'3', "...--"},{'4', "....-"},{'5', "....."},{'6', "-...."},{'7', "--..."},
  {'8', "---.."},{'9', "----."},{'.', ".-.-.-"},{'\'', "--..--"},{',', "---..."},{'?', "..--.."},{'-', "-....-"},{'/', "-..-."},{' ',"    "}};

string encode (char a){
    map<char, string>::iterator it;
    it=  enc.find(a);
    if (it==enc.end()){
        return ""; //si ce n'est pas dans le dictionnaire, on supprime ce caractère
    }
    else{
        return it->second;
    }
}

string decode (string morse){
    Node deb;
    map<char, string>::iterator it;
    it=enc.begin();
    while (it != (enc.end())){
        deb.insert(it->first, it->second); // On remplit le trie (pseudo Arbre Radix)
        it++;
    }
    string trad;
    string tampon;
    int tampespace;
    for (char i : morse){
        if (i==' ') {
            tampespace+=1;
            if (tampespace <2){
                trad += deb.intolettre(tampon);
                tampon.clear();
            }
            else if (tampespace==3){
                trad += ' ';
            }
        }
        else{
            tampon += i;
            tampespace=0;
        }
    }
    trad+=deb.intolettre(tampon);
    deb.~Node();
    return trad;
}