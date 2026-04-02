#pragma once
#include<iostream>
#include"clsBankUser.h";
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
 
class clsAddNewUserScreen :protected clsScreen {
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
    static int calculatePermissions()
    {
        int perm = 0;
        char answer;
        if(_getAnswer("do you want to giv full access? y/n: "))
            return - 1;
        if (_getAnswer("so do you want to give access to:\n //show client list//: "))
            perm += clsBankUser::enMainMenuPermmision::eShowClientList;
        if (_getAnswer(" \n //add new client//: "))
           perm += clsBankUser::enMainMenuPermmision::eAddNewClient;
        if (_getAnswer("\n //delete client//: "))
            perm += clsBankUser::enMainMenuPermmision::eDeleteClient;
        if (_getAnswer("\n //update client//: "))
            perm += clsBankUser::enMainMenuPermmision::eUpdateClient;
        if (_getAnswer("\n //find client//: "))
            perm += clsBankUser::enMainMenuPermmision::eFindClient;
        if (_getAnswer("\n //transaction//: "))
            perm += clsBankUser::enMainMenuPermmision::eTransaction;
        if (_getAnswer("\n //manage users//: "))
            perm += clsBankUser::enMainMenuPermmision::eManageUsers;
        if (_getAnswer("\n //currency exchange//: "))
            perm += clsBankUser::enMainMenuPermmision::eCurrencyExchange;
        if (_getAnswer("\n //register logins screen//: "))
            perm += clsBankUser::enMainMenuPermmision::eRegisterLogin;
        return perm;
    }
    static void ReadUserInfo(clsBankUser& user)
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
        cout << "\nenter permissions:\n ";
        user.setPermissions(calculatePermissions());
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
        cout << "password: " << u.getPassword() << endl;
        cout << "username: " << u.getUserName() << endl;
        cout << "permission: " << u.getPermissions() << endl;
    }

public:
    static void addUser()
    {
        clsScreen::_DrawScreenHeader("Add New User Screen");
        string username = "";
        cout << "enter username: ";
        username= clsInputValidate::ReadString("invalid input, try again");
        while (clsBankUser::isUserExist(username))
        {
            cout << "user already exist, try with a different username: ";
            username = clsInputValidate::ReadString("invalid input, try again");
        }
        clsBankUser newUser = clsBankUser::getAddNewUserObject(username);
        ReadUserInfo(newUser);
        clsBankUser::enSaveResult res = newUser.saveUser();
        switch (res)
        {
        case clsBankUser::enSaveResult::svSucceede:
            cout << "user was added successfuly" << endl;
            _print(newUser);
            break;
        case clsBankUser::enSaveResult::svFailEmptyObj:
            cout << "can't add empty user" << endl;
            break;
        case clsBankUser::enSaveResult::svFailAccountExist:
            cout << "user already exist" << endl;
            break;
        }


    }
};