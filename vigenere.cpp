#include<iostream>
#include<string>
#include<cctype>
#include "caesar.h"
#include "vigenere.h"

std::string encryptVigenere(std::string plaintext, std::string keyword){
  int shift;
  int alphaChars=0;
  std::string encrypted = "";
  for (int i = 0; i < plaintext.length(); i++) {
    if(isalpha(plaintext[i])){
      encrypted += shiftChar(plaintext[i], (int)keyword[alphaChars%keyword.length()]-97);
      alphaChars+=1;
    }
    else{encrypted += plaintext[i];}
  }
  return encrypted;
}
