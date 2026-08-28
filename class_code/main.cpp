#include <iostream>
#include <string>
#include "bankAccount.h"
using namespace std;

int main()
{
    bankAccount myAccount; //construct with defaults
    myAccount.deposit(500);
    myAccount.deposit(140);
    myAccount.withdraw(80);
    cout << "Current balance is: " << myAccount.getBalance() << endl;

    bankAccount yourAccount(100,"dhfjksh38473974"); //construct w/params
    cout << "Your account balance: " << yourAccount.getBalance() << endl;
    yourAccount.deposit(350);
    yourAccount.deposit(-90);
    yourAccount.withdraw(50);
    yourAccount.withdraw(10000);
    cout << "Your account balance: " << yourAccount.getBalance() << endl;

    return 0;
}

