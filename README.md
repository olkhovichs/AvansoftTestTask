# Сar Shop
____
### ТЗ:
* Реализовать автоматическую генерацию каталога автомобилей (не более 10 штук), каждый из которых обладает ID и несколькими произвольными параметрами (например: цвет, цена, скорость).
* Реализовать сущность покупателя, с атрибутом, который указывает на то, что он владеет конкретным автомобилем. По умолчанию, у покупателя нет автомобиля.
* Реализовать возможность выбора фильтрации списка автомобилей по каждому произвольному параметру. Результатом фильтрации должна быть выборка автомобилей, по произвольному условию для конкретного параметра, выбранного через консоль (например: фильтрация по цене, которая принимает определенное число, и выбирает только автомобили с ценой ниже этого числа).
* Реализовать возможность отображения отфильтрованного списка автомобилей.
* Реализовать метод, позволяющий покупателю приобрести автомобиль из списка по ID, введенному через консоль. При покупке выбранный автомобиль пропадает из каталога.
* Реализовать метод, показывающий, каким автомобилем владеет покупатель. 
* Реализовать основной цикл программы, в котором пользователь может:
  * Вызвать help, который показывает доступные методы;
  * Отобразить список авто;
  * Отобразить отфильтрованный список авто (№3);
  * Отобразить каким автомобилем владеет покупатель;
  * Купить определенный автомобиль по ID;
  * Выйти из программы.
____
### Пример работы программы 
![](https://github.com/olkhovichs/CatalogueOfCars-Avansoft-/blob/master/example.gif)
____
### Реализация
> Реализовать автоматическую генерацию каталога автомобилей (не более 10 штук), каждый из которых обладает ID и несколькими произвольными параметрами (например: цвет, цена, скорость).
Каталог заполняется рандомными значениями:
 Цена от 1.10 до 6.49 (млн)
 Максимальная развиваемая скорость от 220 до 340 (км/ч)
```
std::vector<Car> Car::setCatalog() {
	double carPrice = 0;
	std::string color;
	double carSpeed = 0;
	std::vector<Car> catalog;

	srand(time(nullptr));
	for (int i = 1; i <= 10; i++) {
		carPrice = 1.10 + (double)(rand()) / RAND_MAX * (6.49 - 1.10);
		color = carColors[rand() % carColors.size()];
		carSpeed = 220 + (double)(rand()) / RAND_MAX * (340 - 220);
		catalog.push_back(Car(i, carPrice, color, carSpeed));
	}

	return catalog;
}
```

> Реализовать возможность выбора фильтрации списка автомобилей по каждому произвольному параметру. Результатом фильтрации должна быть выборка автомобилей, по произвольному условию для конкретного параметра, выбранного через консоль (например: фильтрация по цене, которая принимает определенное число, и выбирает только автомобили с ценой ниже этого числа).
 Метод вывода каталога один, но может принимать параметры по умолчанию, что позволяет фильтровать вывод исходя из введенных значений цены и скорости
 ```
 void Car::printCatalog(std::vector<Car> catalog, double filterPrice, double filterSpeed) {
	std::cout << "| ID |  Price  |  Color  | Max speed |" << std::endl;
	for (int i = 0; i < catalog.size(); i++) {
		if (catalog[i].price <= filterPrice && catalog[i].speed >= filterSpeed) {
			std::cout << "-----------------------------------" << std::endl;
			std::cout << std::setw(3) << catalog[i].id
				<< std::setw(8) << std::setprecision(3) << catalog[i].price << " млн"
				<< std::setw(10) << catalog[i].color
				<< std::setw(10) << std::setprecision(4) << catalog[i].speed << std::endl;
		}
	}
}
```

> Реализовать метод, позволяющий покупателю приобрести автомобиль из списка по ID, введенному через консоль. При покупке выбранный автомобиль пропадает из каталога.
```
void Client::addGarage(std::vector<Car>& catalog, std::vector<Client>& clientBase, int buyId, std::string name) {
 	auto car = std::find_if(std::begin(catalog), std::end(catalog), [buyId](Car c) { return c.id == buyId; }); // поиск авто по id
	if (!isRepeat(clientBase, name)) { // если клиента нет в базе
		Client client(name);
		client.garage.push_back(*car);
		clientBase.push_back(client);
		catalog.erase(car);
	}
	else { // если клиент уже совершил покупку и есть в базе
		auto client = std::find_if(std::begin(clientBase), std::end(clientBase), [name](Client cl) { return cl.name == name; }); // поиск клиента в базе по имени
		client->garage.push_back(*car);
		catalog.erase(car);
	}
}
```

> Реализовать метод, показывающий, каким автомобилем владеет покупатель.
Поиск клиента в базе и вывод его "гаража"
```
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
```
