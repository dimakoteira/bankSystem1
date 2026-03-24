#pragma once
#include<iostream>
#include"clsBankUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsUpdateUserScreen :protected clsScreen {
private:
    static bool _getAnswer(string s)
    {
        char an;
        cout << s;
        cin >> an;
        if (an == 'y' || an == 'Y')
            return true;
        return false;
    }
    static int _calculatePermissions()
    {
        int perm = 0;
        char answer;
        if (_getAnswer("do you want to giv full access y/n: "))
            return -1;
        if (_getAnswer("so do you want to give access to:\n permession to //show client list//: "))
            perm += clsBankUser::enMainMenuPermmision::eShowClientList;
        if (_getAnswer("permission to //add new client//: "))
            perm += clsBankUser::enMainMenuPermmision::eAddNewClient;
        if (_getAnswer("permission to //delete client//: "))
            perm += clsBankUser::enMainMenuPermmision::eDeleteClient;
        if (_getAnswer("permission to //update client//: "))
            perm += clsBankUser::enMainMenuPermmision::eUpdateClient;
        if (_getAnswer("permission to //find client//: "))
            perm += clsBankUser::enMainMenuPermmision::eFindClient;
        if (_getAnswer("permission to //transaction client//: "))
            perm += clsBankUser::enMainMenuPermmision::eTransaction;
        if (_getAnswer("permission to //manage users//: "))
            perm += clsBankUser::enMainMenuPermmision::eManageUsers;
        return perm;
    }
    static void _ReadUserInfo(clsBankUser& user)
    {
        cout << "enter first name: ";
        user.setFirstName(clsInputValidate::ReadString("invalid input try again"));
        cout << "\n enter last name: ";
        user.setLastName(clsInputValidate::ReadString("invalid input try again"));
        cout << "\n enter Email: ";
        user.setEmail(clsInputValidate::ReadString("invalid input try again"));
        cout << "\nenter phone number: ";
        user.setPhone(clsInputValidate::ReadString("invalid input try again"));
        cout << "\nenter password: ";
        user.setPassword(clsInputValidate::ReadString("invalid input try again"));
        cout << "\n enter permessions: ";
        user.setPermissions(_calculatePermissions());
    }
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
    static void updateUser()
    {
        clsScreen::_DrawScreenHeader("Update User Screen");
        cout << "please enter Username: ";
        string username;
        username = clsInputValidate::ReadString("invalid input try again");
        while (!clsBankUser::isUserExist(username))
        {
            cout << "user not found enter another username: ";
            username = clsInputValidate::ReadString("invalid input try again");
        }
        clsBankUser user = clsBankUser::find(username);
        system("cls");
        _print(user);
        char a;
        cout << "are you sure you want to update this user y/n: ";
        cin >> a;
        if (a == 'y' || a == 'Y') {
            _ReadUserInfo(user);
            clsBankUser::enSaveResult res = user.saveUser();
            switch (res)
            {
            case clsBankUser::enSaveResult::svSucceede:
                cout << "uaer was updated successfuly" << endl;
                _print(user);break;
            case clsBankUser::enSaveResult::svFailEmptyObj:
                cout << "error user was not updated " << endl;
                break;
            }
        }
        else cout << "updating was cancelled by the user" << endl;

    }


};
