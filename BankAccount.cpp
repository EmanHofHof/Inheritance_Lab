//Name: Ethan Hofsteen
//Date: 2/7/26.
//Class: MSCI-272
//Purpose: Define Functions that are used in main.cpp and outlined in BankAccount.h

#include "BankAccount.h"
//Copy Constuctor
BankAccount::BankAccount(const BankAccount& other) {
    this->accountNumber = other.accountNumber;
    this->accountHolderName = other.accountHolderName;
    this->balance = other.balance;
}
//Destructor
BankAccount::~BankAccount() {
    //Used for pointers
}
//Copy Assignment Operator
BankAccount& BankAccount::operator=(const BankAccount& other) {
    //error checking for identical assignment
    if (this != &other) {
        this->accountNumber = other.accountNumber;
        this->accountHolderName = other.accountHolderName;
        this->balance = other.balance;
    }
    return *this;
}
//New deposit function
BankAccount& BankAccount::operator+=(double amount) {
    this->balance += amount;
    std::cout << "---Deposit Successful---" << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
    return *this;
}
//New withdrawal function
BankAccount& BankAccount::operator-=(double amount) {
    this->balance -= amount;
    std::cout << "---Withdrawal Successful---" << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
    return *this;
}
//return true if account1 = account2 (ID)
bool BankAccount::operator==(const BankAccount& other) const {
    if (this->accountNumber == other.accountNumber) {
        return true;
    }
    else {
        return false;
    }
}
//return true if account1 < account2 (balance)
bool BankAccount::operator<(const BankAccount& other) const {
    if (this->balance < other.balance) {
        return true;
    }
    else {
        return false;
    }
}
//return true if account1 > account2 (balance)
bool BankAccount::operator>(const BankAccount& other) const {
    if (this->balance > other.balance) {
        return true;
    }
    else {
        return false;
    }
}
//show account details
void BankAccount::printAccount(const BankAccount& account) {
    std::cout << "Account Name: " << account.accountHolderName << std::endl;
    std::cout << "Account ID: " << account.accountNumber << std::endl;
    std::cout << "Account Balance: " << account.balance << std::endl;
    std::cout << "--------------------" << std::endl;
}
//Account Creation
BankAccount BankAccount::createAccountFromInput() {
    std::string id, name;
    double InitialBal;
    //Account Credentials
    std::cout << "Enter Account ID: " << std::endl; std::cin >> id;
    std::cout << "Enter Account Name: " << std::endl; std::cin.ignore(); std::getline(std::cin, name);
    std::cout << "Enter Initial Balance: " << std::endl; std::cin >> InitialBal;
    //Balance Error Checking
    if (InitialBal < 0) {
        while (InitialBal < 0) {
            std::cout << "Invalid Balance (Must be positive): "; std::cin >> InitialBal;
        }
    }
    std::cout << "---Account Successfully Created---" << std::endl;
    return BankAccount(id, name, InitialBal);
}
//Basic Display Menu
int BankAccount::PrintDisplay() {
    int MenuChoice;
    std::cout << "1. Create New Account" <<std::endl;
    std::cout << "2. Deposit to Account" <<std::endl;
    std::cout << "3. Withdraw from Account" <<std::endl;
    std::cout << "4. Display all Accounts" <<std::endl;
    std::cout << "5. Compare Accounts" <<std::endl;
    std::cout << "6. Exit Program" <<std::endl;
    std::cout << "Enter choice (1-6): ";
    std::cin >> MenuChoice;
    while (MenuChoice < 1 || MenuChoice > 6) {
        std::cout << "Invalid Choice, Try again (1-6): " << std::endl;
        std::cin >> MenuChoice;
    }
    return MenuChoice;
}
int BankAccount::ComparisonDisplay() {
    int MenuChoice;
    std::cout << "1. Compare Account Numbers" << std::endl;
    std::cout << "2. Compare Account Balances (<)" <<std::endl;
    std::cout << "3. Compare Account Balances (>)" << std::endl;
    std::cout << "4. Exit Comparison Menu" << std::endl;
    std::cout << "Enter choice (1-4): "<< std::endl;
    std::cin >> MenuChoice;
    while (MenuChoice < 1 || MenuChoice > 4) {
        std::cout << "Invalid Choice, Try again (1-4): " << std::endl;
        std::cin >> MenuChoice;
    }
    return MenuChoice;
}