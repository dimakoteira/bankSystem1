
#include<iostream>
#include "person.h";
#include"employee.h";
using namespace std;

int main()
{
    employee e(19, "rania", "assfoura", "rania assfoura", "rania@gmail", "09387373", "inherit", "IT", 30000);
    e.print(); 
    person p1(10, "dima", "koteira", "dima koteira", "dima@gmail.com", "09348839");
    p1.print();
    p1.sendEmail("saying hi", "hi dima i miss you");
    p1.sendSMS("hi what are you doing");
    

}