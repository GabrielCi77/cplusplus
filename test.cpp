#include <iostream>
#include "rpn_eval.h"
#include<string>

int main () {
  const char* L1[]={"3","8","52","8","!","x","+","-"};
  std::cout << rpn_eval(8,L1)<< " vaudrait donc " << 3- (52*(-8)+8) << std::endl;
  const char* L2[]={"83","52","22","/","*"};
  std::cout << rpn_eval(5,L2)<<" vaudrait donc " << 83*(52/22)<< std::endl;
  std::cout << "Il semble ici y avoir un problème non résolvable dans le calculateur, la fonction sort un mauvais résultat"<< std::endl;
  const char* L3[]={"3","27","82","+","+"};
  const char* L4[]={"3","27","41","41","+","+","+"};
  std::cout << rpn_eval(6,L3)<<" vaudrait donc "<<rpn_eval(7,L4) << std::endl;
  return 0;
}