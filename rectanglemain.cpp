#include <iostream>
#include "Rectangle.h"
using namespace std;
void Show(Rectangle& rectangle);
int main()
{
	Rectangle one;
	Show(one);
	one.SetHeight(20);
	one.SetWidth(30);

	Show(one);
	return 0;
}
void Show(Rectangle& rectangle)
{
	cout << "Height = " << rectangle.GetHeight() << endl;
	cout << "Width = " << rectangle.GetWidth() << endl;
}