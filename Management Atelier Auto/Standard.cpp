#include "Standard.h"
#include <iostream>
#include <stdlib.h>

Standard::Standard()
{
	setTransmission();
	discount = 0.05;
	isBig = false;
}

double Standard::calcInsurance(bool useDiscount)
{
	double cost = this->isDiesel * 500;

	cost += this->calcAge() * 100;

	if (this->kilometers > 200'000)
	{
		cost += 500;
	}

	if (useDiscount)
		return cost - (this->discount * cost);

	return cost;
}

void Standard::setTransmission()
{
	int t;
	std::cout << "Introduceti tipul de transmisie (manuala[0] automata[1])\n";
	std::cin >> t;
	while (t != 0 && t != 1)
	{
		std::cout << "Tipul introdus nu este valid\n";
		std::cout << "Introduceti tipul de transmisie (manuala[0] automata[1])\n";
		std::cin >> t;
	}
	this->transmission = (Transmission)t;

	system("CLS");
}
