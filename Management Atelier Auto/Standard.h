#pragma once
#include "Car.h"
class Standard : public Car
{
public: 
	Standard();

	double calcInsurance(bool useDiscount) override;
	void setTransmission();
	
private:
	enum Transmission
	{
		Manual,
		Automatic
	} transmission;

};

