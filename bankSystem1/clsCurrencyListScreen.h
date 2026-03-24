#pragma once
#include<iostream>
#include"clsCurrency.h"
#include<iomanip>
#include"clsScreen.h"
#include<vector>
using namespace std;
class clsCurrencyListScreen :protected clsScreen {
private:
    static void printCurrencyRecord(clsCurrency curr)
    {
        cout << left << setw(30) <<curr.getCountry();
        cout << "| " << left << setw(25) << curr.getCurrencyCode();
        cout << "| " << left << setw(40) << curr.getCurrencyName();
        cout << "| " << left << setw(25) << curr.getRate() << " |" << endl;
    }
public:
    static void showAllCurrencies()
    {
        vector<clsCurrency> v = clsCurrency::getAllCurrencies();
        clsScreen::_DrawScreenHeader("Currencies List Screen", "of " + to_string(v.size()) + " country");

        cout << "\n\n" << string(115, '-') << endl; // سطر فاصل علوي
        cout << "| " << left << setw(30) << "Country"
            << "| " << left << setw(25) << "Curreny code"
            << "| " << left << setw(40) << "Currency Name"
            << "| " << left << setw(25) << "Rate(1$)"<< " |" << endl;
        cout << string(115, '-') << endl;
        if (v.size() != 0)
        {
            for (int i = 0;i < v.size();i++)
            {
                cout << "| "; printCurrencyRecord(v[i]);
            }
        }

        else cout << "\t\t\t\t\tno countries available" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
};
