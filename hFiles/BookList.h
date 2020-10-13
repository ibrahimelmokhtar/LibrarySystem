#pragma once

#ifndef BOOKLIST
#define BOOKLIST

#include "../hFiles/Book.h"
#include "../hFiles/Date.h"

#include <iostream>
#include <fstream>

using namespace std;

class BookList : public Book
{
	friend std::ostream& operator<< (std::ostream& output, Book& b);

private:
	Book* startbook;
	Book* currbook;
public:
	// Constructors:
	BookList();
	~BookList();

	// Search functions:
	bool searchByName(string n, bool DISPLAY=true);
	bool searchByISBN(string isbn, bool DISPLAY=true);
	
	// Add new book:
	void addBook(char name[], char isbn[], char A[], Date d, char P[], int pages, Type C);

	// Save new book:
	void saveBook();

	// Display functions:
	void displayBook(string isbn);
	void displayList();
};
#endif // !BOOKLIST
