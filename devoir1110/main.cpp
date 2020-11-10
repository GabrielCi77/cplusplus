#include <iostream>
#include "intstack.h"
using namespace std;

int main(){

    IntStack pile (10);
    pile.push(1);
    cout<<pile.pop();
    pile.push(4);
    pile.printstack();
    return 0;
}