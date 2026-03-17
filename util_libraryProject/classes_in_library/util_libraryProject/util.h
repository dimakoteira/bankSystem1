#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include "clsdate.h";

using namespace std;
class clsUtil {


public:
	static	enum encharType { smallLetter = 1, capitalLetter = 2, digit = 3, specialChar = 4, mix = 5 };
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int from, int to)
	{
		int ra = rand() % (to - from + 1) + from;
		return ra;
	}
	static char randomChar(encharType type)
	{
		switch (type)
		{
		case encharType::smallLetter:
			return char(RandomNumber(97, 122));
			break;

		case encharType::capitalLetter:
			return char(RandomNumber(65, 90));
			break;

		case encharType::specialChar:
			return char(RandomNumber(33, 47));
			break;

		case encharType::digit:
			return char(RandomNumber(48, 57));
			break;

		case encharType::mix:
			int n = RandomNumber(1, 3);
			if (n == 1) return randomChar(encharType::smallLetter);
			else if (n == 2) return randomChar(encharType::capitalLetter);
			else return randomChar(encharType::digit);
			break;
		}
	}

	static string generateWord(encharType type, int len)
	{
		string s = "";
		for (int i = 0;i < len;i++)
		{
			s += randomChar(type);
		}
		return s;
	}

	static string generateKey(encharType t)
	{
		string key;
		for (int i = 0;i < 4;i++)
		{
			key+=generateWord(t, 4);
			key += "-";
		}
		return key.substr(0,key.length()-1);
	}

	static void  generateKey(encharType t, int count)
	{
		for (int i = 0;i < count;i++)
		{
			cout<<"key["<<i+1<<"]: " << generateKey(t) << endl;
		}
	}
	template <typename T>
	static void swap(T &x, T &y)
	{
		T temp = x;
		x = y;
		y = temp;
	}

	static void swapDates(clsDate &d1, clsDate &d2)
	{
		clsDate temp = d1;
		d1 = d2;
		d2 = temp;
	}



	static void shuffleArray(int arr[], int length)
	{
		for (int i = 0;i < length;i++)
		{
			int x = RandomNumber(0, length - 1);
			int y = RandomNumber(0, length - 1);
			swap(arr[x], arr[y]);
				
		}
	}

	static void shuffleArray(string arr[], int length)
	{
		for (int i = 0;i < length;i++)
		{
			int x = RandomNumber(0, length - 1);
			int y = RandomNumber(0, length - 1);
			swap(arr[x], arr[y]);

		}
	}

	static void fillArrayWithRandomNumbers(int arr[], int length, int from, int to)
	{
		for (int i = 0;i < length;i++)
		{
			arr[i] = RandomNumber(from, to);
		}
	}

	static void fillArrayWithRandomWords(string arr[], int length, encharType t, int wordlen)
	{
		for (int i = 0;i < length;i++)
		{
			arr[i] = generateWord(t, wordlen);
		}
	}

	static void fillArrayWithRandomKeys(string arr[],int length, encharType t)
	{
		for (int i = 0;i < length;i++)
		{
			arr[i] = generateKey(t);
		}
	}
	static string generateTabs(int count)
	{
		string tabs = "";
		for (int i = 0;i < count;i++)
		{
			tabs += "\t";
		}
		return tabs;
	 }

	static string encrypt(string name, int encKey)
	{
		for (int i = 0;i < name.length();i++)
		{
			name[i] = char((int)name[i] + encKey);
		}
		return name;
	}

	static string decrypt(string name, int encKey)
	{
		for (int i = 0;i < name.length();i++)
		{
			name[i] = char((int)name[i] - encKey);
		}
		return name;
	}

	static string num_to_text(long long n)
	{
		if (n == 0)
		{
			return "";
		}
		if (n >= 1 && n <= 19)
		{
			string arr[] = { " ","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve",
			"thirteen","fourteen","sixteen","seventeen","eighteen","ninteen" };
			return arr[n] + " ";
		}
		if (n >= 20 && n <= 99)
		{
			string arr2[] = { " "," ","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty" };
			return arr2[n / 10] + " " + num_to_text(n % 10) + " ";
		}
		if (n >= 100 && n <= 199)
		{
			return "one hunred " + num_to_text(n % 100) + " ";
		}
		if (n >= 200 && n <= 999)
		{
			return num_to_text(n / 100) + "hundred " + num_to_text(n % 100) + " ";
		}
		if (n >= 1000 && n <= 1999)
		{
			return "one thousand " + num_to_text(n % 1000);
		}
		if (n >= 2000 && n <= 999999)
		{
			return num_to_text(n / 1000) + "thousand " + num_to_text(n % 1000);
		}
		if (n >= 1000000 && n <= 1999999)
		{
			return "one million " + num_to_text(n % 1000000);
		}
		if (n >= 2000000 && n <= 999999999)
		{
			return num_to_text(n / 1000000) + "million " + num_to_text(n % 1000000);
		}
		if (n >= 1000000000 && n <= 1999999999)

		{
			return "one billion " + num_to_text(n % 1000000000);
		}
		else
		{
			return num_to_text(n / 1000000000) + " billion " + num_to_text(n % 1000000000);
		}
	}

};
