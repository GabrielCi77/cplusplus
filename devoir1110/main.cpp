#include <iostream>
#include "intstack.h"
using namespace std;

void test () {
  IntStack st (12);
  st.print(); // [[

  st.push(81);
  st.print(); // [81 [

  st.push(52);
  st.print(); // [81 52 [

  st.push(36);
  st.print(); // [81 52 36 [

  std :: cout << st.pop () << std::endl; // 36
  st.print (); // [81 52 [
}

int main () {
  test();
  return 0;
}
