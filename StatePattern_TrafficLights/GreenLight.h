#pragma once
#include "TrafficLight.h"
#include "Light.h"

class GreenLight : public Light {
protected:
	std::string name = "Green";
public:
	void Change(TrafficLight* tl, Colors color) override;
	virtual std::string GetName() override;
};