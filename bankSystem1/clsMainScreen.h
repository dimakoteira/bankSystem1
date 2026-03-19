#pragma once
#include<iostream>
#include"clsInputValidate.h";
#include "clsScreen.h";
#include"clsClientListScreen.h";
#include"clsAddNewClientScreen.h";
#include"clsDeleteClientScreen.h";
#include"clsUpdateClientScreen.h";
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h";
#include"clsManageUsersScreen.h";


using namespace std;
class clsMainScreen :protected clsScreen{
private:
	enum enMainMenuOptions{ ShowClientList = 1, AddNewClient = 2,DeleteClient = 3,UpdateClient = 4,FindClient = 5, Transaction = 6,ManageUsers = 7,Logout = 8 };
		static short _ReadMainMenuOption()
	    {				  
		cout << "Choose what do you want to do[1 - 8]: ";
		int choice =  clsInputValidate::ReadShortNumberBetween(1, 8, "number is not between 1 and 8");
		return choice;
	    }

		void static _showAllClientScreen()
		{
			clsClientListScreen::showAllClients();
		}
		void static _showAddNewClientScreen()
		{
			clsAddNewClientScreen::addClient();
		}
		void static _showDeleteClientScreen()
		{
			clsDeleteClientScreen::deleteClient();
		}
		void static _showUpdateClientScreen()
		{
			clsUpdateClientScreen::updateClient();
		}
		void static _showFindClientScreen()
		{
			clsFindClientScreen::FindClient();
		}
		void static _showTransactionScreen()
		{
			clsTransactionScreen::showTransactionMenu();
		}
		void static _showManageUsersScreen()
		{
			clsManageUsersScreen::showManageUsersScreen();
		}
		void static _showLogOutScreen()
		{

			
		}

		void static _goBackToMainMenu()
		{
			cout << "press any key to go back to main menu" << endl;
			system("pause>0");
			ShowMainMenu();
		}
		static void _performMainMenuOption(enMainMenuOptions eOP)
		{
			switch (eOP)
			{
			case enMainMenuOptions::ShowClientList:
				system("cls");
				_showAllClientScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::AddNewClient:
					system("cls");
					_showAddNewClientScreen();
					_goBackToMainMenu();
					break;

			case enMainMenuOptions::DeleteClient:
				system("cls");
				_showDeleteClientScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::UpdateClient:
				system("cls");
				_showUpdateClientScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::FindClient:
				system("cls");
				_showFindClientScreen();
				_goBackToMainMenu();
				break;

			/*case enMainMenuOptions::ShowAllBalances:
				system("cls");
				_showAllBalancesScreen();
				_goBackToMainMenu();
				break;*/

			case enMainMenuOptions::Transaction:
				system("cls");
				_showTransactionScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::ManageUsers:
				system("cls");
				_showManageUsersScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::Logout:
				system("cls");
				_showLogOutScreen();
				_goBackToMainMenu();
				break;
			}
		}
public:
	static void ShowMainMenu()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("Main Screen");
		cout << "\t\t\t===============================================================" << endl;
		cout << setw(57) << "Main Menu" << endl;
		cout << "\t\t\t===============================================================" << endl;

		cout << "\t\t\t[1] Show Client List." << endl;
		cout << "\t\t\t[2] Add New Client." << endl;
		cout << "\t\t\t[3] Delete Client." << endl;
		cout << "\t\t\t[4] Update Client Info." << endl;
		cout << "\t\t\t[5] Find Client." << endl;
		cout << "\t\t\t[6] Transaction." << endl;
		cout << "\t\t\t[7] Manage Users." << endl;
		cout << "\t\t\t[8] Logout." << endl;
		cout << "\t\t\t=================================================================" << endl;
		_performMainMenuOption(enMainMenuOptions(_ReadMainMenuOption()));
	}
};
