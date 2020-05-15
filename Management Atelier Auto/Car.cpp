#include "Car.h"
#include <iostream>
#include <ctime>

Car::Car()
{
	setYear();
	setKilometers();
	setIsDiesel();
}

void Car::setKilometers()
{
	int kilometers_entry;
	std::cout << "Introduceti numarul de kilometrii \n";
	std::cin >> kilometers_entry;
	while (kilometers_entry < 0)
	{
		std::cout << "Kilometrii nu pot fii negativi \n";
		std::cout << "Introduceti numarul de kilometrii \n";
		std::cin >> kilometers_entry;
	}
	this->kilometers = kilometers_entry;
	system("CLS");
}

void Car::setYear()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	int current_year = now->tm_year + 1900;

	int year_entry;
	std::cout << "Introduceti anul fabricatiei \n";
	std::cin >> year_entry;
	while (year_entry < 1900 || year_entry > current_year)
	{
		std::cout << "Anul fabricatiei nu poate mai mic decat 1900 sau mai mare decat anul curent.\n";
		std::cout << "Introduceti anul: \n";
		std::cin >> year_entry;
	}
	this->year = year_entry;
	system("CLS");
}

void Car::setIsDiesel()
{
	int input;
	std::cout << "Masina este diesel[1] sau benzina[0]?\n";
	std::cin >> input;
	while (input != 0 && input != 1)
	{
		std::cout << "Nu ati ales o optiune valida\n";
		std::cout << "Masina este diesel[1] sau benzina[0]?\n";
		std::cin >> input;
	}
	this->isDiesel = input;
	system("CLS");
}

void Car::useDiscount()
{
	int option;
	std::cout << "Doriti sa aplicati discount ? [0-NU] [1-DA] \n";
	std::cin >> option;
	while (option != 0 && option != 1)
	{
		std::cout << "Date de intrare invalide \n";
		std::cout << "Doriti sa aplicati discount ? [0-NU] [1-DA] \n";
		std::cin >> option;
	}

	std::cout << calcInsurance(option) << " ";

}

int Car::calcAge()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

	int current_year = now->tm_year + 1900;

	return current_year - this->year;
}

bool Car::getIsBig() const
{
	return isBig;
}

