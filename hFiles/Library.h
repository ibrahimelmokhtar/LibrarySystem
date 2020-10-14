#pragma once

#ifndef LIBRARY
#define LIBRARY

#include "Book.h"
#include "BookList.h"
#include "Member.h"
#include "MemberList.h"
#include "Borrower.h"
#include "BorrowerList.h"

#include <iostream>
#include <string>
#include <fstream>

class Library
{
public:
	// required variables:
	BookList Books;
	MemberList Members;
	BorrowerList Borrowers;

	// used for books manipulation
	void editBooks();

	// used for members manipulation
	void editMembers();
	
	// used for borrowers manipulation
	void editBorrowers();
};

#endif // !LIBRARY
