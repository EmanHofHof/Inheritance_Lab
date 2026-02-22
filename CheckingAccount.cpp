//Name: Ethan Hofsteen
//Date: 2/22/26.
//Class: MSCI-272
//Purpose: override the withdraw function for checking accounts and defines checking Account constructor
#include "BankAccount.h"
#include "CheckingAccount.h"
//withdrawal implementation
BankAccount& CheckingAccount::operator-=(double amount) {
    double totalWithdrawal = amount + transactionFee;
    return (BankAccount::operator-=(totalWithdrawal));
}
//constructor implementation
CheckingAccount::CheckingAccount(std::string ID, std::string name, double balance, double fee) :
    BankAccount(ID, name, balance ), transactionFee(fee) {};


