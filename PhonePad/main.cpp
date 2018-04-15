#include <iostream>
#include <string>
#include "Dictionary.h"

int main() {
	Dictionary::getInstance("dictionary2.lst");

	int cont = 1;
	std::string userInput;
	std::cout << "Type a number to find a word!" << std::endl;

	do {
		std::getline(std::cin, userInput);					//Get number from user

		Node* nodeFound = Dictionary::SearchWord(userInput);//Search

		if (nodeFound != nullptr) {							//If we found a node...
			nodeFound->PrintWords();						//print all the words for that number
		}
		

		std::cout << "Press 1 to continue" << std::endl;
		std::cin >> cont;
		std::cin.ignore();

	} while (cont == 1);




	return 0;
}