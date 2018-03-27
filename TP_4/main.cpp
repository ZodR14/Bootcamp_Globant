#include <iostream>
#include "DoublyLinkedList.h"

void swap_1(int *p1, int *p2) {
	int temp = *p1;

	*p1 = *p2;
	*p2 = temp;
}

void swap_1(int &p1, int &p2) {
	int temp = p1;

	p1 = p2;
	p2 = temp;
}

int main() {
	/*
	
	//Valid
	int var = 40;
	int &ref = var;

	//Not valid because 1 is not a variable
	int &ref = 1;

	//Not valid because ptr is never initialized and it could point a random location in memory that might be beign used by some other program.	
	int var = 1;
	int* ptr;
	int& ref = var;
	*ptr = ref;
	*/
	
	
	int indice[] = { 1,2,3,4,5,6,7,8,9,10 };
	int *ptr = &indice[0];
	ptr++;
	if ((*ptr * 5) == (*(ptr + 8))) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
	
	std::cout << "\nPress Enter to Continue...\n";
	std::cin.ignore();

	int a = 5;
	int b = 9;

	std::cout << "Original values: \t a: " << a << "\t b: " << b << std::endl;
	swap_1(&a, &b);

	std::cout << "Swap by pointer: \t a: " << a << "\t b: " << b << std::endl;
	swap_1(a, b);

	std::cout << "Swap by reference: \t a: " << a << "\t b: " << b << std::endl;

	std::cout << "\nPress Enter to Continue...\n";
	std::cin.ignore();
	{
	DoublyLinkedList list = DoublyLinkedList();
	int temp;
	int amount = 0;

	std::cout << "Enter number of elements" << std::endl;
	std::cin >> amount;

	std::cout << "Enter " << amount << " numbers that aren't prime numbers" << std::endl;
	for (size_t i = 0; i < amount; i++) {
		do {
			std::cin >> temp;
		} while (!list.AddElement(temp));
		if (i<amount - 1) std::cout << "Next:" << std::endl;
	}


	list.Print();
	}
	std::cout << "\nPress Enter to Continue...\n";
	std::cin.ignore();
	std::cin.ignore();

	return 0;
}