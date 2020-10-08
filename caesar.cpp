#include<iostream>
#include<string>
#include<cctype>
#include "caesar.h"

char shiftChar(char c, int shift){
  char ch;
  int dist;
  if(isalpha(c)){
    if(isupper(c)){
      dist= (int)c - 65;
      ch = (char)((dist + shift)%26 + 65);
    }
    else if(islower(c)){
      dist= (int)c - 97;
      ch =(char)((dist + shift)%26 + 97);
    }
  }
  else{ch=c;}
  return ch;
}

std::string encryptCaesar(std::string s, int shift){
  std::string encrypted = "";
  for(int i = 0; i<s.length(); i++){
    encrypted += shiftChar(s[i],shift);
  }
  return encrypted;
}
