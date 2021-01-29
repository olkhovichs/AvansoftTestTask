#include "menu.h"

void Menu::menuMain() {
	choiceMenu = 0;
	system("cls");
	std::cout << "1. Помощь" << std::endl;
	std::cout << "2. Отобразить список авто" << std::endl;
	std::cout << "3. Отфильтровать" << std::endl;
	std::cout << "4. Какой автомобиль у владельца" << std::endl;
	std::cout << "5. Приобрести автомобиль по ID" << std::endl;
	std::cout << "6. Выйти" << std::endl;
	std::cin >> choiceMenu;
	
}

void Menu::backBegin() {
	choiceBack = 0;
	std::cout << "\n1. Вернуться к началу" << std::endl;
	std::cout << "2. Выйти" << std::endl;
	std::cin >> choiceBack;

}

void Menu::filterMenu() {
	choiceFilter = 0;
	std::cout << "\n1. Цене" << std::endl;
	std::cout << "2. Максимальной скорости" << std::endl;
	std::cout << "3. Вернуться к началу" << std::endl;
	std::cin >> choiceFilter;
}