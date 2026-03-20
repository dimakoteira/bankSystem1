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

	static bool _login()
	{
		bool loginFail = false;
		string username;
		string password;
		/*int counter = 0;*/
		short trials = 0;
		do {
			if (loginFail)
			{
				//counter++;
				trials++;
				cout << "invalid username/password" << endl;
				cout << "you have " << 3-trials << " trial(s) left" << endl;
			}
			//locl system
			if (trials == 3)
			{
				cout << "system is locked" << endl;
				return false;
			}

			//if (counter == 3) {
			//	cout << "the system is locked for 30 seconds";
			//	//this_thread::sleep_for(chrono::seconds(30));//sleep for 30 seconds
			//	counter = 0;
			//	system("cls");
			//}
			username = getUserInfo("Enter Username");
			password = getUserInfo("Enter Password");

			currentUser = clsBankUser::find(username, password);
			loginFail = currentUser.IsEmpty();
		   } 
		while (loginFail);
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