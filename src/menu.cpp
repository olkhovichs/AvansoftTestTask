#include "menu.h"

int Menu::menuMain() {
	choice = 0;
	system("cls");
	std::cout << "1. ������" << std::endl;
	std::cout << "2. ���������� ������ ����" << std::endl;
	std::cout << "3. �������������" << std::endl;
	std::cout << "4. ����� ���������� � ���������" << std::endl;
	std::cout << "5. ���������� ���������� �� ID" << std::endl;
	std::cout << "6. �����" << std::endl;
	std::cin >> choice;
	
	return choice;
}

int Menu::backBegin() {
	choice = 0;
	std::cout << "\n 1. ��������� � ������" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cin >> choice;

	return choice;
}