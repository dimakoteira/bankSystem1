#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"clsString.h"
using namespace std;

class clsCurrency {
private:
	string _country;
	string _currencuCode;
	string _currencyName;
	float _rate;
	enum enMode {empty=0, update=1};
	enMode _mode;

	static clsCurrency _getEmptyObject()
	{
		return clsCurrency(enMode::empty, "", "", "",0);
	}
	static string _convertObjectToLine(clsCurrency curr, string seperator="#//#")
	{
		string line = "";
		line += curr._country + seperator;
		line += curr._currencuCode + seperator;
		line += curr._currencyName + seperator;
		line += to_string(curr._rate) + seperator;
		return line;
	}
	static clsCurrency _convertLineToObject(string line, string seperator = "#//#")
	{
		vector<string> v = clsString::split_stringInVector(line,seperator);
		return clsCurrency(enMode::update, v[0], v[1], v[2], stof(v[3]));
	}
	static vector<clsCurrency>_load()
	{
		fstream currFile;
		vector<clsCurrency>v;
		currFile.open("data/Currencies.txt",ios::in);
		if (currFile.is_open())
		{
			string line;
			while (getline(currFile, line))
			{
				clsCurrency curr = _convertLineToObject(line);
				v.push_back(curr);
			}
			currFile.close();
		}
		return v;
	}

	void _saveCurrencyData(vector<clsCurrency> v)
	{
		fstream currFile;
		currFile.open("data/Currencies.txt", ios::out);//overwrite
		if (currFile.is_open())
		{
			for (clsCurrency& c : v)
			{
				string line = _convertObjectToLine(c);
				currFile << line << endl;
			}
			currFile.close();
		}
	}
	void _update()
	{
		vector<clsCurrency> v = _load();
		for (clsCurrency& c : v)
		{
			if (c._currencuCode == getCurrencyCode())
			{
				c = *this;
				break;
			}
		}
		_saveCurrencyData(v);
	}
public:


	clsCurrency(enMode mode,string country, string currencyCode, string currencyName, float rate)
	{
		this->_mode = mode;
		this->_country = country;
		this->_currencuCode = currencyCode;
		this->_currencyName = currencyName;
		this->_rate = rate;
	}
        string getCountry() const {
            return _country;
        }

        string getCurrencyCode() const {
            return _currencuCode;
        }

        string getCurrencyName() const {
            return _currencyName;
        }

        float getRate() const {
            return _rate;
        }
		void updateRate(float newRate)
		{
			_rate = newRate;
			_update();

		}
		bool isEmpty()
		{
			return _mode==enMode::empty;
		}
	static clsCurrency findByCountry(string country)
	{
		country = clsString::upperString(country);
		vector<clsCurrency>v;
		fstream currFile;
		currFile.open("data/Currencies.txt", ios::in);
		if (currFile.is_open())
		{
			string line;
			while (getline(currFile, line))
			{
				clsCurrency curr = _convertLineToObject(line);
				if (clsString::upperString(curr._country) == country)
				{
					currFile.close();
					return curr;
				}
			}
			currFile.close();
		}
		return _getEmptyObject();
	}

	static clsCurrency findByCode(string code)
	{
		code = clsString::upperString(code);
		vector<clsCurrency>v;
		fstream currFile;
		currFile.open("data/Currencies.txt", ios::in);
		if (currFile.is_open())
		{
			string line;
			while (getline(currFile, line))
			{
				clsCurrency curr = _convertLineToObject(line);
				if (curr._currencuCode == code)
				{
					currFile.close();
					return curr;
				}
				v.push_back(curr);
			}
			currFile.close();
		}
		return _getEmptyObject();
	}

	static bool isCurrencyExistCode(string code)
	{
		clsCurrency c = clsCurrency::findByCode(code);
		return (!c.isEmpty());
	}

	static bool isCurrencyExistCountry(string country)
	{
		clsCurrency c = clsCurrency::findByCountry(country);
		return (!c.isEmpty());
	}

	static vector<clsCurrency> getAllCurrencies()
	{
		return _load();
	}

	 float convertToUSD(float amount)
	{
		 return (float)(amount / getRate());
	}
	 float convertToOtherCurrency(float amount, clsCurrency curr2)
	 {
		 float amountInUSD = convertToUSD(amount);
		 if (curr2._currencuCode == "USD")
		 {
			 return amountInUSD;
		 }
		return (float)(amountInUSD*curr2.getRate());
	 }
	
};
