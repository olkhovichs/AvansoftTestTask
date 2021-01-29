#include "src/car.h"
#include "src/menu.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>

int main() {
	// filling in the catalogue of cars (add to a separate method)
	/*std::vector<Car> carsCatalog;
	std::vector<std::string> carColors{ "white", "black", "red", "blue", "green", "yellow", "purple", "gray"};
	std::string color;
	double carSpeed = 0;
	srand(time(nullptr));
	for (int i = 1; i <= 11; i++) {
		color = carColors[rand() % carColors.size()];
		carSpeed = 220 + (double)(rand()) / RAND_MAX * (340 - 220);
		carsCatalog.push_back(Car(i, color, carSpeed));
	}*/
	
	Car cars;
	cars.setCatalog();

	setlocale(LC_ALL, "Russian");
	Menu* choice = new Menu;
	do {
		choice->menuMain();
		switch (choice->choiceMenu) {
		case 1:
			system("cls");
			do {
				choice->backBegin();
				switch (choice->choiceBack) {
				case 1:
					break;
				case 2:
					exit(EXIT_SUCCESS);
					break;
				}
			} while (choice->choiceBack != 1);
			break;
		case 2:
			system("cls");
			std::cout << "| ID |  Color  | Max speed |" << std::endl;
			for (int i = 0; i < cars.catalog.size() - 1; i++) {
				std::cout << "------------------------------" << std::endl;
				std::cout << std::setw(3) << cars.catalog[i].id
						<< std::setw(10) << cars.catalog[i].color
						<< std::setw(10) << std::setprecision(4) << cars.catalog[i].maxSpeed << std::endl;
			}
			do {
				choice->backBegin();
				switch (choice->choiceBack) {
				case 1:
					break;
				case 2:
					exit(EXIT_SUCCESS);
					break;
				}
			} while (choice->choiceBack != 1);
			break;
		case 3:
			system("cls");
			std::cout << "Отфильтровать список автомобилей по:" << std::endl;
			do {
				choice->filterMenu();
				switch (choice->choiceFilter) {
				case 1:
					//std::cout << "1";

					break;
				case 2:
					std::cout << "2";
					break;
				case 3:
					std::cout << "3";
					break;
				case 4:
					break;
				}
			} while (choice->choiceFilter != 4);
			break;
		case 6:
			exit(EXIT_SUCCESS);
			break;
		default:
			std::cerr << "Вы ввели некорректное значение" << std::endl;
			exit(EXIT_SUCCESS);
		}
	} while (choice->choiceMenu != 6);

	return 0;
}