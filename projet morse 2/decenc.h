#include <string>
#include <cmath>
using namespace std;

class Node {
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

