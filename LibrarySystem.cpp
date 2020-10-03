#include <iostream>
#include "hFiles/Date.h"

using namespace std;

int main()
{
    Date D;

    while (true) {
        cout << "enter date: ";
        cin >> D;

        D.setDate(D);
        
        cout << "date is: ";
        cout << D << "\n\n";
    }
    
    system("pause");
}
