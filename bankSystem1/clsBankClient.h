#pragma once
#include<iostream>
#include "clsPerson.h";
#include<vector>
#include<fstream>
#include"clsString.h";
#include<string>

using namespace std;
class clsBankClient : public clsPerson
{
private:
    //properties
string _accountNum;
string _pinCode;
float _salary;
bool _markDelete = false;
enum enMode{empty=0,update=1,add=2};
   enMode _mode=enMode::empty;

   //methods
  static clsBankClient _convertLineToObject(string line, string seperator)
   {
      
	vector<string> v = clsString::split_stringInVector(line, seperator);
	if (v.size() != 7)
		return _getEmptyClientObject();
       return clsBankClient(enMode::update, v[0], v[1], v[2], v[3], v[4], v[5], stof(v[6]));
   }

  static clsBankClient _getEmptyClientObject()
   {
       return clsBankClient(enMode::empty, " ", " ", " ", " ", " ", " ", 0);
   }

  static string _converObjectToLine(clsBankClient client, string space) {
      string s="";
      s = s + client.getFirstName() + space;
      s += client.getLastName() + space;
      s += client.getEmail() + space;
	  s += client.getPhone() + space;
	  s += client.GetAccountNum() + space;
	  s += client.GetPinCode() + space;
	  s += to_string(client.GetSalary());
	  return s;
  }

  static vector<clsBankClient> _load()
  {

      fstream clients_bank;
      vector<clsBankClient> vfile;
      clients_bank.open("bankClient2.txt", ios::in);
      if (clients_bank.is_open())
      {
          string line;
          while (getline(clients_bank, line))
          {
             clsBankClient client = _convertLineToObject(line, "#//#");
              vfile.push_back(client);
          }
          clients_bank.close();
      }
      return vfile;
  }

  void _saveClientsData(vector<clsBankClient> v)
  {
     fstream bank_client;
         bank_client.open("bankClient2.txt", ios::out);//overwrite
         if (bank_client.is_open())
         {
             for (clsBankClient& c : v)
             {
                 string line = _converObjectToLine(c,"#//#");
                 bank_client << line << endl;
             }
             bank_client.close();
         }
  }

   void _update()
  {
      vector<clsBankClient> vBC = _load();
      for (clsBankClient& c : vBC)
      {
          if (c._accountNum == GetAccountNum())
          {
              c = *this;
              break;
          }
      }
      _saveClientsData(vBC);
  }

   void _addClient()
   {
       fstream bank_client;
       bank_client.open("bankClient2.txt", ios::app);//overwrite
       if (bank_client.is_open())
       {
          string line = _converObjectToLine(*this, "#//#");
          bank_client << line << endl;
           
           bank_client.close();
       }
   }

   void _saveNonDeletedClient(vector<clsBankClient>v)
   {
       fstream bank_client;
	   bank_client.open("bankClient2.txt", ios::out);//overwrite
       for (clsBankClient& c : v)
       {
           if (c._markDelete == false)
           {
               string line = _converObjectToLine(c, "#//#");
               bank_client << line << endl;
           }
       }
	   bank_client.close();
   }
   public:

       clsBankClient(enMode mode,string firstName, string lastName, string email, string phone, string accountNum, string pinCode, float salary)
          :clsPerson(firstName, lastName, email, phone)
       {
           this->_mode = mode;
           this->_accountNum = accountNum;
           this->_pinCode = pinCode;
           this->_salary = salary;
       }

       bool isEmpty()
       {
           return _mode==enMode::empty;
       }
       // Getter (read only)
       string GetAccountNum() const {
           return _accountNum;
       }
       // Getter and Setter for pinCode
       string GetPinCode() const {
           return _pinCode;
       }
       void SetPinCode(const string& value) {
           _pinCode = value;
       }

       // Getter and Setter for salary
       float GetSalary() const {
           return _salary;
       }
       void SetSalary(float value) {
           _salary = value;
       }

     /*  void print() don't include a ui function
       {
           cout << "----------------------------------------------" << endl;
           cout << "\t\t Client Card" << endl;
           cout << "----------------------------------------------" << endl;
           cout << "first name: " << getFirstName() << endl;
           cout << "last name: " << getLastName() << endl;
           cout << "full name: " << getFullName() << endl;
           cout << "E-mail: " << getEmail() << endl;
           cout << "phone number: " << getPhone() << endl;
           cout << "account number: " << _accountNum << endl;
           cout << "pin code: " << _pinCode << endl;
           cout << "salary: " << _salary << endl;
       }*/

     static clsBankClient find(string account)
       {
           vector <clsBankClient> vBC;
           fstream bank_client;
           bank_client.open("bankClient2.txt", ios::in);
           if (bank_client.is_open())
             {
               string line;
               
               while (getline(bank_client, line))
               {
                   clsBankClient client = _convertLineToObject(line, "#//#");
                   if (client.GetAccountNum() == account)
                   {
                       bank_client.close();
                       return client;
                   }
                   vBC.push_back(client);
               }
               bank_client.close();
             }
           return _getEmptyClientObject();// if the client is not found
          
       }

     static clsBankClient find(string account,string pinCode)
     {
         vector <clsBankClient> vBC;
         fstream bank_client;
         bank_client.open("bankClient2.txt", ios::in);
         if (bank_client.is_open())
         {
             string line;

             while (getline(bank_client, line))
             {
                 clsBankClient client = _convertLineToObject(line, "#//#");
                 if (client.GetAccountNum() == account&&client.GetPinCode() == pinCode)
                 {
                     bank_client.close();
                     return client;
                 }
                 vBC.push_back(client);
             }
             bank_client.close();
         }
         return _getEmptyClientObject();// if the client is not found
     }

     static bool isClientExist(string account)
     {
         clsBankClient c1 = clsBankClient::find(account);
         return (!c1.isEmpty());
     }

     enum enSaveResult { svSucceede=1,svFailEmptyObj=2,svFailAccountExist=3};


     enSaveResult saveClient()
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
             if(clsBankClient::isClientExist(_accountNum))
                 return enSaveResult::svFailAccountExist;
             else {
                 _addClient();
                 _mode = enMode::update;//ضفنا العميل فصار بال مود الابديت
                 return enSaveResult::svSucceede;
                 break;
             }
         
         }
        

     }

     static clsBankClient getAddNewClientObject(string account)//initialize the account number
     {
         
         return clsBankClient(enMode::add, "", "", "", "", account, "", 0);
     }
     bool Delete()
     {
		 vector <clsBankClient> vBC = _load();
         for (clsBankClient& c : vBC)
         {
             if (c._accountNum == _accountNum)
             {
                 c._markDelete = true;
                 break;
             }
         }
		 *this = _getEmptyClientObject();
		 _saveNonDeletedClient(vBC);
		 return true;
     }

  static vector<clsBankClient> getAllClients()
     {
         return _load();
     }
  static float getTotalSalary()
  {
	  vector<clsBankClient> v = _load();
	  float totalSalary = 0;
	  if (v.size() == 0)
		  return totalSalary;
      for (clsBankClient& c : v)
      {
          totalSalary += c.GetSalary();
      }
      return totalSalary;
  }

  void deposit(int amount)
  {
      this->_salary = this->_salary + amount;
      saveClient();
  }

  bool withdraw(int amount)
  {
      if (amount > this->_salary)
          return false;
      this->_salary = this->_salary - amount;
      saveClient();
      return true;
  }
  bool transfer(int amount,clsBankClient &toClient)
  {
      if (amount > this->_salary)
          return false;
      withdraw(amount);
      toClient.deposit(amount);
      return true;
  }
};