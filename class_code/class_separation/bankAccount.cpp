#include <iostream>
#include "bankAccount.h"
#include <string>
using namespace std;


void bankAccount::deposit(double amount)
{
    if (amount > 0)
        balance += amount;
    else
        cout << "Invalid deposit amount!" << endl;
}

void bankAccount::withdraw(double amount)
{
    if (balance < amount)
        cout << "Invalid withdraw amount: can't withdraw more than your balance!" << endl;
    else
        balance -= amount;
}

double bankAccount::getBalance () const
{
    return balance;
}

bankAccount::bankAccount(double amount, string id)
{
    if (amount > 0)
        balance = amount;
    else
        balance = 0;
    accountId = id;
}
