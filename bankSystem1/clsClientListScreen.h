#pragma once
#include<iostream>
#include"clsBankClient.h";
#include<iomanip>
#include"clsScreen.h"
using namespace std;
class clsClientListScreen :protected clsScreen {
private:
   static void printClientRecord(clsBankClient client)
    {
        cout << client.GetAccountNum() << setw(23) << client.getFirstName() << setw(25) << client.getLastName() << setw(25) << client.getEmail() << setw(20) << client.getPhone() << setw(20) << client.GetSalary() << endl;
    }
public:
   static void showAllClients()
    {
        vector<clsBankClient> v = clsBankClient::getAllClients();
        clsScreen::_DrawScreenHeader("Client List Screen", "of "+to_string(v.size()) + " clients");
        
        cout << "\n\n\n| account number" << setw(20) << "| first name" << setw(20) << "| last name" << setw(20) << "| email" << setw(20) << "| phone" << setw(20) << "| salary |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        if (v.size() != 0)
        {
            for (int i = 0;i < v.size();i++)
            {
                cout << "| "; printClientRecord(v[i]);
            }
        }

        else cout << "\t\t\t\t\tno clients available" << endl;
        cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    }
};
