/*
(1) c) The output is implementation dependant.

(2) b) The output is "f(double)".

(3) c) Compilation error: the default arguments are given in the cpp and not in the .h file

(4) c) There is an ambiguity when calling f(2.0). Due to floating point promotions.

(5) c) The output is "BA".

(6) d) There is a compilation error:

(7) a) The output is "int".
*/
#include <iostream>

#pragma region Punto 8
void sort(int* nums, const int& size) {
	bool swapped = false;
	for (int i = 0; i < size; ++i) {
		swapped = false;
		for (int j = 0; j < size; ++j) {
			if (*(nums + i) > *(nums + j)) {
				int aux = *(nums + j);
				*(nums + j) = *(nums + i);
				*(nums + i) = aux;
				swapped = true;
			}
		}
		if (!swapped) break;
	}

	for (int i = 0; i < size; ++i) {
		std::cout << nums[i] << std::endl;
	}
}
#pragma endregion

#pragma region Punto 9
void fconst(const int x) {
	//x = 55;//Cannot assign to a variable that is const
}
#pragma endregion

#pragma region Punto 10
int f(double n) {
	return n;
}
#pragma endregion

#pragma region Punto 11
typedef float(*funcp)(char x);

float f2(char x) {
	return x;
}

funcp return_f(int x) {
	return f2;
}
#pragma endregion

int main() {
	//Punto 8
	int numbers[10] = { 1,9,0,5,6,8,2,4,7,3 };
	sort(&numbers[0], 10);
	
	//Punto 10
	int (*fp)(double n) = f;

	//Punto 11
	funcp (*fp2)(int x) = return_f;

	std::cin.ignore();
}