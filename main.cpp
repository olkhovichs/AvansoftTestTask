#include "src/car.h"
#include "src/menu.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>


int main() {
	// filling in the catalogue of cars (add to a separate method)
	std::vector<Car> carsCatalog;
	std::vector<std::string> carColors{ "white", "black", "red", "blue", "green", "yellow", "purple", "gray"};
	std::string color;
	double carSpeed = 0;
	for (int i = 1; i <= 11; i++) {
		color = carColors[rand() % carColors.size()];
		carSpeed = rand() / 260; // от!!
		carsCatalog.push_back(Car(i, color, carSpeed));
	}

	// working outputting all cars
	/*for (int i = 0; i < cars.size(); i++) {
		std::cout << std::setw(5) << cars[i].id << cars[i].color << cars[i].speed << std::endl;
	}*/

	// main menu
	Menu* choice = new Menu;
	setlocale(LC_ALL, "Russian");
	switch (choice->menuMain()) {
	case 1:
		system("cls");
		std::cout << "Помощь";
		break;
	case 2:
		system("cls");
		std::cout << "список авто" << std::endl;
		for (int i = 0; i < carsCatalog.size(); i++) {
			std::cout << std::setw(5) << carsCatalog[i].id << carsCatalog[i].color << carsCatalog[i].speed << std::endl;
		}
		switch (choice->backBegin()) {
		case 1:
			choice->menuMain();
		case 2:
			exit(EXIT_SUCCESS);
			break;
		default:
			std::cerr << "Вы ввели некорректное значение" << std::endl;
			exit(EXIT_SUCCESS);
		}
	case 3:
		system("cls");
		std::cout << "Фильтр";
		break;
	case 4:
		system("cls");
		std::cout << "Узнать авто владельца";
		break;
	case 5:
		system("cls");
		std::cout << "Приобрести автомобиль";
		break;
	case 6:
		exit(EXIT_SUCCESS);
		break;
	default:
		std::cerr << "Вы ввели некорректное значение" << std::endl;
		exit(EXIT_SUCCESS);
	}

	return 0;
}