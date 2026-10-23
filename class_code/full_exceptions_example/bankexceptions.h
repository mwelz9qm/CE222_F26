#pragma once
#include<exception>
#include<stdexcept>

using namespace std;
//base class for all general bank exceptions
//inherits from std::runtime_error which inherits from std::exception
class BankException : public runtime_error
{
protected:
	string accountNumber; 
public:
	BankException(const string& message, const string& acctNum)
		:runtime_error(message), accountNumber(acctNum) {}
	string getAccountNumber() const { return accountNumber; }
};

//for overdraws
class InsufficientFundsException : public BankException
{
private:
	double attemptedAmount;
	double currentBalance;
public:
	InsufficientFundsException(const string &acctnum,double attempted, double balance)
		:BankException("Insufficient funds for withdrawal",acctnum), attemptedAmount(attempted), currentBalance(balance)
	{ }
	double getAttemptedAmount() const { return attemptedAmount; }
	double getCurrentBalance() const { return currentBalance; }
};
// an exception if you try to withdraw or deposit 0 or negative values
class InvalidAmountException : public BankException
{
private:
	double attemptedAmount;
public:
	InvalidAmountException(const string& acctnum, double attempted)
		:BankException("Invalid Transaction Amount", acctnum), attemptedAmount(attempted) {}
	double getAttemptedAmount() const { return attemptedAmount; }
};
//invalid account number format
class InvalidAccountException : public BankException
{
public:
	InvalidAccountException(const string& acctnum)
		:BankException("Invalid Account Number Format", acctnum) {}
};
//exception for when trying to close an account with a remaining balance
class AccountNotEmptyException : public BankException
{
private:
	double remainingBalance;
public:
	AccountNotEmptyException(const string& acctnum, double balance)
		: BankException("Cannot close account with remaining balance", acctnum), remainingBalance(balance)
	{}
	double getRemainingBalance() const { return remainingBalance; }
};