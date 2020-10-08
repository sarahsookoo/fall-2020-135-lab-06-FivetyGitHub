#include <iostream>


#include "funcs.h"
#include "caesar.h"

int main()
{
  //test_ascii("According to all known laws of aviation, there is no way a bee should be able to fly.");

  std::cout << "test" + shiftChar('Z',1);
  std::cout << shiftChar('Z',1) + "\n test";
  return 0;
}
