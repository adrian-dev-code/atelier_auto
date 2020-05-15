#pragma once
#include <iostream>

enum EmployeeType
{
	Director,
	Mechanic,
	Assistent
};

struct Date
{
	int dd;
	int mm;
	int yyyy;
};

class Employee
{

public:
	Employee();

	void showEmployee() const;
	void editEmployee();
	int calculateSalary();
	
	// setters
	void setFirstName();
	void setLastName();
	void setBirthday();
	void setEmpday();

	void setType();
	EmployeeType getType() const;

	bool addCar(bool isBig);

	void removeCar(bool isBig);

	int getNormalCars() const;
	int getBigCars() const;

private:
	int id;

	std::string firstname;
	std::string lastname;

	Date birthday;
	Date empday;

	double coefficient;

	EmployeeType type;

	int normalCars = 0;
	int bigCars = 0;

	static int employessCount;

private:
	int diffDays(Date&);
};

