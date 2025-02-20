#include "Rectangle.h"

void Rectangle::SetHeight(int newHeight)
{

	if (newHeight > 0)
	{
		height = newHeight;
	}
}

void Rectangle::SetWidth(int newWidth)
{
	if (newWidth > 0)
	{
		width = newWidth;
	}
}

int Rectangle::GetHeight() const
{
	return height;
}

int Rectangle::GetWidth() const
{
	return width;
}
