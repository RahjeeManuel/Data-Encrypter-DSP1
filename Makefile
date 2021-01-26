#builds project1.exe
all: project1.exe
project1.exe: main.o DataEncrypter.o HashTable.o HashNode.o
	g++ -o project1.exe main.o DataEncrypter.o HashTable.o HashNode.o
main.o: main.cpp
	g++ -c main.cpp
DataEncrypter.o: DataEncrypter.hpp DataEncrypter.cpp
	g++ -c DataEncrypter.cpp
HashTable.o: HashTable.hpp HashTable.cpp
	g++ -c HashTable.cpp
HashNode.o: HashNode.hpp HashNode.cpp
	g++ -c HashNode.cpp
clean:
	rm *.o project1.exe