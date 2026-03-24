#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;
class clsFindCurrencyScreen :protected clsScreen {
private:
	static void _print(clsCurrency curr)
	{
        cout << "----------------------------------------------" << endl;
        cout << "\t\t Currency" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Country: " << curr.getCountry() << endl;
        cout << "Currency Code: " <<curr.getCurrencyCode() << endl;
        cout << "Currency Name: " << curr.getCurrencyName() << endl;
        cout << "Rate(1$): " << curr.getRate() << endl;
	}
public:
    static void findCurrency()
    {
        clsScreen::_DrawScreenHeader("Find Currency Screen");
        cout << "find currency by [1]: country or [2]: code? ";
        short choice = clsInputValidate::ReadShortNumberBetween(1, 2, "invalid input, try again");
        if (choice == 1)
        {
            cout << "enter country name: ";
            string country = clsInputValidate::ReadString("invaild input, try again");
            while (!clsCurrency::isCurrencyExistCountry(country))
            {
                cout << "country not found, enter again: ";
                country = clsInputValidate::ReadString("invaild input, try again");
            }
            clsCurrency curr = clsCurrency::findByCountry(country);
            if (curr.isEmpty())
                cout << "currency not found" << endl;
            _print(curr);
        }
        else {
            cout << "enter currency code: ";
            string code = clsInputValidate::ReadString("invalid input, try again");
            while (!clsCurrency::isCurrencyExistCode(code))
            {
                cout << "code not found, enter again: ";
                code = clsInputValidate::ReadString("invalid input, try again");
            }
            clsCurrency curr = clsCurrency::findByCode(code);
            if (curr.isEmpty())
            {
                cout << "currency not found" << endl;
            }
            _print(curr);
        }
    }
};
