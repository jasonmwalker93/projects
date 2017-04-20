//Parcel Service Program
//Manages mail and parcels for Parcel Service and calculates delivery charges
# include "Date.h"
# include <string>
# include <iomanip>

class Mail
{
protected:
	float weight;
	string address;
	Date stamp;
	Date deliv;
public:
	Mail::Mail()
	{
		weight = 0;
		address = " ";
		stamp = { 0, 0, 0 };
		deliv = { 0, 0, 0 };
	}
	Mail::Mail(float f, string s, Date d1, Date d2)
	{
		weight = f;
		address = s;
		stamp = d1;
		deliv = d2;
	}
	void Mail::setMail(float f, string s, Date d1, Date d2)
	{
		weight = f;
		address = s;
		stamp = d1;
		deliv = d2;
	}
	float Mail::getWeight()
	{
		return weight;
	};
	string Mail::getAddress()
	{
		return address;
	}
	Date Mail::getStamp()
	{
		return stamp;
	}
	Date Mail::getDeliv()
	{
		return deliv;
	}
	void Mail::displayMail()
	{
		cout << "Weight: " << weight << "\t"
			<< "Address: " << address << endl
			<< "Stamped Date: ";
		stamp.displayDate();
		cout << "Delivery Date: ";
		deliv.displayDate();
	}
	void Mail::getMail()
	{
		cout << "Enter mail weight (in ounces): ";
		cin >> weight;
		cout << "Enter recipient address: ";
		cin.ignore();
		getline(cin,address);		//uses getline function so full address (with spaces) can be entered
		cout << "For stamped date, ";
		stamp.getDate();
		cout << "For delivery date, ";
		deliv.getDate();
	}
	float Mail::findCharges()
	{
		float charge = 0.49 * weight;
		if (deliv - stamp < 3)		//adds 2 to charge if difference between stamped and delivery
			charge += 2;			//fields is less than 3
		return charge;
	}
};

class Parcel : public Mail
{
private:
	float length;
	float width;
	float height;
public:
	Parcel::Parcel() : Mail()
	{
		length = 0;
		width = 0;
		height = 0;
	}
	Parcel::Parcel(float f1, string s, Date d1, Date d2, float f2, float f3, float f4) : Mail(f1, s, d1, d2)
	{
		length = f2;
		width = f3;
		height = f4;
	}
	void Parcel::setParcel(float f1, string s, Date d1, Date d2, float f2, float f3, float f4)
	{
		setMail(f1, s, d1, d2);
		length = f2;
		width = f3;
		height = f4;
	}
	float Parcel::getLength()
	{
		return length;
	}
	float Parcel::getWidth()
	{
		return width;
	}
	float Parcel::getHeight()
	{
		return height;
	}
	void Parcel::displayParcel()
	{
		displayMail();
		cout << "Length: " << length << "\t"
			 << "Width: " << width << "\t"
			 << "Height: " << height << endl;
	}
	void Parcel::getParcel()
	{
		getMail();
		cout << "Enter parcel length, width, and height, seperated by spaces: ";
		cin >> length >> width >> height;
	}
	float Parcel::findCharges()
	{
		float charge = (0.49 * weight) + (0.20*(length + 2 * width + 2 * height));
		if (deliv - stamp < 3)		//adds 5 to charge if difference between stamped and delivery
			charge += 5;			//fields is less than 5
		return charge;
	}
};

int main()
{
	string name, input;
	Mail m1;
	Parcel p1;

	cout << "Enter name: ";
	cin >> name;

	cout << "Enter 'mail' for ordinary mail and 'parcel' for parcel (or 0 to quit): ";
	cin >> input;			//uses string to control loop, with a 0 sentinel. In the loop,
							//the string input enters an if/else structure, which then gets
	while (input != "0")	//recongnized as 'mail', parcel', or invalid input
	{
		if (input == "mail" || input == "Mail")
		{
			m1.getMail();
			cout << endl;
			m1.displayMail();
			cout << fixed << setprecision(2) << "Delivery Charges: $" << m1.findCharges() << endl << endl;
		}
		else if (input == "parcel" || input == "Parcel")
		{
			p1.getParcel();
			cout << endl;
			p1.displayParcel();
			cout << fixed << setprecision(2) << "Delivery Charges: $" << p1.findCharges() << endl << endl;
		}
		else
			cout << "Invalid input." << endl;

		cout << "Enter 'mail' for ordinary mail and 'parcel' for parcel (or 0 to quit): ";
		cin >> input;
	}

	system("pause");
	return 0;
}