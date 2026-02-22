//Name: Ethan Hofsteen
//Date: 2/7/26
//Class: MSCI-272
//Purpose: Outline Functions that will be used in main and defined in BankAccount.cpp

#ifndef OBJECT_AND_CLASSES2_BANKACCOUNT_H
#define OBJECT_AND_CLASSES2_BANKACCOUNT_H
#include <iostream>

class BankAccount {
public:
    //Default constructor
    BankAccount() {
        accountNumber = "00000";
        accountHolderName = "Unknown";
        balance = 0.0;
    }
    // Parameterized constructor
    BankAccount(std::string Num, std::string Name, double bal ) {
        accountNumber = Num;
        accountHolderName = Name;
        balance = bal;
    }

    //public accessor methods
    std::string GetAccountNum() const { return accountNumber; };
    std::string GetAccountHolderName() const { return accountHolderName; };
    double GetBalance() const { return balance; };
    //public setter method
    void SetAccountHolderName(std::string Name) { accountHolderName = Name; };
    //operator overloading functions (Withdraw/Deposit)
    BankAccount& operator+=(double amount);
    virtual BankAccount& operator-=(double amount);
    //comparison operator functions
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;
    //Destructor
    virtual ~BankAccount() = default;
    //Copy Constructor
    BankAccount(const BankAccount& other);
    //Copy Assignment Operator
    BankAccount& operator=(const BankAccount& other);
    //Static Functions
    static void printAccount(const BankAccount& account);
    static std::unique_ptr<BankAccount> createAccountFromInput();
    static int PrintDisplay();
    static int ComparisonDisplay();
protected:
    double balance;
private:
    std::string accountNumber;
    std::string accountHolderName;
};


#endif //OBJECT_AND_CLASSES2_BANKACCOUNT_H