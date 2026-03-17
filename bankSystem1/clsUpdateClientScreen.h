#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
class clsUpdateClientScreen :protected clsScreen {
private:
    static void ReadClientInfo(clsBankClient& client)
    {

        cout << "enter first name: ";
        client.setFirstName(clsInputValidate::ReadString("invalid input try again"));
        cout << "\n enter last name: ";
        client.setLastName(clsInputValidate::ReadString("invalid input try again"));
        cout << "\n enter Email: ";
        client.setEmail(clsInputValidate::ReadString("invalid input try again"));
        cout << "\nenter phone number: ";
        client.setPhone(clsInputValidate::ReadString("invalid input try again"));
        cout << "\nenter pin code: ";
        client.SetPinCode(clsInputValidate::ReadString("invalid input try again"));
        cout << "\n enter salary: ";
        client.SetSalary(clsInputValidate::ReadFloatNumber("invalid input try again"));
    }
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
  static void updateClient()
    {
      clsScreen::_DrawScreenHeader("Update Client Screen");
        cout << "please enter account number: ";
        string account;
        account = clsInputValidate::ReadString("invalid input try again");
        while (!clsBankClient::isClientExist(account))
        {
            cout << "client not found enter another account number: ";
            account = clsInputValidate::ReadString("invalid input try again");
        }
        clsBankClient client = clsBankClient::find(account);
        system("cls");
       _print(client);
        char a;
        cout << "are you sure you want to update this client y/n: ";
        cin >> a;
        if (a == 'y' || a == 'Y') {
            system("cls");
            cout << "------------------------------" << endl;
            cout << "\t Update Client" << endl;
            cout << "------------------------------" << endl;
            ReadClientInfo(client);

            clsBankClient::enSaveResult res = client.saveClient();
            switch (res)
            {
                system("cls");
            case clsBankClient::enSaveResult::svSucceede:
                cout << "client was updated successfuly" << endl;
                _print(client);break;
            case clsBankClient::enSaveResult::svFailEmptyObj:
                cout << "error client was not updated " << endl;
                break;
            }
        }
        else cout << "updating was cancelled by the user" << endl;

    }


};
