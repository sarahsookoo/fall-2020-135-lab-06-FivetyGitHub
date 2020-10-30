#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"
#include "decode.h"
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

TEST_CASE("decode"){
  CHECK(decode("Hjjvykpun av hss ruvdu shdz vm hcphapvu, aolyl pz uv dhf h ill zovbsk il hisl av msf.")=="According to all known laws of aviation, there is no way a bee should be able to fly.");
  CHECK(decode("Qba'g yrg lbhe qernzf or qernzf. Lrfgreqnl lbh fnvq gbzbeebj. Fb whfg qb vg. Znxr lbhe qernzf pbzr gehr. Whfg qb vg. Fbzr crbcyr qernz bs fhpprff. Juvyr lbh'er tbaan jnxr hc naq jbex uneq ng vg. Abguvat vf vzcbffvoyr. Lbh fubhyq trg gb gur")=="Don't let your dreams be dreams. Yesterday you said tomorrow. So just do it. Make your dreams come true. Just do it. Some people dream of success. While you're gonna wake up and work hard at it. Nothing is impossible. You should get to the");
}
