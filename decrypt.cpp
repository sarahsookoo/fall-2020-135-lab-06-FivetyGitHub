#include<iostream>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"

std::string decryptCaesar(std::string cipher, int shift){
  int sh = 26-(shift%26);
  std::string encrypted = "";
  for(int i = 0; i<cipher.length(); i++){
    encrypted += shiftChar(cipher[i],sh);
  }
  return encrypted;
}

std::string decryptVigenere(std::string cipher, std::string keyword){
  int shift;
  int alphaChars=0;
  std::string encrypted = "";
  for (int i = 0; i < cipher.length(); i++) {
    if(isalpha(cipher[i])){
      encrypted += shiftChar(cipher[i], 26- ((int)keyword[alphaChars%keyword.length()]-97));
      alphaChars+=1;
    }
    else{encrypted += cipher[i];}
  }
  return encrypted;
}
