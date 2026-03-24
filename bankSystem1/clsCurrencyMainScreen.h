#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsCurrencyListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculator.h"
using namespace std;

class clsCurrencyMainScreen : protected clsScreen {
private:
	enum _enCurrencyMenuOption{listCurr=1, findCurr=2, updateRate=3, currCal=4};
	static short _ReadMenuOption()
	{
		cout << "Choose what do you want to do[1 - 5]: ";
		short choice = clsInputValidate::ReadShortNumberBetween(1,5,"invalid input, try again");
		return choice;
	}
	void static _showListCurrScreen()
	{
		clsCurrencyListScreen::showAllCurrencies();
	}
	void static _showFindCurrScreen()
	{
		clsFindCurrencyScreen::findCurrency();
	}
	void static _showUpdateRateScreen()
	{
		clsUpdateCurrencyScreen::updateCurrencyRate();
	}
	void static _showCurrCalcScreen()
	{
		clsCurrencyCalculator::calculate();
	}
	void static _goBackToCurrMenu()
	{
		cout << "press any key to go back to currency main menu"<<endl;
		system("pause");
		showCurrencyMainMenu();
	}
	static void _performMenuOption(_enCurrencyMenuOption op)
	{
		switch (op)
		{
		case _enCurrencyMenuOption::listCurr:
			system("cls");
			_showListCurrScreen();
			_goBackToCurrMenu();
			break;

		case _enCurrencyMenuOption::findCurr:
			system("cls");
			_showFindCurrScreen();
			_goBackToCurrMenu();
			break;

		case _enCurrencyMenuOption::updateRate:
			system("cls");
			_showUpdateRateScreen();
			_goBackToCurrMenu();
			break;

		case _enCurrencyMenuOption::currCal:
			system("cls");
			_showCurrCalcScreen();
			_goBackToCurrMenu();
			break;

		}
	}
public:
	static void showCurrencyMainMenu()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("Currency Exchange Main Screen");
		cout << "\t\t\t===============================================================" << endl;
		cout << setw(57) << "Currency Exchange Menu" << endl;
		cout << "\t\t\t===============================================================" << endl;
		cout << "\t\t\t[1] List Currencies." << endl;
		cout << "\t\t\t[2] Find Currency." << endl;
		cout << "\t\t\t[3] Update Rate." << endl;
		cout << "\t\t\t[4] Currency Calculator." << endl;
		cout << "\t\t\t[5] Main Menu." << endl;
		cout << "\t\t\t===============================================================" << endl;
		_performMenuOption(_enCurrencyMenuOption(_ReadMenuOption()));
	}
};
