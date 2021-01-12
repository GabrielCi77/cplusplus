#include <iostream>
#include "intlist.h"
using namespace std;

int TestIntList(){

    cout << "Nouvelle liste" << endl;
    IntList liste1;

    cout << "Remplissage" << endl;
    for(int i=0; i<10;++i){
        liste1.add_front(i);
    }
    for(int i=1; i<10;++i){
        liste1.add_back(i);
    }
    cout << "Affichage:" << endl;
    liste1.print();

    cout << "On retire les 9:"<<endl;
    liste1.remove_front();
    liste1.remove_back();
    liste1.print();

    cout << "Vérif search+remove avec 0"<< endl<< "Résultat:"<< endl;
    liste1.remove(0);
    liste1.print();

    cout <<"Vérif remove sur les cellules de fin et pour vérifier que ca ne retire que le premier"<< endl;
    liste1.remove(8);
    cout<<"on a retiré le premier:"<<endl;
    liste1.print();
    cout<<"on a retiré le second:"<<endl;
    liste1.remove(8);
    liste1.print();
    return 0;
}