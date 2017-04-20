//Jason Walker
//CSCI 272 - Section 01
//Project 11.3.2
//Bank account handling program - adds interest to accounts and conducts searches of requested accounts
# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
using namespace std;

class SavAccount
{
private:
	string name;
	string acnt_num;
	float balance;
	static const float interest;	//initalized after class declaration
public:
	SavAccount::SavAccount()
	{
		name = " ";
		acnt_num = " ";
		balance = 0;
	}
	SavAccount::SavAccount(string s1, string s2, float f1)
	{
		name = s1;
		acnt_num = s2;
		balance = f1;
	}
	void SavAccount::setAccount(string s1, string s2, float f1)
	{
		name = s1;
		acnt_num = s2;
		balance = f1;
	}
	string SavAccount::getName()
	{
		return name;
	}
	string SavAccount::getAcnt_num()
	{
		return acnt_num;
	}
	float SavAccount::getBalance()
	{
		return balance;
	}
	const float SavAccount::getInterest()
	{
		return interest;
	}
	void SavAccount::getAccount()
	{
		cout << "Enter account holder name, account number, and account balance, seperated by spaces: ";
		cin >> name >> acnt_num >> balance;
	}
	void SavAccount::printAccount()
	{
		cout << "   " << "Account Holder:  " << name << "\n   " << "Account Number:  " << acnt_num 
			 << "\n   " << "Account Balance: $" << balance << endl;
	}
	void SavAccount::readFile(fstream &fname)
	{
		fname >> name >> acnt_num >> balance;
	}
	void SavAccount::addInterest(float x)	//parameter x is the number of months in which to calculate total interest
	{										//rate and balance for. For the project specifications, it will recieve 1
		float int_rate = interest * x;		//total interest rate = monthly interest rate * period of months (in this case 1)
		float int_return = balance * int_rate;	//amount of money added to the account = the balance * total interest rate
		balance += int_return;				//modifies balance data field by adding the calculated amount of interest gains
	}
	void SavAccount::searchAccount(string search, SavAccount array[], int size)
	{										//function recieves entered Account Number from user, array of SavAccount
		int z = 0;							//objects to search through, and size of SavAccout array
		while (array[z].acnt_num != search && z < size)		//loop compares Account Number variable of each SavAccount
			z++;											//object in array until it reaches the Account Number entered
		if (z < size)										//by the user, which has been passed as a parameter ("search")
			array[z].printAccount();
		if (z == size)
			cout << "Account not found." << endl;
	}
};
const float SavAccount::interest = 0.002916666667;	//monthly interest rate, assigned to each created class object

int main()
{
	fstream infile("accounts.dat", ios::in);
	string search_key;
	int x = 0, y = 0, z = 0;

	SavAccount customer[100];	//using large array size to handle "any number of data found the file"

	while (!infile.eof())
	{
		customer[x].readFile(infile);
		x++;
	}

	for (y = 0; y < x; y++)
	{
		customer[y].addInterest(1);		//adds 1 month interest to each SavAccount object (see addInterest function)
	}

	cout << "Enter account number to search for an account (or @ to quit): ";
	cin >> search_key;

	while (search_key != "@")
	{
		customer[0].searchAccount(search_key, customer, x);		//passes the entered Account Number, entire SavAccount array,
																//and size of SavAccount array to searchAccount function
		cout << "Enter account number to search for an account (or @ to quit): ";
		cin >> search_key;
	}

	system("pause");
	return 0;
}