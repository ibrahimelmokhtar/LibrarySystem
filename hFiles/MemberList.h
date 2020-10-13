#pragma once

#ifndef MEMBERLIST
#define MEMBERLIST

#include"Member.h"
#include<string>

using namespace std;

class MemberList :public Member
{
private:
	Member* startmember;
	Member* currmember;
public:
	// Constructors:
	MemberList();
	~MemberList();
	
	// Search functions:
	bool searchByName(string name, bool DISPLAY = false);
	bool searchByID(string id, bool DISPLAY = false);

	// Add new book:
	void addMember(char id[], char name[], char address[]);

	// Save new book:
	void saveMember();

	// Display functions:
	void displayList();
	void displayMember(string id);
};
#endif // !MEMBERLIST
