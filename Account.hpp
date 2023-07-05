/* 
Author: Lasha Zibzibadze
*/
#ifndef CREATE_BANK_ACCOUNT
#define CREATE_BANK_ACCOUNT

using namespace std;
#include <iostream>
#include <string>

class Account{
    private:
        string first_name;
        string last_name;
        string account_number;
        string pin_number;
        int balance;
        string generateAccountNumber();

    public:
        //Constructors:
        Account();
        //Constructor with parameters:
        Account(string first_name, string last_name, string pin_number);

        //Mutators:
        void setFirstName(string first_name);
        void setLastName(string last_name);
        bool setPin(string pin_number);

        //Accessors:
        string getFirstName();
        string getLastName();
        string getAccountNumber();
        string getPin();
        int getBalance();

        //Transactions:
        bool transaction(int parameter_for_transaction);







};


#endif //CREATE_BANK_ACCOUNT