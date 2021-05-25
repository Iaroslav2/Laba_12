#include <iostream>
#include "Laba12.h"

int main(){

	DataAndTime a;
	a.output();
	std::cout << a.GetHour() << std::endl;
	std::cout << a.GetMin() << std::endl;
	std::cout << a.GetSec() << std::endl;
	std::cout << a.GetYear() << std::endl;
	std::cout << a.GetMonth() << std::endl;
	std::cout << a.GetDay() << std::endl << std::endl;

	DataAndTime b(a);
	b.output();
	a.SetYear(a.Input());
	a.SetMonth(a.Input());
	a.SetDay(a.Input());
	a.SetHour(a.Input());
	a.SetMin(a.Input());
	a.SetSec(a.Input());

	DataAndTime c;
	DataAndTime d(b);
	DataAndTime e;
	DataAndTime f;
	c = a;
	e = a + b;
	f = d - c;
	std::cout << "result + :\n\n";
	e.Checking();
	e.output();
	std::cout << "result - :\n\n";
	f.Checking();
	f.output();
	return 0;

}
