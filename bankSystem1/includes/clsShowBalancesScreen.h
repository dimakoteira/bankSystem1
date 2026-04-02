#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h";
#include<iomanip>
#include<vector>
#include"util.h";
using namespace std;
class clsShowBalancesScreen :protected clsScreen {
private:
  static void _printClientBalance(clsBankClient client)
    {
        cout << client.GetAccountNum() << setw(34) << client.getFullName() << setw(21) << client.GetSalary() << endl;
    }
public:

   static void showAllBalances()
    {
        vector<clsBankClient> v = clsBankClient::getAllClients();
        string subtitle = "of " + to_string(v.size()) + " clients";
        clsScreen::_DrawScreenHeader("Show All Balances Screen",subtitle);
        cout << "| Account number" << setw(20) << "| full name" << setw(25) << "| balance |" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------" << endl;
        if (v.size() != 0) {
            for (int i = 0;i < v.size();i++)
            {
                _printClientBalance(v[i]);
            }
        }
        else cout << "no clients available" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------" << endl;
        float s = clsBankClient::getTotalSalary();
        cout << "total salaries: " << s << endl;
        cout << clsUtil::num_to_text(s) << " dollars" << endl;
    }

};
