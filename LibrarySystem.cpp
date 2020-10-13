#include <iostream>
#include "hFiles/Date.h"
#include "hFiles/Book.h"
#include "hFiles/Member.h"
#include "hFiles/Borrower.h"
#include "hFiles/BookList.h"
#include "hFiles/MemberList.h"

using namespace std;

int main()
{
	char n[100]; char id[10]; char a[100];
	MemberList members;

	int numberOfMembers = 5;

	cout << "Adding " << numberOfMembers << " different members. then displaying ALL members together.\n";

	for (int i = 0; i < numberOfMembers; i++) {
		cout << "enter member's name: ";	cin.getline(n, 100);
		cout << "enter member's ID: ";	cin.getline(id, 10);

		// Check if the book name/isbn already exists
		if (members.searchByName(n, false) || members.searchByID(id, false)) {
			cout << "Member already exists!\n\n";
			i--;
			continue;
		}
		// Continue adding that new book
		cout << "enter address: ";	cin.getline(a, 100);

		cout << "Adding this member and Saving ..." << endl;
		members.addMember(id, n, a);
		members.saveMember();
    }

	members.displayList();

	cout << "\nSearch member ...\n";
	cout << "enter member's ID: ";	cin.getline(id, 10);
	members.displayMember(id);
	members.searchByID(id);

	cout << "enter member's Name: ";	cin.getline(n, 100);
	members.searchByName(n);
    
    system("pause");
}
