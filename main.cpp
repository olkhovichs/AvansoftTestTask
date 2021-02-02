#include "src/car.h"
#include "src/client.h"
#include "src/menu.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>

#include <typeinfo>

int main() {

	Car cars;
	std::vector<Car> catalog;
	std::vector<Client> clientBase;
	catalog = cars.setCatalog();
	double maxPrice;
	double minSpeed;

	Client client;

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
			cars.printCatalog(catalog);
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
					system("cls");
					std::cout << "Введите максимальную цену: ";
					std::cin >> maxPrice;
					std::cout << std::endl;
					cars.printCatalog(catalog, maxPrice);
					break;
				case 2:
					system("cls");
					std::cout << "Максимальная скорость автомобиля от: ";
					std::cin >> minSpeed;
					std::cout << std::endl;
					cars.printCatalog(catalog, 6.50, minSpeed);
					break;
				case 3:
					break;
				}
			} while (choice->choiceFilter != 3);
			break;
		case 4:
			/*system("cls");
			std::cout << "Введите свое имя: ";
			std::cin >> client.name;
			std::cout << std::endl;
			client.printOwnCars(client.name);
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
			break;*/
		case 5:
		{
			system("cls");
			std::cout << "Введите свое имя: ";
			std::cin >> client.name;
			std::cout << std::endl;
			clientBase.push_back(client);
			cars.printCatalog(catalog);
			std::cout << "\nВведите ID автомобиля, который хотите приобрести: ";
			std::cin >> cars.id;
			system("cls");
			std::cout << "Поздравляем, " << client.name << "! Вы приобрели автомобиль под номером " << cars.id << ".";
			/*auto carBought = cars.buyCar(cars.id);
			client.garage.push_back(carBought);*/
			cars.buyCar(catalog, cars.id);
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
		}
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