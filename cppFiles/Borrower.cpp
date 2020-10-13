#include"../hFiles/Borrower.h"

#include <fstream>
#include <iostream>

using namespace std;

Borrower::Borrower() : Member()
{
	char* empty = (char*)" ";
	Date d(1, 1, 2000);

	setISBN(empty);
	setBorrowDate(d);
	setReturnDate(d);
}
Borrower::Borrower(char id[], char N[], char a[], char isbn[], Date borrowD, Date returnD)
	:Member( id, N, a )
{
	setISBN(isbn);
	setBorrowDate(borrowD);
	setReturnDate(returnD);
}

void Borrower::setBorrowDate(Date d)
{
	borrowing_date.setDay(d.getDay());
	borrowing_date.setMonth(d.getMonth());
	borrowing_date.setYear(d.getYear());
}
void Borrower::setReturnDate(Date d)
{
	return_date.setDay(d.getDay());
	return_date.setMonth(d.getMonth());
	return_date.setYear(d.getYear());
}
void Borrower::setISBN(char isbn[])
{
	for (unsigned int i = 0; i < strlen(isbn); i++)
	{
		bookISBN[i] = isbn[i];
	}
}
void Borrower::setNext(Borrower* ne)
{
	nextBorrower = ne;
}

Date Borrower::getReturnDate()
{
	return return_date;
}
Date Borrower::getBorrowDate()
{
	return borrowing_date;
}
char* Borrower::getISBN()
{
	return bookISBN;
}
Borrower* Borrower::getNext()
{
	return nextBorrower;
}

std::ostream& operator<<(std::ostream& output, Borrower& B)
{
	Date borrowD = B.getBorrowDate();
	Date returnD = B.getReturnDate();

	output << "Member Name\t:" << B.getName() << "\n"
		<< "Member ID\t:" << B.getID() << "\n"
		<< "Member Address\t:" << B.getAdress() << "\n"
		<< "Book ISBN\t:" << B.getISBN() << "\n"
		<< "Borrow Date\t:" << borrowD << "\n"
		<< "Return Date\t:" << returnD << "\n";

	return output;
}
