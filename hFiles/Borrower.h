#pragma once

#ifndef BORROWER
#define BORROWER

#include"../hFiles/Date.h"
#include "../hFiles/Book.h"
#include "../hFiles/Member.h"

#include <iostream>

using namespace std;

class Borrower : public Member	// class Borrower is inheriting class Member
{
	friend std::ostream& operator<< (std::ostream& output, Borrower& b);

private:
	char bookISBN[16];
	Date borrowing_date;
	Date return_date;
	Borrower* nextBorrower;

public:
	// Constructors:
	Borrower();
	Borrower(char id[], char N[], char a[], char isbn[], Date borrowD, Date returnD);

	// Setter functions:
	//void setID(char[]);
	void setISBN(char[]);
	void setBorrowDate(Date d);
	void setReturnDate(Date d);
	void setNext(Borrower*);
	
	// Getter functions:
	char* getISBN();
	Date getReturnDate();
	Date getBorrowDate();
	Borrower* getNext();
};

#endif // !BORROWER
