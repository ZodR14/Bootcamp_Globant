#pragma once
#include <vector>
#include "Node.h"

class Dictionary {
public:
	static Dictionary& getInstance(const std::string& fileLocation) {
		static Dictionary instance(fileLocation);
		return instance;
	}
	static int CharToNum(char& cc);
	static Node* SearchWord(const std::string& userInput);
	static void AddWordToList(std::string& string);
	static void LoadList(const std::string& fileLocation);

private:
	static std::vector<Node*> firstNodes;
	Dictionary(const std::string& fileLocation);
public:
	Dictionary(Dictionary const&) = delete;
	void operator=(Dictionary const&) = delete;
};