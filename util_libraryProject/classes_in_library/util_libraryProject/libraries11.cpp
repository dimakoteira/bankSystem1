
#include <iostream>
#include "clsdate.h";
#include "clsInputValidate.h";
#include "util.h";
int main()
{
	//cout<<clsInputValidate::IsDateBetween(clsDate(), clsDate("4,5,2025"), clsDate("5/11/2026"))<<endl;

	/*cout << clsUtil::RandomNumber(3, 67) << endl;
	cout<<clsInputValidate::IsNumberBetween(4, 6, 78)<<endl;
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate("10/3/2026"), clsDate("4/5/2026")) << endl;
	cout << "enter a number: " << endl;
	int x=clsInputValidate::ReadIntNumber("invalid try again");
	cout << x << endl;

	cout << "enter a number: " << endl;
	double x2 = clsInputValidate::ReadDbNumber("invalid try again");
	cout << x2 << endl;*/

	cout << "enter a number between 1 and 10: " << endl;
	double x3 = clsInputValidate::ReadIntNumberBetween(1,10,"number is not between 1 and 10 try again");
	cout << x3 << endl;

	cout<<clsInputValidate::IsValidDate(clsDate(4, 3, 2025))<<endl;


}
