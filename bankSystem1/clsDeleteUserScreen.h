#pragma once
#include<iostream>
#include"clsBankUser.h";
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsDeleteUserScreen :protected clsScreen {
private:
    static void _print(clsBankUser u)
    {
        cout << "----------------------------------------------" << endl;
        cout << "\t\t Client Card" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "first name: " << u.getFirstName() << endl;
        cout << "last name: " << u.getLastName() << endl;
        cout << "full name: " << u.getFullName() << endl;
        cout << "E-mail: " << u.getEmail() << endl;
        cout << "phone number: " << u.getPhone() << endl;
        cout << "username: " <<u.getUserName() << endl;
        cout << "password: " << u.getPassword() << endl;
        cout << "permissions: " << u.getPermissions() << endl;
    }
public:
    static void deleteUser()
    {
        clsScreen::_DrawScreenHeader("delete user screen");
        string username = "";
        cout << "enter username: ";
        username = clsInputValidate::ReadString("invalid input, try again");
        while (!clsBankUser::isUserExist(username))
        {
            cout << "user is not found, enter another username: ";
            username = clsInputValidate::ReadString("invalid input, try again");
        }
        clsBankUser user = clsBankUser::find(username);
        system("cls");
        _print(user);
        char a;
        cout << "are you sure you want to delete this user y/n: ";
        cin >> a;
        if (a == 'y' || a == 'Y')
        {
            system("cls");
            if (user.Delete())
            {
                cout << "user was deleted successfuly" << endl;
                _print(user);
            }
            else cout << "user was not deleted" << endl;
        }
        else cout << "deleting was cancelled by the user" << endl;

    }
 };