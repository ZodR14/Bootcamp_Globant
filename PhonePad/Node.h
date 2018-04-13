#pragma once
#include <vector>
#include <iostream>
#include <map>



class Node {
	std::vector<std::string> words;
	std::vector<Node*> nextNodes;

public:
	const char keyNumber;
	Node(char num);
	void AddWord(const std::string& word);
	Node* AddNextNode(const char& num);
	void PrintWords() const;
	Node* CheckNode(const char& num) const;
	~Node();
};