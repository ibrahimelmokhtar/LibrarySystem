#pragma once

#ifndef DATE
#define DATE

#include <string>
#include <iostream>

class Date
{
	friend std::ostream& operator<< (std::ostream& output, Date& d);
	friend std::istream& operator>> (std::istream& input, Date& d);

private:
	int day;
	int month;
	int year;

public:
	// Constructors:
	Date();
	Date(int d, int m, int y);

	// Setter functions:
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(Date d);

	// Getter functions:
	int getDay();
	int getMonth();
	int getYear();
};
#endif // !DATE
