#include <iostream>
struct Point
{


};

class Person 
{


};

class Vehicle
{
private:
	Point position;
	double height;
	double length;
	double width;
	double weight;

public:
	void Move(Point direction);
	void Rotate(Point direction);
	void Scale(float direction);
};

class Car : public Vehicle
{
private:
	int doors;
	int tankCapacity;
	char model[30];
	char mark[30];
	bool isStarted;

public:
	void FillUp(int points);
	void Start();
};

class Plane : public Vehicle
{
private:
	int seets;
	Point route[2];

public:
	void AuthorizePeople(const Person* peoplelist);
	void Fly();
	void CallDispatcher(Person dispetcher);
};

int main()
{
	Car car;
	Plane plane;
	plane.Move();
	return 0;
}