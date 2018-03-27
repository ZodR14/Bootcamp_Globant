#pragma once

class Node {
public:
	int number;
	Node* prev = nullptr;
	Node* next = nullptr;
	Node(int number);
};