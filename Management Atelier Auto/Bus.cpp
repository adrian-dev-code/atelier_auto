#include "Bus.h"
#include <iostream>
#include <stdlib.h>

Bus::Bus()
{
	setSeats();
	discount = 0.1;
	isBig = true;
}

void Bus::setSeats()
{
	int seatNo;
	std::cout << "Introduceti numarul de locuri: \n";
	std::cin >> seatNo;
	while (seatNo < 0 || seatNo> 50)
	{
		std::cout << "Numarul de locuri maxim este cuprins intre 0 si 50.\n";
		std::cout << "Introduceti numarul de locuri: ";
		std::cin >> seatNo;
	}
	this->seats = seatNo;

	system("CLS");
}

double Bus::calcInsurance(bool useDiscount)
{
	double cost = this->isDiesel * 1000;

	cost += this->calcAge() * 200;

	if (this->kilometers > 200'000)
	{
		cost += 1000;
	}
	else if(this->kilometers >100'000)
	{
		cost += 500;
	}

	if (useDiscount)
		return cost - (this->discount * cost);
	
	return cost;
}
