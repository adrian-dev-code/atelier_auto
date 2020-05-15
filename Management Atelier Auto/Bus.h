#pragma once
#include "Car.h"
class Bus : public Car
{
public:
	Bus();
	double calcInsurance(bool useDiscount) override;
	void setSeats();
private:
	int seats;

};

