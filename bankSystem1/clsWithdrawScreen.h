#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h";
#include"clsInputValidate.h"
using namespace std;
class clsDWithdrawScreen :protected clsScreen {
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
	static int _WithdrawAmount()
	{
		int am;
		cout << "\n enter the amount you want to Withdraw: ";
		am = clsInputValidate::ReadIntNumber("invalid input, try again");
		return am;
	}
public:
	static void showWithdrawScreen()
	{
		clsScreen::_DrawScreenHeader("Withdraw Screen");
		cout << "enter account number: ";
		string acc = clsInputValidate::ReadString("invaild, try again");
		while (!clsBankClient::isClientExist(acc))
		{
			cout << "client not found, enter another account";
			acc = clsInputValidate::ReadString("invaild, try again");
		}
		clsBankClient client = clsBankClient::find(acc);
		_print(client);
		int amount = _WithdrawAmount();
		cout << "are you sure you want to Withdraw this amount? ";
		char answer;
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (client.withdraw(amount)) {

				cout << "amount withdrawed succesfully" << endl;
				cout << "new balance is: " << client.GetSalary() << endl;
			}
			else cout << "you don't have enough money in the account" << endl;
		}
		else cout << "operation was cancelled by the user" << endl;
	}
};


