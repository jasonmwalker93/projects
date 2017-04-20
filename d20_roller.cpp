# include <iostream>
# include <time.h>
# include <cstdlib>
# include <cctype>
# include <string>
using namespace std;

void cast();

int main()
{
	srand(time(NULL));

	string input, input2, sub1, sub2, sub3, sub4, sub5;
	int total = 0, ind = 0;
	int result1 = 0, result2 = 0, result3 = 0;
	string::size_type sz;

	cout << "Enter 1 for quick d20, 2 for custom roll, 3 to reroll, 4 to quit: ";
	cin >> input;

	while(input != "4")
	{
		if (input == "1")
		{
			int num = (rand() % 20) + 1;
			cout << "d20: " << num << endl;
			ind = 1;
		}

		else if (input == "2")
		{
			cout << "Enter number of desired dice, 'd', die size, '+' or '-', then modifier: ";
			cin >> input2;

			sub1.clear(), sub2.clear(), sub3.clear(), sub4.clear(), sub5.clear();
			result1 = 0, result2 = 0, result3 = 0;

			int l1 = input2.length();
			for (int a = 0; a < l1; a++)
				{
					if (input2[0] == 'd')
						break;
					if (isdigit(input2[0]) != 0)
					{
						sub1.push_back(input2[0]);
						input2.erase(0, 1);

						result1 = (result1*10) + (sub1[a] - 48);
					}
					else
						break;
			}
			
			sub2.push_back(input2[0]);
			input2.erase(0,1);

			int l2 = input2.length();
			for (int a = 0; a < l2; a++)
				{
					if (input2[0] == '+' || input2[0] == '-')
						break;
					if (isdigit(input2[0]) != 0)
					{
						sub3.push_back(input2[0]);
						input2.erase(0, 1);

						result2 = (result2*10) + (sub3[a] - 48);
					}
					else
						break;
			}

			sub4.push_back(input2[0]);
			input2.erase(0,1);

			int l3 = input2.length();
			for (int a = 0; a < l3; a++)
			{
				if (isdigit(input2[0]) != 0)
				{
					sub5.push_back(input2[0]);
					input2.erase(0, 1);

					result3 = (result3*10) + (sub5[a] - 48);
				}
					else
						break;
			}

			if ((sub2 == "d") && ((sub4 == "+") || (sub4 == "-")))
			{
				total = 0;
				for (int a = 0; a < result1; a++)
				{
					int num1 = (rand() % result2) + 1;
					total += num1;
				}
				if (sub4 == "+")
				{
					total += result3;
					cout << result1 << "d" << result2 << sub4 << result3 << ": " << total << endl;
				}
				else if (sub4 == "-")
				{
					total -= result3;
					cout << result1 << "d" << result2 << sub4 << result3 << ": " << total << endl;
				}
			}
			else
				cout << "Error: invalid input." << endl;
			ind = 2;
		}

		else if (input == "3") 
		{
			if (ind == 1)
			{
				int num = (rand() % 20) + 1;
				cout << "d20: " << num << endl;
				ind = 1;
			}
			else if ((ind == 2) && (result1 != 0) && (result2 != 0) && (result3 != 0))
			{
				total = 0;
				for (int a = 0; a < result1; a++)
				{
					int num1 = (rand() % result2) + 1;
					total += num1;
				}
				if (sub4 == "+")
				{
					total += result3;
					cout << result1 << "d" << result2 << sub4 << result3 << ": " << total << endl;
				}
				else if (sub4 == "-")
				{
					total -= result3;
					cout << result1 << "d" << result2 << sub4 << result3 << ": " << total << endl;
				}
			}
			else
				cout << "Error: no previous roll" << endl;
		}

		cout << "Enter 1 for quick d20, 2 for custom roll, 3 to reroll, 4 to quit: ";
		cin >> input;
	}

system("pause");
return 0;
}