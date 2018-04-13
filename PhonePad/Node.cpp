#include "Node.h"
#include <string>

Node::Node(char num) : keyNumber(num) {

}

void Node::AddWord(const std::string& word) {
	for (int i = 0; i < words.size(); ++i) {
		if (words[i] == word) {
			return;
		}
	}
	words.push_back(word);
}

Node* Node::AddNextNode(const char& num) {
	for (int i = 0; i < nextNodes.size(); ++i) {
		if (nextNodes[i]->keyNumber == num) {
			return nextNodes[i];
		}
	}
	nextNodes.push_back(new Node(num));
	return nextNodes.back();
}

void Node::PrintWords() const {
	for (int i = 0; i < words.size(); ++i) {
		std::cout << words[i] << std::endl;
	}
}

Node* Node::CheckNode(const char& num) const {
	for (int i = 0; i < nextNodes.size(); ++i) {
		if (nextNodes[i]->keyNumber == num) {
			return nextNodes[i];
		}
	}
	return nullptr;
}

Node::~Node() {
	for (auto p : nextNodes)
		delete p;
}