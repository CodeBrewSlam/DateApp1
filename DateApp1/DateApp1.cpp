#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Date {
private:
	int month, day, year;
	string monthName = "";

public:
	// Constructor
	Date(int m = 1, int d = 1, int y = 2001)
	{
		month = m;
		day = d;
		year = y;
		monthName = "January";
	}

	void setDate(int m, int d, int y, string mName);
	void printFormat1();
	void printFormat2();
	void printFormat3();
};

void Date::setDate(int m, int d, int y, string mName)
{
	month = m;
	day = d;
	year = y;
	monthName = mName;
}

void Date::printFormat1()
{
	int shortYear = year - 2000;

	cout << endl << month << '/' << day << '/';

	if (shortYear >= 0 && shortYear <= 9)
		cout << 0 << shortYear;
	else
		cout << shortYear;
}

void Date::printFormat2()
{
	cout << endl << monthName << " " << day << ", " << year;
}

void Date::printFormat3()
{
	cout << endl << day << " " << monthName << " " << year;
}
int main()
{
	Date date1;

	const int MAX_YEAR = 2099;
	const int MIN_YEAR = 2000;

	int month = 0;
	int day = 0;
	int year = 0;
	bool leapYear = false;
	string monthName = "";

	do
	{
		cout << "Enter a year between 2000 and 2099: ";
		cin >> year;

		if (year < MIN_YEAR || year > MAX_YEAR)
		{
			cout << "\nINVALID INPUT - Please enter a year between 2000 and 2099.\n";
		}
	} while (year < MIN_YEAR || year > MAX_YEAR);

	for (int i = MIN_YEAR; i <= MAX_YEAR; i += 4)
	{
		if (year == i)
		{
			leapYear = true;
		}
	}

	do
	{
		cout << "Enter a month (1 - 12): ";
		cin >> month;

		if (month < 1 || month > 12)
		{
			cout << "\nINVALID INPUT - Please enter a valid month number (1 - 12).\n";
		}

	} while (month < 1 || month > 12);

	switch (month)
	{
	case 1: monthName = "January";
		break;
	case 2: monthName = "February";
		break;
	case 3: monthName = "March";
		break;
	case 4: monthName = "April";
		break;
	case 5: monthName = "May";
		break;
	case 6: monthName = "June";
		break;
	case 7: monthName = "July";
		break;
	case 8: monthName = "August";
		break;
	case 9: monthName = "September";
		break;
	case 10: monthName = "October";
		break;
	case 11: monthName = "November";
		break;
	case 12: monthName = "December";
	}



	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		do
		{
			cout << "Enter the number of a day: ";
			cin >> day;

			if (day < 1 || day > 31)
			{
				cout << "\nINVALID INPUT - Please enter a valid day for the month of " << monthName << ".\n";
			}
		} while (day < 1 || day > 31);

	}

	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		do
		{
			cout << "Enter the number of a day: ";
			cin >> day;

			if (day < 1 || day > 30)
			{
				cout << "\nINVALID INPUT - Please enter a valid day for the month of " << monthName << ".\n";
			}
		} while (day < 1 || day > 30);
	}


	else
	{
		if (leapYear)
		{
			do
			{
				cout << "Enter the number of a day: ";
				cin >> day;

				if (day < 1 || day > 29)
				{
					cout << "\nINVALID INPUT - Please enter a valid day for the month of " << monthName << ".\n";
				}
			} while (day < 1 || day > 29);
		}

		else
		{
			do
			{
				cout << "Enter the number of a day: ";
				cin >> day;

				if (day < 1 || day > 28)
				{
					cout << "\nINVALID INPUT - Please enter a valid day for the month of " << monthName << ".\n";
				}
			} while (day < 1 || day > 28);
		}
	}

	date1.setDate(month, day, year, monthName);
	date1.printFormat1();
	date1.printFormat2();
	date1.printFormat3();

	return 0;
}

