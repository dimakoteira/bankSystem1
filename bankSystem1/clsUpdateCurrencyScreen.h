#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsUpdateCurrencyScreen :protected clsScreen {
private:
    static void _print(clsCurrency curr)
    {
        cout << "\t\t Currency card: " << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Country: " << curr.getCountry() << endl;
        cout << "Currency Code: " << curr.getCurrencyCode() << endl;
        cout << "Currency Name: " << curr.getCurrencyName() << endl;
        cout << "Rate(1$): " << curr.getRate() << endl;
        cout << "----------------------------------------------" << endl;
    }
    static float _readNewRate()
    {
        float rate;
        cout << "enter the new rate: ";
        rate = clsInputValidate::ReadFloatNumber("invalid");
        return rate;
    }
public:
    static void updateCurrencyRate()
    {
        clsScreen::_DrawScreenHeader("Update Currency Screen");
        cout << "enter country code: ";
        string code = clsInputValidate::ReadString("invalid input, try again");
        while (!clsCurrency::isCurrencyExistCode(code))
        {
            cout << "code is not found enter again: ";
            code = clsInputValidate::ReadString("invalid input, try again");
        }
        clsCurrency curr = clsCurrency::findByCode(code);
        _print(curr);
        cout << "are you sure you want to update the rate of this currency y/n? ";
        char answer;
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            curr.updateRate(_readNewRate());
                cout << "rate updated successfuly" << endl;
                _print(curr);
        }
        else cout << "operation was cancelled by the user" << endl;
    }
};

