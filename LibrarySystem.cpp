#include <iostream>
#include "hFiles/Date.h"
#include "hFiles/Book.h"

using namespace std;

int main()
{
    char n[100]; char isbn[16]; char a[50];
    Date D; char p[50]; int pages = 0;
    Type cover = soft;	char type[5];

    while (true) {
        cout << "enter book's name: ";	cin.getline(n, 100);
        cout << "enter book's ISBN: ";	cin.getline(isbn, 16);
        cout << "enter author: ";	cin.getline(a, 50);
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

        Book b(n, isbn, a, D, p, pages, cover);
        cout << "\n" << b << endl;
    }
    
    system("pause");
}
