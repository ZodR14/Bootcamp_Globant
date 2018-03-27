#include <iostream>
#include "Operaciones_matematicas.h"
#include "Operaciones_String.h"
#include "Operaciones_binarias.h"
#include "Operaciones_logicas.h"
#include "Operaciones_preprocesador.h"
#include "utils.h"
#define MAKECOMMAND(NAME) {#NAME, NAME ## _func}

char userInput[16];
int a=0, b=0;
char name[256];
char title[256];

int var1 = 123;
int var2 = 456;
int CONC(var1, var2) = 5;

struct command{
	const char* name;
	void(*function) (void);
};

#pragma region declaracionFunciones
void cuadrado_func();
void suma_func();
void area_func();
void maximo_func();
void concatenar_func();
void comparacion_func();
void binarias_func();
void imprimir_func();
void cambio_func();
void assert_func();
void and_func();
void or_func();
void izq_func();
void der_func();
#pragma endregion

struct command commands[] ={
	MAKECOMMAND(cuadrado),
	MAKECOMMAND(suma),
	MAKECOMMAND(area),
	MAKECOMMAND(maximo),
	MAKECOMMAND(concatenar),
	MAKECOMMAND(imprimir),
	MAKECOMMAND(comparacion),
	MAKECOMMAND(binarias),
	MAKECOMMAND(cambio),
	MAKECOMMAND(assert),
	MAKECOMMAND(and),
	MAKECOMMAND(or ),
	MAKECOMMAND(der),
	MAKECOMMAND(izq)
};

int main(){
	std::cout << " _____  _             _     _         \n";
	std::cout << "|   __||_|___ ___ ___|_|___|_|___ ___ \n";
	std::cout << "|   __|| | -_|  _|  _| |  _| | . |_ -|\n";
	std::cout << "|_____|| |___|_| |___|_|___|_|___|___|\n";
	std::cout << "     |___|                            \n";
	std::cout << " _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ____  _____ _____ \n";
	std::cout << "|  _  | __  |   __|  _  | __  |     |     |   __|   __|  _  |    \\|     | __  |\n";
	std::cout << "|   __|    -|   __|   __|    -|  |  |   --|   __|__   |     |  |  |  |  |    -|\n";
	std::cout << "|__|  |__|__|_____|__|  |__|__|_____|_____|_____|_____|__|__|____/|_____|__|__|\n";
	std::cout << "\n\n";

	do {
		

		printf("Super Programa C++ Super Programa\n");
		printf("Elegi un numero o pone la palabra que esta entre parentesis!\n");
		printf("1- El cuadrado de un numero. (cuadrado)\n");
		printf("2- La suma de dos numeros. (suma)\n");
		printf("3- El area de un circulo. (area)\n");
		printf("4- El maximo de dos numeros (maximo).\n");
		printf("5- Concatenacion de nombres de variables. (concatenar)\n");
		printf("6- Imprima por pantalla un texto (literal). (imprimir)\n");
		printf("7- Comparacion de cadena. (comparacion)\n");
		printf("8- Operaciones binarias. (binarias)\n");
		printf("9- Intercambie dos variables. (cambio)\n");
		printf("10- Assert valida una expresion logica e imprime un log de error. (assert)\n");

		std::cin.getline(userInput, 16);

		for (int i = 0; i < 11; i++) {
			if (commands[i].name == NULL) break;
			if (atoi(userInput) > 0 && atoi(userInput) < 11) {
				if (atoi(userInput) == i) {
					commands[i - 1].function();
					break;
				}
			}
			if (CompareStrings(userInput, commands[i].name)) {
				commands[i].function();
				break;
			}
		}
		
		std::cout << "\nCONTINUAR? s/n 1/0" << std::endl;
		std::cin.getline(userInput, 16);
		//system("cls");
	} while ((userInput[0] == 'y' || atoi(userInput) == 1));

	return 0;
}

void ValidateInput(int *aa, std::string bb) {
	bool failedInput = false;

	do {
		std::cout << bb;

		std::cin >> *aa;

		failedInput = std::cin.fail();

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (failedInput == true);
}

void cuadrado_func() {
	std::cout << "1- El cuadrado de un numero." << std::endl;
	ValidateInput(&a, "Ingresa el numero: ");
	std::cout << "El cuadrado es: "<< CuadradoDeNum(a) << std::endl;
}

void suma_func() {
	std::cout << "2- La suma de dos numeros." << std::endl;
	ValidateInput(&a, "Ingresa el primer numero: ");
	ValidateInput(&b, "Ingresa el segundo numero: ");
	std::cout << "La resultado de la suma es: " << Suma(a, b) << std::endl;
}

void area_func() {
	std::cout << "3- El area de un circulo." << std::endl;
	ValidateInput(&a, "Ingresa el area:\n");
	std::cout << "La area del circulo es " << AreaCirculo(a) << std::endl;
}

void maximo_func() {
	std::cout << "4- El maximo de dos numeros" << std::endl;
	ValidateInput(&a, "Ingresa el primer numero:\n");
	ValidateInput(&b, "Ingresa el segundo numero:\n");
	std::cout << "El mayor numero es: " << Max(a, b) << std::endl;
}

void concatenar_func() {
	std::cout << "5- Concatenacion de nombres de variables." << std::endl;
	std::cout << NOMB(var1, var2) << ": " << CONC(var1, var2) << std::endl;
}

void comparacion_func() {
	printf("7- Comparacion de cadena.\n");
	std::cout << "Ingresa el primer string: " << std::endl;
	std::cin.getline(userInput, 16);
	std::cout << "Ingresa el segundo string: " << std::endl;
	std::cin.getline(title, 16);
	std::cout << "Los strings " << SonIgualesSignoDePregunta(userInput, title) << std::endl;
}

void binarias_func() {
	std::cout << "8- Operaciones binarias.\n" << std::endl;
	std::cout << "1- AND binario. (and)" << std::endl;
	std::cout << "2- OR binario. (or)" << std::endl;
	std::cout << "3- Desplazamiento de 2 bits a la derecha. (der)" << std::endl;
	std::cout << "4- Desplazamiento de 2 bits a la izquierda. (izq)" << std::endl;

	std::cin.getline(userInput, 16);

	for (int i = 10; i < 14; i++) {
		if (commands[i].name == NULL) break;
		if (atoi(userInput) > 0 && atoi(userInput) < 5) {
			if (atoi(userInput) + 9 == i) {
				commands[i].function();
				break;
			}
		}
		if (CompareStrings(userInput, commands[i].name)) {
			commands[i].function();
			break;
		}
	}
}

void imprimir_func() {
	std::cout << "6- Imprima por pantalla un texto (literal)" << std::endl;
	PrintLiteral();
}

void and_func() {
	std::cout << "1- AND binario." << std::endl;
	ValidateInput(&a, "Ingresa el primer numero: ");
	ValidateInput(&b, "Ingresa el segundo numero: ");
	std::cout << "El resultado es: " << BinaryAnd(a, b) << std::endl;
}

void or_func() {
	std::cout << "2- OR binario." << std::endl;
	ValidateInput(&a, "Ingresa el primer numero: ");
	ValidateInput(&b, "Ingresa el segundo numero: ");
	std::cout << "El resultado es: " << BinaryOr(a, b) << std::endl;
}

void izq_func() {
	std::cout << "4- Desplazamiento de 2 bits a la izquierda." << std::endl;
	ValidateInput(&a, "Ingresa el numero: ");
	std::cout << "El resultado es: " << Shiftleft(a) << std::endl;
}

void der_func() {
	std::cout << "3- Desplazamiento de 2 bits a la derecha." << std::endl;
	ValidateInput(&a, "Ingresa el numero: ");
	std::cout << "El resultado es: " << ShiftRight(a) << std::endl;
}

void cambio_func() {
	printf("9- Intercambie dos variables.\n");
	printf("El valor de var1: %d \n", var1);
	printf("El valor de var2: %d \n\n", var2);
	Swap(&var1, &var2);
	printf("El valor de var1: %d \n", var1);
	printf("El valor de var2: %d \n", var2);
}

void assert_func() {
	std::cout << "10- ASSERT(4==5).\n";
	ASSERT(4 == 5);
}