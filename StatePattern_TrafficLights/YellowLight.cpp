#include "YellowLight.h"
#include "RedLight.h"

void YellowLight::Change(TrafficLight* tl, Colors color) {
	if (RED == color) {
		RedLight* next = new RedLight();
		tl->SetState(next);
	}
	else {
		std::cout << "Not a valid transition..." << std::endl;
	}
}

std::string YellowLight::GetName() {
	return name;
}