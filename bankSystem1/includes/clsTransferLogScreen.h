#pragma once
#include<iostream>
#include"clsBankClient.h";
#include"clsScreen.h"
#include<iomanip>
using namespace std;

class clsTransferLogScreen :protected clsScreen {
private:
    static void printLogRecord(clsBankClient::sTransferLog rec)
    {
        cout << "" << left << setw(23) << rec.dateTime;
        cout << "| " << left << setw(12) << rec.sAccount;
        cout << "| " << left << setw(12) << rec.dAccount;
        cout << "| " << left << setw(13) << rec.amount;
        cout << "| " << left << setw(12) << rec.sBalance;
        cout << "| " << left << setw(12) << rec.dBalance;
        cout << "| " << left << setw(12) << rec.username << " |" << endl;
    }
public:
    static void showAllLogs()
    {
        vector <clsBankClient::sTransferLog> v = clsBankClient::getAllLogs();
        clsScreen::_DrawScreenHeader("Transfer Log Screen", "of " + to_string(v.size()) + " Record(s)");

        cout << "\n\n" << string(120, '-') << endl; // سطر فاصل علوي
        cout << "| " << left << setw(23) << "Date/Time"
            << "| " << left << setw(12) << "s.Acc"
            << "| " << left << setw(12) << "d.Acc"
            << "| " << left << setw(12) << "Amount"
            << "| " << left << setw(12) << "s.Balance"
            << "| " << left << setw(12) << "d.Balance"
            << "| " << left << setw(12) << "User" << endl;

        cout << string(120, '-') << endl;
        if (v.size() != 0)
        {
            for (int i = 0;i < v.size();i++)
            {
                cout << "| "; printLogRecord(v[i]);
            }
        }

        else cout << "\t\t\t\t\tno Users available" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
};
