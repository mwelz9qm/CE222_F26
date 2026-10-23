#include<iostream>
#include "bankaccount.h"
using namespace std;

int main()
{
	cout << " --- Normal Operations --- " << endl;
	try {
		BankAccount account("12345678", "Alice", 1000);
		account.deposit(500);
		account.withdraw(300);
		cout << "Final Balance: " << account.getBalance() << endl;
	}
	catch (const BankException& ex)
	{
		cerr << "Bank Error: " << ex.what() << endl;
	}


	return 0;
}