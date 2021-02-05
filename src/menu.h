#pragma once

#include <iostream>
#include <iomanip>

class Menu {
public:
	int choiceMenu;
	int choiceBack;
	int choiceFilter;

	void menuMain();
	void backBegin();
	void filterMenu();
	void help();
};