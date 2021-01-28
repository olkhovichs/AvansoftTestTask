#include "src/car.h"
#include "src/menu.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

int main() {
	// filling in the catalogue of cars (add to a separate method)
	std::vector<Car> carsCatalog;
	std::vector<std::string> carColors{ "white", "black", "red", "blue", "green", "yellow", "purple", "gray"};
	std::string color;
	double carSpeed = 0;
	for (int i = 1; i <= 11; i++) {
		color = carColors[rand() % carColors.size()];
		carSpeed = 220 + (double)(rand()) / RAND_MAX * (340 - 220);
		carsCatalog.push_back(Car(i, color, carSpeed));
	}
	
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
			for (int i = 0; i < carsCatalog.size() - 1; i++) {
				std::cout << "------------------------------" << std::endl;
				std::cout << std::setw(3) << carsCatalog[i].id
						<< std::setw(10) << carsCatalog[i].color
						<< std::setw(10) << std::setprecision(4) << carsCatalog[i].maxSpeed << std::endl;
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
		case 6:
			exit(EXIT_SUCCESS);
			break;
		default:
			std::cerr << "�� ����� ������������ ��������" << std::endl;
			exit(EXIT_SUCCESS);
		}
	} while (choice->choiceMenu != 6);

	return 0;
}