#pragma once

#include "Date.h"
#include <string>


// Define book's cover type:
#ifndef TYPE
#define TYPE

enum Type
{
	hard,
	soft
};

#endif // !TYPE


#ifndef BOOK
#define BOOK
class Book
{
	friend std::ostream& operator<< (std::ostream& output, Book& b);

private:
	char name[100];
	char ISBN[16];
	char author[50];
	Date publication_date;
	char publisher[50];
	int pagesNum;
	Type coverType;
	Book* nextBook;

public:
	void setNext(Book* b);
	Book* getNext();

	// Constructors:
	Book();
	Book(char name[], char isbn[], char a[], Date d, char p[], int pages, Type c);

	// Setter functions:
	void setName(char name[]);
	void setISBN(char isbn[]);
	void setAuthor(char author[]);
	void setDate(Date d);
	void setPublisher(char publisher[]);
	void setPages(int p);
	void setCover(Type c);

	// Getter functions:
	char* getName();
	char* getISBN();
	char* getAuthor();
	Date getDate();
	int getPages();
	char* getPublisher();
	Type getCover();
};

#endif // !BOOK
