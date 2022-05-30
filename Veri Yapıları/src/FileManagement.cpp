/** 
* @file FileManagement.cpp
* @description Dosya okuma işlemlerinin yapıldığı kaynak dosyasıdır.
* @course 2-C
* @assignment 1. ödev
* @date 05.11.2021
* @author Alaattin Gökmen Kuleyin
*/

#include "FileManagement.hpp"

FileManagement::FileManagement(string filePath){
	this->filePath = filePath;
	list = new DoublyLinkedList();
}

DoublyLinkedList* FileManagement::readFile(){
	ifstream file(filePath);
	string line;
	//Dosya satır satır okunup her satırda bulunan yapıyle liste işlemleri gerçekleştiriliyor.
	while(getline(file, line)){
		int i = 0;		//karakter iteratorü
		//Boşluk karakterleri görmezden geliniyor.
		while(line[i] == ' '){
			i++;
		}
		char operation = line[i];		//Liste üzerinde yapılacak işlem türü belirleniyor.
		//Paranteze ulaşana kadarki karakterler görmezden geliniyor.
		while(line[i] != '('){
			i++;
		}
		i++;
		string indexNumber;		//Liste üzerinde işlem yapılacak index'in tutulduğu değişken.
		if(operation == 'E'){
			//# sembolü görene kadar okuma yapılıyor. Okunan değer index'tir.
			while(line[i] != '#'){
				indexNumber += line[i];
				i++;
			}
			i++;
			//Boşluk karakterleri görmezden geliniyor.
			while(line[i] == ' '){
				i++;
			}
			string name;		//Dosyadan okunan ismin tutulacağı değişken.
			//Boşluk karakteri görene kadarki okunan kısım değişkene atanıyor.
			while(line[i] != ' '){
				name += line[i];
				i++;
			}
			//Fazla boşluk karakterleri görmezden geliniyor.
			while(line[i] == ' '){
				i++;
			}
			string surname;		//Dosyadan okunan soyismin tutulacağı değişken.
			//Boşluk veya karakter görene kadarki okunan kısım değişkene atanıyor.
			while(line[i] != ')' && line[i] != ' '){
				surname += line[i];
				i++;
			}
			//Okunan değerler listeye ekleniyor.
			list->insert(stoi(indexNumber), name, surname);
		}else if(operation == 'S'){
			//Parantez kapanana kadar okunan değer index'tir.
			while(line[i] != ')'){
				indexNumber += line[i];
				i++;
			}
			//Okunan değer listeden kaldırılıyor.
			list->remove(stoi(indexNumber));
		}
	}
	return list;
}