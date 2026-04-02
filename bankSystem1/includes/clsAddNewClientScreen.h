#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsBankClient.h";
#include"clsInputValidate.h";
using namespace std;
class clsAddNewClientScreen :protected clsScreen{
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
       cout << "account number: " << c.GetAccountNum()<< endl;
       cout << "pin code: " << c.GetPinCode() << endl;
       cout << "salary: " << c.GetSalary() << endl;
   }
public:
   static void addClient()
    {
       clsScreen::_DrawScreenHeader("Add New Client Screen");
        string account = "";
        cout << "enter account number: ";
        account = clsInputValidate::ReadString("invalid input, try again");
        while (clsBankClient::isClientExist(account))
        {
            cout << "client already exist, try with a different account number: ";
            account = clsInputValidate::ReadString("invalid input, try again");
        }
        clsBankClient newClient = clsBankClient::getAddNewClientObject(account);
        ReadClientInfo(newClient);
        clsBankClient::enSaveResult res = newClient.saveClient();
        switch (res)
        {
        case clsBankClient::enSaveResult::svSucceede:
            cout << "client was added successfuly" << endl;
            _print(newClient);
            break;
        case clsBankClient::enSaveResult::svFailEmptyObj:
            cout << "can't add empty client" << endl;
            break;
        case clsBankClient::enSaveResult::svFailAccountExist:
            cout << "client already exist" << endl;
            break;
        }


    }
};
