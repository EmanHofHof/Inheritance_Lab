//Name: Ethan Hofsteen
//Date: 2/22/26.
//Class: MSCI-272
//Purpose: Define calculateInterest Function and constructor for SavingsAccount Class
#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string ID, std::string name, double balance, double interest) :
    BankAccount(ID, name, balance), interestRate(interest) {};
//interest Function
// ENSURE PERCENTAGE IS REPRESENTED BY DECIMAL POINTS
// EX. 3% --> 0.03 InterestRate
void SavingsAccount::calculateInterest() {
    double InterestEarned = balance * interestRate;
    balance += InterestEarned;
    std::cout << "Interest Earned = " << InterestEarned << std::endl;
    std::cout << "Balance = " << balance << std::endl;
}