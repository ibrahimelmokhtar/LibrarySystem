#include <iostream>
#include "hFiles/Date.h"
#include "hFiles/Book.h"
#include "hFiles/Member.h"

using namespace std;

int main()
{
    char id[10]; char name[100]; char address[100];

    while (true) {
        cout << "enter member's name: ";	cin.getline(name, 100);
        cout << "enter member's ID: ";	cin.getline(id, 10);
        cout << "enter member's address: ";	cin.getline(address, 100);

        Member m(id, name, address);
        cout << "\n" << m << endl;
    }
    
    system("pause");
}
