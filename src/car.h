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

Car::Car() {
		int id = 0;
		std::string color;
		double speed = 0;
}

Car::Car(int id, std::string color, double speed) {
	this->id = id;
	this->color = color;
	this->speed = speed;
}