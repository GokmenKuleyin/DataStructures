/** 
* @file Node.hpp
* @description Düğüm sınıfının bulunduğu başlık dosyasıdır.
* @course 2-C
* @assignment 1. ödev
* @date 02.11.2021
* @author Alaattin Gökmen Kuleyin
*/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node{
	private:
	string name;
	string surname;
	Node *next;
	Node *previous;

	public:
	Node(string name, string surname, Node* previous = NULL, Node* next = NULL);
	string getName() const;
	string getSurname() const;
	Node* getPrevious() const;
	Node* getNext() const;
	void setName(string);
	void setSurname(string);
	void setPrevious(Node*);
	void setNext(Node*);
};

#endif