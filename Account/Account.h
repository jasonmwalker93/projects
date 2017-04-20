//Account class declaration
#ifndef ACCOUNT_H
#define ACCOUNT_H

# include <iostream>
using namespace std;

class Account
{
protected:
	double balance;
public:
	Account();
	Account(double x);
	void setAccount(double x);
	double getBalance();
	double credit(double x);
	bool debit(double x);
};
#endif