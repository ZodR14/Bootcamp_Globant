#include <iostream>
#define MAX(a, b)  a > b ? a : b
//El problema con los macros es que no evaluan los argumentos, solo pegan el texto cuando sustituyen.
//Esto:
//int m = MAX(x, f() + 1) * 2;
//se  convierte en esto:
//int m = x > f() + 1 ? x : f() + 1 * 2;
//Una de las soluciones es re escribir el macro agregando parentesis
#define MAX_FIXED(a, b) ((a) < (b) ? (b) : (a))

int f() { return 3; }

int main() {
	int x = 3;

	int r0 = MAX(x, f() + 1) * 2;			//Tiene el error

	int r1 = MAX_FIXED(x, f() + 1) * 2;		//Solucion 1 - Funciona gracias a los parentesis

	int y = f() + 1;						//Solucion 2 es crear una variable para f() + 1
	int r2 = MAX(x, y) * 2;					//de esta manera tambien la funcion no es invocada 2 veces.

	std::cout << "Macro con el error: " << r0 << "\nSolucion 1: " << r1 << "\nSolucion 2: " << r2 << std::endl;
	std::cin.ignore();
	return 0;

}