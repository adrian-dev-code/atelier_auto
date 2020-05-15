#include "Employee.h"
#include <ctime>
#include <iomanip>
#include <stdlib.h>

int Employee::employessCount = -1;

Employee::Employee()
{
	setLastName();
	setFirstName();
	setType();
	setBirthday();
	setEmpday();

	employessCount++;
	this->id = employessCount;

	std::cout << "Angajat adaugat cu succes!" << std::endl;

}

void Employee::showEmployee() const
{
	std::cout << "Nume:" << this->lastname << "\tPrenumele:" << this->firstname << "\n";
}

void Employee::editEmployee()
{
	int option;
	std::cout << "1: Modificare nume\n";
	std::cout << "2: Modificare prenume\n";
	std::cout << "3: Modificare salariu\n";
	std::cout << "4: Modificare ziua nastere\n";
	std::cout << "5: Modificare ziua angajare\n";
	std::cin >> option;
	switch (option)
	{
	case 1:

		break;

	case 2:

	default:
		break;
	}

}

int Employee::calculateSalary()
{
	int years = diffDays(this->empday) / 365;

	if (years <= 1) years = 1;

	return years * this->coefficient * 1000;
}

void Employee::setFirstName()
{
	std::string fn;
	std::cout << "Introduceti prenumele angajatului: ";
	std::cin >> fn;

	while (fn.size() == 0 || fn.size() >= 30)
	{
		std::cout << "Prenumele trebuie sa aiba de la 1 pana la 29 caractere." << std::endl;
		std::cout << "Introduceti prenumele angajatului: ";
		std::cin >> fn;
	}

	this->firstname = fn;
	std::cout << "Prenume setat cu succes." << std::endl;

	system("CLS");
}

void Employee::setLastName()
{
	std::string ln;
	std::cout << "Introduceti numele angajatului: ";
	std::cin >> ln;

	while (ln.size() == 0 || ln.size() >= 30)
	{
		std::cout << "Numele trebuie sa aiba de la 1 pana la 29 caractere." << std::endl;
		std::cout << "Introduceti numele angajatului: ";
		std::cin >> ln;
	}

	this->lastname = ln;

	system("CLS");
}

void Employee::setBirthday()
{
	Date b;
	std::cout << "Introduceti data de nastere (dd-mm-yyy) \n";
	std::cout << "Introduceti ziua: \n";
	std::cin >> b.dd;

	while (b.dd < 1 || b.dd > 31)
	{
		std::cout << "Ziua trebuie sa fie cuprinsa intre 1 si 31 (inclusiv).\n";
		std::cout << "Introduceti ziua: \n";
		std::cin >> b.dd;
	}

	std::cout << "Introduceti luna: \n";
	std::cin >> b.mm;
	while (b.mm < 1 || b.mm >12)
	{
		std::cout << "Luna trebuie sa fie cuprinsa intre 1 si 12 (inclusiv).\n";
		std::cout << "Introduceti luna: \n";
		std::cin >> b.mm;

	}

	std::cout << "Introduceti anul: \n";
	std::cin >> b.yyyy;
	while (b.yyyy < 1900 || b.yyyy > 2002)
	{
		std::cout << "Anul nu este valid.\n";
		std::cout << "Introduceti anul: \n";
		std::cin >> b.yyyy;
	}

	this->birthday = b;

	system("CLS");
}

void Employee::setEmpday()
{
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);

	Date current;
	current.dd = now->tm_mday;
	current.mm = now->tm_mon + 1;
	current.yyyy = now->tm_year + 1900;

	Date e;
	std::cout << "Introduceti data angajarii (dd-mm-yyy) \n";
	std::cout << "Introduceti ziua: \n";
	std::cin >> e.dd;

	while (!(e.dd > 0 && e.dd <= 31))
	{
		std::cout << "Ziua trebuie sa fie cuprinsa intre 1 si 31 (inclusiv).\n";
		std::cout << "Introduceti ziua: \n";
		std::cin >> e.dd;
	}

	std::cout << "Introduceti luna: \n";
	std::cin >> e.mm;
	while (e.mm < 0 || e.mm >12)
	{
		std::cout << "Luna trebuie sa fie cuprinsa intre 1 si 12 (inclusiv).\n";
		std::cout << "Introduceti luna: \n";
		std::cin >> e.mm;
	}

	std::cout << "Introduceti anul: \n";
	std::cin >> e.yyyy;
	while (e.yyyy < 1900 || e.yyyy >=current.yyyy+1)
	{
		std::cout << "Anul nu este valid.\n";
		std::cout << "Introduceti anul: \n";
		std::cin >> e.yyyy;
	}

	//Verificam sa nu se faca angajari dupa ziua curenta
	
	while ((e.dd > current.dd) && (e.mm == current.mm) && (e.yyyy == current.yyyy))
	{
		std::cout << "Data introdusa nu este valida. Data nu poate fi mai recenta decat cea de azi \n";
		std::cout << "Introduceti data angajarii (dd-mm-yyy) \n";
		std::cout << "Introduceti ziua: \n";
		std::cin >> e.dd;

		while (!(e.dd > 0 && e.dd <= 31))
		{
			std::cout << "Ziua trebuie sa fie cuprinsa intre 1 si 31 (inclusiv).\n";
			std::cout << "Introduceti ziua: \n";
			std::cin >> e.dd;
		}

		std::cout << "Introduceti luna: \n";
		std::cin >> e.mm;
		while (e.mm < 0 || e.mm >12)
		{
			std::cout << "Luna trebuie sa fie cuprinsa intre 1 si 12 (inclusiv).\n";
			std::cout << "Introduceti luna: \n";
			std::cin >> e.mm;
		}

		std::cout << "Introduceti anul: \n";
		std::cin >> e.yyyy;
		while (e.yyyy < 1900 || e.yyyy >=current.yyyy+1)
		{
			std::cout << "Anul nu este valid.\n";
			std::cout << "Introduceti anul: \n";
			std::cin >> e.yyyy;
		}
	}

	while ((e.mm > current.mm) && (e.yyyy == current.yyyy))
	{
		std::cout << "Data introdusa nu este valida. Data nu poate fi mai recenta decat cea de azi \n";
		std::cout << "Introduceti data angajarii (dd-mm-yyy) \n";
		std::cout << "Introduceti ziua: \n";
		std::cin >> e.dd;

		while (!(e.dd > 0 && e.dd <= 31))
		{
			std::cout << "Ziua trebuie sa fie cuprinsa intre 1 si 31 (inclusiv).\n";
			std::cout << "Introduceti ziua: \n";
			std::cin >> e.dd;
		}

		std::cout << "Introduceti luna: \n";
		std::cin >> e.mm;
		while (e.mm < 0 || e.mm >12)
		{
			std::cout << "Luna trebuie sa fie cuprinsa intre 1 si 12 (inclusiv).\n";
			std::cout << "Introduceti luna: \n";
			std::cin >> e.mm;
		}

		std::cout << "Introduceti anul: \n";
		std::cin >> e.yyyy;
		while (e.yyyy < 1900 || e.yyyy >= current.yyyy+1)
		{
			std::cout << "Anul nu este valid.\n";
			std::cout << "Introduceti anul: \n";
			std::cin >> e.yyyy;
		}
	}

	this->empday = e;

	system("CLS");
}

void Employee::setType()
{
	int type;
	std::cout << "Alegeti tipul angajatului: \n[0->director] [1->mecanic] [2->asistent]\n";
	std::cin >> type;

	while (type < 0 || type > 2)
	{
		std::cout << "Va rugam alegeti un tip de angajat valid.\n";
		std::cout << "Alegeti tipul angajatului: \n[0->director] [1->mecanic] [2->asistent]\n";
		std::cin >> type;

	}

	this->type = (EmployeeType)type;
	if (this->type == Director)
	{
		this->coefficient = 2;
	}
	else if (this->type == Mechanic)
	{
		this->coefficient = 1.5;
	}
	else if (this->type == Assistent)
	{
		this->coefficient = 1;
	}

	system("CLS");
}

EmployeeType Employee::getType() const
{
	return type;
}

bool Employee::addCar(bool isBig)
{
	if (this->type == Mechanic)
	{
		if (isBig)
		{
			if (bigCars == 0)
			{
				std::cout << "Vehiculul de mare tonaj a fost adaugat la primul mecanic disponibil.\n";
				bigCars++;
				return true;
			}
			else if (bigCars == 1)
			{
				std::cout << "Vehiculul de mare tonaj nu a putut fi adaugat la acest mecanic.\n";
				return false;
			}
		}
		else
		{
			if (normalCars < 3)
			{
				std::cout << "Masina a fost adaugata la primul mecanic disponibil.\n";
				normalCars++;
				return true;
			}
			else
			{
				std::cout << "Masina nu a putut fi adaugata la acest mecanic.\n";
				return false;
			}
		}
	}
	else
	{
		std::cout << "Doar un mecanic se poate ocupa de reparatia unui vehicul.\n";
		return false;
	}
}

void Employee::removeCar(bool isBig)
{
	if (isBig)
	{
		if (bigCars != 0)
		{
			this->bigCars--;
			std::cout << "Masina eliminata cu succes \n";
		}
		else
		{
			std::cout << "Acest mecanic nu a avut nici un camion sau autobuz.\n";
		}
	}
	else
	{
		if (normalCars != 0)
		{
			this->normalCars--;
			std::cout << "Masina eliminata cu succes \n";
		}
		else
		{
			std::cout << "Acest mecanic nu a avut nici o masina.\n";
		}
	}
}

int Employee::getNormalCars() const
{
	return normalCars;
}

int Employee::getBigCars() const
{
	return bigCars;
}

int Employee::diffDays(Date& e)
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	Date current;
	current.dd = now->tm_mday;
	current.mm = now->tm_mon + 1;
	current.yyyy = now->tm_year + 1900;

	current.dd -= e.dd;
	current.mm -= e.mm;
	current.yyyy -= e.yyyy;

	return current.dd + current.mm * 30 + current.yyyy * 365;
}
