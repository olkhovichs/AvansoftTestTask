#pragma once

#include <iostream>

class Client {
public:

	std::string name;
	int id;

	Client();
	Client(std::string name, int id);
};