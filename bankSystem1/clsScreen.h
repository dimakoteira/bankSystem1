#pragma once
#include<iostream>
using namespace std;
class clsScreen {
protected:
	static void _DrawScreenHeader(string title, string subtitle="")
	{
		cout << "\t\t\t--------------------------------------------------------------" << endl;
		/*cout << setw(60)<<title<< endl;*/
		cout << setw(70) << right << title << endl;
		if (subtitle != "")
		{
			cout << setw(58) << subtitle << endl;
		}
		cout << "\t\t\t---------------------------------------------------------------" << endl;
		}
 };