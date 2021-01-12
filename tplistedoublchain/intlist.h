#include <iostream>
using namespace std;

#ifndef INTLIST_H
#define INTLIST_H

class IntCell { 
   friend class IntList;
private:
   IntCell(int valeur){
      value = valeur;
   }
   int value;
   IntCell* nextptr=nullptr;
   IntCell* prevptr=nullptr;
};

class IntList {
public:    
   ~IntList(){
    if (first_cell != nullptr){
        IntCell *destr = first_cell;
        while (destr != last_cell){
         
           if (destr->prevptr != nullptr){
              delete destr->prevptr;
               destr = destr->nextptr;
           }
        }
        delete destr->prevptr;
        delete destr;
    }
    else{
        cout << "la liste est vide";
    }
   }
   void add_front (int valeur);
   void add_back (int valeur);
   void remove_front ();
   void remove_back ();
   void remove (int valeur);
   bool search (int valeur);
   void print ();

private:
   IntCell* first_cell=nullptr;
   IntCell* last_cell=nullptr;
};

inline
void IntList::add_front(int valeur){

    IntCell *newptr = new IntCell(valeur);

    if (first_cell != nullptr){                                      
        newptr->nextptr = first_cell;   
        first_cell->prevptr = newptr; 
    }
    else{
        last_cell = newptr;
    }
    first_cell = newptr; 
}

inline
void IntList::add_back(int valeur){

    IntCell *newptr = new IntCell(valeur);

    if (last_cell != nullptr){
        newptr->prevptr = last_cell;
        last_cell->nextptr = newptr;
    }
    else{
        first_cell = newptr;
    }
    last_cell = newptr;
}

inline
void IntList::remove_front(){

    if (first_cell != nullptr){

        if (first_cell->nextptr != nullptr){

            first_cell = first_cell->nextptr;
            delete first_cell->prevptr;
            first_cell->prevptr=nullptr;
        }
        else{ 
            delete first_cell;
            first_cell = nullptr;
            last_cell = nullptr;
        }
    }
    else{

       cout << "la liste est vide";
    }
}

inline
void IntList::remove_back(){

    if (last_cell != nullptr){

        if (last_cell->prevptr != nullptr){

            last_cell = last_cell->prevptr;
            delete last_cell->nextptr;
            last_cell->nextptr = nullptr;
        }
        else{

            delete last_cell;
            first_cell = nullptr;
            last_cell = nullptr;
        }
    }
    else{

       cout << "la liste est vide";
    }
}

inline
void IntList::remove(int valeur){
   if (search(valeur)) {
      if (last_cell->value != valeur){
         IntCell *c = last_cell;
         do{
         c = c->prevptr;
         if (valeur == c->value){
            if (c == first_cell){
               remove_front();
               break;
            }
            else{
                (c->prevptr)->nextptr = c->nextptr;
                (c->nextptr)->prevptr = c->prevptr;
                break;
            }
            delete c;
            }
         }while (c != last_cell);
      }
      else{
         remove_back();
      }
   }
   else{
      cout << "pas dans la liste";
   }
   
}

inline
bool IntList::search(int valeur){
   if (first_cell->value != valeur){
      IntCell *c = first_cell;
      do{
         c = c->nextptr;
         if (valeur == c->value)
         {
            return true;
         }
      }while (c != last_cell);

      return false;
   }
   else{
      return true;
   }
}

inline
void IntList::print(){

    cout << '{';
    IntCell *ptr = first_cell;
    if (ptr != nullptr){

        while (ptr != last_cell){

            cout << ptr->value << " ";
            ptr = ptr->nextptr;
        }
        cout << last_cell->value;
    }
    cout << "}" << endl;
}

#endif