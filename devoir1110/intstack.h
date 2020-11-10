#include<iostream>
using namespace std;

class IntStack{
    public :
        IntStack (int s): size(s),top(0){
            if(s>0){
                tab = new int [size];
            }
            else {
                std::cout<< "Taille inférieure ou égale à 0\n";
                throw(1);
            }
        }

        ~IntStack(){
            delete [] tab;
        }

        void push (int e){
            if (not is_full()){
                tab[top]= e;
                top=top+1;
            }
            else{
                std::cout << "La pile est pleine\n";
            }
        }

        int pop();
        bool is_empty(){
            return top ==0;
        }
        bool is_full(){
            return top == size;
        }
        void printstack(){
            cout << "[ " ;
            for ( int i; i<top;i++ ){
                cout << tab[i] << " \n";
            }
            cout << "[";
        }

    private :
        int top;
        int size;
        int *tab;

};

inline int IntStack::pop(){
    if (not is_empty()){
        top = top-1;
        return tab[top];
    }
    else {
        cout << "la pile est vide \n";
        throw(2);
    }
}