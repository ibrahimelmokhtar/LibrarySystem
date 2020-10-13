#include "../hFiles/BookList.h"

BookList::BookList()
{
	startbook = NULL;
	currbook = NULL;
}
BookList::~BookList()
{
	currbook = startbook;
	while (currbook != NULL)
	{
		currbook = currbook->getNext();
		delete startbook;
		startbook = currbook;
	}
}

void BookList::addBook(char name[], char isbn[], char A[], Date d, char p[], int pages, Type C)
{
	Book* b = new Book(name, isbn, A, d, p, pages, C);
	if (startbook == NULL)
	{
		startbook = b;
	}
	else
	{
		currbook = startbook;
		while (currbook->getNext() != NULL)
			currbook = currbook->getNext();
		currbook->setNext(b);
	}

}

void BookList::displayBook(string isbn)
{
	Book b1;
	ifstream file1("Books.bin", ios::in | ios::binary);
	if (!file1)
	{
		cout << "Error" << endl;
		exit(1);
	}

	while (!file1.eof())
	{
		string foundit;
		file1.read((char*)&b1, sizeof(Book));
		foundit = b1.getISBN();

		char s2[16];
		strcpy_s(s2, foundit.c_str());
		char s3[16];
		strcpy_s(s3, isbn.c_str());

		if ((strcmp(s2, s3)) == 0)
		{
			cout << b1 << endl;
			break;
		}
	}
	file1.close();
}

void BookList::saveBook()
{
	ofstream file("Books.bin", ios::out | ios::app | ios::binary);
	if (!file)
	{
		cout << "Error" << endl;
		return;
	}
	else {
		currbook = startbook;
		while (currbook->getNext() != NULL)
			currbook = currbook->getNext();
		file.write(reinterpret_cast<const char*> (currbook), sizeof(Book));
	}
	file.close();
}

bool BookList::searchByISBN(string isbn, bool DISPLAY)
{
	bool FOUND = false;

	ifstream file1("Books.bin", ios::in | ios::binary);
	if (!file1)
	{
		cout << "Error" << endl;
		exit(1);
	}
	int count = 0;
	Book b1;
	while (!file1.eof())
	{
		string foundit;
		file1.read((char*)&b1, sizeof(Book));
		foundit = b1.getISBN();

		char s2[16];
		strcpy_s(s2, foundit.c_str());
		char s3[16];
		strcpy_s(s3, isbn.c_str());

		if ((strcmp(s2, s3)) == 0)
		{
			cout << "Found.\n\n";
			FOUND = true;
			count++;
			break;
		}
	}
	if (count == 0 && DISPLAY)
	{
		cout << "Book was not found." << endl;
	}
	file1.close();
	return FOUND;
}

bool BookList::searchByName(string n, bool DISPLAY)
{
	bool FOUND = false;

	ifstream file1("Books.bin", ios::in | ios::binary);
	if (!file1)
	{
		cout << "Error" << endl;
		exit(1);
	}

	Book b1;
	int count = 0;
	while (!file1.eof())
	{
		string foundit;
		file1.read((char*)&b1, sizeof(Book));
		foundit = b1.getName();

		char s2[100];
		strcpy_s(s2, foundit.c_str());
		char s3[100];
		strcpy_s(s3, n.c_str());

		if ((strcmp(s2, s3)) == 0)
		{
			cout << "Found.\n\n";
			FOUND = true;
			count++;
			break;
		}
	}
	if (count == 0 && DISPLAY)
	{
		cout << "Book not found." << endl;
	}
	file1.close();
	return FOUND;
}

void BookList::displayList()
{
	ifstream file2("Books.bin", ios::in | ios::binary);
	if (!file2)
	{
		cout << "Error";
		exit(1);
	}
	Book b1;
	while (true)
	{
		file2.read((char*)&(b1), sizeof(Book));
		if (file2.eof())
			break;
		cout << b1 << endl;;
	}
	file2.close();
}
