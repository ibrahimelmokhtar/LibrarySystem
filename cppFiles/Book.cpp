#include "../hFiles/Book.h"
#include "../hFiles/Date.h"

#include <iostream>
#include <string>

Book::Book()
{
	char* empty = (char*)" ";
	setName(empty);
	setISBN(empty);
	setAuthor(empty);
	setPublisher(empty);
	setPages(0);
	setCover(soft);
}
Book::Book(char name[], char isbn[], char a[], Date d, char p[], int pages, Type c)
{
	setName(name);
	setISBN(isbn);
	setAuthor(a);
	setDate(d);
	setPublisher(p);
	setPages(pages);
	setCover(c);
}

void Book::setName(char n[])
{
	for (unsigned int i = 0; i < strlen(n); i++)
	{
		name[i] = n[i];
	}
}
void Book::setISBN(char isbn[])
{
	for (unsigned int i = 0; i < strlen(isbn); i++)
	{
		ISBN[i] = isbn[i];
	}
}
void Book::setAuthor(char a[])
{
	for (unsigned int i = 0; i < strlen(a); i++)
	{
		author[i] = a[i];
	}
}
void Book::setDate(Date d)
{
	publication_date.setDate(d);
}
void Book::setPages(int p)
{
	pagesNum = p;
}
void Book::setPublisher(char p[])
{
	for (unsigned int i = 0; i < strlen(p); i++)
	{
		publisher[i] = p[i];
	}
}
void Book::setCover(Type c)
{
	coverType = c;
}
void Book::setNext(Book* b)
{
	nextBook = b;
}

char* Book::getISBN()
{
	return ISBN;
}
char* Book::getAuthor()
{
	return author;
}
Date Book::getDate()
{
	return publication_date;
}
int Book::getPages()
{
	return pagesNum;
}
char* Book::getPublisher()
{
	return publisher;
}
Type Book::getCover()
{
	return coverType;
}
char* Book::getName()
{
	return name;
}
Book* Book::getNext()
{
	return nextBook;
}

std::ostream& operator<<(std::ostream& output, Book& B)
{
	Date D = B.getDate();
	output << "Name\t\t:" << B.getName() << "\n"
		<< "ISBN\t\t:" << B.getISBN() << "\n"
		<< "Author\t\t:" << B.getAuthor() << "\n"
		<< "Date\t\t:" << D << "\n"
		<< "Publisher\t:" << B.getPublisher() << "\n"
		<< "Pages\t\t:" << B.getPages() << "\n"
		<< "Cover\t\t:" << B.getCover() << "\n";

	return output;
}