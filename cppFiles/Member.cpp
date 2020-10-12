#include "../hFiles/Member.h"
#include<iostream>

using namespace std;

Member::Member()
{
	char* empty = (char*)" ";
	setID(empty);
	setName(empty);
	setAddress(empty);
}
Member::Member(char id[], char N[], char a[])
{
	setID(id);
	setName(N);
	setAddress(a);
}

void Member::setID(char id[])
{
	for (unsigned int i = 0; i < strlen(id); i++)
	{
		ID[i] = id[i];
	}
}
void Member::setName(char N[])
{
	for (unsigned int i = 0; i < strlen(N); i++)
	{
		name[i] = N[i];
	}
}
void Member::setAddress(char a[])
{
	for (unsigned int i = 0; i < strlen(a); i++)
	{
		address[i] = a[i];
	}
}
void Member::setNext(Member* n)
{
	nextMember = n;
}

char* Member::getID()
{
	return ID;
}
char* Member::getName()
{
	return name;
}
char* Member::getAdress()
{
	return address;
}
Member* Member::getNext()
{
	return nextMember;
}

std::ostream& operator<<(std::ostream& output, Member& M)
{
	output << "ID\t:" << M.getID() << "\n" 
		<< "Name\t:" << M.getName() << "\n"
		<< "Address\t:" << M.getAdress() << "\n";

	return output;
}
