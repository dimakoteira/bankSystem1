#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsInputValidate.h";
#include"clsDepositScreen.h";
#include"clsWithdrawScreen.h"
#include"clsShowBalancesScreen.h"
#include"clsTransferScreen.h"
using namespace std;

class clsTransactionScreen :protected clsScreen {
private:

	enum enTransactionOptions { deposit = 1, withdraw = 2, allBalances = 3,transfer=4, goBack = 5 };

	 short static _ReadOption()
	{
		short choice;
		cout << "choose what do you want [1-5]: ";
		choice = clsInputValidate::ReadShortNumberBetween(1, 5,"invalid try again");
		return choice;
	}

	void static _showDepositScreen()
	{
		clsDepositScreen::showDepositScreen();
	}

	void static _showWithdrawScreen()
	{
		clsDWithdrawScreen::showWithdrawScreen();
	}

	void static _showTransferScreen()
	{
		clsTransferScreen::transfer();
	}

	void static _showAllBalancesScreen()
	{
		clsShowBalancesScreen::showAllBalances();
	}
	void static _goBackToTransactionMenu()
	{
		cout << "press any key to go back to transaction menu.." << endl;
		system("pause>0");
		showTransactionMenu();
	}
	  void static _performTransactionOption(enTransactionOptions op)
	{
		switch (op)
		{
		case enTransactionOptions::deposit:
			system("cls");
			_showDepositScreen();
			_goBackToTransactionMenu();
			break;

		case enTransactionOptions::withdraw:
			system("cls");
			_showWithdrawScreen();
			_goBackToTransactionMenu();
			break;

		case enTransactionOptions::transfer:
			system("cls");
			_showTransferScreen();
			_goBackToTransactionMenu();
			break;

		case enTransactionOptions::allBalances:
			system("cls");
			_showAllBalancesScreen();
			_goBackToTransactionMenu();
			break;
		}
	}

public:
	static void showTransactionMenu(){
		system("cls");
		clsScreen::_DrawScreenHeader("Transaction Screen");
		cout << "\t\t\t===============================================================" << endl;
		cout << setw(57) << "Transaction Menu" << endl;
		cout << "\t\t\t===============================================================" << endl;
		cout << "\t\t\t[1] Deposit." << endl;
		cout << "\t\t\t[2] Withdraw." << endl;
		cout << "\t\t\t[3] Show Total Balances." << endl;
		cout << "\t\t\t[4] Transfer." << endl;
		cout << "\t\t\t[5] Go Back To Main menu." << endl;
		cout << "\t\t\t===============================================================" << endl;

		_performTransactionOption(enTransactionOptions(_ReadOption()));
		
	}
};