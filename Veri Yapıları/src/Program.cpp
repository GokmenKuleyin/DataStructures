/** 
* @file Program.cpp
* @description main dosyasının bulunduğu dosyadır.
* @course 2-C
* @assignment 1. ödev
* @date 02.11.2021
* @author Alaattin Gökmen Kuleyin
*/


#include "FileManagement.hpp"
#include <Windows.h>

int main(){
	SetConsoleOutputCP(65001);
	FileManagement *file = new FileManagement("./Veri.txt");
	DoublyLinkedList *list = file->readFile();
	system("cls");
	cout << *list;
	delete(file);
	delete(list);
}