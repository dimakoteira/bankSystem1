#pragma once  
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h";
#include"clsInputValidate.h"
using namespace std;
class clsDepositScreen :protected clsScreen {
private:
	static void _print(clsBankClient c)
	{
		cout << "----------------------------------------------" << endl;
		cout << "\t\t Client Card" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "first name: " << c.getFirstName() << endl;
		cout << "last name: " << c.getLastName() << endl;
		cout << "full name: " << c.getFullName() << endl;
		cout << "E-mail: " << c.getEmail() << endl;
		cout << "phone number: " << c.getPhone() << endl;
		cout << "account number: " << c.GetAccountNum() << endl;
		cout << "pin code: " << c.GetPinCode() << endl;
		cout << "salary: " << c.GetSalary() << endl;
	}
	static int _DepositAmount()
	{
		int am;
		cout << "enter the amount you want to deposit: ";
		am = clsInputValidate::ReadIntNumber("invalid input, try again");
		return am;
	}
public:
	static void showDepositScreen()
	{
		clsScreen::_DrawScreenHeader("Deposit Screen");
		cout << "enter account number: ";
		string acc = clsInputValidate::ReadString("invaild, try again");
		while (!clsBankClient::isClientExist(acc))
		{
			cout << "client not found, enter another account";
			 acc = clsInputValidate::ReadString("invaild, try again");
		}
		clsBankClient client = clsBankClient::find(acc);
		_print(client);
			int amount=_DepositAmount();
			cout << "are you sure you want to deposit this amount? ";
			char answer;
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				client.deposit(amount);
				cout << "amount deposited succesfully" << endl;
				cout << "new balance is: " << client.GetSalary() << endl;
			}
			else cout << "operation was cancelled by the user" << endl;
	}
};

