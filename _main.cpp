
#include "hFiles/Library.h"


using namespace std;

int main()
{
	Library L;

	int choice;
	while (true)
	{
		cout << "0.end the program  1.books  2.members  3.borrowers" << endl
			<< "editing in: ";	cin >> choice;
		cin.ignore();

		if (choice != 0)
		{
			switch (choice) {
			case 1:
				L.editBooks();	break;
			case 2:
				L.editMembers();	break;
			case 3:
				L.editBorrowers();	break;
			default:
				cout << "please enter a valid choice ...\n\n";
			}
		}
		else {
			cout << "\n\n";
			cout << "Shutting down the program ... \n\n";
			break;
		}
	}
    system("pause");
}
