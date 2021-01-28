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
		carSpeed = rand() / 260; // от
		carsCatalog.push_back(Car(i, color, carSpeed));
	}

	// main menu
	Menu* choice = new Menu;
	setlocale(LC_ALL, "Russian");
	do {
		switch (choice->menuMain()) {
		case 1:
			system("cls");
			std::cout << "Помощь";
			break;
		case 2:
			do {
				system("cls");
				std::cout << "Cписок авто:" << std::endl;
				//
				for (int i = 0; i < carsCatalog.size() - 1; i++) {
					//
					std::cout << std::setw(5) << carsCatalog[i].id << carsCatalog[i].color << carsCatalog[i].speed << std::endl;
				}
				switch (choice->backBegin()) {
				case 1:
					choice->menuMain();
					break;
				case 2:
					exit(EXIT_SUCCESS);
					break;
				default:
					std::cerr << "Вы ввели некорректное значение" << std::endl;
					exit(EXIT_SUCCESS);
				}
			} while (choice->backBegin() != 1);
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
	} while (choice->menuMain() != 6);

	return 0;
}