#pragma once
#include<iostream>
using namespace std;
class person
{
private:
    int id;
    string firstName;
    string lastName;
    string fullName;
    string email;
    string phoneNum;
public:

    person(int idnum, string first, string last, string full, string emailadd, string num)
    {
        id = idnum;
        firstName = first;
        lastName = last;
        fullName = full;
        email = emailadd;
        phoneNum = num;
    }
    int getID()
    {
        return id;
    }
    void setfirst(string first)
    {
        firstName = first;
    }
    string getfirst()
    {
        return firstName;
    }
    void setlast(string last)
    {
        lastName = last;
    }
    string getlast()
    {
        return lastName;
    }
    void setemail(string mail)
    {
        email = mail;
    }
    string getemail()
    {
        return email;
    }
    void setphone(string num)
    {
        phoneNum = num;
    }
    string getphone()
    {
        return phoneNum;
    }

    string getfull()
    {
        fullName = firstName + " " + lastName;
        return fullName;
    }
    void sendEmail(string sub, string body)
    {
        cout << "mail sent successfully to the email " << email << endl;
        cout << "subject: " << sub << endl;
        cout << "body: " << body << endl;
    }
    void sendSMS(string message)
    {
        cout << "SMS sent successfully to the number: " << phoneNum << endl;
        cout << "message: " << message << endl;
    }
    void print()
    {
        cout << "________________________________________" << endl;
        cout << "id: " << id << endl;
        cout << "first name: " << firstName << endl;
        cout << "last name: " << lastName << endl;
        cout << "full name: " << fullName << endl;
        cout << "email: " << email << endl;
        cout << "phone number: " << phoneNum << endl;
        cout << "________________________________________" << endl;

    }
};
