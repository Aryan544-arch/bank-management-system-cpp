#include<iostream>
#include "bankAccount.hpp"
#include<vector>
#include<cctype>

int main(){
    std::vector<BankAccount>accounts;
    while(true){
        showMainMenu();
        int n; std::cout<<"Enter Choice: "; std::cin>>n; std::cin.ignore();
        if(n==5) break;
        switch(n){
            case 1: addAccount(accounts); break;
            case 2: displayAllAccounts(accounts); break;
            case 3: searchAccountByName(accounts); break;
            case 4: depositMoney(accounts); break;
            default: std::cout<<"Invalid Input"<<std::endl<<std::endl;
        }
    }
    return 0;
}