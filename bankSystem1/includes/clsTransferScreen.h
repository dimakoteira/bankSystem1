#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class clsTransferScreen :protected clsScreen {
private:
	static void _print(clsBankClient c)
	{
		cout << "----------------------------------------------" << endl;
		cout << "\t\t Client Card" << endl;
		cout << "----------------------------------------------" << endl;
		cout << "full name: " << c.getFullName() << endl;
		cout << "account number: " << c.GetAccountNum() << endl;
		cout << "salary: " << c.GetSalary() << endl;
		cout << "----------------------------------------------" << endl;

	}

public:
	static void transfer()
	{
		clsScreen::_DrawScreenHeader("Transfer screen");
		cout << "enter account number you want to transfer from: ";
		string account1 = clsInputValidate::ReadString("invalid input");
		while (!clsBankClient::isClientExist(account1))
		{
			cout << "this client does not exist" << endl;
			 account1 = clsInputValidate::ReadString("invalid input");
		}

		clsBankClient client1 = clsBankClient::find(account1);
		_print(client1);

		cout << "enter the account number you want to transfer to: ";
		string account2 = clsInputValidate::ReadString("invalid input");
		while (!clsBankClient::isClientExist(account2))
		{
			cout << "this client does not exist" << endl;
			account2 = clsInputValidate::ReadString("invalid input");
		}
		while (account1 == account2)
		{
			cout << "you can't enter the same account number" << endl;
			cout << "enter another one: ";
			account2 = clsInputValidate::ReadString("invalid input");

		}
		clsBankClient client2 = clsBankClient::find(account2);
		_print(client2);

		cout << "enter the amount you want to transfer: " ;
		int amount = clsInputValidate::ReadIntNumber("invalid input");
		cout << "are you sure you want to transfer this amount? ";
		char answer;
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (client1.transfer(amount,client2))
			{

				cout << "amount transfered succesfully" << endl;
				_print(client1); _print(client2);
			}
			else cout << "you don't have enough money in the account" << endl;
		}
		else cout << "operation was cancelled by the user" << endl;
	}

	
};

