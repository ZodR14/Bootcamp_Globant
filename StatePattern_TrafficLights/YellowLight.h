#pragma once
#include "TrafficLight.h"
#include "Light.h"

class YellowLight : public Light {

protected:
	std::string name = "Yellow";
public:
	void Change(TrafficLight* tl, Colors color) override;
	virtual std::string GetName() override;
};