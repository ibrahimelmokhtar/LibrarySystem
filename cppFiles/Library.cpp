#include "../hFiles/Library.h"

void Library::editBooks()
{
	char n[100]; char isbn[16]; char a[50]; char p[50];
	int pages;
	Type cover;	char type[5];
	int choice;
	while (true) {
		cout << "0.return to menu  1.add  2.search  3.display book  4.display list" << endl
			<< "enter your choice: ";	cin >> choice;
		cin.ignore();

		if (choice != 0) {
			switch (choice) {
			case 1: // adding book
			{
				cout << "enter book's name: ";	cin.getline(n, 100);
				cout << "enter book's ISBN: ";	cin.getline(isbn, 16);
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
				Books.addBook(n, isbn, a, D, p, pages, cover);
				Books.saveBook();
				cout << endl; break;
			}

			case 2:	//searching book
			{
				cout << "1.search by name  2.search by ISBN" << endl
					<< "enter your choice: ";	cin >> choice;
				cin.ignore();

				switch (choice) {
				case 1:
				{
					cin.ignore();
					cout << "enter book's name: ";	cin.getline(n, 100);
					Books.searchByName(n);
					cout << endl; break;
				}
				case 2:
				{
					cin.ignore();
					cout << "enter book's ISBN: ";	cin.getline(isbn, 16);
					Books.searchByISBN(isbn);
					cout << endl; break;
				}
				default:
				{
					cout << "please enter a valid choice ..." << endl;
					break;
				}
				}	break;
			}

			case 3: //displaying book
			{
				cout << "enter book's ISBN: ";	cin.getline(isbn, 16);
				Books.displayBook(isbn);
				cout << endl; break;
			}

			case 4:	//displaying list
			{
				Books.displayList();
				cout << endl; break;
			}

			default:
				cout << "please enter a valid choice ... now try again: ";
			}
		}
		else
			break;
	}
}
void Library::editMembers()
{
	char n[100]; char id[10]; char a[100];
	int choice;
	while (true) {
		cout << "0.return to menu  1.add  2.search  3.display member  4.display list" << endl
			<< "enter your choice: ";	cin >> choice;
		cin.ignore();

		if (choice != 0) {
			switch (choice) {
			case 1: // adding member
			{
				cin.ignore();
				cout << "enter member's name: ";	cin.getline(n, 100);
				cout << "enter member's ID: ";	cin.getline(id, 10);
				cout << "enter address: ";	cin.getline(a, 100);
				Members.addMember(id, n, a);
				Members.saveMember();
				cout << endl; break;
			}

			case 2:	//searching member
			{
				cout << "1.search by name  2.search by ID" << endl
					<< "enter your choice: ";	cin >> choice;
				cin.ignore();

				switch (choice) {
				case 1:
				{
					cout << "enter member's name: ";	cin.getline(n, 100);
					Members.searchByName(n);
					cout << endl; break;
				}
				case 2:
				{
					cout << "enter member's ID: ";	cin.getline(id, 10);
					Members.searchByID(id);
					cout << endl; break;
				}
				default:
				{
					cout << "please enter a valid choice ..." << endl;
					break;
				}
				}	break;
			}

			case 3: //displaying member
			{
				cout << "enter member's ID: ";	cin.getline(id, 10);
				Members.displayMember(id);
				cout << endl; break;
			}

			case 4:	//displaying list
			{
				Members.displayList();
				cout << endl; break;
			}

			default:
				cout << "please enter a valid choice ... now try again: ";
			}
		}
		else
			break;
	}
}
void Library::editBorrowers()
{
	char id[10]; char isbn[16];
	char name[100]; char address[100];
	int choice;
	while (true) {
		cout << "0.return to menu  1.add  2.search  3.display borrower  4.display list" << endl
			<< "enter your choice: ";	cin >> choice;
		cin.ignore();

		if (choice != 0) {
			switch (choice) {
			case 1: // adding borrower
			{
				cout << "enter borrower's ID: ";	cin.getline(id, 10);
				cout << "enter borrower's Name: ";	cin.getline(name, 50);
				cout << "enter borrower's address: ";		cin.getline(address, 50);
				cout << "enter book's ISBN: ";		cin.getline(isbn, 16);
				Date bd;	Date rd;
				cout << "enter borrowing date (dd/mm/yy): ";	cin >> bd;
				cin.ignore();
				cout << "enter return date (dd/mm/yy): ";		cin >> rd;
				cin.ignore();
				Borrowers.addBorrower(id, name, address, isbn, bd, rd);
				if (Borrowers.checkID(id) && Borrowers.checkISBN(isbn))
					Borrowers.saveBorrower();
				else
					Borrowers.checkISBN(isbn);
				cout << endl; break;
			}

			case 2:	//searching borrower
			{
				cout << "enter borrower's ID: ";	cin.getline(id, 10);
				Borrowers.searchByID(id);
				cout << endl; break;
			}

			case 3: //displaying borrower
			{
				cout << "enter borrower's ID: ";	cin.getline(id, 10);
				Borrowers.displayBorrower(id);
				cout << endl; break;
			}

			case 4:	//displaying list
			{
				Borrowers.displayList();
				cout << endl; break;
			}

			default:
				cout << "please enter a valid choice ... now try again: ";
			}
		}
		else
			break;
	}
}
