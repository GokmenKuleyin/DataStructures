all: compile run

compile:
	g++ -I ./include/ -o ./lib/FileManagement.o -c ./src/FileManagement.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/DoublyLinkedList.o -c ./src/DoublyLinkedList.cpp
	g++ -I ./include/ -o ./bin/Program ./lib/FileManagement.o ./lib/Node.o ./lib/DoublyLinkedList.o ./src/Program.cpp

run:
	./bin/Program