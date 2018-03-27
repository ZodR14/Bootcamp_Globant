#include "DoublyLinkedList.h"
#include <iostream>

bool DoublyLinkedList::checkPrime(int n) {
	if (n <= 1) return false;

	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

bool DoublyLinkedList::AddElement(int number) {
	if (!checkPrime(number)) {
		Node* newNode = new Node(number);
		if (head == nullptr) {
			head = newNode;
			return true;
		}
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		return true;
	}
	else {
		std::cout << number << " is a prime number! Try again: " << std::endl;
	}
	return false;
}

void DoublyLinkedList::Print() {
	Node* temp = head;
	std::cout << "List: ";
	while (temp != nullptr) {
		std::cout << temp->number;
		temp = temp->next;
		if (temp != nullptr) std::cout << ", ";
	}
	printf("\n");
}

 DoublyLinkedList::~DoublyLinkedList() {
	 Node* temp = head;
	 Node* tempNext = nullptr;

	 while (temp != nullptr) {
		 tempNext = temp->next;
		 std::cout << "Deleting: " << temp->number << std::endl;
		 delete temp;
		 temp = tempNext;
	 }
}