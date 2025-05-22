
#include <iostream>

/*
void ShowIntArr(int arr[], size_t size);
void ShowDoubleArr(double arr[], size_t size);
void ShowCharArr(char arr[], size_t size);

template <typename T>
void Show(const T arr[], size_t size);

int main()
{
	int arr1[] = { 1,2,3 };
	double arr2[] = { 1.1, 2.2, 3.3 };
	char arr3[] = { 'a','b','c' };

	Show(arr1, 3);
	Show(arr2, 3);
	Show(arr3, 3);

	return 0
}

void ShowIntArr(int arr[], size_t size);
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void ShowIntArr(double arr[], size_t size);
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void ShowIntArr(char arr[], size_t size);
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void Show(const T arr[], size_t size);
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
*/

/*
void Show(int number);
void Show(const char* str);
int main()
{
	int number = 10;

	char str[] = "Hello World";

	Show(number);
	Show(str);
 return 0;
}
void Show(int number);
{
	std::cout << number << std::endl;
}
void Show(const char* str);
{
	size_t size = std::strlen(str);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << str[i] << " ";
	}
	std::cout << std::endl;
}
*/
/*
using namespace std;


struct Position {
	int x;
	int y;
};


class Unit {
protected:
	Position position;
	int hp;

public:
	Unit(const Position& pos, int hp)
		: position(pos), hp(hp > 0 ? hp : 0) {}


	virtual void Show() const {
		cout << "Unit position: [" << position.x << ", " << position.y << "]\n";
		cout << "HP: " << hp << "\n";
	}

	virtual ~Unit() {}
};


class Archer : public Unit {
private:
	float bowDamage;
	int countArrows;

public:
	Archer(const Position& position, int hp, float bowDamage, int countArrows)
		: Unit(position, hp)
		, bowDamage(bowDamage > 0 ? bowDamage : 0)
		, countArrows(countArrows > 0 ? countArrows : 0)
	{}

	
	void Show() const override {
		Unit::Show(); 
		cout << "Bow Damage: " << bowDamage << "\n";
		cout << "Arrows: " << countArrows << "\n";
	}
};


int main() {
	Archer a({ 5, 10 }, 80, 25.5f, 15); 

	Unit* ptr = &a; 

	ptr->Show(); 

	return 0;
}
*/

/*
class A
{
public:
	void UsualMethodA() { std::cout << "I'm usual method A\n"; }
	virtual void Method() { std::cout << "A::Method() \n"; }
};

class B : public A
{
public:
	void UsualMethodB() { std::cout << "I'm usual method B\n"; }
	virtual void Method() { std::cout << "B::Method() \n"; }
};

class C : public B
{
public:
	void UsualMethodC() { std::cout << "I'm usual method C\n"; }
	virtual void Method() { std::cout << "C::Method() \n"; }
};

int main()
{
	A objectA;
	B objectB;
	C objectC;

	A* ptr;

	ptr = &objectA;
	ptr->UsualMethod();

	ptr = &objectB;
	ptr->UsualMethod();

	ptr = &objectC;
	ptr->Method();
	ptr->UsualMethod();

	return 0;
}
*/

/*
class Archer
{
protected:
	float bowDamage = 0;
	int countArrows = 0;

public:
	Archer()
	{
		std::cout << "Archer::Archer()\n";
	}

	float GetBowDamage() const { return bowDamage; }
	int GetArrowsCount() const { return countArrows; }

	virtual void Show() const
	{
		std::cout << "Archer Info:\n";
		std::cout << "Bow damage: " << bowDamage << "\n";
		std::cout << "Arrows: " << countArrows << "\n";
	}

	virtual void SetPosition(const Position& newPosition)
	{
		std::cout << "Archer::SetPosition()\n";
		this->position = newPosition;
	}

	virtual ~Archer() {}
};

class WitchArcher : public Archer
{
	float magicPower = 0;

public:
	WitchArcher()
	{
		bowDamage = 100;
		countArrows = 50;
		magicPower = 200;
	}

	void Show() const override
	{
		std::cout << "WitchArcher Info:\n";
		std::cout << "Bow damage: " << bowDamage << "\n";
		std::cout << "Arrows: " << countArrows << "\n";
		std::cout << "Magic power: " << magicPower << "\n";
	}

	void SetPosition(const Position& newPosition) override
	{
		std::cout << "WitchArcher::SetPosition()\n";
		this->position = newPosition;
	}
};
*/
/*
class A
{
public:
	virtual void Method() {}
};

class B : public A;
{
	virtual void Method() final {}
};
Class C : public B;
{
	virtual void Method() override {}
}

int main()
{
A objectA;

objectA.Method();

B objectB;

objectB.Method();

B* ptr = &objectB;

ptr->Method();


}

*/

/*
int Sum(int a, int b) { return a + b; }
int Diff(int a, int b) { return a - b; }
int Mult(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

int main()
{
	int (*operation)(int, int);

	std::cout << "Enter two numbers: ";
	int number1, number2;
	std::cin >> number1 >> number2;

	std::cout << "Enter operation (+, -, *, /): ";
	char operationSYMBOL;
	std::cin >> operationSYMBOL;

	switch (operationSYMBOL)
	{
	case '+':
		operation = Sum;
		break;

	case '-':
		operation = Diff;
		break;

	case '*':
		operation = Mult;
		break;

	case '/':
		operation = Div;
		break;

	default:
		std::cout << "Error\n";
		break;
	}

	int result = operation(number1, number2);
	std::cout << "RESULT = " << number1 << " " << operationSYMBOL << " " << number2 << " = " << result << std::endl;

	return 0;
}
*/


class A
{
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}
	void f4() {}
};

class B : public A
{
public:
	virtual void f1() override {}
	virtual void f2() override {}
	virtual void f5() override {}
	virtual void f6() {}
};

int main()
{
	A* ptr = new B;
	ptr->f3();
	delete ptr;
	return 0;
}