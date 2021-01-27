#include "menu.h"

int Menu::menuMain() {
	choice = 0;
	system("cls");
	std::cout << "1. Помощь" << std::endl;
	std::cout << "2. Отобразить список авто" << std::endl;
	std::cout << "3. Отфильтровать" << std::endl;
	std::cout << "4. Какой автомобиль у владельца" << std::endl;
	std::cout << "5. Приобрести автомобиль по ID" << std::endl;
	std::cout << "6. Выйти" << std::endl;
	std::cin >> choice;
	
	return choice;
}

int Menu::backBegin() {
	choice = 0;
	std::cout << "\n 1. Вернуться к началу" << std::endl;
	std::cout << "2. Выйти" << std::endl;
	std::cin >> choice;

	return choice;
}