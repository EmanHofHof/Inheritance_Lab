//
// Created by Ethan Hofsteen on 2/21/26.
//
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


