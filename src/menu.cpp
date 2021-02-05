#include "menu.h"

void Menu::menuMain() {
	choiceMenu = 0;
	system("cls");
	std::cout << "1. Помощь" << std::endl;
	std::cout << "2. Отобразить список авто" << std::endl;
	std::cout << "3. Отфильтровать" << std::endl;
	std::cout << "4. Автомобили в собственности" << std::endl;
	std::cout << "5. Приобрести автомобиль" << std::endl;
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

void Menu::help() {
	std::cout << "Навигация по меню:" << std::endl;
	std::cout << "2. Отобразить список доступных автомобилей\n"
		<< "3. Отфильтровать список авто\n"
		<< "	- Введя максимальную цену, ниже которой выведутся доступные автомобили\n"
		"	- Введя максимальную скорость, выше которой выведутся доступные автомобили\n"
		"4. Отобразить автомобили владельца по введенному имени (Ввод производится на английском языке)\n"
		<< "5. Купить автомобиль по ID (ID не является порядковым номером в списке)\n"
		<< "6. Выход из программы (Неверное введенное значение также приводит к выходу)\n\n";
}