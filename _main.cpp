#include <iostream>
#include "hFiles/Date.h"
#include "hFiles/Book.h"
#include "hFiles/Member.h"
#include "hFiles/Borrower.h"
#include "hFiles/BookList.h"
#include "hFiles/MemberList.h"
#include "hFiles/BorrowerList.h"

using namespace std;

int main()
{
	// display members from Members.bin:
	cout << "Members: \n";
	MemberList members;
	members.displayList();
	cout << "\n\n";

	// display books from Books.bin:
	cout << "Books: \n";
	BookList books;
	books.displayList();
	cout << "\n\n";


	char id[10]; char isbn[16];
	char n[100]; char a[100];
	Date bd;	Date rd;

	BorrowerList borrowers;

	int numberOfBorrowers = 2;

	cout << "Adding " << numberOfBorrowers << " different borrowers. then displaying ALL borrowers together.\n";

	for (int i = 0; i < numberOfBorrowers; i++) {
		cout << "enter member's name: ";	cin.getline(n, 100);
		cout << "enter member's ID: ";	cin.getline(id, 10);
		cout << "enter address: ";	cin.getline(a, 100);

		// Check if that member's id already exists in Members.bin
		if (!borrowers.checkID(id)) {
			cout << "*** Invalid member!\n\n";
			i--;
			continue;
		}

		cout << "enter book's ISBN: ";		cin.getline(isbn, 16);

		// Check if that book's isbn already exists in Books.bin
		if (!borrowers.checkISBN(isbn)) {
			cout << "*** Invalid book!\n\n";
			i--;
			continue;
		}

		// Check if the borrower id already exists
		// As every borrower has only one book to borrow at a time.
		if (i > 0 && borrowers.searchByID(id, false)) {
			cout << "Borrower already exists!\n\n";
			i--;
			continue;
		}
		
		// Continue adding that new borrower
		cout << "enter borrowing date (dd/mm/yy): ";	cin >> bd;
		cin.ignore();
		cout << "enter return date (dd/mm/yy): ";		cin >> rd;
		cin.ignore();

		cout << "Adding this borrower and Saving ...\n\n";
		borrowers.addBorrower(id, n, a, isbn, bd, rd);
		borrowers.saveBorrower();
    }

	borrowers.displayList();

	cout << "\nSearch borrower ...\n";
	cout << "enter member's ID: ";	cin.getline(id, 10);
	borrowers.searchByID(id);
	borrowers.displayBorrower(id);
    
    system("pause");
}
