#include "Dictionary.h"
#include <fstream>
#include <string>
#include "utils.h"

std::vector<Node*> Dictionary::firstNodes;

void Dictionary::LoadList(const std::string& fileLocation) {
	std::string line;
	std::ifstream myfile(fileLocation);

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			AddWordToList(line);
		}
		myfile.close();
	}
	else {
		LOG_ERROR("OPENING FILE: " << fileLocation);
	}
}

Dictionary::Dictionary(const std::string& fileLocation) {
	LoadList(fileLocation);
}

int Dictionary::CharToNum(char& cc) {
	cc = tolower(cc);

	if (cc == 'a' || cc == 'b' || cc == 'c')
		return '2';
	if (cc == 'd' || cc == 'e' || cc == 'f')
		return '3';
	if (cc == 'g' || cc == 'h' || cc == 'i')
		return '4';
	if (cc == 'j' || cc == 'k' || cc == 'l')
		return '5';
	if (cc == 'm' || cc == 'n' || cc == 'o')
		return '6';
	if (cc == 'p' || cc == 'q' || cc == 'r' || cc == 's')
		return '7';
	if (cc == 't' || cc == 'u' || cc == 'v')
		return '8';
	if (cc == 'w' || cc == 'x' || cc == 'y' || cc == 'z')
		return '9';

	return 0;
}

void Dictionary::AddWordToList(std::string& string) {
	Node* currentNode = nullptr;
	char firstLetter = CharToNum(string[0]);

	if (firstLetter == 0) {//Check to see whether we can store letter as a number
		LOG_ERROR("ADDING THE WORD: " << string << " unknown character: " << string[0]);
		return;
	}

	//Find first Node (root node, the node with the first letter of the word)
	if (firstNodes.size() == 0) {					//If the vector is empty create the first node
		currentNode = new Node(firstLetter);		//Create it and store it
		firstNodes.push_back(currentNode);
	}
	else {
		for (int i = 0; i < firstNodes.size(); ++i) {
			if (firstNodes[i]->keyNumber == firstLetter) {
				currentNode = firstNodes[i];			//if a first node (root) with this number exists, store it
				break;
			}
		}
		if (currentNode == nullptr) {
			currentNode = new Node(firstLetter);		//if no first node with this number exists, create one and store it
			firstNodes.push_back(currentNode);
		}

	}

	for (int i = 1; i < string.size(); ++i) {			//for every letter in the word (except the first one)
		if (CharToNum(string[i]) == 0) {				//Check to see whether we can store letter as a number
			LOG_ERROR("ADDING THE WORD: " << string << " unknown character: " << string[i]);
			return;
		}
		else {
			currentNode = currentNode->AddNextNode(CharToNum(string[i]));	//add a new node (if it doesnt exists! if it doest just store it) 
		}
	}

	//we reached the end of the word, so store the string in this node
	currentNode->AddWord(string);
}

Node* Dictionary::SearchWord(const std::string& userInput) {
	//Timer timer;//Un-comment to see aprox time taken.
	if (firstNodes.size() < 1) return nullptr;
	Node* temp = nullptr;

	//Find the first node with the first character
	for (int i = 0; i < firstNodes.size(); ++i) {
		if (firstNodes[i]->keyNumber == userInput[0]) {
			temp = firstNodes[i];
			break;
		}
	}

	for (int i = 0; i < userInput.size() - 1; ++i) {
		if (temp == nullptr)						//If no node exists exit the loop...
			break;
		temp = temp->CheckNode(userInput[i + 1]);	//...otherwise, check to see if theres a next node
	}

	//we reached the end of the word
	//if the current node is not null, means we found at least 1 matching word!
	return temp;
}