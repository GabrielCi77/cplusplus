#include <string>
#include <iostream>
#include "decenc.h"
#include "inout.h"

using namespace std;

int main(){
    char c; //utile pour le choix
    cout << "Entrez e pour encoder ou d pour décoder :"<< endl;
    cin >> c;
    switch(c){
        case 'e':{
            cout << "Voulez vous récupérer le texte d'un fichier ou écrire un message ? Tapez f pour fichier et m pour un message"<<endl;
            cin >> c;
            string mess;
            switch(c){
                case 'f':{
                    cout<< endl << "Entrez le chemin vers le fichier .txt voulu :     ";
                    string chemin;
                    cin.ignore();
                    getline(cin,chemin);
                    mess=getchemin(chemin);
                    break;
                }
                case 'm':{
                    cout << endl <<"Ecrivez ce que vous voulez encoder:     ";
                    cin.ignore();
                    getline(cin,mess); // on récupère le message
                    break;
                }
            }
            cout << "Voulez vous écrire dans un fichier texte ou en audio ? Tapez t pour texte et a pour un audio"<<endl;
            char c2;
            cin >> c2;
            string morse;
            for (char i : mess){
                morse+=encode(i);
                morse+=" ";
            }
            switch(c2){
                case 't':
                    writechemin(morse);
                    break;
                case 'a':
                    createwav(morse); //on crée le .wav
                    break;
            }
            cout << endl<< "Le fichier est créé"<<endl;
            break;
        }
        case 'd':{
            cout << "Voulez vous transmettre un fichier audio ou un message écrit ou encore un fichier texte en morse ? Tapez a pour audio, m pour message et t pour texte"<<endl;
            char c;
            cin >> c;
            switch(c){
                case 'a':{
                    string chemin;
                    cout << "Quel est le chemin vers le fichier audio?"<< endl;
                    cin.ignore();
                    getline(cin,chemin);
                    string morse=getwav(chemin);
                    string dec = decode(morse);
                    cout << morse;
                    break;
                }
                case 'm':{
                    string mess;
                    cout << "Ecrivez le message :       ";
                    cin.ignore();
                    getline(cin,mess);
                    string dec = decode(mess);
                    cout << dec<< endl;
                    break;
                }
                case 't':{
                    string chemin;
                    cout << "Quel est le chemin vers le fichier texte?"<< endl;
                    cin.ignore();
                    getline(cin,chemin);
                    string morse=getchemin(chemin);
                    string dec = decode(morse);
                    cout << dec;
                    break;
                }
            }
        }
    }
    return 0;
 }
 
 