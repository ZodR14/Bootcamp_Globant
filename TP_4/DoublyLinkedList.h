#pragma once
#include "Node.h"

class DoublyLinkedList {
public:
	Node * head = nullptr;
	bool checkPrime(int n);	
	bool AddElement(int number);
	void Print();
	~DoublyLinkedList();
};