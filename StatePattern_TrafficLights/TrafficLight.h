#pragma once
#include <iostream>

class Light;

enum Colors
{
	GREEN = 1, YELLOW, RED
};


class TrafficLight {
	Light* current;
public:
	void ChangeState(Colors color);
	void SetState(Light* l);
	std::string GetState();

	TrafficLight();
	~TrafficLight();
};