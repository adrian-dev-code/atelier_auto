#include "Truck.h"
#include <iostream>

Truck::Truck()
{
	setTonnage();
	discount = 0.15;
	isBig = true;
}

void Truck::setTonnage()
{
	int tonn;
	std::cout << "Introduceti greutatea (tone): \n";
	std::cin >> tonn;
	while (tonn < 0)
	{
		std::cout << "Tonajul nu poate fi negativ\n";
		std::cout << "Introduceti greutatea (tone): \n";
		std::cin >> tonn;
	}

	this->tonnage = tonn;
}

double Truck::calcInsurance(bool useDiscount)
{
	double cost = 0.0;

	cost += this->calcAge() * 300;
	
	if (this->kilometers > 800'000)
	{
		cost += 700;
	}

	if (useDiscount)
		return cost - (this->discount * cost);

	return cost;
}