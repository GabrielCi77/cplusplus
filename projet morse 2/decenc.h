#pragma once
// vr: protège tes fichiers d'entête contre l'inclusion multiple soit par ifndef/define/endif soit par le pragme once (il n'est pas normalisé mais est utilisable)
#include <string>
#include <cmath>
using namespace std;

// vr: ce code manque de commentaires
class Node {
  friend void delete_all_nodes(Node*); // vr: destructeur de Node
    public :
        void insert (char,string);
        char intolettre(string morse){
            if (morse.size() == 0){
                return lettre;
            }
            switch (morse[0]){
                case '.' :
                    morse.erase(0,1);
                    if (clptr[0] != nullptr) {
                        return clptr [0]->intolettre(morse);
                    }
                    else{
                        throw("Caractère non pris en charge//Arbre mal initialisé");
                    }
                    break;
                case '-' :
                    morse.erase(0,1);
                    if (clptr[1] != nullptr) {
                        return clptr [1]->intolettre(morse);
                    }
                    else{
                        throw("Caractère non pris en charge//Arbre mal initialisé");
                    }
                    break;
            }
            throw("Problème: le code n'est pas en morse");
        }

    private :    
        char lettre = '\0';
        Node* clptr [2] ={nullptr,nullptr};
};

inline void Node::insert(char a,std::string code){
  // vr: pourquoi recopier la string code qui est déjà une copie ?

    string code_=code;
    if (code_.size()==0){
        lettre = a;
        return;
    }
    switch (code_[0]){
            case '.':{
                if (clptr[0] != nullptr){
                    code_.erase(0,1);
                    clptr[0]->insert(a,code_);
                }
                else{
		  // vr: il faut détruire les Node (un destructeur ne fonctionnera pas il faut une fonction qui prend en argument l'arbre à détruire
                    Node* court= new Node;
                    clptr[0] = court;
                    code_.erase(0,1);
                    clptr[0]->insert(a,code_);
                }
                break;
            }
            case '-':{
                if (clptr[1] != nullptr){
                    code_.erase(0,1);
                    clptr[1]->insert(a,code_);
                }
                else{
                    Node* longlong= new Node;
                    clptr[1]= longlong;
                    code_.erase(0,1);
                    clptr[1]->insert(a,code_);
                }
                break;
            }
            throw ("Problème : pas du morse");
    }
}


std::string encode(char);
std::string decode(std::string);

