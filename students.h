#pragma once
using namespace std;
class Student
{
private:
	//����
	char name[20] = "NoName";
	int age = 0;
public:
	//������
	void Show();
	
	void ChangeAge(int newAge);
	
	void ChangeName(const char* newName);
	
	void EnterName();
	
	void EnterAge();
	

};