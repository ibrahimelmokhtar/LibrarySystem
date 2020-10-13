#include <iostream>
#include "hFiles/Date.h"
#include "hFiles/Book.h"
#include "hFiles/Member.h"
#include "hFiles/Borrower.h"
#include "hFiles/BookList.h"

using namespace std;

int main()
{
	char n[100]; char isbn[16]; char a[50]; char p[50];
	int pages;
	Type cover;	char type[5];
	BookList books;

	int numberOfBooks = 10;

	cout << "Adding " << numberOfBooks << " different books. then displaying ALL books together.\n";

	for (int i = 0; i < numberOfBooks; i++) {
		cout << "enter book's name: ";	cin.getline(n, 100);
		cout << "enter book's ISBN: ";	cin.getline(isbn, 16);

		// Check if the book name/isbn already exists
		if (books.searchByName(n, false) || books.searchByISBN(isbn, false)) {
			cout << "Book already exists!\n\n";
			i--;
			continue;
		}
		// Continue adding that new book
		cout << "enter author: ";	cin.getline(a, 50);
		Date D;
		cout << "enter date of publication (dd/mm/yy): ";	cin >> D;
		cin.ignore();
		cout << "enter publisher: ";	cin.getline(p, 50);
		cout << "enter no. of pages: ";	cin >> pages;
		cin.ignore();
		cout << "enter cover type: "; cin.getline(type, 5);
		if (strcmp(type, "soft") == 0)
			cover = soft;
		else
			cover = hard;

		cout << "Adding this book and Saving ..." << endl;
		books.addBook(n, isbn, a, D, p, pages, cover);
		books.saveBook();
    }

	books.displayList();

	cout << "\nSearch book ...\n";
	cout << "enter book's ISBN: ";	cin.getline(isbn, 16);
	books.displayBook(isbn);
	books.searchByISBN(isbn);

	cout << "enter book's Name: ";	cin.getline(n, 100);
	books.searchByName(n);
    
    system("pause");
}
