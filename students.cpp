#include <iostream>
#include <cstring>
#include "students.h"
using namespace std;

void Student::Show()
{
	cout << "\tName:" << name << endl;
	cout << "\tAge:" << age << endl;
}
void Student::ChangeAge(int newAge)
{
	if (newAge > 0)
	{
		age = newAge;
	}
	else
	{
		cout << "New age is incorrect\n";
	}
}
void Student::ChangeName(const char* newName)
{
	if (newName != nullptr && strlen(newName) < 20)
	{
		strcpy_s(name, 20, newName);
	}
	else
	{

		cout << "New name is incorrect\n";
	}
}
void Student::EnterName()
{
	char temp[255];
	cout << "enter Name: ";
	cin >> temp;
	ChangeName(temp);
}
void Student::EnterAge()
{
	int temp;
	cout << "enter Age: ";
	cin >> temp;
	ChangeAge(temp);
}
