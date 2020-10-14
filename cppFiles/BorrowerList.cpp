#include "../hFiles/BorrowerList.h"
#include "../hFiles/Member.h"
#include "../hFiles/Borrower.h"
#include "../hFiles/Date.h"
#include "../hFiles/Book.h"

#include <fstream>

using namespace std;

BorrowerList::BorrowerList()
{
	startBorrower = NULL;
	currBorrower = NULL;
}
BorrowerList::~BorrowerList()
{
	currBorrower = startBorrower;
	while (currBorrower != NULL)
	{
		currBorrower = currBorrower->getNext();
		delete startBorrower;
		startBorrower = currBorrower;
	}
}

void BorrowerList::addBorrower(char id[], char N[], char a[], char isbn[], Date bd, Date rd)
{
	Borrower* b = new Borrower(id, N, a, isbn, bd, rd);
	if (startBorrower == NULL)
	{
		startBorrower = b;
	}
	else
	{
		currBorrower = startBorrower;
		while (currBorrower->getNext() != NULL)
			currBorrower = currBorrower->getNext();
		currBorrower->setNext(b);
	}
}

bool BorrowerList::searchByID(string n, bool DISPLAY)
{
	bool FOUND = false;

	ifstream file1("Borrowers.bin", ios::in | ios::binary);
	if (!file1)
	{
		cout << "Error" << endl;
		exit(1);
	}
	int count = 0;
	Borrower b1;
	while (!file1.eof())
	{
		string foundit;
		file1.read((char*)&b1, sizeof(Borrower));
		foundit = b1.getID();

		char s2[100];
		strcpy_s(s2, foundit.c_str());
		char s3[100];
		strcpy_s(s3, n.c_str());

		if ((strcmp(s2, s3)) == 0)
		{
			cout << "Found" << endl;
			count++;
			break;
		}
	}

	if (count == 0 && DISPLAY)
	{
		cout << "Borrower was not found." << endl;
	}
	file1.close();
	return FOUND;
}

void BorrowerList::displayList()
{
	ifstream file2("Borrowers.bin", ios::in | ios::binary);
	if (!file2)
	{
		cout << "Error";
		exit(1);
	}
	Borrower b1;
	while (true)
	{
		file2.read((char*)&b1, sizeof(Borrower));
		if (file2.eof())
			break;
		cout << b1 << endl;
	}
	file2.close();
}

bool BorrowerList::checkID(string id)
{
	bool FOUND = false;

	ifstream file("Members.bin", ios::in | ios::binary);
	if (!file)
	{
		cout << "Error" << endl;
		exit(1);
	}
	Member m1;
	while (!file.eof())
	{
		string foundit;
		file.read((char*)&m1, sizeof(Member));
		foundit = m1.getID();
		char s2[10];
		strcpy_s(s2, foundit.c_str());
		char s3[10];
		strcpy_s(s3, id.c_str());

		if ((strcmp(s2, s3)) == 0)
		{
			FOUND = true;
		}
	}

	// Member is NOT found:
	if (!FOUND) {
		cout << "member is not found" << endl;
	}

	file.close();
	return FOUND;
}

bool BorrowerList::checkISBN(string isbn)
{
	bool FOUND = false;

	ifstream file("Books.bin", ios::in | ios::binary);
	if (!file)
	{
		cout << "Error" << endl;
		exit(1);
	}
	Book b1;
	while (!file.eof())
	{
		string foundit;
		file.read((char*)&b1, sizeof(Book));
		foundit = b1.getISBN();
		char s2[16];
		strcpy_s(s2, foundit.c_str());
		char s3[16];
		strcpy_s(s3, isbn.c_str());

		if ((strcmp(s2, s3)) == 0)
		{
			FOUND = true;
		}
	}

	// Book is NOT found:
	if (!FOUND) {
		cout << "book is not found" << endl;
	}

	file.close();
	return FOUND;
}

void BorrowerList::saveBorrower()
{
	ofstream file("Borrowers.bin", ios::out | ios::app | ios::binary);
	if (!file)
	{
		cout << "Error" << endl;
		return;
	}
	else {
		currBorrower = startBorrower;
		while (currBorrower->getNext() != NULL)
		{
			currBorrower = currBorrower->getNext();
		}
		file.write(reinterpret_cast<const char*> (currBorrower), sizeof(Borrower));
	}
	file.close();
}

void BorrowerList::displayBorrower(string id)
{
	Borrower b1;
	ifstream file1("Borrowers.bin", ios::in | ios::binary);
	if (!file1)
	{
		cout << "Error" << endl;
		exit(1);
	}

	else
	{
		while (!file1.eof())
		{
			string foundit;
			file1.read((char*)&b1, sizeof(Borrower));
			foundit = b1.getID();

			char s2[100];
			strcpy_s(s2, foundit.c_str());
			char s3[100];
			strcpy_s(s3, id.c_str());

			if ((strcmp(s2, s3)) == 0)
			{
				cout << b1 << endl;
				break;
			}
		}
	}
	file1.close();
}
