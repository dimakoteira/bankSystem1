#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h";
#include"clsScreen.h";
#include"clsListUsersScreen.h";
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;
class clsManageUsersScreen :protected clsScreen {
private:
	enum enManageMenuOptions { ListUsers = 1, AddNewUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5};
	static short _ReadManageMenuOption()
	{
		cout << "Choose what do you want to do[1 - 6]: ";
		int choice = clsInputValidate::ReadShortNumberBetween(1, 6, "number is not between 1 and 6");
		return choice;
	}
	static void _executeManageMenuOption(void (*screenFunction)())
	{
		system("cls");
		screenFunction();
		_goBackToManageMenu();
	}
	static void _showListUsersScreen()
	{
		clsListUserScreen::showAllUsers();
	}
	static void _showAddNewUserScreen()
	{
		clsAddNewUserScreen::addUser();
	}
	static void _showDeleteUserScreen()
	{
		clsDeleteUserScreen::deleteUser();
	}
	static void _showUpdateUserScreen()
	{
		clsUpdateUserScreen::updateUser();
	}
	static void _showFindUserScreen()
	{
		clsFindUserScreen::FindUser();
	}
	static void _goBackToManageMenu()
	{
		cout << "press any key to go back to manage users menu.." << endl;
		system("pause>0");
		showManageUsersScreen();
	}
	static void _performManageUserOption(enManageMenuOptions op)
	{
		switch (op)
		{
		case enManageMenuOptions::ListUsers:
			_executeManageMenuOption(&_showListUsersScreen);
			return;

		case enManageMenuOptions::AddNewUser:
			_executeManageMenuOption(&_showAddNewUserScreen);
			break;

		case enManageMenuOptions::DeleteUser:
			_executeManageMenuOption(&_showDeleteUserScreen);
			break;

		case enManageMenuOptions::UpdateUser:
			_executeManageMenuOption(&_showUpdateUserScreen);
			break;

		case enManageMenuOptions::FindUser:
			_executeManageMenuOption(&_showFindUserScreen);
			break;
		}
	}
public:
	static void showManageUsersScreen()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("Manage Users Screen");
		cout << "\t\t\t===============================================================" << endl;
		cout << setw(57) << "Manage Users Menu" << endl;
		cout << "\t\t\t===============================================================" << endl;

		cout << "\t\t\t[1] List Users." << endl;
		cout << "\t\t\t[2] Add New User." << endl;
		cout << "\t\t\t[3] Delete User." << endl;
		cout << "\t\t\t[4] Update User Info." << endl;
		cout << "\t\t\t[5] Find User." << endl;
		cout << "\t\t\t[6] Main Menu." << endl;
		cout << "\t\t\t=================================================================" << endl;
		_performManageUserOption(enManageMenuOptions(_ReadManageMenuOption()));
	}

	
};