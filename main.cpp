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
	cars.setCatalog();
	double maxPrice;
	double minSpeed;

	//std::map<Car, int> cat;

	Client client;
	std::vector<Client> clientBase;

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
			cars.printCatalog();
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
			std::cout << "������������� ������ ����������� ��:" << std::endl;
			do {
				choice->filterMenu();
				switch (choice->choiceFilter) {
				case 1:
					system("cls");
					std::cout << "������� ������������ ����: ";
					std::cin >> maxPrice;
					std::cout << std::endl;
					cars.printCatalog(maxPrice);
					break;
				case 2:
					system("cls");
					std::cout << "������������ �������� ���������� ��: ";
					std::cin >> minSpeed;
					std::cout << std::endl;
					cars.printCatalog(6.50, minSpeed);
					break;
				case 3:
					break;
				}
			} while (choice->choiceFilter != 3);
			break;
		case 4:
			system("cls");
			std::cout << "������� ���� ���: ";
			std::cin >> client.name;
			std::cout << std::endl;
			// 
		case 5:
			system("cls");
			std::cout << "������� ���� ���: ";
			std::cin >> client.name; 
			clientBase.push_back(client);
			std::cout << std::endl;
			cars.printCatalog();
			std::cout << "\n������� ID ����������, ������� ������ ����������: ";
			std::cin >> cars.id;
			system("cls");
			std::cout << "�����������, " << client.name << "! �� ��������� ���������� ��� ������� " << cars.id << ".";
			cars.buyCar(cars.id);
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