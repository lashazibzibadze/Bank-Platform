/* 
Author: Lasha Zibzibadze
*/

#ifndef BANK_COMPANY
#define BANK_COMPANY
using namespace std;
#include <iostream>
#include <string>
#include "Account.hpp"

class Bank{

private:
    
    Account profiles[200];
    int existing_accounts;
    
public:
    Bank(); //default contructor
    string createAccount(string first_name, string last_name, string pin); //create account function
    bool removeAccount(string id_number); // remove acc function
    bool withdraw(int amount, string acc_number, string pin); //withdraw function
    bool deposit(int amount, string acc_number, string pin); // deposit function
    int getAccountBalance(string acc_number, string pin); // Check balance function
};




#endif //BANK_COMPANY