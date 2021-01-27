#include "src/car.h"
#include "src/menu.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>


int main() {
	std::vector<Car> cars;
	std::vector<std::string> carColors{ "white", "black", "red", "blue", "green", "yellow", "purple", "gray"};
	std::string color;
	double carSpeed = 0;
	for (int i = 0; i <= 10; i++) {
		color = carColors[rand() % 8];
		carSpeed = rand() / 260;
		cars.push_back(Car(i, color, carSpeed));
	}

	for (int i = 0; i < cars.size(); i++) {
		std::cout << std::setw(5) << cars[i].id << cars[i].color << cars[i].speed << std::endl;
	}

	/*Menu* choice = new Menu;
	setlocale(LC_ALL, "Russian");
	switch (choice->menuMain()) {
	case 1:
		system("cls");
		std::cout << "помощь";
		break;
	case 2:
		system("cls");
		std::cout << "список авто";
		break;
	case 3:
		system("cls");
		std::cout << "отфильтрованный список";
		break;
	case 4:
		system("cls");
		std::cout << "какой авто?";
		break;
	case 5:
		system("cls");
		std::cout << "купить авто";
		break;
	case 6:
		exit(EXIT_SUCCESS);
		break;
	default:
		std::cerr << "Вы ввели некорректное значение" << std::endl;
		exit(EXIT_SUCCESS);
	}*/

	return 0;
}