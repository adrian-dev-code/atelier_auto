#pragma once
#include <vector>
#include "Car.h"
#include "Employee.h"

class Service
{
public:
	bool getIsRunning() const;
	void menu();



private:
	void showEmployees();
	void removeEmployee();
	void editEmployee();
	void calculateSalary();
	void addCar();
	void removeCar();

private:
	std::vector <Car*> cars;
	std::vector <Employee> employees;

	bool isRunning = true;
	
};

