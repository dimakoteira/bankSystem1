#pragma once
#include<iostream>
#include "clsdate.h";
#include<iomanip>
using namespace std;
class clsInputValidate
{
public:
	template <typename T>
	static bool IsNumberBetween(T n, T from, T to)
	{
		if (n <= to && n >= from)
			return true;
		else return false;
	}

	static bool IsDateBetween(clsDate d1, clsDate d2, clsDate d3)
	{
		if (clsDate::is_before_date(d2, d3))
		{
			if (!clsDate::is_before_date(d1, d2) && clsDate::is_before_date(d1, d3))
				return true;
			else return false;
		}
		else if (!clsDate::is_before_date(d2, d3))
		{
			if (!clsDate::is_before_date(d1, d3) && clsDate::is_before_date(d1, d2))
				return true;
			else return false;
		}
		else return false;
	}

	static int ReadIntNumber(string message)
	{
		int n;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
			cin >> n;
		}
		return n;
	}

	static short ReadShortNumber(string message)
	{
		short n;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
			cin >> n;
		}
		return n;
	}
	static float ReadFloatNumber(string message)
	{
		float n;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
			cin >> n;
		}
		return n;
	}
	static double ReadDbNumber(string message)
	{
		double n;
		cin >> n;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << message << endl;
			cin >> n;
		}
		return double(n);
	}

	static string ReadString(string message)
	{
		string s;
		getline(cin >> ws, s);
		return s;
	}

	static int ReadIntNumberBetween(int from, int to, string message)
	{
		int n=ReadIntNumber("invalid input try again");
		while (!IsNumberBetween(n, from, to))
		{
			cout << message << endl;
			 n = ReadIntNumber("invalid input try again");
		}
		return n;
	}
	static short ReadShortNumberBetween(short from, short to, string message)
	{
		short n = ReadIntNumber("invalid input try again");
		while (!IsNumberBetween(n, from, to))
		{
			cout << message << endl;
			n = ReadIntNumber("invalid input try again");
		}
		return n;
	}
	static double ReadDbNumberBetween(double from, double to, string message)
	{
		double n = ReadIntNumber("invalid input try again");
		while (!IsNumberBetween(n, from, to))
		{
			cout << message << endl;
			n = ReadIntNumber("invalid input try again");
		}
		return n;
	}

	static bool IsValidDate(clsDate d)
	{
		if (d.getDay()>31||d.getDay()<1||d.getMonth() > 12 || d.getMonth() < 1)
			return false;
		else return true;
	}

};
