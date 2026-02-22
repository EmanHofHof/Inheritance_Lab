//
// Created by Ethan Hofsteen on 2/21/26.
//

#ifndef INHERITANCE_LAB_SAVINGSACCOUNT_H
#define INHERITANCE_LAB_SAVINGSACCOUNT_H
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
public:
    //Constructor
    SavingsAccount(std::string ID, std::string name, double balance, double interest);
    //interest Function
    void calculateInterest();
private:
    double interestRate;
};


#endif //INHERITANCE_LAB_SAVINGSACCOUNT_H