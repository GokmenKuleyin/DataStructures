/** 
* @file FileManagement.hpp
* @description Dosya okuma işlemlerinin yapıldığı başlık dosyasıdır.
* @course 2-C
* @assignment 1. ödev
* @date 05.11.2021
* @author Alaattin Gökmen Kuleyin
*/

#ifndef FILEMANAGEMENT_HPP
#define FILEMANAGEMENT_HPP

#include <iostream>
#include <fstream>
#include "DoublyLinkedList.hpp"
using namespace std;

class FileManagement{
	private:
	string filePath;
	DoublyLinkedList *list;
	public:
	FileManagement(string);
	DoublyLinkedList* readFile();
};

#endif