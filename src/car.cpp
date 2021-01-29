#include "car.h"

Car::Car() {
	int id = 0;
	std::string color;
	double maxSpeed = 0;
}

Car::Car(int id, std::string color, double maxSpeed) {
	this->id = id;
	this->color = color;
	this->maxSpeed = maxSpeed;
}

void Car::setCatalog() {
	std::string color;
	double carSpeed = 0;
	srand(time(nullptr));
	for (int i = 1; i <= 11; i++) {
		color = carColors[rand() % carColors.size()];
		carSpeed = 220 + (double)(rand()) / RAND_MAX * (340 - 220);
		catalog.push_back(Car(i, color, carSpeed));
	}
}