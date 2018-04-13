#include "TrafficLight.h"
#include "YellowLight.h"
#include <iostream>
#include <string>
int main() {
	TrafficLight semaforo;
	int input, conti;

	do {
		std::cout << "Current State: " << std::endl;
		std::cout << semaforo.GetState() << std::endl;

		std::cout << "1= Change to Green" << std::endl;
		std::cout << "2= Change to Yellow" << std::endl;
		std::cout << "3= Change to Red" << std::endl;


		std::cin >> input;

		semaforo.ChangeState((Colors)input);

		std::cout << "Current State: " << std::endl;
		std::cout << semaforo.GetState() << std::endl;

		std::cout << "Continue: (1:Yes / 0:No)" << std::endl;
		std::cin >> conti;
	} while (conti > 0);


	return 0;
}