#pragma once
#include<iostream>
#include"clsBankUser.h";
#include"clsScreen.h"
using namespace std;
class clsRegisterLoginScreen :protected clsScreen {
private:
    static void printLoginRecord(clsBankUser::stLoginRegister rec)
    {
        cout << "| " << left << setw(25) << rec.date;
        cout << "| " << left << setw(25) << rec.password;
        cout << "| " << left << setw(15) << rec.username;
        cout << "| " << left << setw(15) << rec.perm<< " |" << endl;
    }
public:
    static void showAllLogins()
    {
        vector <clsBankUser::stLoginRegister> v = clsBankUser::getAllLogins();
        clsScreen::_DrawScreenHeader("Logins List Screen", "of " + to_string(v.size()) + " users");

        cout << "\n\n" << string(115, '-') << endl; // سطر فاصل علوي
        cout << "| " << left << setw(25) << "Date/Time"
            << "| " << left << setw(25) << "Password"
            << "| " << left << setw(15) << "Username"
            << "| " << left << setw(15) << "Permissions" << endl;
           
        cout << string(115, '-') << endl;
        if (v.size() != 0)
        {
            for (int i = 0;i < v.size();i++)
            {
                cout << "| "; printLoginRecord(v[i]);
            }
        }

        else cout << "\t\t\t\t\tno Users available" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
};