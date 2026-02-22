//Name: Ethan Hofsteen
//Date: 2/22/26.
//Class: MSCI-272
//Purpose: Outline the Checking Account Class.

#ifndef INHERITANCE_LAB_CHECKINGACCOUNT_H
#define INHERITANCE_LAB_CHECKINGACCOUNT_H
# include "BankAccount.h"

class CheckingAccount : public BankAccount {
public:
    //Constructor
    CheckingAccount(std::string ID, std::string name, double balance, double transactionFee);
    //withdrawal with transactionFee
    BankAccount& operator-=(double amount) override;
private:
    double transactionFee;
};


#endif //INHERITANCE_LAB_CHECKINGACCOUNT_H