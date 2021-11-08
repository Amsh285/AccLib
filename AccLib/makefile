acclib.exe: Program.o String.o
	g++ -std=c++14 -static Binaries/String.o Binaries/Program.o -o Binaries/acclib.exe

String.o: AccLib/String.cpp
	g++ -std=c++14 -c AccLib/String.cpp -o Binaries/String.o

Program.o: AccLib/Program.cpp
	g++ -std=c++14 -c AccLib/Program.cpp -o Binaries/Program.o 
