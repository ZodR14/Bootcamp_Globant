#pragma once
#include "TrafficLight.h"
#include "Light.h"

class RedLight : public Light {
protected:
	std::string name = "Red";
public:
	void Change(TrafficLight* tl, Colors color) override;
	virtual std::string GetName() override;
};