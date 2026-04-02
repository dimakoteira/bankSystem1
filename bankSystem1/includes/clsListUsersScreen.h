#pragma once
#include<iostream>
#include"clsBankUser.h";
#include"clsScreen.h"
#include<iomanip>
using namespace std;
class clsListUserScreen :protected clsScreen {
private:
    static void printUserRecord(clsBankUser user)
    {
        cout << "| " << left << setw(25) << user.getFullName();
        cout << "| " << left << setw(25) << user.getEmail();
        cout << "| " << left << setw(15) << user.getPhone();
        cout << "| " << left << setw(15) << user.getUserName();
        cout << "| " << left << setw(12) << user.getPassword();
        cout << "| " << left << setw(12) << user.getPermissions() << " |" << endl;
    }
public:
    static void showAllUsers()
    {vector <clsBankUser> v = clsBankUser::getAllUsers();
        clsScreen::_DrawScreenHeader("Users List Screen", "of " + to_string(v.size()) + " users");

        cout << "\n\n" << string(115, '-') << endl; // سطر فاصل علوي
        cout << "| " << left << setw(25) << "Full Name"
            << "| " << left << setw(25) << "Email"
            << "| " << left << setw(15) << "Phone"
            << "| " << left << setw(15) << "Username"
            << "| " << left << setw(12) << "Password"
            << "| " << left << setw(12) << "Permissions" << " |" << endl;
        cout << string(115, '-') << endl;
        if (v.size() != 0)
        {
            for (int i = 0;i < v.size();i++)
            {
                cout << "| "; printUserRecord(v[i]);
            }
        }

        else cout << "\t\t\t\t\tno Users available" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    }
};
