#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>

class Car {
public:
	int id;
	double price;
	std::string color;
	double speed;

	//std::vector<Car> catalog;
	std::vector<std::string> carColors{ "white", "black", "red", "blue", "green", "yellow", "purple", "gray" };
	

	Car();
	Car(int id, double price, std::string color, double speed);
	std::vector<Car> setCatalog();
	void printCatalog(std::vector<Car> catalog, double filterPrice = 6.50, double filterSpeed = 0);
	Car buyCar(std::vector<Car> catalog, int buyId);
};