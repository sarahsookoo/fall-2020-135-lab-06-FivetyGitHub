#include <iostream>
#include <cmath>
#include "caesar.h"
#include "decode.h"

double frequency[] = {0.082, 0.015, 0.028, 0.043, 0.13, 0.022, 0.02, 0.061, 0.07, 0.0015, 0.0077,
  0.04, 0.024, 0.067, 0.075, 0.019, 0.00095, 0.06, 0.063, 0.091, 0.028, 0.0098, 0.024, 0.0015, 0.02, 0.00074};

double distance(double cryptFreq[26]){
  double squared = 0;
  for(int i = 0; i<26; i++){
    squared+=pow(cryptFreq[i]-frequency[i],2);
  }
  return sqrt(squared);
}

double * getFreq(std::string text){
  double* cryptFreq = new double[26];
  int alphaChars=0;
  for(int i = 0; i<text.length(); i++){
    char c = text[i];
    if(isalpha(c)){
      if(isupper(c)){
        cryptFreq[c-65] +=1;
        alphaChars++;
      }
      else if(islower(c)){
        cryptFreq[c-97] +=1;
        alphaChars++;
      }
    }
  }
  for(int i = 0; i< 26; i++){
    cryptFreq[i] = cryptFreq[i]/alphaChars;
  }
  return cryptFreq;
}

std::string decode(std::string cipherText){
  double testValue;
  int shift = 0;
  double* freqPointer = getFreq(cipherText);
  double min = distance(freqPointer);
  for(int i = 1; i<26; i++){
      freqPointer = getFreq(encryptCaesar(cipherText,i));
      testValue = distance(freqPointer);
      if(testValue < min){
        min = testValue;
        shift = i;
      }
  }
  return encryptCaesar(cipherText,shift);
}
