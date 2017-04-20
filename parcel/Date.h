# include <iostream>
using namespace std;

class Date
{
private:
	int month;	//a private data field of Date class
	int day;	//a private data field of Date class
	int year;	//a private data field of Date class
	//all of these fields can only be accessed by
	//member-functions of the class
public:
	Date();							//default constructor
	Date(int, int, int);  			//assignment constructor
	int getMonth();
	int getDay();
	int getYear();
	void getDate();					//to get a date from the user and store it in a Date object
	void setDate(int, int, int);    //for constructing and storing data
	void displayDate();	            //to display an object on the screen
	void copyDate(Date);			//to copy a Date object to another
	int difference(Date);			//for subtraction operation
	bool operator< (Date &);
	int operator- (Date &);
	bool operator== (Date &);
	Date Date::futureDate(int n);
	Date Date::pastDate(int n);
};
//class implementation section
Date::Date()				//when called, creates an object of this class and
{							//initializes the data members of the object with zero	
	month = 0;
	day = 0;
	year = 0;
}
Date::Date(int m, int d, int y)      //when called, creates an object of this class
{			      //and initializes components with the received values
	month = m;
	day = d;
	year = y;
}
int Date::getMonth()	//to extract month component of a Date object
{
	return month;
}
int Date::getDay()      //to extract day component of a Date object
{
	return day;
}
int Date::getYear()     //to extract year component of a Date object
{
	return year;
}
void Date::getDate()
{
	cout << "enter month, day and year separated by a space: ";
	cin >> month >> day >> year;
}
void Date::displayDate()	//displays the date when called
{
	cout << month << "/" << day << "/" << year << endl;
}
void Date::setDate(int mo, int da, int yr)	//to assign a date to a Date object
{
	month = mo;
	day = da;
	year = yr;
}
void Date::copyDate(Date d)
{
	month = d.getMonth();
	day = d.getDay();
	year = d.getYear();
}
int Date::difference(Date d2)   //finds the number of days between two dates
{
	int days;
	if (d2.month != month || d2.year != year)
	{
		cout << "invalid dates used in difference function" << endl;
		return -1;
	}
	else
	{		             
		if (d2.day > day)
			days = d2.day - day;
		else
			days = day - d2.day;
		return days;
	}
}
bool Date::operator< (Date &d)
{
	if (year < d.year)
		return true;
	else if (year > d.year)
		return false;
	else if (month < d.month)		//years are equal. Compare months
		return true;
	else if (month > d.month)
		return false;
	else              				//months are equal. Compare days
		return day < d.day;
}
int Date::operator- (Date &d2)
{
	int difference;
	int totaldays = (day)+(month * 30) + (year * 360);
	int totaldays2 = (d2.day) + (d2.month * 30) + (d2.year * 360);
	if (totaldays > totaldays2)
		difference = totaldays - totaldays2;
	else
		difference = totaldays2 - totaldays;
	return difference;
}
bool Date::operator== (Date &newDate)
{
	if (month == newDate.month)
	{
		if (day == newDate.day)
		{
			if (year == newDate.year)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
Date Date::futureDate(int n)
{
	Date future;
	future.day = day + n;
	future.month = month;
	future.year = year;
	while (future.day > 30)
	{
		future.day -= 30;
		future.month++;
	}
	while (future.month > 12)
	{
		future.month -= 12;
		future.year++;
	}
	return future;
}
Date Date::pastDate(int n)
{
	Date past;
	past.day = day - n;
	past.month = month;
	past.year = year;
	while (past.day < 0)
	{
		past.day += 30;
		past.month--;
	}
	while (past.month < 0)
	{
		past.month += 12;
		past.year--;
	}
	return past;
}