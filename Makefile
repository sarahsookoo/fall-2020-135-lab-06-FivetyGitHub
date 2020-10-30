

main: main.o funcs.o caesar.o decrypt.o decode.o
	g++ -o main main.o funcs.o caesar.o decrypt.o decode.o

tests: tests.o funcs.o caesar.o vigenere.o decrypt.o decode.o
	g++ -o tests tests.o funcs.o caesar.o vigenere.o decrypt.o decode.o

decrypt.o: decrypt.h decrypt.cpp

vigenere.o: vigenere.h vigenere.cpp

caesar.o: caesar.cpp caesar.h

funcs.o: funcs.cpp funcs.h

main.o: main.cpp funcs.h

decode.o: decode.cpp decode.h

tests.o: tests.cpp  doctest.h

clean:
	rm -f main.o tests.o funcs.o caesar.o vigenere.o decrypt.o decode.o tests main

help:
	@echo  make main : make executable named main
	@echo make tests : make test suite named tests
