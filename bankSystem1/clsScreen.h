#pragma once
#include<iostream>
#include"clsDate.h"
#include"GlobalUser.h"
using namespace std;
class clsScreen {
protected:
	static void _DrawScreenHeader(string title, string subtitle="")
	{
		cout << "\t\t\t--------------------------------------------------------------" << endl;
		cout << setw(60) << right << title << endl;
		if (subtitle != "")
		{
			cout << setw(58) << subtitle << endl;
		}
		cout << "\t\t\t---------------------------------------------------------------" << endl;
		//bank extension1
		cout << setw(50)<<right<<"User: " << currentUser.getUserName() << endl;
		clsDate todayDate;
		cout<<setw(50)<<right << "Date: "; todayDate.print();
		}
 };