#include "TrafficLight.h"
#include "Light.h"
#include "YellowLight.h"
#include <iostream>
#include <string>

void TrafficLight::ChangeState(Colors color) {
	current->Change(this, color);
}

void TrafficLight::SetState(Light* l) {
	std::cout << "Current State: " << current->GetName() << ", changing to " << l->GetName() << std::endl;
	Light* temp = current;
	delete temp;
	current = l;
}

TrafficLight::TrafficLight() {
	current = new YellowLight();
}

TrafficLight::~TrafficLight() {
	delete current;
}

std::string TrafficLight::GetState() {
	return current->GetName();
}