//Savings account declaration
#ifndef SAVINGS_H
#define SAVINGS_H
# include "Account.h"

class SavingAccount : public Account
{
private:
	double interest;
public:
	SavingAccount();
	SavingAccount(double x, double y);
	void setInterest(double x);
	double getInterest();
	double calculateInterest();
};
#endif