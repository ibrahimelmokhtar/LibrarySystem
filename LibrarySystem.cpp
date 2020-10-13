#include <iostream>
#include "hFiles/Date.h"
#include "hFiles/Book.h"
#include "hFiles/Member.h"
#include "hFiles/Borrower.h"

using namespace std;

int main()
{
    char memberName[100];   char memberAddress[100];
    char memberID[10]; char bookISBN[16];
    Date borrowD;   Date returnD;

    while (true) {
        cout << "enter member's Name: ";    cin.getline(memberName, 100);
        cout << "enter member's ID: ";	cin.getline(memberID, 10);
        cout << "enter member's Address: ";    cin.getline(memberAddress, 100);
        cout << "enter book's isbn: ";	cin.getline(bookISBN, 16);
        cout << "enter borrowing date: ";	cin >> borrowD;
        cin.ignore();
        cout << "enter returning date: ";	cin >> returnD;
        cin.ignore();

        Borrower b(memberID, memberName, memberAddress, bookISBN, borrowD, returnD);
        cout << "\n" << b << endl;
    }
    
    system("pause");
}
