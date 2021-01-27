#pragma once

#include <string>

class Car {
public:
	int id;
	std::string color;
	double speed;

	Car();
	Car(int id, std::string color, double speed);
};