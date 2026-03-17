#pragma once
#include<iostream>
#include"clsBankClient.h";
#include"clsScreen.h";
#include"clsInputValidate.h";
class clsDeleteClientScreen :protected clsScreen {
private:
    static void _print(clsBankClient c)
    {
        cout << "----------------------------------------------" << endl;
        cout << "\t\t Client Card" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "first name: " << c.getFirstName() << endl;
        cout << "last name: " << c.getLastName() << endl;
        cout << "full name: " << c.getFullName() << endl;
        cout << "E-mail: " << c.getEmail() << endl;
        cout << "phone number: " << c.getPhone() << endl;
        cout << "account number: " << c.GetAccountNum() << endl;
        cout << "pin code: " << c.GetPinCode() << endl;
        cout << "salary: " << c.GetSalary() << endl;
    }
public:
   static void deleteClient()
    {
       clsScreen::_DrawScreenHeader("delete client screen");
        string account = "";
        cout << "enter account number: ";
        account = clsInputValidate::ReadString("invalid input, try again");
        while (!clsBankClient::isClientExist(account))
        {
            cout << "client is not found, enter another account number: ";
            account = clsInputValidate::ReadString("invalid input, try again");
        }
        clsBankClient client = clsBankClient::find(account);
        system("cls");
        _print(client);
        char a;
        cout << "are you sure you want to delete this client y/n: ";
        cin >> a;
        if (a == 'y' || a == 'Y')
        {
            system("cls");
            if (client.Delete())
            {
                cout << "client was deleted successfuly" << endl;
                _print(client);
            }
            else cout << "client was not deleted" << endl;
        }
        else cout << "deleting was cancelled by the user" << endl;

    }

};
