#pragma once
#include<iostream>
#include"ClsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
class clsCurrencyCalculator :protected clsScreen {
	static void _print(clsCurrency curr)
	{
		cout << "--------------------------------------------------------------------------" << endl;		
		cout << "Country: " << curr.getCountry() << endl;
		cout << "Currency Code: " << curr.getCurrencyCode() << endl;
		cout << "Currency Name: " << curr.getCurrencyName() << endl;
		cout << "Rate(1$): " << curr.getRate() << endl;
		cout << "--------------------------------------------------------------------------" << endl;		
	}

	static clsCurrency _getCurrency(string message)
	{
		string code;
		cout << message ;
		code = clsInputValidate::ReadString("invalid");
		while (!clsCurrency::isCurrencyExistCode(code))
		{
			cout << "not found, enter again: ";
			code = clsInputValidate::ReadString("invalid");
		}
		clsCurrency curr = clsCurrency::findByCode(code);
		return curr;

	}
	static void _printCalResult(float amount, clsCurrency from, clsCurrency to)
	{
		cout << "from: " << endl;
		_print(from);
		cout << "to: " << endl;
		_print(to);
		float amountInUSD = from.convertToUSD(amount);
		cout << amount << " " << from.getCurrencyCode() << " = " << amountInUSD << "USD" << endl;
		if (to.getCurrencyCode() == "USD")
			return;
		cout << "converting from USD to: " << endl;
		_print(to);
		float amountInCurr2= from.convertToOtherCurrency(amount, to);
		cout << amount << " " << from.getCurrencyCode() << " = " << amountInCurr2 << " " << to.getCurrencyCode();


	}
public:
	static void calculate()
	{
		
		char answer='y';
		while(answer=='y'||answer=='Y') {
			system("cls");
			clsScreen::_DrawScreenHeader("Calculator Screen");

			clsCurrency fromCurr=_getCurrency("enter currency1 code: ");
			
			clsCurrency toCurr = _getCurrency("enter currency2 code: ");
			

			cout << "enter the amount to calculate: ";
			float amount = clsInputValidate::ReadFloatNumber("invalid input, try again");
			_printCalResult(amount, fromCurr, toCurr);
			cout << "\n\n do you want to perform another calculation? y/n ";
			cin >> answer;
		}
	}
};