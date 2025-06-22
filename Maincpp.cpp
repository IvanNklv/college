#include "String.h"
#include <cstring>
#include <iostream>
char ConvertDigitToChar(int digit);
String CreateStringWithNumbers(const int arr[], size_t size);


int main()
{
	String str1{ "Some interesting text" };
	
	String str2{ std::move( str1) };
	String str3;

	const char* C_STR = "C-Some interesting text";
	String str4{ C_STR };

	const size_t SIZE = 3;
	char someLetters[SIZE] = { 'A', 'B','C' };
	String str5{ someLetters,SIZE };

	std::cout << "str1 = [" << str1.GetString() << "]\n";
	std::cout << "str2 = [" << str2.GetString() << "]\n";
	std::cout << "str3 = [" << str3.GetString() << "]\n";
	std::cout << "str4 = [" << str4.GetString() << "]\n";
	std::cout << "str5 = [" << str5.GetString() << "]\n";

	std::cout << std::endl;

	std::cout << "str1 lenght = " << str1.GetLenth() << std::endl;
	std::cout << "str1 lenght = " << str2.GetLenth() << std::endl;
	std::cout << "str1 lenght = " << str3.GetLenth() << std::endl;
	std::cout << "str1 lenght = " << str4.GetLenth() << std::endl;
	std::cout << "str1 lenght = " << str5.GetLenth() << std::endl;

	std::cout << std::endl;

	str3.SetString(C_STR);
	std::cout << "str3 = [" << str3.GetString() << "]\n";
	str3.SetString(someLetters, SIZE);
	std::cout << "str3 = [" << str3.GetString() << "]\n";
	str3.SetString(str1);
	std::cout << "str3 = [" << str3.GetString() << "]\n";

	int arr[SIZE] = { 4,6,9 };
	String str6{ CreateStringWithNumbers(arr,SIZE) };
	std::cout << "str6 = [" << str6.GetString() << "]\n";

	return 0;
}

char ConvertDigitToChar(int digit)
{
	return digit >= 0 && digit <= 9 ? digit + '0' : '!';
}
String CreateStringWithNumbers(const int arr[], size_t size)
{
	if (arr == nullptr || size == 0)
		return String();

	char* str = new char[size + 1];

	for (size_t i = 0; i < size; i++)
	{
		char ConvertedDigit = ConvertDigitToChar(arr[i]);
		str[i] = ConvertedDigit;
	}
	str[size] = '\0';

	String object{ str };
	delete[] str;
	return object;
}