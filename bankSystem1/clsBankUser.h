#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h";
#include<string>
using namespace std;

class clsBankUser : public clsPerson {
private:
    enum enMode { empty = 0, update = 1, add = 2 };
    enMode _mode;
    string _userName;
    string _password;
    int _permissions;
    bool _markForDelete = false;

    //methods
    static clsBankUser _convertLineToObject(string line, string seperator)
    {
        vector<string> v = clsString::split_stringInVector(line, seperator);
        if (v.size() != 7)
            return _getEmptyUserObject();
        return clsBankUser( v[0], v[1], v[2], v[3], v[4], v[5], stoi(v[6]), enMode::update);
    }

    static clsBankUser _getEmptyUserObject()
    {
        return clsBankUser( " ", " ", " ", " ", " ", " ", 0, enMode::empty);
    }

    static string _converObjectToLine(clsBankUser user, string space) {
        string s = "";
        s = s +user.getFirstName() + space;
        s += user.getLastName() + space;
        s += user.getEmail() + space;
        s += user.getPhone() + space;
        s += user.getUserName() + space;
        s += user.getPassword() + space;
        s += to_string(user.getPermissions());
        return s;
    }

    static vector<clsBankUser> _load()
    {

        fstream user_bank;
        vector<clsBankUser> vfile;
        user_bank.open("BankUsers.txt", ios::in);
        if (user_bank.is_open())
        {
            string line;
            while (getline(user_bank, line))
            {
                clsBankUser user = _convertLineToObject(line, "#//#");
                vfile.push_back(user);
            }
            user_bank.close();
        }
        return vfile;
    }

    void _saveUserData(vector<clsBankUser> v)
    {
        fstream bank_user;
        bank_user.open("BankUsers.txt", ios::out);//overwrite
        if (bank_user.is_open())
        {
            for (clsBankUser& u : v)
            {
                string line = _converObjectToLine(u, "#//#");
                bank_user << line << endl;
            }
            bank_user.close();
        }
    }

    void _update()
    {
        vector<clsBankUser> vBU = _load();
        for (clsBankUser& u : vBU)
        {
            if (u._userName== getUserName())
            {
                u = *this;
                break;
            }
        }
        _saveUserData(vBU);
    }

    void _addUser()
    {
        fstream bank_user;
        bank_user.open("BankUsers.txt", ios::app);
        if (bank_user.is_open())
        {
            string line = _converObjectToLine(*this, "#//#");
            bank_user << line << endl;

            bank_user.close();
        }
    }

    void _saveNonDeletedUser(vector<clsBankUser>v)
    {
        fstream bank_user;
        bank_user.open("BankUsers.txt", ios::out);//overwrite
        for (clsBankUser& u : v)
        {
            if (u._markForDelete == false)
            {
                string line = _converObjectToLine(u, "#//#");
                bank_user << line << endl;
            }
        }
        bank_user.close();
    }


public:
    // Constructor
    clsBankUser(const string& firstName,const string& lastName,const string& email,const string& phone,const string& userName,const string& password,int permissions,enMode mode) 
       : clsPerson(firstName, lastName, email, phone),
        _userName(userName),
        _password(password),
        _permissions(permissions),
        _mode(mode)
    {}
     
    bool IsEmpty()
    {
        return (_mode == enMode::empty);
    }
    // Getters
    string getUserName() const { return _userName; }
    string getPassword() const { return _password; }
    int getPermissions() const { return _permissions; }
    bool isMarkedForDelete() const { return _markForDelete; }
    enMode getMode() const { return _mode; }

    // Setters
    void setUserName(const string& userName) { _userName = userName; }
    void setPassword(const string& password) { _password = password; }
    void setPermissions(int permissions) { _permissions = permissions; }
    void setMarkForDelete(bool mark) { _markForDelete = mark; }
    void setMode(enMode mode) { _mode = mode; }

    //find client
    static clsBankUser find(string username)
    {
        vector <clsBankUser> vBU;
        fstream bank_user;
        bank_user.open("bankUsers.txt", ios::in);
        if (bank_user.is_open())
        {
            string line;

            while (getline(bank_user, line))
            {
                clsBankUser user = _convertLineToObject(line, "#//#");
                if (user.getUserName() == username)
                {
                    bank_user.close();
                    return user;
                }
                vBU.push_back(user);
            }
            bank_user.close();
        }
        return _getEmptyUserObject();// if the client is not found
    }

    static clsBankUser find(string username,string password)
    {
        vector <clsBankUser> vBU;
        fstream bank_user;
        bank_user.open("bankUsers.txt", ios::in);
        if (bank_user.is_open())
        {
            string line;

            while (getline(bank_user, line))
            {
                clsBankUser user = _convertLineToObject(line, "#//#");
                if (user.getUserName() == username && user.getPassword() == password)
                {
                    bank_user.close();
                    return user;
                }
                vBU.push_back(user);
            }
            bank_user.close();
        }
        return _getEmptyUserObject();// if the client is not found
    }

    static bool isUserExist(string username)
    {
        clsBankUser u = clsBankUser::find(username);
        return (!u.IsEmpty());
    }

    //save options
    enum enSaveResult { svSucceede = 1, svFailEmptyObj = 2, svFailAccountExist = 3 };

    enSaveResult saveUser()
    {
        switch (_mode)
        {
        case enMode::empty:
            return enSaveResult::svFailEmptyObj;
            break;

        case enMode::update:
           _update();
            return enSaveResult::svSucceede;
            break;

        case enMode::add:
            if (clsBankUser::isUserExist(_userName))
                return enSaveResult::svFailAccountExist;
            else {
               _addUser();
                _mode = enMode::update;//ضفنا العميل فصار بال مود الابديت
                return enSaveResult::svSucceede;
                break;
            }

        }


    }

    static clsBankUser getAddNewUserObject(string username)//initialize the username
    {

        return clsBankUser( "", "", "", "", username, "", 0, enMode::add);
    }
    bool Delete()
    {
        vector <clsBankUser> vBU = _load();
        for (clsBankUser& u : vBU)
        {
            if (u._userName == _userName)
            {
                u._markForDelete = true;
                break;
            }
        }
        *this = _getEmptyUserObject();
        _saveNonDeletedUser(vBU);
        return true;
    }
    static vector<clsBankUser> getAllUsers()
    {
        return _load();
    }
};
