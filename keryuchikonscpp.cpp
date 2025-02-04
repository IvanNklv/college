#include <iostream>
int main()
{
	/*
	std::cout << "Enter a number: ";
	int num;
	std::cin >> num;
	
	if (num ==0)
	{
		std::cout << "TRY AGAIN\n";
		std::cin >> num;
		if (num == 0)
		{
			std::cout << "TRY AGAIN\n";
			std::cin >> num;
		}

	}
	std::cout << "You entered " << num << std::endl;
	*/

	/*
	std::cout << "Enter a number in range [1;15]: ";
	int num;
	std::cin >> num;
	if (num >= 1 && num <= 15)
	{
		std::cout << "Okay";
	}
	else
	{
		std::cout << "It`s not in range";
	}
	*/

	/* 
	std::cout << "Enter a number in range [1;15]: ";
	int num;
	std::cin >> num;
	if (num ==1)
		std::cout << "One";
	else if (num == 2)
			std::cout << "two";
	else if (num == 3)
		std::cout << "Three";
	else
		std::cout << "other";

		*/

	/*
		std::cout << "enter two numbers";
	int num1;
	int num2;
	std::cin >> num1 >> num2;
	int max = (num1 > num2) ? num1 : num2;
	std::cout << "Max number is: " << max << std::endl;
	/*
	
	/*
	if (num1 > num2)
	{
		max = num1;
		}
	else
	{
		max = num2;
	}
	
	std::cout << "Max number is: " << max << std::endl;
	*/

	/*std::cout << "Enter a number in range [1;10]: ";
	int num;
	std::cin >> num;
	switch (num)
	{
	case 1:
		std::cout << "Its one\n";
		std::cout << num << std::endl;
		break;
	case 2:
		std::cout << "Its two\n";
		std::cout << num *2 << std::endl;
		break;
	case 3:
		std::cout << "Its three\n";
		std::cout << num *3 << std::endl;
		break;
	case 4:
		std::cout << "Its four\n";
		std::cout << num *4 << std::endl;
		break;
	default:
		std::cout << "its something different";
		break;
		}
		*/

	/*
	std::cout << "Enter a two numbers (second > first) ";
		int min, max;
		std::cin >> min >> max;
		int num = min;
		while (num <= max)
		{
			std::cout << num++ << " ";
			
		}
		*/

/*int num;
int sum = 0;
std::cout << "enter a number (0 to stop) ";
std::cin >> num;
sum += num;

while (num != 0)
{
	std::cout << "enter a number (0 to stop)";
	std::cin >> num;
	sum += num;
}
std::cout << "Sum =" << sum << std::endl;
*/

/*
int num;
do
{
	std::cout << "enter a number (negative to stop): ";
	std::cin >> num;
	if (num >= 0)
		std::cout << "square=" << num * num << std::endl;
} 
while (num >= 0);
*/
/*
int num1;
int num2;
;
for ( num1 = 0, num2 = 1; num1 <= 10 && num2 <= 10; num1++, num2++)
{
	std::cout << num1 << " " << num2 << std::endl;
}
*/

	/* 
	for (int val : {10, 123456, 12345678, 2345678})
	{
		std::cout << val << " ";
	}
	*/

		return 0;
	}