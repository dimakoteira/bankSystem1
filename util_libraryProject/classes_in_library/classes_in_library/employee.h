#include<iostream>
#include"person.h";
using namespace std;

class employee :public person
{
private:

    string title;
    string department;
    float salary;
public:
    employee(int id, string first, string last, string full, string email, string phone, string tit, string dep, float sal)
        :person(id, first, last, full, email, phone)//like super in java
    {
        title = tit;
        department = dep;
        salary = sal;

    }
    void setTitle(string tit)
    {
        title = tit;
    }
    string getTitle()
    {
        return title;
    }
    void setDepart(string dep)
    {
        department = dep;
    }
    string getdepart()
    {
        return department;
    }
    void setSalary(float s)
    {
        salary = s;
    }
    float getSalary()
    {
        return salary;
    }
    void print()
    {
        //person::print();//?this is a way to print
        //?this is another way to print
        cout << "________________________________________" << endl;
        cout << "id: " << getID() << endl;
        cout << "first name: " << getfirst() << endl;
        cout << "last name: " << getlast() << endl;
        cout << "full name: " << getfull() << endl;
        cout << "email: " << getemail() << endl;
        cout << "phone number: " << getphone() << endl;//!we access them using get function because they are private members

        cout << "title: " << title << endl;
        cout << "department: " << department << endl;
        cout << "salary: " << salary << endl;
        cout << "________________________________________" << endl;
    }

};