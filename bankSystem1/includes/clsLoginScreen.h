#pragma once
#include<iostream>
#include"clsBankUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsMainScreen.h";
#include<vector>
#include"GlobalUser.h"
using namespace std;
class clsLoginScreen :protected clsScreen {
private:
	static string getUserInfo(string message)
	{
		string s;
		cout << message << endl;
		cin >> s;
		return s;
	}

	static bool _login()
	{
		bool loginFail = false;
		string username;
		string password;
		short trials = 0;
		do {
			if (loginFail)
			{
				trials++;
				cout << "invalid username/password" << endl;
				cout << "you have " << 3-trials << " trial(s) left" << endl;
			}
			//lock system
			if (trials == 3)
			{
				cout << "system is locked" << endl;
				return false;
			}
			username = getUserInfo("Enter Username");
			password = getUserInfo("Enter Password");

			currentUser = clsBankUser::find(username, password);
			loginFail = currentUser.IsEmpty();

		   } 
		while (loginFail);
		currentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
		return true;

	}
public:
	static bool loginScreen()
	{
		clsScreen::_DrawScreenHeader("Login Screen");
		return _login();
	}
};