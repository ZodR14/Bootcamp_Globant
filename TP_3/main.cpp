#include <iostream>

int main() {

	int indice[] = { 1,2,3,4,5,6,7,8,9,10 };
	int *ptr = &indice[0];
	ptr++;
	
	std::cout << "aaaa: " << (*(ptr + 8)) << std::endl;
	
	
	if ((*ptr * 5) == (*(ptr + 4)))
	{
		printf("true");
	}else
	{
		printf("false");
	}

	std::cout << "\n" << std::endl;

	std::cout << " _                             _                  _ " << std::endl;
	std::cout << "|_ o  _  ._ _ o  _ o  _   _   |_) _. ._ _|_  _    _)"<< std::endl;
	std::cout << "|_ | (/_ | (_ | (_ | (_) _>   |  (_| |   |_ (/_   _)" << std::endl;
	std::cout << "  _|                                                 "<< std::endl;


	std::cout << "\n" << std::endl;
	std::cout << "\t - Tipos de datos - " << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "\n" << std::endl;

	std::cout << "Size of a short: \t" << sizeof(short) << std::endl;
	std::cout << "Size of an int: \t" << sizeof(int) << std::endl;
	std::cout << "Size of a float: \t" << sizeof(float) << std::endl;
	std::cout << "Size of a double: \t" << sizeof(double) << std::endl;
	std::cout << "Size of a long: \t" << sizeof(long) << std::endl;
	std::cout << "Size of a long long: \t" << sizeof(long long) << std::endl;
	std::cout << "Size of a size_t: \t" << sizeof(size_t) << std::endl;
	//The size of a given data type is dependent on the compiler and/or the computer architecture.

	std::cout << "\nPress any key to continue..." << std::endl;
	std::cin.get();

	char cVar = 65;

	printf("The value of \"cVar\" is: \t \t%d \n", cVar);
	printf("The char equivalent of %d is: \t \t%c \n", cVar, cVar);
	printf("The float equivalent of %d is: \t \t%f \n", cVar, (float)cVar);
	printf("The octal equivalent of %d is: \t \t%o \n", cVar, cVar);
	printf("The hexadecimal equivalent of %d is: \t%x \n", cVar, cVar);

	std::cout << "\nPress any key to continue..." << std::endl;
	std::cin.get();

	std::cout << "The min value for short is " << std::numeric_limits<short>::min() << " and the max value is " << std::numeric_limits<short>::max() << std::endl;
	std::cout << "The min value for int is " << std::numeric_limits<int>::min() << " and the max value is " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "The min value for float is " << std::numeric_limits<float>::min() << " and the max value is " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "The min value for double is " << std::numeric_limits<double>::min() << " and the max value is " << std::numeric_limits<double>::max() << std::endl;
	std::cout << "The min value for long is " << std::numeric_limits<long>::min() << " and the max value is " << std::numeric_limits<long>::max() << std::endl;
	std::cout << "The min value for long long is " << std::numeric_limits<long long>::min() << " and the max value is " << std::numeric_limits<long long>::max() << std::endl;
	std::cout << "The min value for size_t is " << std::numeric_limits<size_t>::min() << " and the max value is " << std::numeric_limits<size_t>::max() << std::endl;

	std::cout << "\nPress any key to continue..." << std::endl;
	std::cin.get();

	int a = 0xFFFFFFFF;
	unsigned int b = 0xFFFFFFFF;

	std::cout  << "0xFFFFFFFF as an int is: " << a << " and as an unsigned int is: " << b << std::endl;

	//The bit pattern for an int x=-1 is FFFFFFFF in hexadecimal
	//FFFFFFFF in binary is 1111 1111 1111 1111 1111 1111 1111 1111
	//                      ^
	//In int the first bit signifies whether it is negative.
	//In unsigned int the first bit is just extra number, so the extra bit makes an unsigned int able to store bigger numbers.

	std::cout << "\nPress any key to continue..." << std::endl;
	std::cin.get();
	

	std::cout << "Please enter 5 integer values" << std::endl;
	int nums[5];


	for (int i = 0; i < 5; i++) {
		bool failedInput = false;
		do {
			std::cin >> nums[i];

			failedInput = std::cin.fail();

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (failedInput) std::cout << "Thats not an integer" << std::endl;
		} while (failedInput == true);
	}

	std::cout << "\n**************\n" << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << "numbers[" << i << "] = " << nums[i] << std::endl;
	}


	std::cout << "\nPress any key to exit..." << std::endl;
	std::cin.get();

	return 0;
}