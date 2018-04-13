#include "RedLight.h"
#include "GreenLight.h"

void RedLight::Change(TrafficLight* tl, Colors color) {
	if (GREEN == color) {
		GreenLight* next = new GreenLight();
		tl->SetState(next);
	}
	else {
		std::cout << "Not a valid transition..." << std::endl;
	}
}

std::string RedLight::GetName() {
	return name;
}