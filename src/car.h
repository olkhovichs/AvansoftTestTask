#pragma once

#include <string>
#include <vector>
#include <ctime>

class Car {
public:
	int id;
	std::string color;
	double maxSpeed;

	// filling in the catalogue of cars (add to a separate method)
	std::vector<Car> catalog;
	std::vector<std::string> carColors{ "white", "black", "red", "blue", "green", "yellow", "purple", "gray" };
	

	Car();
	Car(int id, std::string color, double maxSpeed);
	void setCatalog();
};