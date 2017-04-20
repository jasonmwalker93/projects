# include "Account.h"
# include "Savings.h"
# include "Checking.h"

int main()
{
	Account a;
	SavingAccount s;
	CheckingAccount c;
	double input, input2, input3, input4, x;

	//creates sentinel-controlled loop for modifying the three types of account

	cout << "Would you like to modify a regular, savings, or checking account?" << endl;
	cout << "Press 1 for regular account, 2 for savings account, 3 for checking account, or 0 to quit: ";
	cin >> input;

	while (input != 0)
	{
		if (input == 1)
		{					//creates inner sentinel-controlled loop for regular account, which implements all member functions
			cout << "ACCOUNT: Press 1 to view balance, 2 to set balance, 3 to credit account, 4 to debit account, or 0 to return to main menu: ";
			cin >> input2;

			while (input2 != 0)
			{
				if (input2 == 1)
					cout << "Account Balance: $" << a.getBalance() << endl;
				else if (input2 == 2)
				{
					cout << "Enter account balance: ";
					cin >> x;
					a.setAccount(x);
					if (a.getBalance() > 0)
						cout << "Account balance set." << endl;
					else
						cout << "Account balance set to $0." << endl;
				}
				else if (input2 == 3)
				{
					cout << "Enter amount to credit account: ";
					cin >> x;
					cout << "Account credited. Remaining balance: $" << a.credit(x) << endl;
				}
				else if (input2 == 4)
				{
					cout << "Enter amount to debit: ";
					cin >> x;
					a.debit(x);
				}
				else if (input2 == 0)
					break;
				else
					cout << "Error: invalid input. Please enter a valid option (0-4)." << endl;

				cout << "ACCOUNT: Press 1 to view balance, 2 to set balance, 3 to credit account, 4 to debit account, or 0 to return to main menu: ";
				cin >> input2;
			}
		}
		else if (input == 2)
		{					//creates inner sentinel-controlled loop for savings account, which implements all member functions
			cout << "SAVINGS: Press 1 to view balance, 2 to set balance, 3 to set interest rate, 4 to calculate interest, 5 to add interest, 6 to credit account, 7 to debit account, or 0 to return to main menu: ";
			cin >> input3;

			while (input3 != 0)
			{
				if (input3 == 1)
				{
					cout << "Account balance: $" << s.getBalance() << endl;
					cout << "Account interest rate: " << s.getInterest() << "%" << endl;
				}
				else if (input3 == 2)
				{
					cout << "Enter account balance: ";
					cin >> x;
					s.setAccount(x);
					if (s.getBalance() > 0)
						cout << "Account balance set." << endl;
					else
						cout << "Account balance set to $0." << endl;
				}
				else if (input3 == 3)
				{
					cout << "Enter interest rate: ";
					cin >> x;
					if (x < 0)
					{
						cout << "Error: interest rate cannot be negative." << endl;
						s.setInterest(0);
						cout << "Interest rate set to 0." << endl;
					}
					else
					{
						s.setInterest(x);
						cout << "Account interest set." << endl;
					}
				}
				else if (input3 == 4)
					cout << "Account interest: $" << s.calculateInterest() << endl;
				else if (input3 == 5)
				{
					s.credit(s.calculateInterest());
					cout << "Interest added to account. Remaining balance: $" << s.getBalance() << endl;
				}
				else if (input3 == 6)
				{
					cout << "Enter amount to credit account: ";
					cin >> x;
					cout << "Account credited. Remaining balance: $" << s.credit(x) << endl;
				}
				else if (input3 == 7)
				{
					cout << "Enter amount to debit: ";
					cin >> x;
					s.debit(x);
				}
				else if (input3 == 0)
					break;
				else

					cout << "Error: invalid input. Please enter a valid option (0-7)." << endl;

				cout << "SAVINGS: Press 1 to view balance, 2 to set balance, 3 to set interest rate, 4 to calculate interest, 5 to add interest, 6 to credit account, 7 to debit account, or 0 to return to main menu: ";
				cin >> input3;
			}
		}
		else if (input == 3)
		{					//creates inner sentinel-controlled loop for checking account, which implements all member functions
			cout << "CHECKING: Press 1 to view balance, 2 to set balance, 3 to set account fee, 4 to charge fee, 5 to credit account, 6 to debit account, or 0 to return to main menu: ";
			cin >> input4;

			while (input4 != 0)
			{
				if (input4 == 1)
				{
					cout << "Account balance: $" << c.getBalance() << endl;
					cout << "Account fee: $" << c.getFee() << endl;
				}
				else if (input4 == 2)
				{
					cout << "Enter account balance: ";
					cin >> x;
					c.setAccount(x);
					if (c.getBalance() > 0)
						cout << "Account balance set." << endl;
					else
						cout << "Account balance set to $0." << endl;
				}
				else if (input4 == 3)
				{
					cout << "Enter account fee: ";
					cin >> x;
					if (x < 0)
					{
						cout << "Error: account fee cannot be negative (unfortunately)." << endl;
						c.setFee(0);
						cout << "Account fee set to $0." << endl;
					}
					else
					{
						c.setFee(x);
						cout << "Account fee set." << endl;
					}
				}
				else if (input4 == 4)
					c.chargeFee();
				else if (input4 == 5)
				{
					cout << "Enter amount to credit account: ";
					cin >> x;
					cout << "Account credited. Remaining balance: $" << c.credit(x) << endl;
				}
				else if (input4 == 6)
				{
					cout << "Enter amount to debit: ";
					cin >> x;
					c.debit(x);
				}
				else if (input4 == 0)
					break;
				else
					cout << "Error: invalid input. Please enter a valid option (0-6)." << endl;

				cout << "CHECKING: Press 1 to view balance, 2 to set balance, 3 to set account fee, 4 to charge fee, 5 to credit account, 6 to debit account, or 0 to return to main menu: ";
				cin >> input4;
			}
		}
		else
		{
			cout << "Error: invalid input. Please enter a valid option (0-3)." << endl;
			cout << "Press 1 for regular account, 2 for savings account, 3 for checking account, or 0 to quit: ";
			cin >> input;
		}

		cout << "Would you like to modify a regular, savings, or checking account?" << endl;
		cout << "Press 1 for regular account, 2 for savings account, 3 for checking account, or 0 to quit: ";
		cin >> input;
	}

	system("pause");
	return 0;
}