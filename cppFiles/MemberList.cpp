#include "../hFiles/MemberList.h"

#include <iostream>
#include <fstream>

MemberList::MemberList()
{
	startmember = NULL;
	currmember = NULL;
}
MemberList::~MemberList()
{
	currmember = startmember;
	while (currmember != NULL)
	{
		currmember = currmember->getNext();
		delete startmember;
		startmember = currmember;
	}
}

void MemberList::addMember(char id[], char name[], char address[])
{
	Member* m = new Member(id, name, address);
	if (startmember == NULL)
	{
		startmember = m;
	}
	else
	{
		currmember = startmember;
		while (currmember->getNext() != NULL)
			currmember = currmember->getNext();
		currmember->setNext(m);
	}
}

void MemberList::displayMember(string id)
{
	Member m1;
	ifstream file1("Members.bin", ios::in | ios::binary);
	if (!file1)
	{
		cout << "Error" << endl;
		exit(1);
	}

	else
	{
		while (!file1.eof())
		{
			string foundit;
			file1.read((char*)&m1, sizeof(Member));
			foundit = m1.getID();

			char s2[16];
			strcpy_s(s2, foundit.c_str());
			char s3[16];
			strcpy_s(s3, id.c_str());

			if ((strcmp(s2, s3)) == 0)
			{
				cout << m1 << endl;
				break;
			}
		}
		file1.close();
	}
}

void MemberList::saveMember()
{
	ofstream file("Members.bin", ios::out | ios::app | ios::binary);
	if (!file)
	{
		cout << "Error" << endl;
		return;
	}
	else {
		currmember = startmember;
		while (currmember->getNext() != NULL)
			currmember = currmember->getNext();
		file.write(reinterpret_cast<const char*> (currmember), sizeof(Member));
	}
	file.close();
}

bool MemberList::searchByID(string id, bool DISPLAY)
{
	bool FOUND = false;

	ifstream file1("Members.bin", ios::in | ios::binary);
	if (!file1)
	{
		cout << "Error" << endl;
		exit(1);
	}
	int count = 0;
	Member m1;
	while (!file1.eof())
	{
		string foundit;
		file1.read((char*)&m1, sizeof(Member));
		foundit = m1.getID();

		char s2[16];
		strcpy_s(s2, foundit.c_str());
		char s3[16];
		strcpy_s(s3, id.c_str());

		if ((strcmp(s2, s3)) == 0)
		{
			cout << "Found" << endl;
			FOUND = true;
			count++;
			break;
		}
	}
	if (count == 0 && DISPLAY)
	{
		cout << "Member was not found." << endl;
	}
	file1.close();
	return FOUND;
}

bool MemberList::searchByName(string n, bool DISPLAY)
{
	bool FOUND = false;

	ifstream file1("Members.bin", ios::in | ios::binary);
	if (!file1)
	{
		cout << "Error" << endl;
		exit(1);
	}

	Member m1;
	int count = 0;
	while (!file1.eof())
	{
		string foundit;
		file1.read((char*)&m1, sizeof(Member));
		foundit = m1.getName();

		char s2[100];
		strcpy_s(s2, foundit.c_str());
		char s3[100];
		strcpy_s(s3, n.c_str());

		if ((strcmp(s2, s3)) == 0)
		{
			cout << "Found." << endl;
			FOUND = true;
			count++;
			break;
		}
	}
	if (count == 0 && DISPLAY)
		cout << "Member not found." << endl;
	file1.close();
	return FOUND;
}

void MemberList::displayList()
{
	ifstream file2("Members.bin", ios::in | ios::binary);
	if (!file2)
	{
		cout << "Error";
		exit(1);
	}
	Member m1;
	while (true)
	{
		file2.read((char*)&(m1), sizeof(Member));
		if (file2.eof())
			break;
		cout << m1 << endl;
	}
	file2.close();
}