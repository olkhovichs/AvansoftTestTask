#include "menu.h"

void Menu::menuMain() {
	choiceMenu = 0;
	system("cls");
	std::cout << "1. ������" << std::endl;
	std::cout << "2. ���������� ������ ����" << std::endl;
	std::cout << "3. �������������" << std::endl;
	std::cout << "4. ����� ���������� � ���������" << std::endl;
	std::cout << "5. ���������� ���������� �� ID" << std::endl;
	std::cout << "6. �����" << std::endl;
	std::cin >> choiceMenu;
	
}

void Menu::backBegin() {
	choiceBack = 0;
	std::cout << "\n1. ��������� � ������" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cin >> choiceBack;

}

void Menu::filterMenu() {
	choiceFilter = 0;
	std::cout << "\n1. ����" << std::endl;
	std::cout << "2. ������������ ��������" << std::endl;
	std::cout << "3. ��������� � ������" << std::endl;
	std::cin >> choiceFilter;
}