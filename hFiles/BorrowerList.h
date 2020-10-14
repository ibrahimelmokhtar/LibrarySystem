#pragma once

#ifndef BORROWERLIST
#define BORROWERLIST

#include "Member.h"
#include "Borrower.h"
#include "Book.h"

using namespace std;

class BorrowerList : public Borrower
{
private:
	Borrower* startBorrower;
	Borrower* currBorrower;

public:
	// Constructors:
	BorrowerList();
	~BorrowerList();

	// Search functions:
	bool searchByID(string id, bool DISPLAY = false);

	// Check functions:
	bool checkID(string id);
	bool checkISBN(string isbn);

	// Add new borrower:
	void addBorrower(char id[], char N[], char a[], char isbn[], Date bd, Date rd);

	// Save new borrower:
	void saveBorrower();

	// Display functions:
	void displayList();
	void displayBorrower(string id);
};
#endif // !BORROWERLIST
