//Complex number calculator
//Computes and displays basic operations on complex numbers
# include <iostream>
# include <iomanip>
# include <string>
using namespace std;

class Complex
{
private:
	float a;
	float b;
public:
	Complex::Complex()
	{
		a = 0;
		b = 0;
	}
	Complex::Complex(float x, float y)
	{
		a = x;
		b = y;
	}
	void Complex::setComplex(float x, float y)
	{
		a = x;
		b = y;
	}
	float Complex::getA()
	{
		return a;
	}
	float Complex::getB()
	{
		return b;
	}
	void Complex::getComplex()
	{
		cout << "Enter value for real and imaginary number, seperated by a space: ";
		cin >> a >> b;
	}
	void Complex::displayComplex()
	{
		cout << "(" << a << "+" << b << "i" << ")";
	}
	void Complex::operator= (Complex &newComplex)
	{
		a = newComplex.a;
		b = newComplex.b;
	}
	bool Complex::operator== (Complex &newComplex)
	{
		if (a == newComplex.a && b == newComplex.b)
			return true;
		else
			return false;
	}
	Complex Complex::operator+ (Complex &newComplex)
	{
		Complex val;
		val.a = a + newComplex.a;
		val.b = b + newComplex.b;
		return val;
	}
	Complex Complex::operator- (Complex &newComplex)
	{
		Complex val;
		val.a = a - newComplex.a;
		val.b = b - newComplex.b;
		return val;
	}
	Complex Complex::operator* (Complex &newComplex)
	{
		Complex val;
		val.a = ((a*newComplex.a) - (b*newComplex.b));
		val.b = ((a*newComplex.b) + (newComplex.a*b));
		return val;
	}
	Complex Complex::operator/ (Complex &newComplex)
	{
		Complex val;
		float denom = (newComplex.a*newComplex.a) + (newComplex.b*newComplex.b);
		val.a = ((a*newComplex.a) + (b*newComplex.b)) / (denom);
		val.b = ((b*newComplex.a) - (a*newComplex.b)) / (denom);
		return val;
	}
};

int main()
{
	Complex number1, number2;
	string op;

	cout << "Enter operator (+,-,*,/,==, or @ to quit): ";
	cin >> op;

	while (op != "@")
	{
		number1.getComplex(), number2.getComplex();

		if (op == "+")
		{
			number1.displayComplex();
			cout << " + ";
			number2.displayComplex();
			cout << " = ";
			(number1 + number2).displayComplex();
			cout << endl;
		}
		if (op == "-")
		{
			number1.displayComplex();
			cout << " - ";
			number2.displayComplex();
			cout << " = ";
			(number1 - number2).displayComplex();
			cout << endl;
		}
		if (op == "*")
		{
			number1.displayComplex();
			cout << " * ";
			number2.displayComplex();
			cout << " = ";
			(number1 * number2).displayComplex();
			cout << endl;
		}
		if (op == "/")
		{
			number1.displayComplex();
			cout << " / ";
			number2.displayComplex();
			cout << " = ";
			(number1 / number2).displayComplex();
			cout << endl;
		}
		if (op == "==")
		{
			if (number1 == number2)
			{
				number1.displayComplex();
				cout << " equals ";
				number2.displayComplex();
				cout << endl;
			}
			else
			{
				number1.displayComplex();
				cout << " does not equal ";
				number2.displayComplex();
				cout << endl;
			}
		}

		cout << "Enter operator (+,-,*,/,==, or @ to quit): ";
		cin >> op;
	}

	system("pause");
	return 0;
}