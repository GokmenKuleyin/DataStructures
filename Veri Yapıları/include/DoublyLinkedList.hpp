/** 
* @file DoublyLinkedDist.hpp
* @description İki yönlü bağıl liste sınıfının bulunduğu başlık dosyasıdır.
* @course 2-C
* @assignment 1. ödev
* @date 02.11.2021
* @author Alaattin Gökmen Kuleyin
*/

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "Node.hpp"

class DoublyLinkedList{
	private:
	Node *root;
	int size;
	void addIntoRoot(string, string);
	void removeLastItem();
	void add(string, string);
	void clear();

	public:
	DoublyLinkedList();
	void insert(int, string, string);
	friend ostream& operator<<(ostream&, const DoublyLinkedList&);
	void remove(int);
	~DoublyLinkedList();
};

#endif