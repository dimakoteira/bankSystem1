#pragma once
#include<iostream>
#include"clsBankClient.h";
#include"clsScreen.h";
#include"clsInputValidate.h"
class clsFindClientScreen :protected clsScreen {
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
        static void FindClient()
        {
            clsScreen::_DrawScreenHeader("Find Client Screen");
           
            cout << "enter an account number: ";
            string acc,pin;
            acc = clsInputValidate::ReadString("invalid input, try again");
           

                clsBankClient client = clsBankClient::find(acc);
                if (client.isEmpty())
                {
                    cout << "client is not found" << endl;
                }
                _print(client);
            }
        
};
