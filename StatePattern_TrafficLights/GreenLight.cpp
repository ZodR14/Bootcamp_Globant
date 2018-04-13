#include "GreenLight.h"
#include "YellowLight.h"

void GreenLight::Change(TrafficLight* tl, Colors color) {
	if (color == YELLOW) {
		YellowLight* next = new YellowLight();
		tl->SetState(next);
	}
	else {
		std::cout << "Not a valid transition..." << std::endl;
	}
}

std::string GreenLight::GetName() {
	return name;
}