#include <iostream>
#include "bankAccount.hpp"
#include <vector>
#include <cctype>

std::string normalizedName(std::string n)
{
    if (n.empty())
        return " ";
    n[0] = toupper(n[0]);
    int len = n.length();
    for (size_t i = 1; i < len; i++)
    {
        n[i] = tolower(n[i]);
    }
    return n;
}

void showMainMenu()
{
    std::cout << std::endl
              << std::endl;
    std::cout << "Press:" << std::endl
              << std::endl;
    ;
    std::cout << "1 to Add Account" << std::endl;
    std::cout << "2 to Display Accounts" << std::endl;
    std::cout << "3 to Search Account" << std::endl;
    std::cout << "4 to Deposit Money" << std::endl;
    std::cout << "5 to Exit" << std::endl
              << std::endl;
}

void addAccount(std::vector<BankAccount> &account)
{
    int n;
    std::cout << "Enter Number of Inputs: ";
    std::cin >> n;
    std::cin.ignore();
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            std::string name;
            getline(std::cin, name);
            name = normalizedName(name);
            double amount;
            std::cin >> amount;
            std::cin.ignore();
            account.emplace_back(name, amount);
        }
        if (n == 1)
            std::cout << "Account Added SuccessFully" << std::endl;
        else
            std::cout << "Accounts Added SuccessFully" << std::endl;
    }
    else
        std::cout << "Invalid Input" << std::endl;
}

void displayAllAccounts(const std::vector<BankAccount> &account)
{
    if (account.empty())
    {
        std::cout << "No Account Created" << std::endl;
        return;
    }
    else
    {
        int len = account.size();
        for (size_t i = 0; i < len; i++)
        {
            account[i].display();
        }
    }
}

void searchAccountByName(const std::vector<BankAccount> &account)
{
    if (account.empty())
    {
        std::cout << "No Account Created" << std::endl;
        return;
    }
    else
    {
        bool flag = false;
        std::string name;
        getline(std::cin, name);
        name = normalizedName(name);
        int len = account.size();
        for (size_t i = 0; i < len; i++)
        {
            if (account[i].getName() == name)
            {
                account[i].display();
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            std::cout << "Account Not Found" << std::endl;
        }
    }
}

void depositMoney(std::vector<BankAccount> &account)
{
    if (account.empty())
    {
        std::cout << "No Account Created" << std::endl;
        return;
    }
    else
    {
        bool flag = false;
        std::string name;
        getline(std::cin, name);
        name = normalizedName(name);
        double amount;
        std::cin >> amount;
        std::cin.ignore();
        int len = account.size();
        for (size_t i = 0; i < len; i++)
        {
            if (account[i].getName() == name)
            {
                account[i] += amount;
                std::cout << "Balance Updated" << std::endl;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            std::cout << "Account Not Found" << std::endl;
        }
    }
}