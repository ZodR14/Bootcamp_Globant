#include <iostream>
#include <string>
#include <fstream>


std::string caminito(std::string baldosas) {
	for (int i = 0; i < baldosas.size(); ++i) {								//Por cada letra en la palabra
		if (baldosas[i] == 'R') {											//Si la letra actual es una 'R'
			baldosas[i] = 'B';												//La letra se asigna 'B'
			if (i > 0 && baldosas[i - 1] == 'B') {							//Si no es la primer letra y la letra anterior es 'B'...
				if (i < baldosas.size() - 1 && baldosas[i + 1] == 'G')		//Si la actual no es la ultima letra, me fijo si la proxima letra es 'G'
					baldosas[i] = 'N';										//Si lo es, asigno 'N' a la letra actual
				else
					baldosas[i] = 'G';										//Si no lo es, asigno 'G' a la letra actual
			}

			if (baldosas[i] == 'B') {										//Si la letra actual sigue siendo 'B'
				if (i < baldosas.size() - 1 && baldosas[i + 1] == 'B') {	//Y si no es la ultima letra y la proxima letra es 'B'...
					if (i > 0 && baldosas[i - 1] == 'N')					//Si la actual no es la primera letra, me fijo si la letra anterior es 'N'
						baldosas[i] = 'G';									//Si lo es, asigno 'G' a la letra actual
					else
						baldosas[i] = 'N';									//Si no lo es, asigno 'N' a la letra actual
				}
			}
		}
	}

	return baldosas;														//Devuelvo la palabra modificada 
}


int main() {
	char letra;													//letra para agregar a la palabra
	int contador=0;												//la cantidad de letras agregadas, se pide que el limite sea 2000
	std::string palabra;										//palabra que contiene las baldosas
	std::ifstream miArchivo("caminito.in");						//archivo que contiene la secuencia de baldosas


	if (miArchivo.is_open()) {									//si el archivo existe
		while (contador<2000 && miArchivo.get(letra)) {			//extraemos cada letra mientras el contador sea menor a 2000
			palabra += letra;									//sumamos la letra a la palabra
			contador++;											//y sumamos 1 al contador
		}
		miArchivo.close();										//cerramos el archivo
	}
	else {
		std::cout << "Archivo no encontrado!" << std::endl;
	}
		

	std::cout << palabra << std::endl;
	std::cout << caminito(palabra) << std::endl;

	return 0;
}