#pragma once
#include "car.h"

#include <iostream>

class Client: public Car {
public:

	std::string name;
	std::vector<Car> garage;

	Client();
	Client(std::string name, std::vector<Car> garage);

	Car b(std::vector<Car>& catalog, int buyId);
};