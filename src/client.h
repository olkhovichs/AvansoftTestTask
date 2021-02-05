#pragma once
#include "car.h"

class Client: public Car {
public:
	Client();
	Client(std::string name);

	std::string name;
	std::vector<Car> garage;

	void addGarage(std::vector<Car>& catalog, std::vector<Client>& clientBase, int buyId,  std::string name);
	void printGarage(std::vector<Client> clientBase, std::string name);

private:
	bool isRepeat(std::vector<Client> clientBase, std::string name);

};