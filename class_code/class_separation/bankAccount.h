#include<string>

using namespace std;

class bankAccount
{
private:
    double balance;
    string accountId;
public:
    bankAccount(double amount = 0, string id = "123456789"); //constructor w/params
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
};