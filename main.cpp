#include "src/car.h"
#include "src/client.h"
#include "src/menu.h"

#include <iostream>
#include <vector>
#include <string>
#include <clocale>

int main() {

	Car actionCatalog;
	Client actionBase;
	std::vector<Car> catalog;
	std::vector<Client> clientBase;
	catalog = actionCatalog.setCatalog();
	clientBase.resize(1);

	std::setlocale(0, "");
	Menu choice;
	do {
		choice.menuMain();
		switch (choice.choiceMenu) {
		case 1:
			system("cls");
			choice.help();
			do {
				choice.backBegin();
				switch (choice.choiceBack) {
				case 1:
					break;
				case 2:
					exit(EXIT_SUCCESS);
					break;
				}
			} while (choice.choiceBack != 1);
			break;
		case 2:
			system("cls");
			actionCatalog.printCatalog(catalog);
			do {
				choice.backBegin();
				switch (choice.choiceBack) {
				case 1:
					break;
				case 2:
					exit(EXIT_SUCCESS);
					break;
				}
			} while (choice.choiceBack != 1);
			break;
		case 3:
			double maxPrice;
			double minSpeed;
			system("cls");
			std::cout << "Отфильтровать список автомобилей по:" << std::endl;
			do {
				choice.filterMenu();
				switch (choice.choiceFilter) {
				case 1:
					system("cls");
					std::cout << "Введите максимальную цену: ";
					std::cin >> maxPrice;
					std::cout << std::endl;
					actionCatalog.printCatalog(catalog, maxPrice);
					break;
				case 2:
					system("cls");
					std::cout << "Максимальная скорость автомобиля от: ";
					std::cin >> minSpeed;
					std::cout << std::endl;
					actionCatalog.printCatalog(catalog, 6.50, minSpeed);
					break;
				case 3:
					break;
				}
			} while (choice.choiceFilter != 3);
			break;
		case 4:
		{
			std::string name;
			system("cls");
			std::cout << "Введите свое имя: ";
			std::cin >> name;
			std::cout << std::endl;
			
			actionBase.printGarage(clientBase, name);

			do {
				choice.backBegin();
				switch (choice.choiceBack) {
				case 1:
					break;
				case 2:
					exit(EXIT_SUCCESS);
					break;
				}
			} while (choice.choiceBack != 1);
		}
			break;
		case 5:
		{
			Car car;
			std::string name;
			system("cls");
			std::cout << "Введите свое имя: ";
			std::cin >> name;
			std::cout << std::endl;
			actionCatalog.printCatalog(catalog);
			std::cout << "\nВведите ID автомобиля, который хотите приобрести: ";
			std::cin >> car.id;
			system("cls");
			std::cout << "Поздравляем, " << name << "! Вы приобрели автомобиль под номером " << car.id << ".";

			actionBase.addGarage(catalog, clientBase, car.id, name);

			do {
				choice.backBegin();
				switch (choice.choiceBack) {
				case 1:
					break;
				case 2:
					exit(EXIT_SUCCESS);
					break;
				}
			} while (choice.choiceBack != 1);
		}
			break;
		case 6:
			exit(EXIT_SUCCESS);
			break;
		default:
			std::cerr << "Вы ввели некорректное значение" << std::endl;
			exit(EXIT_SUCCESS);
		}
	} while (choice.choiceMenu != 6);

	return 0;
}