#pragma once
#include "TrafficLight.h"
#include <iostream>

class Light {
protected:
	std::string name;
public:
	virtual void Change(TrafficLight* tl, Colors color) = 0;
	virtual std::string GetName() = 0;
};