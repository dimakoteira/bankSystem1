#pragma once
#include<iostream>
#include"clsBankUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsFindUserScreen :protected clsScreen {
private:
    static void _print(clsBankUser u)
    {
        cout << "----------------------------------------------" << endl;
        cout << "\t\t User Card" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "first name: " << u.getFirstName() << endl;
        cout << "last name: " << u.getLastName() << endl;
        cout << "full name: " << u.getFullName() << endl;
        cout << "E-mail: " << u.getEmail() << endl;
        cout << "phone number: " << u.getPhone() << endl;
        cout << "username: " << u.getUserName() << endl;
        cout << "password: " << u.getPassword() << endl;
        cout << "permissions: " << u.getPermissions() << endl;
    }
public:
    static void FindUser()
    {
        clsScreen::_DrawScreenHeader("Find User Screen");

        cout << "enter an username: ";
        string username;
        username = clsInputValidate::ReadString("invalid input, try again");


        clsBankUser user = clsBankUser::find(username);
        if (user.IsEmpty())
        {
            cout << "user is not found" << endl;
        }
        _print(user);
    }
};