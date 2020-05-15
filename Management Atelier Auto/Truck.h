#pragma once
#include "Car.h"
class Truck : public Car
{
public:
	Truck();
	void setTonnage();
	double calcInsurance(bool useDiscount) override;
private:
	int tonnage;
};

