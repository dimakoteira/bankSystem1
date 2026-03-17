
#include <iostream>
#include"clsString.h";
#include<vector>
using namespace std;
int main()
{
    clsString s1("dima koteira");
    cout << clsString::count_vowels("dima");
    s1.upperFirstLetter() ;
    cout << s1.getvalue() << endl;
    

}
