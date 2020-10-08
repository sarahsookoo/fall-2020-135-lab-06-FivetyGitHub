#include <iostream>
#include "funcs.h"

// add functions here

void test_ascii(std::string s){
  for(int i = 0; i<s.length(); i++){
    int num = int(s[i]);
    std::cout << s[i];
    std::cout << " ";
    std::cout << num;
    std::cout << std::endl;
  }
}
