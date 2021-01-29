#include "car.h"

Car::Car() {
	int id = 0;
	double price = 0;
	std::string color;
	double speed = 0;
}

Car::Car(int id, double price, std::string color, double speed) {
	this->id = id;
	this->price = price;
	this->color = color;
	this->speed = speed;
}

// filling in the catalogue of cars
void Car::setCatalog() {
	//int carId = 0;
	double carPrice = 0;
	std::string color;
	double carSpeed = 0;

	srand(time(nullptr));
	for (int i = 1; i <= 11; i++) {
		//carId = 1 + (rand()) % 9;
		carPrice = 1.10 + (double)(rand()) / RAND_MAX * (6.49 - 1.10);
		color = carColors[rand() % carColors.size()];
		carSpeed = 220 + (double)(rand()) / RAND_MAX * (340 - 220);
		catalog.push_back(Car(i, carPrice, color, carSpeed));
	}
}

void Car::printCatalog(double filterPrice, double filterSpeed) {
	std::cout << "| ID |  Price  |  Color  | Max speed |" << std::endl;
	for (int i = 0; i < catalog.size() - 1; i++) {
		if (catalog[i].price <= filterPrice && catalog[i].speed >= filterSpeed) {
			std::cout << "-----------------------------------" << std::endl;
			std::cout << std::setw(3) << catalog[i].id
				<< std::setw(8) << std::setprecision(3) << catalog[i].price << " млн"
				<< std::setw(10) << catalog[i].color
				<< std::setw(10) << std::setprecision(4) << catalog[i].speed << std::endl;
		}
	}
}