#pragma once
#include<iostream>
#include"clsBankUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsMainScreen.h";
#include<vector>
#include"GlobalUser.h"
#include<thread>
#include<chrono>
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

	static void _login()
	{
		bool loginFail = false;
		string username;
		string password;
		int counter = 0;
		do {
			if (loginFail)
			{
				counter++;
				cout << "invalid username/password" << endl;
			}
			if (counter == 3) {
				cout << "the system is locked for 30 seconds";
				this_thread::sleep_for(chrono::seconds(30));
				system("cls");

			}
			username = getUserInfo("Enter Username");
			password = getUserInfo("Enter Password");

			currentUser = clsBankUser::find(username, password);
			loginFail = currentUser.IsEmpty();
		

		} while (loginFail);
			clsMainScreen::ShowMainMenu();

	}
public:
	static void loginScreen()
	{
		clsScreen::_DrawScreenHeader("Login Screen");
		_login();
		


	}
};