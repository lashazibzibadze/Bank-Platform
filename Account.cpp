/* 
Author: Lasha Zibzibadze

Part of the bank platform
*/
#include <iostream>
#include <string>
#include "Account.hpp"

using namespace std;

string Account::generateAccountNumber(){
    string an_str = "";
    for(int i{0}; i < 8; i++ ){
        int temp = rand() % 10;
        an_str += std::to_string(temp);
    }
        return an_str;
}

Account::Account(){
    this->first_name = "anonymous";
    this->last_name = "anonymous";
    this->pin_number = "0000";
    this->account_number = generateAccountNumber();
    this->balance = 0;
}



Account::Account(string first_name, string last_name, string pin_number){
    this->first_name = first_name;
    this->last_name = last_name;
    if(pin_number.size() != 4){
        this-> pin_number = "0000";
    }
    else{
        this->pin_number = pin_number;
    }
    this->account_number = generateAccountNumber();
    this->balance = 0;

}

//Mutators:
void Account::setFirstName(string first_name){
    this->first_name= first_name;
}

void Account::setLastName(string last_name){
    this->last_name = last_name;
}

bool Account::setPin(string pin_number){
    if(pin_number.size() == 4){
        this->pin_number = pin_number;
        return true;
    }
    else{
        return false;
    }

}

//Accessors:
string Account::getFirstName(){
    return first_name;
}
string Account::getLastName(){
    return last_name;
}

string Account::getAccountNumber(){
    return account_number;
}
string Account::getPin(){
    return pin_number;

}

int Account::getBalance(){
    return balance;
}

//Transactions:
bool Account::transaction(int parameter_for_transaction){
    if(balance + parameter_for_transaction > 0){
        balance+= parameter_for_transaction;
        return true;
    }
    else{
        return false;
    }


}
