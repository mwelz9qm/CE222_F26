#pragma once
#include<iostream>
#include<string>
#include"bankexceptions.h"

using namespace std;

class BankAccount {
private:
	string accountNumber;
	string ownerName;
	double balance;
	bool isOpen;

	// Helper to validate account number format (must be 8 digits)
	void validateAccountNumber(const string& acctNum) {
		if (acctNum.length() != 8) {
			throw InvalidAccountException(acctNum);
		}
		for (char c : acctNum) {
			if (!isdigit(c)) {
				throw InvalidAccountException(acctNum);
			}
		}
	}

public:
	// Constructor can throw InvalidAccountException
	BankAccount(const string& acctNum, const string& owner, double initialDeposit = 0.0)
		: accountNumber(acctNum), ownerName(owner), balance(initialDeposit), isOpen(true) {
		validateAccountNumber(acctNum);
		
		if (initialDeposit < 0) {
			throw InvalidAmountException(acctNum, initialDeposit);
		}
	}

	void deposit(double amount) {
		if (amount <= 0) {
			throw InvalidAmountException(accountNumber, amount);
		}
		balance += amount;
		cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
	}

	void withdraw(double amount) {
		if (amount <= 0) {
			throw InvalidAmountException(accountNumber, amount);
		}
		if (amount > balance) {
			throw InsufficientFundsException(accountNumber, amount, balance);
		}
		balance -= amount;
		cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
	}

	void closeAccount() {
		if (balance > 0.01) { // Allow for floating point rounding
			throw AccountNotEmptyException(accountNumber, balance);
		}
		isOpen = false;
		cout << "Account " << accountNumber << " closed successfully." << endl;
	}

	double getBalance() const { return balance; }
	string getAccountNumber() const { return accountNumber; }
	string getOwnerName() const { return ownerName; }
};