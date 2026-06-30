#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <iostream>
#include <vector>

class BankAccount
{
    std::string name;
    double balance;

public:
    BankAccount(std::string name, double balance)
    {
        if (name.empty())
            this->name = "Unknown";
        else
            this->name = name;
        balance > 0 ? this->balance = balance : this->balance = 0;
    }
    std::string getName() const
    {
        return name;
    }
    BankAccount &operator+=(double amount)
    {
        balance += amount;
        return *this;
    }
    void display() const
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Balance: " << balance << std::endl
                  << std::endl;
    }
};

std::string normalizedName(std::string);
void showMainMenu();
void addAccount(std::vector<BankAccount> &);
void displayAllAccounts(const std::vector<BankAccount> &);
void searchAccountByName(const std::vector<BankAccount> &);
void depositMoney(std::vector<BankAccount> &);

#endif