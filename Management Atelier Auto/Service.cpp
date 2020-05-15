#include "Service.h"
#include <iomanip>
#include <stdlib.h>

bool Service::getIsRunning() const
{
	return this->isRunning;
}

void Service::menu()
{
	std::cout << std::setw(45) << std::setfill('=') << "\n";
	std::cout << "MANAGEMENT ATELIER AUTO | MENIU PRINCIPAL	 \n";
	std::cout << "1. Afisare angajati\n";
	std::cout << "2. Adaugare angajat\n";
	std::cout << "3. Stergere angajat\n";
	std::cout << "4. Editare angajat\n";
	std::cout << "5. Calculare salariu angajat\n";
	std::cout << "6. Adaugare vehicul\n";
	std::cout << "7. Eliminare vehicul\n";
	std::cout << "8. Iesire program\n";
	std::cout << std::setw(45) << std::setfill('=') << "\n";

	int option;
	std::cin >> option;
	switch (option)
	{
	case 1:
		showEmployees();
		break;

	case 2:
		employees.push_back(Employee());
		break;

	case 3:
		removeEmployee();
		break;

	case 4:
		editEmployee();
		break;

	case 5:
		calculateSalary();
		break;
	case 6:
		addCar();
		break;
	case 7:
		removeCar();
		break;
	case 8:
		this->isRunning = false;
		break;
	default:
		std::cout << "Optiunea aleasa nu este valida.";
		break;
	}
}

void Service::removeEmployee()
{
	std::cout << "Introduceti id-ul persoanei ce urmeaza sau a fost concediata \n";
	int id;
	std::cin >> id;
	while (id > employees.size() - 1 || id < 0 || employees.empty())
	{
		std::cout << "Id-ul introdus nu este valid \n";
		std::cout << "Introduceti id-ul persoanei ce urmeaza sau a fost concediata \n";
		std::cin >> id;
	}
	employees.erase(employees.begin() + id);
	std::cout << "Angajatul a fost sters din lista\n";
}

void Service::editEmployee()
{
	std::cout << "Introduceti id-ul persoanei care trebuie modificate: \n";
	int id;
	std::cin >> id;

	while ((id > employees.size() - 1 || id < 0) || employees.empty())
	{
		std::cout << "Id-ul introdus nu este valid\n";
		std::cout << "Introduceti id-ul persoanei care trebuie modificate: \n";
		std::cin >> id;
	}

	std::cout << "1:Modificare nume \n";
	std::cout << "2:Modificare prenume \n";
	std::cout << "3:Modificare data nastere \n";
	std::cout << "4:Modificare ziua angajare \n";
	int input;
	std::cin >> input;

	switch (input)
	{
	case 1:
		employees[id].setLastName();
		break;

	case 2:
		employees[id].setFirstName();
		break;
	case 3:
		employees[id].setBirthday();
		break;

	case 4:
		employees[id].setEmpday();
		break;

	default:
		std::cout << "Nu ati ales o optiune valida \n";
		break;
	}
}

void Service::calculateSalary()
{
	std::cout << "Introduceti id-ul persoanei al carei salariu doriti sa il calculati: \n";
	int id;
	std::cin >> id;

	while ((id > employees.size() - 1 || id < 0) || employees.empty())
	{
		std::cout << "Id-ul introdus nu este valid\n";
		std::cout << "Introduceti id-ul persoanei al carei salariu doriti sa il calculati: \n";
		std::cin >> id;
	}

	std::cout << "SALARIU : " << employees[id].calculateSalary() << " RON\n";
}

void Service::addCar()
{	
	int input;
	std::cout << "Selectati tipul masinii : \n";
	std::cout << "0\t->masina \n";
	std::cout << "1\t->camion sau autobuz\n";
	
	std::cin >> input;
	while (input != 0 && input != 1)
	{
		std::cout << "Tipul ales nu este valid. \n";
		std::cout << "Selectati tipul masinii : \n";
		std::cout << "0\t->masina \n";
		std::cout << "1\t->camion sau autobuz\n";

		std::cin >> input;
	}
	
	for (int i = 0; i < employees.size(); i++)
	{
		if (employees[i].getType() == EmployeeType::Mechanic)
		{
			if (input == 0 && employees[i].getNormalCars() < 3)
			{
				employees[i].addCar(input);
			}
			else if (input == 1 && employees[i].getBigCars() < 1)
			{
				employees[i].addCar(input);
			}
		}
	}

}

void Service::removeCar()
{
	std::cout << "Introduceti ID-ul mecanicului ce a terminat lucrarea:\n";
	int id;
	std::cin >> id;

	while ((id > employees.size() - 1 || id < 0) || employees.empty() || employees[id].getType() != EmployeeType::Mechanic)
	{
		std::cout << "Id-ul introdus nu este valid sau angajatul nu este mecanic.\n";
		std::cout << "Introduceti ID-ul mecanicului ce a terminat lucrarea:\n";
		std::cin >> id;
	}

	int input;
	std::cout << "Selectati tipul masinii : \n";
	std::cout << "0\t->masina \n";
	std::cout << "1\t->camion sau autobuz\n";

	std::cin >> input;
	while (input != 0 && input != 1)
	{
		std::cout << "Tipul ales nu este valid. \n";
		std::cout << "Selectati tipul masinii : \n";
		std::cout << "0\t->masina \n";
		std::cout << "1\t->camion sau autobuz\n";

		std::cin >> input;
	}

	employees[id].removeCar(input);

}

void Service::showEmployees()
{
	system("CLS");
	if (employees.size() == 0)
	{
		std::cout << "\nNu sunt angajati de afisat \n \n";
	}
	else
		for (auto x : employees)
		{
			x.showEmployee();
		}
}
