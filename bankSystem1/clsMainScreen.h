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
#include"GlobalUser.h"
#include"clsRegisterLoginScreen.h"
#include"clsCurrencyMainScreen.h"
using namespace std;
class clsMainScreen :protected clsScreen{
private:
	enum enMainMenuOptions{ ShowClientList = 1, AddNewClient = 2,DeleteClient = 3,UpdateClient = 4,FindClient = 5, Transaction = 6,ManageUsers = 7,RegisterLogin=8,currencyExchange=9,Logout = 10 };
		static short _ReadMainMenuOption()
	    {				  
		cout << "Choose what do you want to do[1 - 10]: ";
		int choice =  clsInputValidate::ReadShortNumberBetween(1, 10, "number is not between 1 and 10 \n enter a vaild choice");
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
		void static _showRegisterLoginScreen()
		{
			clsRegisterLoginScreen::showAllLogins();
		}
		void static _showCurrencyExchangeScreen()
		{
			clsCurrencyMainScreen::showCurrencyMainMenu();
		}
		void static _showLogOutScreen()
		{
			currentUser = clsBankUser::find("", "");
			//it will go back to main menu
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
				if (!currentUser.checkAccessPerm(clsBankUser::enMainMenuPermmision::eShowClientList))
				{
					cout << "access denied to this user" << endl;
					_goBackToMainMenu();
					break;
				}
				system("cls");
				_showAllClientScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::AddNewClient:
				if (!currentUser.checkAccessPerm(clsBankUser::enMainMenuPermmision::eAddNewClient))
				{
					cout << "access denied to this user" << endl;
					_goBackToMainMenu();
					break;
				}
					system("cls");
					_showAddNewClientScreen();
					_goBackToMainMenu();
					break;

			case enMainMenuOptions::DeleteClient:
				if (!currentUser.checkAccessPerm(clsBankUser::enMainMenuPermmision::eDeleteClient))
				{
					cout << "access denied to this user" << endl;
					_goBackToMainMenu();
					break;
				}
				system("cls");
				_showDeleteClientScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::UpdateClient:
				if (!currentUser.checkAccessPerm(clsBankUser::enMainMenuPermmision::eUpdateClient))
				{
					cout << "access denied to this user" << endl;
					_goBackToMainMenu();
					break;
				}
				system("cls");
				_showUpdateClientScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::FindClient:
				if (!currentUser.checkAccessPerm(clsBankUser::enMainMenuPermmision::eFindClient))
				{
					cout << "access denied to this user" << endl;
					_goBackToMainMenu();
					break;
				}
				system("cls");
				_showFindClientScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::Transaction:
				if (!currentUser.checkAccessPerm(clsBankUser::enMainMenuPermmision::eTransaction))
				{
					cout << "access denied to this user" << endl;
					_goBackToMainMenu();
					break;
				}
				system("cls");
				_showTransactionScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::ManageUsers:
				if (!currentUser.checkAccessPerm(clsBankUser::enMainMenuPermmision::eManageUsers))
				{
					cout << "access denied to this user" << endl;
					_goBackToMainMenu();
					break;
				}
				system("cls");
				_showManageUsersScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::Logout:
				system("cls");
				_showLogOutScreen();
				break;

			case enMainMenuOptions::RegisterLogin:
				if (!currentUser.checkAccessPerm(clsBankUser::enMainMenuPermmision::eRegisterLogin))
				{
					cout << "access denied to this user" << endl;
					_goBackToMainMenu();
					break;
				}
				system("cls");
				_showRegisterLoginScreen();
				_goBackToMainMenu();
				break;

			case enMainMenuOptions::currencyExchange:
				if (!currentUser.checkAccessPerm(clsBankUser::enMainMenuPermmision::eCurrencyExchange))
				{
					cout << "access denied to this user" << endl;
					_goBackToMainMenu();
					break;
				}
				system("cls");
				_showCurrencyExchangeScreen();
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
		cout << "\t\t\t[8] Login Register." << endl;
		cout << "\t\t\t[9] Currency Exchange." << endl;
		cout << "\t\t\t[10] Logout." << endl;
		cout << "\t\t\t=================================================================" << endl;
		_performMainMenuOption(enMainMenuOptions(_ReadMainMenuOption()));
	}
};
