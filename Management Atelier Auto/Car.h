#pragma once
class Car
{
public:
	Car();

	void setKilometers();
	void setYear();
	void setIsDiesel();
	virtual double calcInsurance(bool useDiscount) = 0;
	void useDiscount();

	int calcAge();

	bool getIsBig() const;

protected:
	int id;
	int kilometers;
	int year;
	bool isDiesel;
	static int carCount;

	bool isBig;

	double discount;
};

