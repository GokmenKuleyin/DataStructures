/** 
* @file DoublyLinkedDist.cpp
* @description İki yönlü bağıl liste sınıfının metotlarının bulunduğu kaynak dosyasıdır.
* @course 2-C
* @assignment 1. ödev
* @date 02.11.2021
* @author Alaattin Gökmen Kuleyin
*/

#include "DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList(){
	root = NULL;
	size = 0;
}

//Liste boşsa NULL ise liste başına ekleme yapılıyor.
void DoublyLinkedList::addIntoRoot(string name, string surname){
	root = new Node(name, surname);
	size++;
}

//Liste sonundan eleman silme işlemi yapılıyor.
void DoublyLinkedList::removeLastItem(){
	Node* iterator = root;
	while(iterator->getNext() != NULL){
		iterator = iterator->getNext();
	}
	iterator->getPrevious()->setNext(NULL);
	delete(iterator);
	size--;
}

//Liste sonuna ekleme işlemi yapılıyor.
void DoublyLinkedList::add(string name, string surname){
	Node *iterator = root;
	while(iterator->getNext() != NULL){
		iterator = iterator->getNext();
	}
	Node* node = new Node(name, surname, iterator);
	iterator->setNext(node);
	size++;
}

//Gelen index'e eleman ekleniyor.
void DoublyLinkedList::insert(int index, string name, string surname){
	if(root == NULL){
		addIntoRoot(name, surname);
		return;
	}
	//Eğer gelen index listede bulunamamışsa sona eleman ekleme yapılıyor.
	if(index >= size || index < 0){
		add(name, surname);
		return;
	}
	Node* iterator = root;
	while(iterator->getNext() != NULL){
		iterator = iterator->getNext();
	}
	iterator->setNext(new Node(iterator->getName(), iterator->getSurname(), iterator));
	for(int i = size; i > index + 1; i--){
		Node* next = iterator;
		iterator = iterator->getPrevious();
		next->setName(iterator->getName());
		next->setSurname(iterator->getSurname());
	}
	size++;
	iterator->setName(name);
	iterator->setSurname(surname);
}

//Gelen index'ten eleman siliniyor.
void DoublyLinkedList::remove(int index){
	if(root == NULL){
		return;
	}
	//Eğer gelen index listede bulunamamışsa sondan eleman siliniyor.
	if(index >= size || index < 0){
		removeLastItem();
		return;
	}
	Node *iterator = root;
	for(int i = 0; i < index; i++){
		iterator = iterator->getNext();
	}
	while(iterator->getNext() != NULL){
		iterator->setName(iterator->getNext()->getName());
		iterator->setSurname(iterator->getNext()->getSurname());
		iterator = iterator->getNext();
	}
	iterator->getPrevious()->setNext(NULL);
	delete(iterator);
	size--;
}

//Liste yazdırılıyor.
ostream& operator<<(ostream &os, const DoublyLinkedList &list){
	Node* iterator = list.root;
	while(iterator->getNext() != NULL){
		os << iterator->getName() << " " << iterator->getSurname() << " <--> ";
		iterator = iterator->getNext();
	}
	os << iterator->getName() << " " << iterator->getSurname();
	return os;
}

//Liste temizleniyor.
void DoublyLinkedList::clear(){
	if(root == NULL){
		return;
	}
	while(root->getNext() != NULL){
		root = root->getNext();
		delete(root->getPrevious());
	}
	delete(root);
	root = NULL;
	size = 0;
}

DoublyLinkedList::~DoublyLinkedList(){
	clear();
}