/*#include <iostream>
#include <cstring>
#include "students.h"
using namespace std;

void Initialize(Student students[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Student #" << i + 1 << ":\n";
		students[i].EnterName();
		students[i].EnterAge();
	}
}
void Show(Student students[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Student #" << i + 1 << ":\n";

		students[i].Show();
	}
}

//int main()
{
	/*Student ivan;
	Student olga;

	ivan.ChangeAge(18);
	ivan.ChangeName("Ivan");

	olga.ChangeAge(20);
	olga.ChangeName("Olga");

	ivan.Show();

	Student* pIvan = &ivan;
	
	pIvan->ChangeAge(19);
	pIvan->ChangeName("Ivan");

	ivan.Show();
	olga.Show(); 
	

	cout << "Enter amount of students: ";
	size_t size;
	cin >> size;
	Student* students = new Student[size];

	Initialize(students, size);
	Show(students, size);

	delete[] students;
	return 0;
}
*/
