#include "client.h"

Client::Client() {
	std::string name = "";
	std::vector<Car> garage = {};
}

Client::Client(std::string name, std::vector<Car> garage) {
	this->name = name;
	this->garage = garage;
}

Car Client::b(std::vector<Car>& catalog, int buyId) {
	auto car = std::find_if(std::begin(catalog), std::end(catalog), [buyId](Car c) { return c.id == buyId; });
	return *car; // car - итератор
}