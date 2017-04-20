# include <iostream>
# include <stack>
# include <string>
# include <algorithm>
using namespace std;

int main()
{
	stack<int> calc;
	string input;
	int y, tmp1, tmp2, tmp3;

	cout << "Enter an arithmetic problem in postfix expression, without spaces (or @ to quit): ";
	cin >> input;

	while (input != "@")
	{
		for(int x = 0; x < input.length(); x++)
		{
			if(isdigit(input[x]))
			{
				y = input[x] - '0';								//converts input[x] to int
				calc.push(y);
			}
			else if (input[x] == '+' && calc.size() >= 2)		//ensures there are at least the minimum necessary
			{													//number of operands on the stack
				tmp1 = calc.top();
				calc.pop();
				tmp2 = calc.top();
				calc.pop();
				tmp3 = tmp2 + tmp1;
				calc.push(tmp3);
			}
			else if (input[x] == '-' && calc.size() >= 2)
			{
				tmp1 = calc.top();
				calc.pop();
				tmp2 = calc.top();
				calc.pop();
				tmp3 = tmp2 - tmp1;
				calc.push(tmp3);
			}
			else if (input[x] == '*' && calc.size() >= 2)
			{
				tmp1 = calc.top();
				calc.pop();
				tmp2 = calc.top();
				calc.pop();
				tmp3 = tmp2 * tmp1;
				calc.push(tmp3);
			}
			else if (input[x] == '/' && calc.size() >= 2)
			{
				tmp1 = calc.top();
				calc.pop();
				tmp2 = calc.top();
				calc.pop();
				tmp3 = tmp2 / tmp1;
				calc.push(tmp3);
			}
			else if (input[x] == '%' && calc.size() >= 2)
			{
				tmp1 = calc.top();
				calc.pop();
				tmp2 = calc.top();
				calc.pop();
				tmp3 = tmp2 % tmp1;
				calc.push(tmp3);
			}
			else
			{
				while(!calc.empty())			//clears the stack of improperly entered data
					calc.pop();
			}
		}

		if (calc.size() == 1)					//prints stack if there is data to print (and data was entered properly)
			cout << "Result: " << calc.top() << endl;
		else
			cout << "Invalid input. Please enter a valid expression. " << endl;

		while(!calc.empty())					//ensures the stack is clear before loop repeats
			calc.pop();

		cout << "Enter an arithmetic problem in postfix expression, without spaces (or @ to quit): ";
		cin >> input;
	}

	system("pause");
	return 0;
}