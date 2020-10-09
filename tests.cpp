#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
// add your tests here

TEST_CASE("shiftChar"){
  CHECK(shiftChar('c', 2)=='e');
  CHECK(shiftChar('z', 2)=='b');
  CHECK(shiftChar('Z', 2)=='B');
  CHECK(shiftChar('e', 4)=='i');
}

TEST_CASE("encryptCaesar"){
  CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
  CHECK(encryptCaesar("According to all known laws of aviation, there is no way a bee should be able to fly.",7)=="Hjjvykpun av hss ruvdu shdz vm hcphapvu, aolyl pz uv dhf h ill zovbsk il hisl av msf.");
  CHECK(encryptCaesar("The quick brown fox; he jumps over the lazy dog!", 42069)=="Uif rvjdl cspxo gpy; if kvnqt pwfs uif mbaz eph!");
  CHECK(encryptCaesar("", 42069)=="");
}

TEST_CASE("encryptVigenere"){
  CHECK(encryptVigenere("The quick brown fox jumps over lazy dogs.", "cryptii")=="Vyc fnqkm spdpv nqo hjfxa qmcg eiha umvl.");
  CHECK(encryptVigenere("", "")=="");
  CHECK(encryptVigenere("According to all known laws of aviation, there is no way a bee should be able to fly.", "bees")=="Bgggshmfh xs smp ofpar dbaw gg ezabxmgo, xlwsi mk os asz e fwf wlgvph tf efdf xs xmc.");
}

TEST_CASE("decryptCaesar"){
  CHECK(decryptCaesar("Bfd yt Lt!",5)=="Way to Go!");
  CHECK(decryptCaesar("Hjjvykpun av hss ruvdu shdz vm hcphapvu, aolyl pz uv dhf h ill zovbsk il hisl av msf.",7)=="According to all known laws of aviation, there is no way a bee should be able to fly.");
}

TEST_CASE("decryptVigenere"){
  CHECK(decryptVigenere("Bgggshmfh xs smp ofpar dbaw gg ezabxmgo, xlwsi mk os asz e fwf wlgvph tf efdf xs xmc.","bees")=="According to all known laws of aviation, there is no way a bee should be able to fly.");
  CHECK(decryptVigenere("Vyc fnqkm spdpv nqo hjfxa qmcg eiha umvl.","cryptii")=="The quick brown fox jumps over lazy dogs.");

}
