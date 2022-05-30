/** 
* @file Node.cpp
* @description Düğüm sınıfının metotlarının bulunduğu kaynak dosyasıdır.
* @course 2-C
* @assignment 1. ödev
* @date 02.11.2021
* @author Alaattin Gökmen Kuleyin
*/

#include "Node.hpp"

Node::Node(string name, string surname, Node *previous, Node *next){
	this->name = name;
	this->surname = surname;
	this->previous = previous;
	this->next = next;
}

string Node::getName() const{
	return name;
}

string Node::getSurname() const{
	return surname;
}

Node* Node::getPrevious() const{
	return previous;
}

Node* Node::getNext() const{
	return next;
}

void Node::setName(string name){
	this->name = name;
}

void Node::setSurname(string surname){
	this->surname = surname;
}

void Node::setPrevious(Node* node){
	previous = node;
}

void Node::setNext(Node* node){
	next = node;
}