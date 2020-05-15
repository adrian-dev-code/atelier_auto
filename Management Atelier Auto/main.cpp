#include "Employee.h"
#include <vector>
#include "Bus.h"
#include "Standard.h"
#include "Truck.h"
#include "Service.h"

int main() 
{
	Service s1;
	while (s1.getIsRunning())
	{
		s1.menu();
	}

	return 0;
}


