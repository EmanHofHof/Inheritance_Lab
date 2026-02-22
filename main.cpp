//Name: Ethan Hofsteen
//Date: 2/22/26
//Class: MSCI-272
//Purpose: Use a class and operator overloading to organize Bank Accounts within a Vector
//and deposit, withdraw, deposit, and compare those Bank Accounts
#include <iostream>
#include <vector>
#include <memory>
#include "BankAccount.h"
//searches through accounts vector by ID (returns corresponding vector index)
int FindAccountbyID(const std::vector<std::unique_ptr<BankAccount>>& accounts, const std::string accNum) {
        for (int i = 0; i < accounts.size(); ++i) {
            if (accounts.at(i)->GetAccountNum() == accNum) {
                std::cout << "Account Found" << std::endl;
                return i;
            }
        }
    std::cout << "Account Not Found" << std::endl;
    return -1;
}
//searches through accounts vector by Name (returns corresponding vector index)
int FindAccountbyName(const std::vector<std::unique_ptr<BankAccount>>& accounts, const std::string accName) {
    for (int i = 0; i < accounts.size(); ++i) {
        std::string storedName = accounts.at(i)->GetAccountHolderName();
        if (accounts.at(i)->GetAccountHolderName() == accName) {
            std::cout << "Account Found" << std::endl;
            return i;
        }
    }
    std::cout << "Account Not Found" << std::endl;
    return -1;
}
int main() {
    std::vector<std::unique_ptr<BankAccount>> accounts;
    int choice;
        do {
            choice = BankAccount::PrintDisplay();
            switch (choice) {
                //New Account Creation
                case 1:{
                    //All logic written in BankAccount.cpp
                    std::unique_ptr<BankAccount> newAccount = BankAccount::createAccountFromInput();
                    accounts.push_back(std::move(newAccount));
                    break;
                }
                    //Deposit to existing account
                case 2: {
                    std::string searchID;
                    double depositAmount;
                    std::cout << "Enter Account ID: "; std::cin >> searchID;
                    int index = FindAccountbyID(accounts, searchID);
                        //check if account exists
                        if (index != -1) {
                            std::cout << "Enter Deposit Amount: " << std::endl;
                            std::cin >> depositAmount;
                            //ensure deposit is positive
                            if (depositAmount < 0) {
                                while (depositAmount < 0) {
                                    std::cout << "Invalid Deposit Amount (must be positive): ";
                                    std::cin >> depositAmount;
                                }
                            }
                            *accounts.at(index) += depositAmount;              //.Deposit(depositAmount);
                        }
                    break;
                }
                    //Withdraw from existing Account
                case 3: {
                    std::string searchID;
                    double withdrawAmount;
                    std::cout << "Enter Account ID: "; std::cin >> searchID;
                    int index = FindAccountbyID(accounts, searchID);
                        //find existing account
                        if (index != -1) {
                            std::cout << "Enter Withdraw Amount: " << std::endl;
                            std::cin >> withdrawAmount;
                            //ensure withdrawal is positive
                            if (withdrawAmount < 0) {
                                while (withdrawAmount < 0) {
                                    std::cout << "Invalid Withdraw Amount (must be positive): ";
                                    std::cin >> withdrawAmount;
                                }
                            }
                            //ensure withdrawal is less than account balance
                            if (withdrawAmount > accounts.at(index)->GetBalance()) {
                                std::cout << "---Insufficient Funds---" << std::endl;
                                break;
                            }
                            *accounts.at(index) -= withdrawAmount;
                        }
                    break;
                }
                    //Display All Accounts
                case 4: {
                    std::cout << "--------------------" << std::endl;
                    //loop through accounts vector
                    for (int i = 0; i < accounts.size(); ++i) {
                        BankAccount::printAccount(*accounts.at(i));
                    }
                    break;
                }
                case 5: {
                    if (accounts.size() < 2) {
                        std::cout << "Need at least 2 accounts to compare" << std::endl;
                        break;
                    }
                    int ComparisonChoice = BankAccount::ComparisonDisplay();
                    switch (ComparisonChoice) {
                        //Equal Comparison
                        case 1: {
                            if (std::cin.peek() == '\n') std::cin.ignore();
                            std::string Searchindex1, Searchindex2;
                            std::cout << "Enter 1st Account Name: "; getline(std::cin, Searchindex1);
                            int index1 = FindAccountbyName(accounts, Searchindex1);
                            std::cout << "Enter 2nd Account Name: "; getline(std::cin,Searchindex2);
                            int index2 = FindAccountbyName(accounts, Searchindex2);
                            if (index1 != -1 && index2 != -1) {
                                if (*accounts.at(index1) == *accounts.at(index2)) {
                                    std::cout << "Account Numbers are Identical" << std::endl;
                                    std::cout << accounts.at(index1)->GetAccountHolderName() << " has the same ID as ";
                                    std::cout << accounts.at(index2)->GetAccountHolderName() << std::endl;
                                }
                                else {
                                    std::cout << "Account Numbers are Not Identical" << std::endl;
                                }
                            }
                            else {
                                std::cout << "One or both entered account Names are invalid" << std::endl;
                            }
                            break;
                        }
                        //less than Comparison
                        case 2: {
                            std::string Searchindex1, Searchindex2;
                            std::cout << "Enter 1st Account ID: "; std::cin >> Searchindex1;
                            int index1 = FindAccountbyID(accounts, Searchindex1);
                            std::cout << "Enter 2nd Account ID: "; std::cin >> Searchindex2;
                            int index2 = FindAccountbyID(accounts, Searchindex2);
                            if (index1 != -1 && index2 != -1) {
                                if (*accounts.at(index1) < *accounts.at(index2)) {
                                    std::cout << accounts.at(index1)->GetAccountHolderName() << " has a lower balance than ";
                                    std::cout << accounts.at(index2)->GetAccountHolderName() << std::endl;
                                }
                                else {
                                    std::cout << accounts.at(index1)->GetAccountHolderName() << " does not have a lower balance than ";
                                    std::cout << accounts.at(index2)->GetAccountHolderName() << std::endl;
                                }
                            }
                            break;
                        }
                            //greater than Comparison
                        case 3: {
                            std::string Searchindex1, Searchindex2;
                            std::cout << "Enter 1st Account ID: "; std::cin >> Searchindex1;
                            int index1 = FindAccountbyID(accounts, Searchindex1);
                            std::cout << "Enter 2nd Account ID: "; std::cin >> Searchindex2;
                            int index2 = FindAccountbyID(accounts, Searchindex2);
                            if (index1 != -1 && index2 != -1) {
                                if (*accounts.at(index1) > *accounts.at(index2)) {
                                    std::cout << accounts.at(index1)->GetAccountHolderName() << " has a higher balance than ";
                                    std::cout << accounts.at(index2)->GetAccountHolderName() << std::endl;
                                }
                                else {
                                    std::cout << accounts.at(index1)->GetAccountHolderName() << " does not have a higher balance than ";
                                    std::cout << accounts.at(index2)->GetAccountHolderName() << std::endl;
                                }
                            }
                            break;
                        }
                        case 4: {
                            std::cout << "Exiting Comparison Menu" << std::endl;
                            break;
                        }
                    }
                    break;
                }
                //Apply Interest
                case 6: {
                    if (accounts.empty()) {
                        std::cout << "No Accounts Created" << std::endl;
                        std::cout << "Create a Savings Account before Applying Interest" << std::endl;
                    }
                    std::string SearchID;
                    std::cout << "Enter Savings Account ID to Apply Interest: " << std::endl;
                    std::cin >> SearchID;
                    int index = FindAccountbyID(accounts, SearchID);
                    if (index != -1) {
                        accounts.at(index)->calculateInterest();
                    }
                    break;
                }
                case 7: {
                    std::cout << "Thank You For Trying My Program" << std::endl;
                }
            }
        }while (choice != 7);
        return 0;
    }