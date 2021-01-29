#include "client.h"

Client::Client() {
	name = "";
	id = 0;
}

Client::Client(std::string name, int id) {
	this->name = name;
	this->id = id;
}