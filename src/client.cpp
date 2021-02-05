#include "client.h"

Client::Client() {
	std::string name = "";
	std::vector<Car> garage = {};
}

Client::Client(std::string name) {
	this->name = name;
}

void Client::addGarage(std::vector<Car>& catalog, std::vector<Client>& clientBase, int buyId, std::string name) {
 	auto car = std::find_if(std::begin(catalog), std::end(catalog), [buyId](Car c) { return c.id == buyId; });
	if (!isRepeat(clientBase, name)) { // если клиента нет в базе
		Client client(name);
		client.garage.push_back(*car);
		clientBase.push_back(client);
		catalog.erase(car);
	}
	else { // если клиент уже совершил покупку и есть в базе
		auto client = std::find_if(std::begin(clientBase), std::end(clientBase), [name](Client cl) { return cl.name == name; });
		client->garage.push_back(*car);
		catalog.erase(car);
	}
}

void Client::printGarage(std::vector<Client> clientBase, std::string name) {
	if (isRepeat(clientBase, name)) {
		std::cout << "Ваши автомобили: " << std::endl;
		auto client = std::find_if(std::begin(clientBase), std::end(clientBase), [name](Client cl) { return cl.name == name; });
		for (int i = 0; i < client->garage.size(); i++) {
			std::cout << "-----------------------------------" << std::endl;
			std::cout << std::setw(3) << client->garage[i].id
				<< std::setw(8) << std::setprecision(3) << client->garage[i].price << "млн"
				<< std::setw(10) << client->garage[i].color
				<< std::setw(10) << std::setprecision(4) << client->garage[i].speed << std::endl;
		}
	}
	else {
		std::cout << "У вас пока нет ни одного автомобиля" << std::endl;
	}
}

bool Client::isRepeat(std::vector<Client> clientBase, std::string name) {
	bool flag = false;
	for (int i = 0; i < clientBase.size(); i++) {
		if (name == clientBase[i].name) {
			flag = true;
			break;
		}
		else {
			flag = false;
		}
	}

	return flag;
}
