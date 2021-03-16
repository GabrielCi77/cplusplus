#include <map>
#include "decenc.h"
#include <iostream>
using namespace std;

// vr: il faudrait faire une classe pour mettre ces variables globales en attributs et ces fonctions en méthodes et y implémenter la fonction pour détruire l'arbre de Node créé pqr decode (on peut aussi lui mettre la class Node en sous classe private)

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

// vr: destructeur de l'arbre des Node
void delete_all_nodes (Node* node) {
  if (node) {
    delete_all_nodes(node->clptr[0]);
    delete_all_nodes(node->clptr[1]);
    delete node;
  }
}

// vr: mettre des commentaires
string decode (string morse){
  
  // vr: il faut séparer le code en fonction, faire une fonction (ou une méthode de la classe) qui crée l'arbre à partir du dictionnaire de Morse

  // vr: utiliser un arbre de Node pour le décodage c'est très bien, ce serait intéressant de le comparer avec l'utilisation directe de la map pour voir ce que l'on gagne en temps par rapport à un dictionnaire avec une string comme key

    Node* pdeb =new Node;
    Node& deb = *pdeb;
    map<char, string>::iterator it;
    it=enc.begin();
    while (it != (enc.end())){
        deb.insert(it->first, it->second); // On remplit le trie (pseudo Arbre Radix) tree ?
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
    // vr: ce n'est pas avec un destructeur de Node que tu peux détruire l'arbre des Node
    //    deb.~Node();
    delete_all_nodes(pdeb);
    return trad;
}
