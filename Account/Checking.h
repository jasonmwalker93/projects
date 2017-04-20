//Checking account delcaration
#ifndef CHECKING_H
#define CHECKING_H
# include "Account.h"

class CheckingAccount : public Account
{
private:
	double fee;
public:
	CheckingAccount();
	CheckingAccount(double x, double y);
	void setFee(double x);
	double getFee();
	bool chargeFee();
};
#endif