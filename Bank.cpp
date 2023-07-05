/* 
Author: Lasha Zibzibadze

Bank Platform
*/
#include <iostream>
#include <string>
#include "Bank.hpp"

using namespace std;

//Constructor

Bank::Bank(){
    existing_accounts= 0;
}

// Bank Functions

string Bank::createAccount(string first_name, string last_name, string pin){
    if(existing_accounts < 200){
        Account new_profile;
        new_profile.setFirstName(first_name);
        new_profile.setLastName(last_name);
        new_profile.setPin(pin);
        profiles[existing_accounts] = new_profile;
        existing_accounts+= 1;
        return new_profile.getAccountNumber();

    }
    else{
        return "-1";
    }
}

bool Bank::removeAccount(string acc_number){
    for(int x= 0; x < existing_accounts; x++){
        if(profiles[x].getAccountNumber() == acc_number){
            Account blank;
            profiles[x]= blank;
            existing_accounts-= 1;
            return true;
        }
    }

    return false;
}

bool Bank::withdraw(int amount, string acc_number, string pin){
    for(int x=0; x < existing_accounts; x++){
        if(profiles[x].getAccountNumber() == acc_number){
            if(profiles[x].getPin() == pin){
                if(profiles[x].getBalance() >= amount){
                    //int withdraw= profiles[x].getBalance() - amount;
                    //withdraw= -withdraw;
                    amount= -amount;
                    profiles[x].transaction(amount);
                    return true;
                }
            }
        }
    }
    return false;

}

bool Bank::deposit(int amount, string acc_number, string pin){

    for(int x=0; x < existing_accounts; x++){
        if(profiles[x].getAccountNumber() == acc_number){
            if(profiles[x].getPin() == pin){
                //if(profiles[x].getBalance() >= amount){
                    //int withdraw= profiles[x].getBalance() + amount;
                    //withdraw= -withdraw;
                    profiles[x].transaction(amount);
                    return true;
                //}
            }
        }
    }
    return false;
}

int Bank::getAccountBalance(string acc_number, string pin){
    for(int x=0; x< existing_accounts; x++){
        if(profiles[x].getAccountNumber() == acc_number){
            if(profiles[x].getPin() == pin){
                return profiles[x].getBalance();
            }
        }
    }

    return -1;
}
