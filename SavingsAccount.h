//Name: Ethan Hofsteen
//Date: 2/22/26.
//Class: MSCI-272
//Purpose: Define Functions that are used in main.cpp and outlined in BankAccount.h

#ifndef INHERITANCE_LAB_SAVINGSACCOUNT_H
#define INHERITANCE_LAB_SAVINGSACCOUNT_H
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
public:
    //Constructor
    SavingsAccount(std::string ID, std::string name, double balance, double interest);
    //interest Function
    void calculateInterest() override;
private:
    double interestRate;
};


#endif //INHERITANCE_LAB_SAVINGSACCOUNT_H