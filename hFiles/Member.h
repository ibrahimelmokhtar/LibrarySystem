#pragma once

#ifndef MEMBER
#define MEMBER

#include <string>

class Member
{
	friend std::ostream& operator<< (std::ostream& output, Member& M);

private:
	char ID[10];
	char name[100];
	char address[100];
	Member* nextMember;

public:
	// Constructors:
	Member();
	Member(char[], char[], char[]);

	// Setter functions:
	void setID(char[]);
	void setName(char[]);
	void setAddress(char[]);
	void setNext(Member* n);

	// Getter functions:	
	char* getID();
	char* getName();
	char* getAdress();
	Member* getNext();
};

#endif // !MEMBER
