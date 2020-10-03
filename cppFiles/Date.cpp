#include "../hFiles/Date.h"

// Constructors:

Date::Date()
{
	setDay(1);
	setMonth(1);
	setYear(2016);
}

Date::Date(int d, int m, int y)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}

// Setter functions:

void Date::setDay(int d)
{
	// Special case for Feb.
	if (getMonth() == 2) {
		if (d % 29 != 0 && d / 28.0 <= 1.0) {
			day = d;
		}
		else {
			std::cout << "*** setting default day ***\n";
			day = 1;
		}
	}
	// Odd month: (Jan, Mar, May, ... etc.)
	else if (getMonth() % 2 != 0) {

		if (d % 31 != 0 && d / 30.0 <= 1.0) {
			day = d;
		}
		else {
			std::cout << "*** setting default day ***\n";
			day = 1;
		}
	}
	// Even month: (Apr, Jun, Aug, ... etc.)
	else {
		if (d % 32 != 0 && d / 31.0 <= 1.0) {
			day = d;
		}
		else {
			std::cout << "*** setting default day ***\n";
			day = 1;
		}
	}
}

void Date::setMonth(int m)
{
	if (m%13 != 0 && m/12.0 <= 1.0) {
		this->month = m;
	}
	else {
		this->month = 1;
	}
}
void Date::setYear(int y)
{
	year = y;
}
void Date::setDate(Date d)
{
	setYear(d.getYear());
	setMonth(d.getMonth());
	setDay(d.getDay());	
}

// Getter functions:

int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}


// Used for making customized Input/Output for Date():

std::istream& operator>>(std::istream& input, Date& D)
{
	input >> D.day >> D.month >> D.year;
	return input;
}

std::ostream& operator<<(std::ostream& output, Date& D)
{
	output << D.day << " / " << D.month << " / " << D.year;
	return output;
}
