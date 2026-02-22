//Name: Ethan Hofsteen
//Date: 2/7/26.
//Class: MSCI-272
//Purpose: Define Functions that are used in main.cpp and outlined in BankAccount.h

#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
//Copy Constuctor
BankAccount::BankAccount(const BankAccount& other) {
    this->accountNumber = other.accountNumber;
    this->accountHolderName = other.accountHolderName;
    this->balance = other.balance;
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
    std::cout << "Account Balance: $" << account.balance << std::endl;
    std::cout << "--------------------" << std::endl;
}
//Account Creation
std::unique_ptr<BankAccount> BankAccount::createAccountFromInput() {
    std::string id, name;
    double InitialBal;
    int accountChoice;
    std::cout << "What kind of Account would You like to Create?" << std::endl;
    std::cout << "1. Checking Account" << std::endl;
    std::cout << "2. Savings Account" << std::endl;
    std::cout << "Enter Choice here (1-2): " << std::endl;
    std::cin >> accountChoice;
    while (accountChoice < 1 || accountChoice > 2) {
        std::cout << "Invalid Choice, Please enter an integer (1-2):" << std::endl;
        std::cin >> accountChoice;
    }
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
    if (accountChoice == 1) {
        double fee;
        std::cout << "Enter Account Transaction Fee: $"; std::cin >> fee;
        //Fee error check
        while (fee < 0) {
            std::cout << "Invalid Fee (Must be positive): "; std::cin >> fee;
        }
        //use make_unique in return statement in order to find space in memory for pointer
        std::cout << "---Account Successfully Created---" << std::endl;
        return std::make_unique<CheckingAccount>(id, name, InitialBal, fee);
    }
    if (accountChoice == 2) {
        double interestRate;
        std::cout << "Enter Interest Rate (EX. %3 = 0.03): "; std::cin >> interestRate;
        //Interest Error check
        while (interestRate < 0) {
            std::cout << "Invalid Interest Rate (Must be positive): "; std::cin >> interestRate;
        }
        std::cout << "---Account Successfully Created---" << std::endl;
        return std::make_unique<SavingsAccount>(id, name, InitialBal, interestRate);
    }
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