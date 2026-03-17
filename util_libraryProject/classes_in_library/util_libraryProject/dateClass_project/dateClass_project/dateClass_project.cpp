#include <iostream>
#include"clsDate.h";
using namespace std;
int main()
{
	clsDate date1;
	date1.increase_day();
	date1.print();
	clsDate::increase_day(3, 5, 2023);
	clsDate date2 = clsDate::increase_day(3, 5, 2023);
	date2.print();

}
