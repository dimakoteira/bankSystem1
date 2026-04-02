#pragma once
#include<iostream>
using namespace std;
class clsPerson {
private:
  
	string _firstName;
	string _lastName;
	string _email;
	string _phone;
public:
	clsPerson() {
	}
	clsPerson(string firstName, string lastName, string email, string phone) {
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_email = email;
		this->_phone = phone;
	}
	string getFirstName() {
		return _firstName;
	}
	string getLastName() {
		return _lastName;
	}

	string getFullName()
	{
		return _firstName + " " + _lastName;
	}
	string getEmail() {
		return _email;
	}
	string getPhone() {
		return _phone;
	}

	void setFirstName(const string& firstName) {
		_firstName = firstName;
	}
	void setLastName(const string& lastName) {
		_lastName = lastName;
	}
	void setEmail(const string& email) {
		_email = email;
	}
	void setPhone(const string& phone) {
		_phone = phone;
	}
};